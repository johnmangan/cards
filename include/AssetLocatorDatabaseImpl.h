#ifndef ASSET_LOCATOR_DATABASE_IMPL_H_
#define ASSET_LOCATOR_DATABASE_IMPL_H_

#include <map>
#include <string>
#include <vector>

#include "AssetTag.h"
#include "AssetLocator.h"
#include "AssetLocatorDatabase.h"

namespace cards {

class AssetLocatorDatabaseImpl : public AssetLocator
{
public:
    //Constructor & Destructor
    AssetLocatorDatabaseImpl();
    virtual ~AssetLocatorDatabaseImpl();

    // Query Functionality
    virtual Locations
    getFilepath( AssetTag* assetTag ) const;

    // Asset Management
    virtual void
    removeAsset( AssetTag* assetTag );

    // Location Management
    virtual void
    addLevelOfDetailLocation( AssetTag* assetTag, unsigned int lod, std::string location );

    virtual void
    removeLevelOfDetailLocation( AssetTag* assetTag, unsigned int lod );

    virtual void
    updateLevelOfDetailLocation( AssetTag* assetTag, unsigned int lod, std::string location );

protected:
    AssetLocatorDatabase* database;
};

}


#endif /* ASSET_LOCATOR_DATABASE_IMPL_H_ */
