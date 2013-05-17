namespace cards {

#ifndef ASSET_LOCATOR_H_
#define ASSET_LOCATOR_H_

#include <string>

#include "AssetTag.h"

class AssetLocator
{
public:

    virtual std::string
    getFilepath(AssetTag assetTag) = 0;

    virtual void
    addAsset( AssetTag assetTag, std::string location ) = 0;

    virtual void
    removeAsset( AssetTag assetTag ) = 0;

    virtual void
    updateLocation( AssetTag assetTag, std::string location ) = 0;
}

#endif /*ASSET_LOCATOR_H_*/

}

