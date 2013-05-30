#ifndef ACCESS_MANAGER_IMPL_H_
#define ACCESS_MANAGER_IMPL_H_

#include <AccessManager.h>

namespace cards {

class AccessManagerImpl : public AccessManager
{
public:
    AccessManagerImpl();

    virtual AssetLocator*
    getAssetLocator( void ) const;

    virtual AssetMetadataMapping*
    getAssetMetadataMapping( void ) const;

    virtual RankedSearch*
    getRankedSearch( void ) const;

private:
    AssetLocator* mAssetLocator;
    AssetMetadataMapping* mAssetMetadataMapping;
    RankedSearch* mRankedSearch;
};

}

#endif /*ACCESS_MANAGER_IMPL_H_*/

