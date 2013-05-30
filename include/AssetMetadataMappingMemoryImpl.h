#ifndef ASSET_METADATA_MAPPING_MEMORY_IMPL_H_
#define ASSET_METADATA_MAPPING_MEMORY_IMPL_H_

#include <AssetMetadataMapping.h>

#include <map>

namespace cards {

class AssetMetadataMappingMemoryImpl : public AssetMetadataMapping
{
public:

    virtual AssetSet
    describedAssets( MetadataSet metadataTags );

    virtual void
    augmentAsset( AssetTag* assetTag, MetadataTag* metadataTag );

    virtual void
    unaugmentAsset( AssetTag* assetTag, MetadataTag* metadataTag );

    virtual void
    removeAsset( AssetTag* assetTag );

private:
    typedef std::map< MetadataTag*, AssetSet > MetaAssetSetMap;

    MetaAssetSetMap mMetaAssetMap;
};

}

#endif /*ASSET_METADATA_MAPPING_MEMORY_IMPL_H_*/

