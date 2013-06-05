#ifndef ASSET_METADATA_MAPPING_DATABASE_H_
#define ASSET_METADATA_MAPPING_DATABASE_H_

#include <string>
#include <vector>

namespace cards
{
  class AssetMetadataMappingDatabase 
  {
  public:
    virtual void 
    addMetadataToAsset(std::string assetName, std::string metadataTagName) = 0;

    virtual void
    getDescribedAssets(MetadataSet metadataTags) = 0;

    virtual void
    removeAsset(std::string assetName) = 0;

    virtual void 
    removeMetadataFromAsset(std::string assetName, std::string metadataTagName) = 0;

  protected:
    virtual void open(std::string databaseName) = 0;
  };
}

#endif

