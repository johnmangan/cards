namespace cards {

#ifndef ASSETS_H_
#define ASSETS_H_

#include <string>

#include "AssetTag.h"

class Assets
{
public:

    virtual std::string
    getAssetFilepath(AssetTag assetTag) = 0;

    virtual void
    addAsset( AssetTag assetTag, std::string filepath ) = 0;

    virtual void
    removeAsset( AssetTag assetTag ) = 0;

    virtual void
    updateFilepath( AssetTag assetTag, std::string filepath ) = 0;
}

#endif /*ASSETS_H_*/

}

