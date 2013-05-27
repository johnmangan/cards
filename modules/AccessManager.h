#ifndef ACCESS_MANAGER_H_
#define ACCESS_MANAGER_H_

#include "AssetLocator.h"
#include "AssetMetadataMapping.h"
#include "RankedSearch.h"

namespace cards {

class AccessManager
{
public:
    virtual AssetLocator *
    getAssetLocator( void ) = 0;

    virtual AssetMetadataMapping *
    getAssetMetadataMapping( void ) = 0;

    virtual RankedSearch *
    getRankedSearch( void ) = 0;
};

}

#endif /*ACCESS_MANAGER_H_*/

