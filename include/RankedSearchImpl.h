#ifndef RANKED_SEARCH_IMPL_H_
#define RANKED_SEARCH_IMPL_H_

#include <RankedSearch.h>
#include <AccessManager.h>

namespace cards {

class RankedSearchImpl : public RankedSearch
{
public:
    RankedSearchImpl( AccessManager* accessManager );

    virtual AssetTag*
    topRankedAsset( MetadataWeights metadataWeights, double percent );

private:
    AccessManager* mAccessManager;

    struct AssetValue
    {
        AssetTag* assetTag;
        int value;
    };

    struct AssetValueComparator
    {
        bool operator() (AssetValue const& l, AssetValue const& r) const
        {
            // If values are the same, we don't really care, but need some consistency
            if (l.value == r.value)
                return l.assetTag < r.assetTag;

            // Values are different, so it's actually worth sorting.
            return l.value > r.value;
        }
    } mAssetValueComparator;
};

}

#endif /*RANKED_SEARCH_IMPL_H_*/
