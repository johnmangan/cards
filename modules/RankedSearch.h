#ifndef RANKED_SEARCH_H_
#define RANKED_SEARCH_H_

#include <map>

#include "AssetTag.h"
#include "MetadataTag.h"

namespace cards {

class RankedSearch
{
public:
    virtual AssetTag
    topRankedAsset( std::map< MetadataTag, int > metadataWeights ) = 0;
};

}

#endif /*RANKED_SEARCH_H_*/

