#include <RankedSearchImpl.h>

#include <algorithm>
#include <stdlib.h>
#include <time.h>

namespace cards {

RankedSearchImpl::RankedSearchImpl( AccessManager* accessManager )
: mAccessManager( accessManager )
{
    srand( time(NULL) );
}

/*virtual*/ AssetTag*
RankedSearchImpl::topRankedAsset( MetadataWeights metadataWeights, double percent )
{
    std::map< AssetTag*, int, AssetTag::AssetTagComparator > assetValues;

    // Get assets and assign then weighted values
    for (MetadataWeights::iterator mit = metadataWeights.begin();
        metadataWeights.end() != mit;
        ++mit)
    {
        AssetMetadataMapping::MetadataSet metaSet;
        metaSet.insert( mit->first );

        AssetMetadataMapping::AssetSet assetSet = mAccessManager->getAssetMetadataMapping()->describedAssets(metaSet);

        for (AssetMetadataMapping::AssetSet::iterator ait = assetSet.begin();
            assetSet.end() != ait;
            ++ait)
        {
            assetValues[ *ait ] += mit->second;
        }
    }

    // If we have an empty map, return NULL
    if (metadataWeights.empty())
        return NULL;

    // Created a vector of assets sorted by decreasing value
    std::vector< AssetValue > rankedAssets;

    for (std::map< AssetTag*, int, AssetTag::AssetTagComparator >::iterator it = assetValues.begin();
        assetValues.end() != it;
        ++it)
    {
        AssetValue assetValue;
        assetValue.assetTag = it->first;
        assetValue.value = it->second;
        rankedAssets.push_back(assetValue);
    }

    std::sort( rankedAssets.begin(), rankedAssets.end(), mAssetValueComparator );

    // return top percent at random
    unsigned int choice_set_size = rankedAssets.size() * (1.0 - percent);
    if (choice_set_size < 0)
        choice_set_size = 1;
    if (choice_set_size > rankedAssets.size())
        choice_set_size = rankedAssets.size();

    // don't cut off options of equal value as other included assets
    while (choice_set_size < rankedAssets.size() )
    {
        if (rankedAssets[ choice_set_size - 1 ].value != rankedAssets[ choice_set_size ].value)
            break;
        ++choice_set_size;
    }

    int choice = rand() % choice_set_size;

    return rankedAssets[ choice ].assetTag;
}

}

