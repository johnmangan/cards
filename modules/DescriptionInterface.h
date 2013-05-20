#ifndef DESCRIPTION_INTERFACE_H_
#define DESCRIPTION_INTERFACE_H_

#include <string>
#include <vector>

namespace cards {

class IDescription
{
public:

    // Asset
    virtual void
    createAsset( std::string assetName ) = 0;

    virtual void
    removeAsset( std::string assetName ) = 0;

    virtual void
    renameAsset( std::string oldAssetName, std::string newAssetName ) = 0;

    // Filepaths to different Levels Of Detail
    virtual void
    addLevelOfDetail( std::string assetName, unsigned int lod, std::string location ) = 0;

    virtual void
    removeLevelOfDetail( std::string assetName, unsigned int lod ) = 0;

    virtual void
    updateLevelOfDetail( std::string assetName, unsigned int lod, std::string location ) = 0;

    virtual void
    removeLocation( std::string location ) = 0;

    virtual std::vector< std::string >
    viewLevelsOfDetail( std::string assetName ) = 0;

    // Augmenting Assets with Metadata
    virtual void
    augmentAsset( std::string assetName, std::string metadataName ) = 0;

    virtual void
    unaugmentAsset( std::string assetName, std::string metadataName ) = 0;
};

}

#endif /*DESCRIPTION_INTERFACE_H_*/

