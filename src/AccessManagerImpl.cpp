#include <AccessManagerImpl.h>

namespace cards {

/*virtual*/ AssetLocator *
AccessManagerImpl::getAssetLocator( void )
{
    return NULL;
}

/*virtual*/ AssetMetadataMapping *
AccessManagerImpl::getAssetMetadataMapping( void )
{
    return NULL;
}

/*virtual*/ RankedSearch *
AccessManagerImpl::getRankedSearch( void )
{
    return NULL;
}

}

