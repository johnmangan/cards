namespace cards {

#ifndef ASSET_LOCATOR_H_
#define ASSET_LOCATOR_H_

#include <vector>
#include <string>

#include "AssetTag.h"

class AssetLocator
{
public:

    // Query Functionality
    virtual std::vector< std::string >
    getFilepath(AssetTag assetTag) = 0;

    // Asset Management
    virtual void
    addAsset( AssetTag assetTag ) = 0;

    virtual void
    removeAsset( AssetTag assetTag ) = 0;

    // Location Management
    virtual void
    addLevelOfDetailLocation( AssetTag assetTag, int lod, std::string location );

    virtual void
    removeLevelOfDetailLocation( AssetTag assetTag, int lod );

    virtual void
    updateLevelOfDetailLocation( AssetTag assetTag, int lod, std::string location );
}

#endif /*ASSET_LOCATOR_H_*/

}

