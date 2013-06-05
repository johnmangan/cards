#include <RankedSearch.h>

#include <AccessManager.h>

#include <AssetTagImpl.h>
#include <MetadataTagImpl.h>

#include "cpptest.h"

class RankedSearchTestSuite : public Test::Suite
{
public:

    struct TestUtilities
    {
        std::string className;
        cards::AccessManager* accessManager;
    };

    RankedSearchTestSuite( cards::RankedSearch* rankedSearch, TestUtilities testUtilities )
        : mRankedSearch( rankedSearch ), mAssetMetadataMapping( testUtilities.accessManager->getAssetMetadataMapping() )
    {
        mClassMsg = std::string("Class: ") + testUtilities.className;

        mAssetTags.push_back( new cards::AssetTagImpl( "asset-0" ) );
        mAssetTags.push_back( new cards::AssetTagImpl( "asset-1" ) );
        mAssetTags.push_back( new cards::AssetTagImpl( "asset-2" ) );
        mAssetTags.push_back( new cards::AssetTagImpl( "asset-3" ) );

        mMetadataTags.push_back( new cards::MetadataTagImpl( "metadata-0" ) );
        mMetadataTags.push_back( new cards::MetadataTagImpl( "metadata-1" ) );
        mMetadataTags.push_back( new cards::MetadataTagImpl( "metadata-2" ) );

        TEST_ADD(RankedSearchTestSuite::noTopRankedAsset)
        TEST_ADD(RankedSearchTestSuite::singleTopRankedAsset)
        TEST_ADD(RankedSearchTestSuite::ignoreIrreleventAssets)
        TEST_ADD(RankedSearchTestSuite::multipleTopRankedAssets)
        TEST_ADD(RankedSearchTestSuite::singleBestTopRankedAsset)
        TEST_ADD(RankedSearchTestSuite::differingMetadataWeightsTopRankedAsset)
    }

    ~RankedSearchTestSuite()
    {
        for (unsigned int i = 0; i < mAssetTags.size(); ++i)
            delete mAssetTags[i];

        for (unsigned int i = 0; i < mMetadataTags.size(); ++i)
            delete mMetadataTags[i];
    }    
private:

    cards::RankedSearch* mRankedSearch;
    std::string mClassMsg;
    cards::AssetMetadataMapping* mAssetMetadataMapping;

    std::vector< cards::AssetTag* > mAssetTags; // Assume size 4
    std::vector< cards::MetadataTag* > mMetadataTags; // Assume size 2

    void noTopRankedAsset()
    {
        cards::RankedSearch::MetadataWeights metadataWeights;
        metadataWeights[ mMetadataTags[0] ] = 1;

        TEST_ASSERT_MSG( NULL == mRankedSearch->topRankedAsset( metadataWeights ),
            mClassMsg.c_str() );
    }

    void singleTopRankedAsset()
    {
        mAssetMetadataMapping->augmentAsset( mAssetTags[1], mMetadataTags[0] );

        cards::RankedSearch::MetadataWeights metadataWeights;
        metadataWeights[ mMetadataTags[0] ] = 1;

        TEST_ASSERT_MSG( mAssetTags[1] == mRankedSearch->topRankedAsset( metadataWeights ), mClassMsg.c_str() );
    }

    void ignoreIrreleventAssets()
    {
        mAssetMetadataMapping->augmentAsset( mAssetTags[2], mMetadataTags[1] );

        cards::RankedSearch::MetadataWeights metadataWeights;
        metadataWeights[ mMetadataTags[0] ] = 1;

        TEST_ASSERT_MSG( mAssetTags[1] == mRankedSearch->topRankedAsset( metadataWeights ), mClassMsg.c_str() );
    }

    void multipleTopRankedAssets()
    {
        mAssetMetadataMapping->augmentAsset( mAssetTags[3], mMetadataTags[0] );
        mAssetMetadataMapping->augmentAsset( mAssetTags[3], mMetadataTags[1] );

        cards::RankedSearch::MetadataWeights metadataWeights;
        metadataWeights[ mMetadataTags[0] ] = 1;

        std::set< cards::AssetTag* > accepted;
        accepted.insert( mAssetTags[1] );
        accepted.insert( mAssetTags[3] );

        // Numerous tests for high confidence
        for (unsigned int i = 0; i < 20; ++i)
            TEST_ASSERT_MSG( accepted.end() != accepted.find( mRankedSearch->topRankedAsset( metadataWeights ) ), mClassMsg.c_str() );
    }

    void singleBestTopRankedAsset()
    {
        cards::RankedSearch::MetadataWeights metadataWeights;
        metadataWeights[ mMetadataTags[0] ] = 1;
        metadataWeights[ mMetadataTags[1] ] = 1;

        TEST_ASSERT_MSG( mAssetTags[3] == mRankedSearch->topRankedAsset( metadataWeights ), mClassMsg.c_str() );
    }

    void differingMetadataWeightsTopRankedAsset()
    {
        cards::RankedSearch::MetadataWeights metadataWeights;
        metadataWeights[ mMetadataTags[0] ] = 1;
        metadataWeights[ mMetadataTags[1] ] = 2;

        // Numerous tests for high confidence
        for (unsigned int i = 0; i < 20; ++i)
            TEST_ASSERT_MSG( mAssetTags[3] == mRankedSearch->topRankedAsset( metadataWeights ), mClassMsg.c_str() );
    }
};

