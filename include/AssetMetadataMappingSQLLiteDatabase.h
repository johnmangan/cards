#ifndef ASSET_METADATA_MAPPING_SQLLITE_DATABASE_H_
#define ASSET_METADATA_MAPPING_SQLLITE_DATABASE_H_

#include "AssetMetadataMappingSQLLiteDatabase.h"

#include <sqlite3.h>

namespace cards
{
  class AssetMetadataMappingSQLLiteDatabase : public AssetMetadataMappingDatabase
  {
  public:
    AssetMetadataMappingSQLLiteDatabase ();
    AssetMetadataMappingSQLLiteDatabase (std::string filename);

    virtual void 
    addMetadataToAsset(std::string assetName, std::string metadataTagName);

    virtual AssetMetadataMapping::AssetSet
    getDescribedAssets(MetadataSet metadataTags);

    virtual void
    removeAsset(std::string assetName);

    virtual void 
    removeMetadataFromAsset(std::string assetName, std::string metadataTagName);

  protected:
    virtual void
    open(std::string filename);

  private:
    int getMetaID(std::string metadataName);

    sqlite3* database;
  };
}

#endif

