namespace cards {

#ifndef ACCESS_MANAGER_H_
#define ACCESS_MANAGER_H_

#include "AssetLocator.h"
#include "AssetMetadataMapping.h"
#include "RankedSearch.h"

class AccessManager
{
public:
    virtual AssetLocator *
    AssetLocator( void ) = 0;

    virtual AssetMetadataMapping *
    AssetMetadataMapping( void ) = 0;

    virtual RankedSearch *
    RankedSearch( void ) = 0;
}

#endif /*ACCESS_MANAGER_H_*/

}

