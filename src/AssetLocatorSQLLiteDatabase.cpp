#include "AssetLocatorSQLLiteDatabase.h"
#include "SQLLiteDatabasePrepStmts.h"

#include <iostream>

namespace cards
{
    AssetLocatorSQLLiteDatabase::AssetLocatorSQLLiteDatabase()
    {
      database = NULL;
    }

    AssetLocatorSQLLiteDatabase::AssetLocatorSQLLiteDatabase(std::string filename)
    {
      database = NULL;
      open(filename);
    } 

    void 
    AssetLocatorSQLLiteDatabase::insert(std::string name, int lod, std::string location)
    {
      updateLODsForInsert(name, lod);

      sqlite3_stmt* statement; 
      sqlite3_prepare_v2(database, stmt_insert.c_str(), -1, &statement, 0);
      sqlite3_bind_text(statement, 1, name.c_str(), name.size(), SQLITE_STATIC);
      sqlite3_bind_int(statement, 2, lod);
      sqlite3_bind_text(statement, 3, location.c_str(), location.size(), SQLITE_STATIC);
    
      int result = sqlite3_step(statement);

      if (result != SQLITE_DONE)
	std::cerr << "Error inserting to database" << std::endl;

      sqlite3_finalize(statement);
    }

    std::vector<std::string>
    AssetLocatorSQLLiteDatabase::query(std::string name)
    {
      std::vector<std::string> results;

      sqlite3_stmt* statement;
      if(sqlite3_prepare_v2(database, stmt_select.c_str(), -1, &statement, 0) == SQLITE_OK)
      {
	  sqlite3_bind_text(statement, 1, name.c_str(), name.size(), SQLITE_STATIC);

	  int cols = sqlite3_column_count(statement);
	  int result = 0;

	  while(true)
	  {
            result = sqlite3_step(statement);
             
            if(result == SQLITE_ROW)
            {
              results.push_back((char*)sqlite3_column_text(statement, cols-1));
            }
            else
            {
              break;  
            }
	  }
        
        sqlite3_finalize(statement);
      }

      return results;
    }

    void
    AssetLocatorSQLLiteDatabase::remove(std::string name)
    {
      sqlite3_stmt* statement; 
      sqlite3_prepare_v2(database, stmt_delete_noid.c_str(), -1, &statement, 0);
      sqlite3_bind_text(statement, 1, name.c_str(), name.size(), SQLITE_STATIC);

      int result = sqlite3_step(statement);

      if (result != SQLITE_DONE)
	std::cerr << "Error deleting from database" << std::endl;

      sqlite3_finalize(statement);
    }

    void
    AssetLocatorSQLLiteDatabase::remove(std::string name, int lod)
    {
      sqlite3_stmt* statement; 
      sqlite3_prepare_v2(database, stmt_delete_id.c_str(), -1, &statement, 0);
      sqlite3_bind_text(statement, 1, name.c_str(), name.size(), SQLITE_STATIC);
      sqlite3_bind_int(statement, 2, lod);

      int result = sqlite3_step(statement);

      if (result != SQLITE_DONE)
	std::cerr << "Error deleting from database" << std::endl;

      sqlite3_finalize(statement);

      updateLODsForRemove(name, lod);
    }

    void
    AssetLocatorSQLLiteDatabase::update(std::string name, int lod, std::string location)
    {
      sqlite3_stmt* statement; 
      sqlite3_prepare_v2(database, stmt_update.c_str(), -1, &statement, 0);
      sqlite3_bind_text(statement, 1, location.c_str(), location.size(), SQLITE_STATIC);
      sqlite3_bind_text(statement, 2, name.c_str(), name.size(), SQLITE_STATIC);
      sqlite3_bind_int(statement, 3, lod);

      int result = sqlite3_step(statement);

      if (result != SQLITE_DONE)
	std::cerr << "Error updating database" << std::endl;

      sqlite3_finalize(statement);
    }

    void
    AssetLocatorSQLLiteDatabase::open(std::string filename)
    {
      sqlite3_open(filename.c_str(), &database);
      
      sqlite3_stmt* statement; 
      sqlite3_prepare_v2(database, stmt_create.c_str(), -1, &statement, 0);

      int result = sqlite3_step(statement);

      if (result != SQLITE_DONE)
	std::cerr << "Error opening database" << std::endl;

      sqlite3_finalize(statement);
    }

    int
    AssetLocatorSQLLiteDatabase::getMaxLOD(std::string assetName)
    {
      int LOD = -1;
      sqlite3_stmt* statement; 

      if(sqlite3_prepare_v2(database, stmt_select_max_lod.c_str(), -1, &statement, 0) == SQLITE_OK)
      {
          sqlite3_bind_text(statement, 1, assetName.c_str(), assetName.size(), SQLITE_STATIC);
	  int cols = sqlite3_column_count(statement);
	  int result = sqlite3_step(statement);
             
          if(result == SQLITE_ROW)
          {
            LOD = sqlite3_column_int(statement, cols-1);
          }
        
        sqlite3_finalize(statement);
      }
 
      return LOD;
    }

    void
    AssetLocatorSQLLiteDatabase::updateLODsForInsert(std::string name, int & lod)
    {
      int maxLOD = getMaxLOD(name);
      
      std::cerr << "THIS is maxLOD " << maxLOD << std::endl;

      //the asset does not exist in the db
      //adding the highest LOD val into the database
      if(lod > maxLOD)
	lod = maxLOD + 1;

      //inserting into the front or middle
      else 
      {
	//increment all LOD vals larger than the lod 
	sqlite3_stmt* statement; 

	if(sqlite3_prepare_v2(database, stmt_incr_LOD_on_insert.c_str(), -1, &statement, 0) == SQLITE_OK)
	{
	  sqlite3_bind_text(statement, 1, name.c_str(), name.size(), SQLITE_STATIC);
	  sqlite3_bind_int(statement, 2, lod);

	  int result = sqlite3_step(statement);
             
          if(result != SQLITE_DONE)
          {
	    std::cerr << "Error incrementing LOD values" << std::endl;
          }
        
	  sqlite3_finalize(statement);
	}
      }
    }

    void
    AssetLocatorSQLLiteDatabase::updateLODsForRemove(std::string name, int lod)
    {
      int maxLOD = getMaxLOD(name);

      if (!(maxLOD == -1 || lod > maxLOD))
      {
  	//increment all LOD vals larger than the lod 
	sqlite3_stmt* statement; 

	if(sqlite3_prepare_v2(database, stmt_decr_LOD_on_remove.c_str(), -1, &statement, 0) == SQLITE_OK)
	{
	  sqlite3_bind_text(statement, 1, name.c_str(), name.size(), SQLITE_STATIC);
	  sqlite3_bind_int(statement, 2, lod);

	  int result = sqlite3_step(statement);
             
          if(result != SQLITE_DONE)
          {
	    std::cerr << "Error decrementing LOD values" << std::endl;
          }
        
	  sqlite3_finalize(statement);
	}
      }
    }
}

   
