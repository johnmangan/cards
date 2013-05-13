namespace cards {

#ifndef AUGMENTATION_LOGIC_HANDLER_H_
#define AUGMENTATION_LOGIC_HANDLER_H_

#include <string>

class AugmentationLogicHandler
{
public:

    virtual void
    createAsset( std::string assetName, std::string filepath ) = 0;

    virtual void
    removeAsset( std::string assetName ) = 0;

    virtual void
    updateAsset( std::string assetName, std::string filepath ) = 0;

    virtual void
    augmentAsset( std::string assetName, std::string metadataName ) = 0;

    virtual void
    unaugmentAsset( std::string assetName, std::string metadataName ) = 0;
}

#endif /*AUGMENTATION_LOGIC_HANDLER_H_*/

}

