namespace cards {

#ifndef ASSET_METADATA_MAPPING_H_
#define ASSET_METADATA_MAPPING_H_

#include <set>

#include "AssetTag.h"
#include "MetadataTag.h"

class AssetMetadataMapping
{
public:
    virtual std::set< AssetTag >
    getAssets( MetadataTag metadataTag ) = 0;

    virtual void
    augmentAsset( AssetTag assetTag, MetadataTag metadataTag ) = 0;

    virtual void
    unaugmentAsset( AssetTag assetTag, MetadataTag metadataTag ) = 0;
}

#endif /*ASSET_METADATA_MAPPING_H_*/

}

