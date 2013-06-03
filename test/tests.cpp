#include <iostream>
#include <cstdlib>
#include <cstring>

#include <AssetLocator.h>

#include <AssetTagImpl.h>
#include <AssetLocatorMemoryImpl.h>
#include <AssetLocatorDatabaseImpl.h>

#include "cpptest.h"

using namespace std;
using namespace cards;

class AssetLocatorTestSuite : public Test::Suite
{
public:
    AssetLocatorTestSuite( AssetLocator* assetLocator, std::string className )
        : mAssetLocator( assetLocator )
    {
        mClassMsg = std::string("Class: ") + className;

        TEST_ADD(AssetLocatorTestSuite::addAndRetrieveLOD)
        TEST_ADD(AssetLocatorTestSuite::addAndRetrieveSecondLOD)
        TEST_ADD(AssetLocatorTestSuite::removeAndRetrieveLOD)
        TEST_ADD(AssetLocatorTestSuite::updateAndRetrieveLOD)
        TEST_ADD(AssetLocatorTestSuite::removeToCleanupAsset)
    }

    ~AssetLocatorTestSuite()
    {
        delete mAssetTag;
    }    
private:

    std::string mClassMsg;
    AssetLocator* mAssetLocator;
    AssetTag* mAssetTag = new AssetTagImpl( "foo" );
    std::string location0 = "bar0";
    std::string location1 = "bar1";

    void addAndRetrieveLOD()
    {
        mAssetLocator->addLevelOfDetailLocation( mAssetTag, 0, location0 );

        AssetLocator::Locations expected;
        expected.push_back( location0 );

        TEST_ASSERT_MSG( expected == mAssetLocator->getFilepath( mAssetTag ), mClassMsg.c_str() );
    }

    void addAndRetrieveSecondLOD()
    {
        mAssetLocator->addLevelOfDetailLocation( mAssetTag, 1, location1 );

        AssetLocator::Locations expected;
        expected.push_back( location0 );
        expected.push_back( location1 );

        TEST_ASSERT_MSG( expected == mAssetLocator->getFilepath( mAssetTag ), mClassMsg.c_str() );
    }

    void removeAndRetrieveLOD()
    {
        mAssetLocator->removeLevelOfDetailLocation( mAssetTag, 1 );

        AssetLocator::Locations expected;
        expected.push_back( location0 );

        TEST_ASSERT_MSG( expected == mAssetLocator->getFilepath( mAssetTag ), mClassMsg.c_str() );
    }

    void updateAndRetrieveLOD()
    {
        mAssetLocator->updateLevelOfDetailLocation( mAssetTag, 0, location1 );

        AssetLocator::Locations expected;
        expected.push_back( location1 );

        TEST_ASSERT_MSG( expected == mAssetLocator->getFilepath( mAssetTag ), mClassMsg.c_str() );
    }

    void removeToCleanupAsset()
    {
        TEST_ASSERT_MSG( !mAssetLocator->getFilepath( mAssetTag ).empty(),
            (mClassMsg + ":\t Missing Asset").c_str() );

        mAssetLocator->removeAsset( mAssetTag );

        TEST_ASSERT_MSG( mAssetLocator->getFilepath( mAssetTag ).empty(),
            (mClassMsg + ":\t Failed to remove asset").c_str() );
    }
};

enum OutputType
{
	Compiler,
	Html,
	TextTerse,
	TextVerbose
};

static void
usage()
{
	cout << "usage: mytest [MODE]\n"
		 << "where MODE may be one of:\n"
		 << "  --compiler\n"
		 << "  --html\n"
		 << "  --text-terse (default)\n"
		 << "  --text-verbose\n";
	exit(0);
}

static auto_ptr<Test::Output>
cmdline(int argc, char* argv[])
{
	if (argc > 2)
		usage(); // will not return
	
	Test::Output* output = 0;
	
	if (argc == 1)
		output = new Test::TextOutput(Test::TextOutput::Verbose);
	else
	{
		const char* arg = argv[1];
		if (strcmp(arg, "--compiler") == 0)
			output = new Test::CompilerOutput;
		else if (strcmp(arg, "--html") == 0)
			output =  new Test::HtmlOutput;
		else if (strcmp(arg, "--text-terse") == 0)
			output = new Test::TextOutput(Test::TextOutput::Terse);
		else if (strcmp(arg, "--text-verbose") == 0)
			output = new Test::TextOutput(Test::TextOutput::Verbose);
		else
		{
			cout << "invalid commandline argument: " << arg << endl;
			usage(); // will not return
		}
	}
	
	return auto_ptr<Test::Output>(output);
}

// Main test program
//
int
main(int argc, char* argv[])
{
	try
	{
                // Setup
                AssetLocator* asset_locator_mem = new AssetLocatorMemoryImpl;
                AssetLocator* asset_locator_db = new AssetLocatorDatabaseImpl;

		// Demonstrates the ability to use multiple test suites
		Test::Suite ts;
		ts.add(auto_ptr<Test::Suite>(new AssetLocatorTestSuite(asset_locator_mem, "AssetLocatorMemoryImpl")));
		ts.add(auto_ptr<Test::Suite>(new AssetLocatorTestSuite(asset_locator_db, "AssetLocatorDatabaseImpl")));

		// Run the tests
		auto_ptr<Test::Output> output(cmdline(argc, argv));
		ts.run(*output, true);

                // Teardown
                delete asset_locator_mem;
                delete asset_locator_db;
	}
	catch (...)
	{
		cout << "unexpected exception encountered\n";
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

