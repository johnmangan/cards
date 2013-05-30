#include <AssetMetadataMappingMemoryImpl.h>

#include <algorithm>

namespace cards {

/*virtual*/ AssetSet
AssetMetadataMappingMemoryImpl::describedAssets( MetadataSet metadataTags )
{
    AssetSet current_assets;

    for (MetadataSet::iterator it = metadataTags.begin();
        metadataTags.end() != it;
        ++it)
    {
        AssetSet new_assets;

        MetaAssetSetMap::iterator masm_it = mMetaAssetMap.find( *it );

        // If we ever read an unaccounted for MetadataTag, return empty set
        if (masm_it == mMetaAssetMap.end())
            return new_assets; // new_assets is empty here

        // First tag is added no matter what
        if (metadataTags.begin() == it)
        {
            current_assets.insert( masm_it->second.begin(), masm_it->second.end() );
        }
        else // all but the first tag only keep intersecting assets
        {
            AssetSet intersection;

            std::set_intersection (current_assets.begin(), current_assets.end(),
                masm_it->second.begin(), masm_it->second.end(), intersection.begin());

            assets = intersection;
        }

        // If we ever end up with 0 assets to intersect with, get out
        if (current_assets.empty())
            break;
    }

    return current_assets;
}

/*virtual*/ void
AssetMetadataMappingMemoryImpl::augmentAsset( AssetTag* assetTag, MetadataTag* metadataTag )
{
    mMetaAssetMap[ metadataTag ].insert( assetTag );
}

/*virtual*/ void
AssetMetadataMappingMemoryImpl::unaugmentAsset( AssetTag* assetTag, MetadataTag* metadataTag )
{
    mMetaAssetMap[ metadataTag ].erase( assetTag );
}

/*virtual*/ void
AssetMetadataMappingMemoryImpl::removeAsset( AssetTag* assetTag )
{
    for (MetaAssetSetMap::iterator it = mMetaAssetMap.begin();
        mMetaAssetMap.end() != it;
        ++it)
    {
        it->second.erase( assetTag );
    }
}

}

