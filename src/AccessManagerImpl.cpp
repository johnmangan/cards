#include <AccessManagerImpl.h>

#include <AssetLocator.h>
#include <AssetMetadataMapping.h>
#include <RankedSearch.h>

namespace cards {

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

