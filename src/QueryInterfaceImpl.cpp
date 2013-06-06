#include <QueryInterfaceImpl.h>

#include <AssetTagImpl.h>
#include <MetadataTagImpl.h>
#include <AccessManagerImpl.h>

namespace cards {

IQueryImpl::IQueryImpl()
{
    mAccessManager = new AccessManagerImpl;
}

IQueryImpl::IQueryImpl( AccessManager* accessManager )
: mAccessManager( accessManager )
{
}

/*virtual*/ std::vector< std::string >
IQueryImpl::getFilepaths( std::map< std::string, int > metadataWeights, double percent )
{
    std::map< MetadataTag*, int, MetadataTag::MetadataTagComparator > tagWeights;

    for (std::map< std::string, int >::iterator it = metadataWeights.begin();
        metadataWeights.end() != it;
        ++it)
    {
        MetadataTag* tag = new MetadataTagImpl( it->first );
        tagWeights[ tag ] = it->second;
    }

    AssetTag* assetTag = mAccessManager->getRankedSearch()->topRankedAsset( tagWeights, percent );

    std::vector< std::string > filepaths = mAccessManager->getAssetLocator()->getFilepath( assetTag );

    // cleanup
    delete assetTag;
    for (std::map< MetadataTag*, int >::iterator it = tagWeights.begin();
        tagWeights.end() != it;
        ++it)
    {
        delete it->first;
    }

    return filepaths;
}

}

