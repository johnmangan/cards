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
    getAssetLocator( void ) const = 0;

    virtual AssetMetadataMapping *
    getAssetMetadataMapping( void ) const = 0;

    virtual RankedSearch *
    getRankedSearch( void ) const = 0;
};

}

#endif /*ACCESS_MANAGER_H_*/

