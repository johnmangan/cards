#include <AssetLocatorMemoryImpl.h>

namespace cards {

/*virtual*/ AssetLocatorMemoryImpl::Locations
AssetLocatorMemoryImpl::getFilepath( AssetTag* pAssetTag ) const
{
    LocationsOfAsset::const_iterator it = mAssetLocations.find( pAssetTag );

    if (mAssetLocations.end() != it)
        return it->second;
    return Locations();
}

// Asset Management
/*virtual*/ void
AssetLocatorMemoryImpl::removeAsset( AssetTag* pAssetTag )
{
    mAssetLocations.erase( pAssetTag );
}

// Location Management
/*virtual*/ void
AssetLocatorMemoryImpl::addLevelOfDetailLocation( AssetTag* pAssetTag, unsigned int lod, std::string location )
{
    Locations locations = mAssetLocations[ pAssetTag ];

    // Defensive Progamming: Cap LOD at size of old_vector.
    if (lod > locations.size())
        lod = locations.size();

    locations.insert( locations.begin() + lod, location );

    mAssetLocations[ pAssetTag ] = locations;
}

/*virtual*/ void
AssetLocatorMemoryImpl::removeLevelOfDetailLocation( AssetTag* pAssetTag, unsigned int lod )
{
    LocationsOfAsset::iterator it = mAssetLocations.find( pAssetTag );

    if (mAssetLocations.end() == it)
        return;

    if (lod >= it->second.size())
        return;

    it->second.erase( it->second.begin() + lod );
}

/*virtual*/ void
AssetLocatorMemoryImpl::updateLevelOfDetailLocation( AssetTag* pAssetTag, unsigned int lod, std::string location )
{
    LocationsOfAsset::iterator it = mAssetLocations.find( pAssetTag );

    if (mAssetLocations.end() == it)
        return;

    if (lod >= it->second.size())
        return;

    it->second.at(lod) = location;
}

}

