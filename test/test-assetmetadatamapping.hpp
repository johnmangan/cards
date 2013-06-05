#include <AccessManager.h>

#include <AssetLocator.h>
#include <AssetMetadataMapping.h>
#include <RankedSearch.h>

#include <MetadataTag.h>
#include <MetadataTagImpl.h>

#include "cpptest.h"

class AssetMetadataMappingTestSuite : public Test::Suite
{
public:

    AssetMetadataMappingTestSuite( cards::AssetMetadataMapping* assetMetadataMapping, std::string className )
        : mAssetMetadataMapping( assetMetadataMapping )
    {
        mClassMsg = std::string("Class: ") + className;

        mt0 = new cards::MetadataTagImpl ("foo0");
        mt1 = new cards::MetadataTagImpl ("foo1");
        mt2 = new cards::MetadataTagImpl ("foo2");
        mt3 = new cards::MetadataTagImpl ("foo3");

        at1    = new cards::AssetTagImpl("bar1");
        at2    = new cards::AssetTagImpl("bar2");
        at3    = new cards::AssetTagImpl("bar3");

        TEST_ADD(AssetMetadataMappingTestSuite::emptyAssetsSet)
        TEST_ADD(AssetMetadataMappingTestSuite::augmentMD1toAT1)      
        TEST_ADD(AssetMetadataMappingTestSuite::unaugmentMD1toAT1)     
        TEST_ADD(AssetMetadataMappingTestSuite::augmentMany)     
        TEST_ADD(AssetMetadataMappingTestSuite::unaugmentMany)     
        TEST_ADD(AssetMetadataMappingTestSuite::removeAsset)     
    }

private:

    cards::AssetMetadataMapping* mAssetMetadataMapping;

    std::string mClassMsg;

    cards::MetadataTagImpl* mt0 ;
    cards::MetadataTagImpl* mt1 ;
    cards::MetadataTagImpl* mt2 ;
    cards::MetadataTagImpl* mt3 ;

    cards::AssetTagImpl* at1    ;
    cards::AssetTagImpl* at2    ;
    cards::AssetTagImpl* at3    ;
    
    void emptyAssetsSet()
    {
       cards::AssetMetadataMapping::AssetSet    expectedAssetSet;
       cards::AssetMetadataMapping::MetadataSet inputMetadataSet;

       inputMetadataSet.empty();
       inputMetadataSet.insert(mt0);
       
       TEST_ASSERT_MSG( mAssetMetadataMapping->describedAssets(inputMetadataSet) == expectedAssetSet,
            (mClassMsg + ":\t Failed to return proper EmptySet").c_str() );
    }

    void augmentMD1toAT1()
    {
       cards::AssetMetadataMapping::AssetSet    expectedAssetSet;
       cards::AssetMetadataMapping::MetadataSet inputMetadataSet;
     
       inputMetadataSet.insert(mt1);
       expectedAssetSet.insert(at1);

       mAssetMetadataMapping->augmentAsset(at1,mt1);

       TEST_ASSERT_MSG( mAssetMetadataMapping->describedAssets(inputMetadataSet) == expectedAssetSet,
            (mClassMsg + ":\t Failed to return proper AssetTag 1").c_str() );

    }

    void unaugmentMD1toAT1()
    {
       cards::AssetMetadataMapping::AssetSet    expectedAssetSet;
       cards::AssetMetadataMapping::MetadataSet inputMetadataSet;
     
       mAssetMetadataMapping->unaugmentAsset(at1,mt1);

       TEST_ASSERT_MSG( mAssetMetadataMapping->describedAssets(inputMetadataSet) == expectedAssetSet,
            (mClassMsg + ":\t Failed to return proper EmptySet").c_str() );

    }

    void augmentMany()
    {
       cards::AssetMetadataMapping::AssetSet    expectedAssetSet;
       cards::AssetMetadataMapping::MetadataSet inputMetadataSet;
     
       inputMetadataSet.insert(mt1);
       inputMetadataSet.insert(mt2);

       expectedAssetSet.insert(at3);

       mAssetMetadataMapping->augmentAsset(at1,mt1);
       mAssetMetadataMapping->augmentAsset(at2,mt2);
       mAssetMetadataMapping->augmentAsset(at3,mt1);
       mAssetMetadataMapping->augmentAsset(at3,mt2);

       TEST_ASSERT_MSG( mAssetMetadataMapping->describedAssets(inputMetadataSet) == expectedAssetSet,
            (mClassMsg + ":\t Failed to return proper AssetTag 3").c_str() );

    }

    void unaugmentMany()
    {
       cards::AssetMetadataMapping::AssetSet    expectedAssetSet;

       cards::AssetMetadataMapping::MetadataSet inputMetadataSet1;
       cards::AssetMetadataMapping::MetadataSet inputMetadataSet2;
       cards::AssetMetadataMapping::MetadataSet inputMetadataSet3;

       inputMetadataSet1.insert(mt1);
       inputMetadataSet2.insert(mt2);
       inputMetadataSet3.insert(mt1);
       inputMetadataSet3.insert(mt2);

       mAssetMetadataMapping->unaugmentAsset(at1,mt1);
       mAssetMetadataMapping->unaugmentAsset(at2,mt2);
       mAssetMetadataMapping->unaugmentAsset(at3,mt1);
       mAssetMetadataMapping->unaugmentAsset(at3,mt2);

       TEST_ASSERT_MSG( mAssetMetadataMapping->describedAssets(inputMetadataSet1) == expectedAssetSet,
            (mClassMsg + ":\t Failed to return proper EmptySet").c_str() );

       TEST_ASSERT_MSG( mAssetMetadataMapping->describedAssets(inputMetadataSet2) == expectedAssetSet,
            (mClassMsg + ":\t Failed to return proper EmptySet").c_str() );

       TEST_ASSERT_MSG( mAssetMetadataMapping->describedAssets(inputMetadataSet3) == expectedAssetSet,
            (mClassMsg + ":\t Failed to return proper EmptySet").c_str() );

    }

    void removeAsset()
    {
       cards::AssetMetadataMapping::AssetSet    expectedAssetSet1;
       cards::AssetMetadataMapping::AssetSet    expectedAssetSet2;

       cards::AssetMetadataMapping::MetadataSet inputMetadataSet1;
       cards::AssetMetadataMapping::MetadataSet inputMetadataSet2;
       cards::AssetMetadataMapping::MetadataSet inputMetadataSet3;

       inputMetadataSet1.insert(mt1);
       inputMetadataSet2.insert(mt2);
       inputMetadataSet3.insert(mt1);
       inputMetadataSet3.insert(mt2);

       expectedAssetSet1.insert(at3);


       mAssetMetadataMapping->augmentAsset(at1,mt1);
       mAssetMetadataMapping->augmentAsset(at2,mt2);
       mAssetMetadataMapping->augmentAsset(at3,mt1);
       mAssetMetadataMapping->augmentAsset(at3,mt2);
  
       mAssetMetadataMapping->removeAsset(at1);
       
       TEST_ASSERT_MSG( mAssetMetadataMapping->describedAssets(inputMetadataSet1) == expectedAssetSet1,
            (mClassMsg + ":\t Failed to return proper Asset Set 1").c_str() );

       mAssetMetadataMapping->removeAsset(at2);

       TEST_ASSERT_MSG( mAssetMetadataMapping->describedAssets(inputMetadataSet2) == expectedAssetSet1,
            (mClassMsg + ":\t Failed to return proper Asset Set 2").c_str() );

       mAssetMetadataMapping->removeAsset(at3);

       TEST_ASSERT_MSG( mAssetMetadataMapping->describedAssets(inputMetadataSet3) == expectedAssetSet2,
            (mClassMsg + ":\t Failed to return proper EmptySet").c_str() );

    }


};

