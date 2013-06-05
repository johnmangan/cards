#include <AccessManager.h>

#include <AssetLocator.h>
#include <AssetMetadataMapping.h>
#include <RankedSearch.h>

#include "cpptest.h"

class AccessManagerTestSuite : public Test::Suite
{
public:
    struct TestUtilities
    {
        cards::AssetLocator* assetLocator;
        cards::AssetMetadataMapping* assetMetadataMapping;
        cards::RankedSearch* rankedSearch;
        std::string className;
    };

    AccessManagerTestSuite( cards::AccessManager* accessManager, TestUtilities testUtilities )
        : mAccessManager( accessManager ),
          mAssetLocator( testUtilities.assetLocator ),
          mAssetMetadataMapping( testUtilities.assetMetadataMapping ),
          mRankedSearch( testUtilities.rankedSearch )
    {
        mClassMsg = std::string("Class: ") + testUtilities.className;

        TEST_ADD(AccessManagerTestSuite::getAssetLocator)
        TEST_ADD(AccessManagerTestSuite::getAssetMetadataMapping)
        TEST_ADD(AccessManagerTestSuite::getRankedSearch)
    }

private:

    cards::AccessManager* mAccessManager;
    std::string mClassMsg;
    cards::AssetLocator* mAssetLocator;
    cards::AssetMetadataMapping* mAssetMetadataMapping;
    cards::RankedSearch* mRankedSearch;

    void getAssetLocator()
    {
        TEST_ASSERT_MSG( mAccessManager->getAssetLocator() == mAssetLocator,
            (mClassMsg + ":\t Failed to return proper AssetLocator").c_str() );
    }

    void getAssetMetadataMapping()
    {
        TEST_ASSERT_MSG( mAccessManager->getAssetMetadataMapping() == mAssetMetadataMapping,
            (mClassMsg + ":\t Failed to return proper AssetMetadataMapping").c_str() );
    }

    void getRankedSearch()
    {
        TEST_ASSERT_MSG( mAccessManager->getRankedSearch() == mRankedSearch,
            (mClassMsg + ":\t Failed to return proper RankedSearch").c_str() );
    }
};

