#include <AccessManagerImpl.h>

#include <AssetLocator.h>
#include <AssetMetadataMapping.h>
#include <RankedSearch.h>

// Following 3 included headers allow default ctor to create default members
#include <AssetLocatorMemoryImpl.h>
#include <AssetMetadataMappingMemoryImpl.h>
#include <RankedSearchImpl.h>

namespace cards {

AccessManagerImpl::AccessManagerImpl()
{
    mAssetLocator = new AssetLocatorMemoryImpl;
    mAssetMetadataMapping = new AssetMetadataMappingMemoryImpl;
    mRankedSearch = new RankedSearchImpl;
}

AccessManagerImpl::AccessManagerImpl(AssetLocator* assetLocator, AssetMetadataMapping* assetMetadataMapping, RankedSearch* rankedSearch)
: mAssetLocator( assetLocator ), mAssetMetadataMapping( assetMetadataMapping ), mRankedSearch (rankedSearch )
{
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
    // TODO: fix hack on next line - so ugly!
    mRankedSearch->setAccessManager( this );
    return mRankedSearch;
}

}

