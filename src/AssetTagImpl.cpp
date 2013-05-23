#include <AssetTagImpl.h>

namespace cards {

AssetTagImpl::AssetTagImpl( std::string name )
{
    mName = name;
}

/*virtual*/ std::string
AssetTagImpl::getName( void ) const
{
    return mName;
}

/*virtual*/ bool
AssetTagImpl::lessThan( AssetTag const& r ) const
{
    return mName.compare( r.getName() ) < 0;
}

}

