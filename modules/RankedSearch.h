#ifndef RANKED_SEARCH_H_
#define RANKED_SEARCH_H_

#include <map>

#include <AccessManager.h>
#include <AssetTag.h>
#include <MetadataTag.h>

namespace cards {

// Forward Declaration
class AccessManager;

class RankedSearch
{
public:
    typedef std::map< MetadataTag*, int, MetadataTag::MetadataTagComparator > MetadataWeights;

    virtual void
    setAccessManager( AccessManager const* accessManager ) = 0;

    virtual AssetTag*
    topRankedAsset( MetadataWeights metadataWeights, double percent = 1.0 ) = 0;
};

}

#endif /*RANKED_SEARCH_H_*/

