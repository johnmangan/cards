#ifndef ASSET_METADATA_MAPPING_DATABASE_IMPL_H_
#define ASSET_METADATA_MAPPING_DATABASE_IMPL_H_

#include "AssetMetadataMapping.h"
#include "AssetMetadataMappingDatabase.h"

namespace cards {

class AssetMetadataMappingDatabaseImpl : public AssetMetadataMapping
{
public:
    AssetMetadataMappingDatabaseImpl();

    virtual AssetSet
    describedAssets( MetadataSet metadataTags );

    virtual void
    augmentAsset( AssetTag* assetTag, MetadataTag* metadataTag );

    virtual void
    unaugmentAsset( AssetTag* assetTag, MetadataTag* metadataTag );

    virtual void
    removeAsset( AssetTag* assetTag );

private:
    AssetMetadataMappingDatabase* database; 
};

}

#endif /*ASSET_METADATA_MAPPING_DATABASE_IMPL_H_*/


