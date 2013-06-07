#include <QueryInterface.h>

#include <AssetTagImpl.h>
#include <MetadataTagImpl.h>

#include "cpptest.h"

class QueryInterfaceTestSuite : public Test::Suite
{
public:

    struct TestUtilities
    {
        std::string className;
        cards::AccessManager* accessManager;
    };

    QueryInterfaceTestSuite( cards::IQuery* iQuery, TestUtilities testUtilities )
        : mQueryInterface( iQuery ), mAccessManager( testUtilities.accessManager )
    {
        mClassMsg = std::string("Class: ") + testUtilities.className;

        mAssetName = "Asset";
        mBadMetadataName = "Bad Metadata";
        mGoodMetadataName = "Good Metadata";

        mAssetTag = new cards::AssetTagImpl( mAssetName );
        mMetadataTag = new cards::MetadataTagImpl( mGoodMetadataName );

        mLocation0 = "location0";
        mLocation1 = "location1";

        TEST_ADD(QueryInterfaceTestSuite::noMetadata)
        TEST_ADD(QueryInterfaceTestSuite::noValidAssets)
        TEST_ADD(QueryInterfaceTestSuite::noFilepaths)
        TEST_ADD(QueryInterfaceTestSuite::oneFilepath)
        TEST_ADD(QueryInterfaceTestSuite::multipleOrderedFilepaths)
        TEST_ADD(QueryInterfaceTestSuite::cleanupAndReturnNoFilepaths)
    }

    ~QueryInterfaceTestSuite()
    {
        delete mAssetTag;
        delete mMetadataTag;
    }    
private:

    std::string mClassMsg;
    cards::IQuery* mQueryInterface;
    cards::AccessManager* mAccessManager;

    std::string mAssetName;
    std::string mBadMetadataName;
    std::string mGoodMetadataName;

    cards::AssetTag* mAssetTag;
    cards::MetadataTag* mMetadataTag;

    std::string mLocation0;
    std::string mLocation1;

    void noMetadata()
    {
        std::map< std::string, int > metadataWeights;

        TEST_ASSERT_MSG( mQueryInterface->getFilepaths( metadataWeights ).empty(),
            mClassMsg.c_str() );
    }

    void noValidAssets()
    {
        std::map< std::string, int > metadataWeights;
        metadataWeights[ mBadMetadataName ] = 1;

        TEST_ASSERT_MSG( mQueryInterface->getFilepaths( metadataWeights ).empty(),
            mClassMsg.c_str() );
    }

    void noFilepaths()
    {
        mAccessManager->getAssetMetadataMapping()->augmentAsset( mAssetTag, mMetadataTag );

        std::map< std::string, int > metadataWeights;
        metadataWeights[ mGoodMetadataName ] = 1;

        TEST_ASSERT_MSG( mQueryInterface->getFilepaths( metadataWeights ).empty(), mClassMsg.c_str() );
    }

    void oneFilepath()
    {
        std::map< std::string, int > metadataWeights;
        metadataWeights[ mGoodMetadataName ] = 1;

        mAccessManager->getAssetLocator()->addLevelOfDetailLocation( mAssetTag, 0, mLocation0 );

        std::vector< std::string > expected;
        expected.push_back( mLocation0 );

        TEST_ASSERT_MSG( expected ==  mQueryInterface->getFilepaths( metadataWeights ), mClassMsg.c_str() );
    }

    void multipleOrderedFilepaths()
    {
        std::map< std::string, int > metadataWeights;
        metadataWeights[ mGoodMetadataName ] = 1;

        mAccessManager->getAssetLocator()->addLevelOfDetailLocation( mAssetTag, 1, mLocation1 );

        std::vector< std::string > expected;
        expected.push_back( mLocation0 );
        expected.push_back( mLocation1 );

        TEST_ASSERT_MSG( expected ==  mQueryInterface->getFilepaths( metadataWeights ), mClassMsg.c_str() );
    }

    void cleanupAndReturnNoFilepaths()
    {
        mAccessManager->getAssetLocator()->removeAsset( mAssetTag );
        mAccessManager->getAssetMetadataMapping()->removeAsset( mAssetTag );

        std::map< std::string, int > metadataWeights;
        metadataWeights[ mGoodMetadataName ] = 1;

        TEST_ASSERT_MSG( mQueryInterface->getFilepaths( metadataWeights ).empty(), mClassMsg.c_str() );
    }

};

