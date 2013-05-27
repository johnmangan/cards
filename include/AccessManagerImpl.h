#ifndef ACCESS_MANAGER_IMPL_H_
#define ACCESS_MANAGER_IMPL_H_

#include <AccessManager.h>

namespace cards {

class AccessManagerImpl
{
public:
    virtual AssetLocator *
    getAssetLocator( void );

    virtual AssetMetadataMapping *
    getAssetMetadataMapping( void );

    virtual RankedSearch *
    getRankedSearch( void );
};

}

#endif /*ACCESS_MANAGER_IMPL_H_*/

