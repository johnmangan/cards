#include "AssetMetadataMappingSQLLiteDatabase.h"
#include "AssetMetadataMappingSQLLiteDatabasePrepStmts.h"
#include "AssetTagImpl.h"

#include <iostream>
#include <sstream>
#include <vector>

namespace cards
{
    AssetMetadataMappingSQLLiteDatabase::AssetMetadataMappingSQLLiteDatabase ()
    {
      database = NULL;
    }
   
    AssetMetadataMappingSQLLiteDatabase::AssetMetadataMappingSQLLiteDatabase (std::string filename)
    {
      database = NULL;
      open(filename);
    }

    void 
    AssetMetadataMappingSQLLiteDatabase::addMetadataToAsset(std::string assetName, std::string metadataTagName)
    {
      sqlite3_stmt* statement;
      
      int metaID = getMetaID( metadataTagName );

      if (-1 == metaID)
      {
          sqlite3_prepare_v2(database, stmt_insert_mtable.c_str(), -1, &statement, 0);
          sqlite3_bind_text(statement, 1, metadataTagName.c_str(), metadataTagName.size(), SQLITE_STATIC);

          int result = sqlite3_step(statement);

          if (result != SQLITE_DONE)
            std::cerr << "Error inserting Metadata into database" << std::endl;
      }

      metaID = getMetaID(metadataTagName);

      sqlite3_prepare_v2(database, stmt_insert_atable.c_str(), -1, &statement, 0);
      sqlite3_bind_int(statement, 1, metaID);
      sqlite3_bind_text(statement, 2, assetName.c_str(), assetName.size(), SQLITE_STATIC);

      int result = sqlite3_step(statement);

      if (result != SQLITE_DONE)
	std::cerr << "Error inserting Asset into  database" << std::endl;

      sqlite3_finalize(statement);
    }

    AssetMetadataMapping::AssetSet
    AssetMetadataMappingSQLLiteDatabase::getDescribedAssets(AssetMetadataMapping::MetadataSet metadataTags)
    {
      AssetMetadataMapping::AssetSet results;
      std::stringstream queryStream;
      std::vector<int> metaIDs;

      for (AssetMetadataMapping::MetadataSet::iterator metaIter = metadataTags.begin(); metaIter != metadataTags.end(); ++metaIter)
      {
	metaIDs.push_back(getMetaID((*metaIter)->getName()));	
      }

      for (std::vector<int>::iterator idIter = metaIDs.begin(); idIter != metaIDs.end(); idIter++)
      {
	queryStream << "SELECT Name FROM Assets WHERE metaID = " << (*idIter);

	if (idIter != metaIDs.end()-1)
	{
	  queryStream << " INTERSECT ";
	}
      }

      queryStream << ";";

      sqlite3_stmt* statement;
    
      if(sqlite3_prepare_v2(database, queryStream.str().c_str(), -1, &statement, 0) == SQLITE_OK)
      {
        int cols = sqlite3_column_count(statement);
        int result = 0;

        while(true)
        {
            result = sqlite3_step(statement);
             
            if(result == SQLITE_ROW)
            {
	      std::string assetName = (char*)sqlite3_column_text(statement, 0);
              results.insert(new AssetTagImpl(assetName));
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
    AssetMetadataMappingSQLLiteDatabase::removeAsset(std::string assetName)
    {
      sqlite3_stmt* statement; 
      sqlite3_prepare_v2(database, stmt_delete_asset.c_str(), -1, &statement, 0);
      sqlite3_bind_text(statement, 1, assetName.c_str(), assetName.size(), SQLITE_STATIC);

      int result = sqlite3_step(statement);

      if (result != SQLITE_DONE)
	std::cerr << "Error removing asset from database" << std::endl;

      sqlite3_finalize(statement);
    }

    void 
    AssetMetadataMappingSQLLiteDatabase::removeMetadataFromAsset(std::string assetName, std::string metadataTagName)
    {
      sqlite3_stmt* statement;
      int metaID = getMetaID(metadataTagName);

      sqlite3_prepare_v2(database, stmt_delete_metadata_atable.c_str(), -1, &statement, 0);
      sqlite3_bind_int(statement, 1, metaID);
      sqlite3_bind_text(statement, 2, assetName.c_str(), assetName.size(), SQLITE_STATIC);

      int result = sqlite3_step(statement);

      if (result != SQLITE_DONE)
	std::cerr << "Error remove metadata from asset database" << std::endl;

      sqlite3_finalize(statement);
    }

    void
    AssetMetadataMappingSQLLiteDatabase::open(std::string filename)
    {
      sqlite3_open(filename.c_str(), &database);
      
      sqlite3_stmt* statement; 
      sqlite3_prepare_v2(database, stmt_create_metadata_table.c_str(), -1, &statement, 0);

      int result = sqlite3_step(statement);

      if (result != SQLITE_DONE)
	std::cerr << "Error creating Metadata table" << std::endl;

      sqlite3_finalize(statement);

      sqlite3_prepare_v2(database, stmt_create_asset_table.c_str(), -1, &statement, 0);

      result = sqlite3_step(statement);

      if (result != SQLITE_DONE)
	std::cerr << "Error creating Asset table" << std::endl;

      sqlite3_finalize(statement);

    }

    int AssetMetadataMappingSQLLiteDatabase::getMetaID(std::string metadataTagName)
    {
      int metaID = -1;
      sqlite3_stmt* statement; 

      if(sqlite3_prepare_v2(database, stmt_select_metaID.c_str(), -1, &statement, 0) == SQLITE_OK)
      {
	  sqlite3_bind_text(statement, 1, metadataTagName.c_str(), metadataTagName.size(), SQLITE_STATIC);

	  int cols = sqlite3_column_count(statement);
	  int result = sqlite3_step(statement);
             
          if(result == SQLITE_ROW)
          {
            metaID = sqlite3_column_int(statement, cols-1);
          }
        
        sqlite3_finalize(statement);
      }
 
      return metaID;
    }
}
