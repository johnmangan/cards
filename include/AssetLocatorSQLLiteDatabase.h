#ifndef ASSET_LOCATOR_SQLLITE_DATABASE_H_
#define ASSET_LOCATOR_SQLLITE_DATABASE_H_

#include "AssetLocatorDatabase.h"

#include <sqlite3.h>

namespace cards
{
  class AssetLocatorSQLLiteDatabase : public AssetLocatorDatabase
  {
  public:
    AssetLocatorSQLLiteDatabase();
    AssetLocatorSQLLiteDatabase(std::string filename);
    virtual ~AssetLocatorSQLLiteDatabase() {}

    virtual void 
    insert(std::string name, int lod, std::string location);

    virtual std::vector<std::string>
    query(std::string name);

    virtual void 
    remove(std::string name);

    virtual void
    remove(std::string name, int lod);

    virtual void
    update(std::string name, int lod, std::string location);

  protected:
    virtual void
    open(std::string filename);

  private:
    sqlite3* database;
  };
}

#endif
