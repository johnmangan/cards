#include "AssetMetadataMappingDatabaseImpl.h"
#include "AssetMetadataMappingSQLLiteDatabase.h"

#include <algorithm>

namespace cards {

AssetMetadataMappingDatabaseImpl::AssetMetadataMappingDatabaseImpl()
{
  database = new AssetMetadataMappingSQLLiteDatabase("AssetMetadataMapping.db");
}

AssetMetadataMapping::AssetSet
AssetMetadataMappingDatabaseImpl::describedAssets(AssetMetadataMapping::MetadataSet metadataTags )
{
  return database->getDescribedAssets(metadataTags);
}

void
AssetMetadataMappingDatabaseImpl::augmentAsset( AssetTag* assetTag, MetadataTag* metadataTag )
{
  database->addMetadataToAsset(assetTag->getName(), metadataTag->getName());
}

/*virtual*/ void
AssetMetadataMappingDatabaseImpl::unaugmentAsset( AssetTag* assetTag, MetadataTag* metadataTag )
{
  database->removeMetadataFromAsset(assetTag->getName(), metadataTag->getName());
}

/*virtual*/ void
AssetMetadataMappingDatabaseImpl::removeAsset( AssetTag* assetTag )
{
  database->removeAsset(assetTag->getName());
}

}


