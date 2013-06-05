#include <iostream>
#include <cstdlib>
#include <cstring>

#include <AssetLocatorMemoryImpl.h>
#include <AssetLocatorDatabaseImpl.h>

#include <AccessManagerImpl.h>
#include <AssetMetadataMappingMemoryImpl.h>
#include <RankedSearchImpl.h>

#include "test-assetlocator.hpp"
#include "test-accessmanager.hpp"

#include "cpptest.h"

using namespace std;
using namespace cards;

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
                std::map< AssetLocator*, std::string > asset_locators;
                asset_locators[ new AssetLocatorMemoryImpl ] = "AssetLocatorMemoryImpl";
                asset_locators[ new AssetLocatorDatabaseImpl ] = "AssetLocatorDatabaseImpl";

                std::map< AssetMetadataMapping*, std::string > asset_metadata_mappings;
                asset_metadata_mappings[ new AssetMetadataMappingMemoryImpl ] = "AssetMetadataMappingMemoryImpl";

                std::map< RankedSearch*, std::string > ranked_searches;
                ranked_searches[ new RankedSearchImpl ] = "RankedSearchImpl";

                std::map< AccessManager*, AccessManagerTestSuite::TestUtilities > access_managers;
                for (std::map< AssetLocator*, std::string >::iterator al_it = asset_locators.begin();
                     asset_locators.end() != al_it;
                     ++al_it)
                {
                    for (std::map< AssetMetadataMapping*, std::string >::iterator amm_it = asset_metadata_mappings.begin();
                         asset_metadata_mappings.end() != amm_it;
                         ++amm_it)
                    {
                        for (std::map< RankedSearch*, std::string >::iterator rs_it = ranked_searches.begin();
                             ranked_searches.end() != rs_it;
                             ++rs_it)
                        {
                            AccessManagerTestSuite::TestUtilities testUtilities;
                            testUtilities.assetLocator = al_it->first;
                            testUtilities.assetMetadataMapping = amm_it->first;
                            testUtilities.rankedSearch = rs_it->first;
                            testUtilities.className = "AccessManagerImpl{ ";
                            testUtilities.className += al_it->second;
                            testUtilities.className += " ";
                            testUtilities.className += amm_it->second;
                            testUtilities.className += " ";
                            testUtilities.className += rs_it->second;
                            testUtilities.className += "}";

                            AccessManager* am = new AccessManagerImpl( al_it->first, amm_it->first, rs_it->first );
                            access_managers[ am ] = testUtilities; 
                        }
                    }
                }

		// Demonstrates the ability to use multiple test suites
		Test::Suite ts;

                // + Asset Locator Tests
                for (std::map< AssetLocator*, std::string >::iterator it = asset_locators.begin();
                     asset_locators.end() != it;
                     ++it)
                {
                    ts.add(auto_ptr<Test::Suite>(new AssetLocatorTestSuite( it->first, it->second )));
		}

                // + Access Manager Tests
                for (std::map< AccessManager*, AccessManagerTestSuite::TestUtilities >::iterator it = access_managers.begin();
                     access_managers.end() != it;
                     ++it)
                {
                    ts.add(auto_ptr<Test::Suite>(new AccessManagerTestSuite( it->first, it->second )));
		}

		// Run the tests
		auto_ptr<Test::Output> output(cmdline(argc, argv));
		ts.run(*output, true);

                // Teardown
                for (std::map< AssetLocator*, std::string >::iterator it = asset_locators.begin();
                     asset_locators.end() != it;
                     ++it)
                {
                    delete it->first;
                }
	}
	catch (...)
	{
		cout << "unexpected exception encountered\n";
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

