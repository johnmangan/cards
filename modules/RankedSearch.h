namespace cards {

#ifndef RANKED_SEARCH_H_
#define RANKED_SEARCH_H_

#include <map>

#include "AssetTag.h"
#include "MetadataTag.h"

class RankedSearch
{
public:
    virtual std::map< AssetTag, int >
    searchAndRankAssets( std::map< MetadataTag, int > metadataWeights ) = 0;
}

#endif /*RANKED_SEARCH_H_*/

}

