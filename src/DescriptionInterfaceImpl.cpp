#include <DescriptionInterfaceImpl.h>

// Factories can get rid of these includes:
#include <AssetTagImpl.h>
#include <MetadataTagImpl.h>
#include <AccessManagerImpl.h>

namespace cards {

IDescriptionImpl::IDescriptionImpl()
{
    mAccessManager = new AccessManagerImpl;
}

IDescriptionImpl::IDescriptionImpl( AccessManager* accessManager )
: mAccessManager( accessManager )
{
}

/*virtual*/ void
IDescriptionImpl::removeAsset( std::string assetName )
{
    AssetTag* assetTag = new AssetTagImpl( assetName );

    mAccessManager->getAssetLocator()->removeAsset( assetTag );
    mAccessManager->getAssetMetadataMapping()->removeAsset( assetTag );
}

/*virtual*/ void
IDescriptionImpl::addLevelOfDetail( std::string assetName, unsigned int lod, std::string location )
{
    AssetTag* assetTag = new AssetTagImpl( assetName );

    mAccessManager->getAssetLocator()->addLevelOfDetailLocation( assetTag, lod, location );
}

/*virtual*/ void
IDescriptionImpl::removeLevelOfDetail( std::string assetName, unsigned int lod )
{
    AssetTag* assetTag = new AssetTagImpl( assetName );

    mAccessManager->getAssetLocator()->removeLevelOfDetailLocation( assetTag, lod );
}

/*virtual*/ void
IDescriptionImpl::updateLevelOfDetail( std::string assetName, unsigned int lod, std::string location )
{
    AssetTag* assetTag = new AssetTagImpl( assetName );

    mAccessManager->getAssetLocator()->updateLevelOfDetailLocation( assetTag, lod, location );
}

/*virtual*/ std::vector< std::string >
IDescriptionImpl::viewLevelsOfDetail( std::string assetName )
{
    AssetTag* assetTag = new AssetTagImpl( assetName );

    return mAccessManager->getAssetLocator()->getFilepath( assetTag );
}

/*virtual*/ void
IDescriptionImpl::augmentAsset( std::string assetName, std::string metadataName )
{
    AssetTag* assetTag = new AssetTagImpl( assetName );
    MetadataTag* metadataTag = new MetadataTagImpl( metadataName );

    mAccessManager->getAssetMetadataMapping()->augmentAsset( assetTag, metadataTag );
}

/*virtual*/ void
IDescriptionImpl::unaugmentAsset( std::string assetName, std::string metadataName )
{
    AssetTag* assetTag = new AssetTagImpl( assetName );
    MetadataTag* metadataTag = new MetadataTagImpl( metadataName );

    mAccessManager->getAssetMetadataMapping()->unaugmentAsset( assetTag, metadataTag );
}

}

