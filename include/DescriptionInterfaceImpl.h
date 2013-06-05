#ifndef DESCRIPTION_INTERFACE_IMPL_H_
#define DESCRIPTION_INTERFACE_IMPL_H_

#include <DescriptionInterface.h>

#include <AccessManager.h>

namespace cards {

class IDescriptionImpl : public IDescription
{
public:

    IDescriptionImpl();

    IDescriptionImpl( AccessManager* accessManager );

    // Asset
    virtual void
    removeAsset( std::string assetName );

    // Filepaths to different Levels Of Detail
    virtual void
    addLevelOfDetail( std::string assetName,unsigned int lod, std::string location );

    virtual void
    removeLevelOfDetail( std::string assetName,unsigned int lod );

    virtual void
    updateLevelOfDetail( std::string assetName,unsigned int lod, std::string location );

    virtual std::vector< std::string >
    getLevelsOfDetail( std::string assetName );

    // Augmenting Assets with Metadata
    virtual void
    augmentAsset( std::string assetName, std::string metadataName );

    virtual void
    unaugmentAsset( std::string assetName, std::string metadataName );

private:
    AccessManager* mAccessManager;
};

}

#endif /*DESCRIPTION_INTERFACE_IMPL_H_*/

