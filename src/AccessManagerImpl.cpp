#include <AccessManagerImpl.h>

#include <AssetLocatorMemoryImpl.h>
#include <AssetMetadataMappingMemoryImpl.h>
#include <RankedSearchImpl.h>

namespace cards {

AccessManagerImpl::AccessManagerImpl()
{
    mAssetLocator = new AssetLocatorMemoryImpl();
    mAssetMetadataMapping = new AssetMetadataMappingMemoryImpl();
    mRankedSearch = new RankedSearchImpl(this);
}

/*virtual*/ AssetLocator *
AccessManagerImpl::getAssetLocator( void ) const
{
    return mAssetLocator;
}

/*virtual*/ AssetMetadataMapping *
AccessManagerImpl::getAssetMetadataMapping( void ) const
{
    return mAssetMetadataMapping;
}

/*virtual*/ RankedSearch *
AccessManagerImpl::getRankedSearch( void ) const
{
    return mRankedSearch;
}

}

