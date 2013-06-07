#include <DescriptionInterface.h>

#include <AssetTagImpl.h>
#include <MetadataTagImpl.h>

using namespace std;

#include "cpptest.h"

class DescriptionInterfaceTestSuite : public Test::Suite
{
public:

    struct TestUtilities
    {
        std::string className;
        cards::AccessManager* accessManager;
    };

    DescriptionInterfaceTestSuite( cards::IDescription* iDescription, TestUtilities testUtilities)
    : mIDescription (iDescription),
      mAccessManager( testUtilities.accessManager )
    {
        mClassMsg = std::string("Class: ") + testUtilities.className;
        mAssetName = "foo";
        location0 = "bar0";
        location1 = "bar1";
        
        mt0_s = "foo0";
        mt1_s = "foo1";
        mt2_s = "foo2";
        mt3_s = "foo3";
        at1_s = "bar1";
        at2_s = "bar2";
        at3_s = "bar3";

        mt0 = new cards::MetadataTagImpl (mt0_s);
        mt1 = new cards::MetadataTagImpl (mt1_s);
        mt2 = new cards::MetadataTagImpl (mt2_s);
        mt3 = new cards::MetadataTagImpl (mt3_s);

        at1    = new cards::AssetTagImpl(at1_s);
        at2    = new cards::AssetTagImpl(at2_s);
        at3    = new cards::AssetTagImpl(at3_s);

        TEST_ADD(DescriptionInterfaceTestSuite::addAndRetrieveLOD)
        TEST_ADD(DescriptionInterfaceTestSuite::addAndRetrieveSecondLOD)
        TEST_ADD(DescriptionInterfaceTestSuite::removeAndRetrieveLOD)
        TEST_ADD(DescriptionInterfaceTestSuite::updateAndRetrieveLOD)
        TEST_ADD(DescriptionInterfaceTestSuite::removeToCleanupAsset)

        TEST_ADD(DescriptionInterfaceTestSuite::augmentMD1toAT1)      
        TEST_ADD(DescriptionInterfaceTestSuite::unaugmentMD1toAT1)     
        TEST_ADD(DescriptionInterfaceTestSuite::augmentMany)     
        TEST_ADD(DescriptionInterfaceTestSuite::unaugmentMany)     
        TEST_ADD(DescriptionInterfaceTestSuite::removeAsset)     
    }
    

    ~DescriptionInterfaceTestSuite()
    {
        delete mt0;
        delete mt1;
        delete mt2;
        delete mt3;
        delete at1;
        delete at2;
        delete at3;
    }
        
private:

    cards::IDescription* mIDescription;
    cards::AccessManager* mAccessManager;

    std::string mClassMsg;
    std::string mAssetName;
    std::string location0;
    std::string location1;

    std::string mt0_s ;
    std::string mt1_s ;
    std::string mt2_s ;
    std::string mt3_s ;

    std::string at1_s    ;
    std::string at2_s    ;
    std::string at3_s    ;

    cards::MetadataTagImpl* mt0 ;
    cards::MetadataTagImpl* mt1 ;
    cards::MetadataTagImpl* mt2 ;
    cards::MetadataTagImpl* mt3 ;

    cards::AssetTagImpl* at1    ;
    cards::AssetTagImpl* at2    ;
    cards::AssetTagImpl* at3    ;

    void addAndRetrieveLOD()
    {
        mIDescription->addLevelOfDetail(mAssetName, 0, location0 );

        std::vector< std::string > expected;
        expected.push_back( location0 );

        TEST_ASSERT_MSG( expected == mIDescription->viewLevelsOfDetail( mAssetName ), mClassMsg.c_str() );
    }

    void addAndRetrieveSecondLOD()
    {
        mIDescription->addLevelOfDetail( mAssetName, 1, location1 );

        std::vector< std::string > expected;
        expected.push_back( location0 );
        expected.push_back( location1 );

        TEST_ASSERT_MSG( expected == mIDescription->viewLevelsOfDetail( mAssetName ), mClassMsg.c_str() );
    }

    void removeAndRetrieveLOD()
    {
        mIDescription->removeLevelOfDetail( mAssetName, 1 );

        std::vector< std::string > expected;
        expected.push_back( location0 );

        TEST_ASSERT_MSG( expected == mIDescription->viewLevelsOfDetail( mAssetName ), mClassMsg.c_str() );
    }

    void updateAndRetrieveLOD()
    {
        mIDescription->updateLevelOfDetail( mAssetName, 0, location1 );

        std::vector< std::string > expected;
        expected.push_back( location1 );

        TEST_ASSERT_MSG( expected == mIDescription->viewLevelsOfDetail( mAssetName ), mClassMsg.c_str() );
    }

    void removeToCleanupAsset()
    {
        TEST_ASSERT_MSG( !mIDescription->viewLevelsOfDetail( mAssetName ).empty(),
            (mClassMsg + ":\t Missing Asset").c_str() );

        mIDescription->removeAsset(mAssetName);

        TEST_ASSERT_MSG( mIDescription->viewLevelsOfDetail( mAssetName ).empty(),
            (mClassMsg + ":\t Failed to remove asset").c_str() );
    }

    void augmentMD1toAT1()
    {
       cards::AssetMetadataMapping::AssetSet    expectedAssetSet;
       cards::AssetMetadataMapping::MetadataSet inputMetadataSet;

       inputMetadataSet.insert(mt1);
       expectedAssetSet.insert(at1);

       mIDescription->augmentAsset(at1_s,mt1_s);

       TEST_ASSERT_MSG( mAccessManager->getAssetMetadataMapping()->describedAssets(inputMetadataSet) == expectedAssetSet,
            (mClassMsg + ":\t Failed to return proper AssetTag 1").c_str() );

    }

    void unaugmentMD1toAT1()
    {
       cards::AssetMetadataMapping::AssetSet    expectedAssetSet;
       cards::AssetMetadataMapping::MetadataSet inputMetadataSet;

       inputMetadataSet.insert(mt1);
       mIDescription->unaugmentAsset(at1_s,mt1_s);

       TEST_ASSERT_MSG( mAccessManager->getAssetMetadataMapping()->describedAssets(inputMetadataSet) == expectedAssetSet,
            (mClassMsg + ":\t Failed to return proper EmptySet").c_str() );

    }

    void augmentMany()
    {
       cards::AssetMetadataMapping::AssetSet    expectedAssetSet;
       cards::AssetMetadataMapping::MetadataSet inputMetadataSet;

       inputMetadataSet.insert(mt1);
       inputMetadataSet.insert(mt2);

       expectedAssetSet.insert(at3);

       mIDescription->removeAsset(at1_s);
       mIDescription->removeAsset(at2_s);
       mIDescription->removeAsset(at3_s);

       mIDescription->augmentAsset(at1_s,mt1_s);
       mIDescription->augmentAsset(at2_s,mt2_s);
       mIDescription->augmentAsset(at3_s,mt1_s);
       mIDescription->augmentAsset(at3_s,mt2_s);

       TEST_ASSERT_MSG( mAccessManager->getAssetMetadataMapping()->describedAssets(inputMetadataSet) == expectedAssetSet,
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

       mIDescription->unaugmentAsset(at1_s,mt1_s);
       mIDescription->unaugmentAsset(at2_s,mt2_s);
       mIDescription->unaugmentAsset(at3_s,mt1_s);
       mIDescription->unaugmentAsset(at3_s,mt2_s);

       TEST_ASSERT_MSG( mAccessManager->getAssetMetadataMapping()->describedAssets(inputMetadataSet1) == expectedAssetSet,
            (mClassMsg + ":\t Failed to return proper EmptySet").c_str() );

       TEST_ASSERT_MSG( mAccessManager->getAssetMetadataMapping()->describedAssets(inputMetadataSet2) == expectedAssetSet,
            (mClassMsg + ":\t Failed to return proper EmptySet").c_str() );

       TEST_ASSERT_MSG( mAccessManager->getAssetMetadataMapping()->describedAssets(inputMetadataSet3) == expectedAssetSet,
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

       mIDescription->augmentAsset(at1_s,mt1_s);
       mIDescription->augmentAsset(at2_s,mt2_s);
       mIDescription->augmentAsset(at3_s,mt1_s);
       mIDescription->augmentAsset(at3_s,mt2_s);

       mIDescription->removeAsset(at1_s);

       TEST_ASSERT_MSG( mAccessManager->getAssetMetadataMapping()->describedAssets(inputMetadataSet1) == expectedAssetSet1,
            (mClassMsg + ":\t Failed to remove AssetTag 1").c_str() );

       mIDescription->removeAsset(at2_s);

       TEST_ASSERT_MSG( mAccessManager->getAssetMetadataMapping()->describedAssets(inputMetadataSet2) == expectedAssetSet1,
            (mClassMsg + ":\t Failed to remove AssetTag 2").c_str() );

       mIDescription->removeAsset(at3_s);

       TEST_ASSERT_MSG( mAccessManager->getAssetMetadataMapping()->describedAssets(inputMetadataSet3) == expectedAssetSet2,
            (mClassMsg + ":\t Failed to remove AssetTag 3").c_str() );

    }


};

