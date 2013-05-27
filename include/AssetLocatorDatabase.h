#ifndef ASSET_LOCATOR_DATABASE_H_
#define ASSET_LOCATOR_DATABASE_H_

#include <string>
#include <vector>

namespace cards
{
  class AssetLocatorDatabase 
  {
  public:
    virtual void 
    insert(std::string name, int lod, std::string location) = 0;

    virtual std::vector<std::string>
    query(std::string name) = 0;

    virtual void 
    remove(std::string name) = 0;

    virtual void
    remove(std::string name, int lod) = 0;

    virtual void
    update(std::string name, int lod, std::string location) = 0;

  protected:
    virtual void open(std::string databaseName) = 0;
  };
}

#endif
