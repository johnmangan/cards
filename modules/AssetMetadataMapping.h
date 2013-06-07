#ifndef ASSET_METADATA_MAPPING_H_
#define ASSET_METADATA_MAPPING_H_

#include <set>

#include <AssetTag.h>
#include <MetadataTag.h>

namespace cards {

class AssetMetadataMapping
{
public:
    class AssetSet : public std::set< AssetTag*, AssetTag::AssetTagComparator>
    {
        friend bool operator== ( AssetSet const& l, AssetSet const& r )
        {
            if (l.size() != r.size())
                return false;

            AssetTag::AssetTagComparator compare;
            for (AssetSet::iterator li = l.begin(), ri = r.begin();
                l.end() != li;
                ++li, ++ri)
            {
                if (compare(*li,*ri) || compare(*ri,*li))
                    return false;
            }

            return true;
        }
    };

    class MetadataSet : public std::set< MetadataTag*, MetadataTag::MetadataTagComparator>
    {
        friend bool operator== ( MetadataSet const& l, MetadataSet const& r )
        {
            if (l.size() != r.size())
                return false;

            MetadataTag::MetadataTagComparator compare;
            for (MetadataSet::iterator li = l.begin(), ri = r.begin();
                l.end() != li;
                ++li, ++ri)
            {
                if (compare(*li,*ri) || compare(*ri,*li))
                    return false;
            }

            return true;
        }
    };

    virtual AssetSet
    describedAssets( MetadataSet metadataTags ) = 0;

    virtual void
    augmentAsset( AssetTag* assetTag, MetadataTag* metadataTag ) = 0;

    virtual void
    unaugmentAsset( AssetTag* assetTag, MetadataTag* metadataTag ) = 0;

    virtual void
    removeAsset( AssetTag* assetTag ) = 0;
};

}

#endif /*ASSET_METADATA_MAPPING_H_*/

