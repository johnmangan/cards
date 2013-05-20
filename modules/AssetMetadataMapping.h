#ifndef ASSET_METADATA_MAPPING_H_
#define ASSET_METADATA_MAPPING_H_

#include <set>

#include "AssetTag.h"
#include "MetadataTag.h"

namespace cards {

class AssetMetadataMapping
{
public:
    virtual std::set< AssetTag >
    describedAssets( std::set< MetadataTag > metadataTags ) = 0;

    virtual void
    augmentAsset( AssetTag assetTag, MetadataTag metadataTag ) = 0;

    virtual void
    unaugmentAsset( AssetTag assetTag, MetadataTag metadataTag ) = 0;
};

}

#endif /*ASSET_METADATA_MAPPING_H_*/

