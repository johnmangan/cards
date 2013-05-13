namespace cards {

#ifndef AUGMENTATION_LOGIC_HANDLER_H_
#define AUGMENTATION_LOGIC_HANDLER_H_

#include <string>

class AugmentationLogicHandler
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
    addLevelOfDetail( std::string assetName, int lod, std::string filepath );

    virtual void
    removeLevelOfDetail( std::string assetName, int lod );

    virtual void
    updateLevelOfDetail( std::string assetName, int lod, std::string filepath );

    virtual void
    removeFilepath( std::string filepath );

    virtual std::vector< std::string >
    viewLevelsOfDetail( std::string assetName );

    // Augmenting Assets with Metadata
    virtual void
    augmentAsset( std::string assetName, std::string metadataName ) = 0;

    virtual void
    unaugmentAsset( std::string assetName, std::string metadataName ) = 0;
}

#endif /*AUGMENTATION_LOGIC_HANDLER_H_*/

}

