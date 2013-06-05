#include <AssetMetadataMappingDatabaseImpl.h>

#include <algorithm>

namespace cards {

AssetMetadataMappingDatabaseImpl::AssetMetadataMappingDatabaseImpl()
{
  database = new AssetMetadataMappingDatabase("AssetMetadataMapping.db");
}

AssetMetadataMapping::AssetSet
AssetMetadataMappingDatabaseImpl::describedAssets( MetadataSet metadataTags )
{
  return database->getDescribedAssets(MetadataSet metadataTags);
}

void
AssetMetadataMappingDatabaseImpl::augmentAsset( AssetTag* assetTag, MetadataTag* metadataTag )
{
  database->addMetadataToAsset(assetTage->getName(), metadataTag->getName());
}

/*virtual*/ void
AssetMetadataMappingDatabaseImpl::unaugmentAsset( AssetTag* assetTag, MetadataTag* metadataTag )
{
  database->removeMedataFromAsset(assetTag->getName(), metadataTag->getName());
}

/*virtual*/ void
AssetMetadataMappingDatabaseImpl::removeAsset( AssetTag* assetTag )
{
  database->removeAsset(assetTag->getName());
}

}


