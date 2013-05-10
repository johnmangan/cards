namespace cards {

#ifndef ASSET_TAG_H_
#define ASSET_TAG_H_

#include <string>

class AssetTag
{
public:
    virtual
    AssetTag(std::string name) = 0;
}

#endif /*ASSET_TAG_H_*/

}

