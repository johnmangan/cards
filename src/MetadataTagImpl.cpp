#include <MetadataTagImpl.h>

namespace cards {

MetadataTagImpl::MetadataTagImpl( std::string name )
{
    mName = name;
}

/*virtual*/ std::string
MetadataTagImpl::getName( void ) const
{
    return mName;
}

/*virtual*/ bool
MetadataTagImpl::lessThan( MetadataTag const& r ) const
{
    return mName.compare( r.getName() ) < 0;
}

}

