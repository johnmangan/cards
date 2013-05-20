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
    removeAsset( AssetTag assetTag ) = 0;

    // Location Management
    virtual void
    addLevelOfDetailLocation( AssetTag assetTag, unsigned int lod, std::string location ) = 0;

    virtual void
    removeLevelOfDetailLocation( AssetTag assetTag, unsigned int lod ) = 0;

    virtual void
    updateLevelOfDetailLocation( AssetTag assetTag, unsigned int lod, std::string location ) = 0;
}

#endif /*ASSET_LOCATOR_H_*/

}

