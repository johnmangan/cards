#ifndef ASSET_TAG_IMPL_H_
#define ASSET_TAG_IMPL_H_

#include <AssetTag.h>

namespace cards {

class AssetTagImpl : public AssetTag
{
public:
    AssetTagImpl( std::string name );

    virtual std::string
    getName( void ) const;

    virtual bool
    lessThan( AssetTag const& r ) const;

private:
    std::string mName;
};

}

#endif /*ASSET_TAG_IMPL_H_*/

