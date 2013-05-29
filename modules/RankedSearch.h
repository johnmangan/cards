#ifndef RANKED_SEARCH_H_
#define RANKED_SEARCH_H_

#include <map>

#include <AssetTag.h>
#include <MetadataTag.h>

namespace cards {

class RankedSearch
{
public:
    typedef std::map< MetadataTag*, int, MetadataTag::MetadataTagComparator > MetadataWeights;

    virtual AssetTag*
    topRankedAsset( MetadataWeights metadataWeights, double percent ) = 0;
};

}

#endif /*RANKED_SEARCH_H_*/

