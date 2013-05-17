namespace cards {

#ifndef ASSET_TAG_H_
#define ASSET_TAG_H_

#include <string>

class AssetTag
{
public:
    virtual AssetTag
    createAssetTag(std::string name) = 0;

private:
    AssetTag();
}

#endif /*ASSET_TAG_H_*/

}

