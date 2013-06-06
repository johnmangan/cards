#include <iostream>
#include <cstdlib>
#include <cstring>

#include <AssetLocatorMemoryImpl.h>
#include <AssetLocatorDatabaseImpl.h>
#include <AccessManagerImpl.h>
#include <AssetMetadataMappingMemoryImpl.h>
#include <RankedSearchImpl.h>
#include <QueryInterfaceImpl.h>

#include "test-accessmanager.hpp"
#include "test-assetlocator.hpp"
#include "test-assetmetadatamapping.hpp"
#include "test-queryinterface.hpp"
#include "test-rankedsearch.hpp"

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
                map< AssetLocator*, string > unit_asset_locators;
                unit_asset_locators[ new AssetLocatorMemoryImpl ] = "AssetLocatorMemoryImpl";
                unit_asset_locators[ new AssetLocatorDatabaseImpl ] = "AssetLocatorDatabaseImpl";

                map< AssetMetadataMapping*, string > unit_asset_metadata_mappings;
                unit_asset_metadata_mappings[ new AssetMetadataMappingMemoryImpl ] = "AssetMetadataMappingMemoryImpl";

                map< RankedSearch*, RankedSearchTestSuite::TestUtilities > unit_ranked_searches;
                {
                    RankedSearchTestSuite::TestUtilities testUtilities;
                    testUtilities.className = "RankedSearchImpl{ AccessManagerImpl }";
                    testUtilities.accessManager = new AccessManagerImpl;

                    RankedSearch* rs = new RankedSearchImpl;
                    rs->setAccessManager( testUtilities.accessManager );

                    unit_ranked_searches[ rs ] = testUtilities;
                }


                map< RankedSearch*, RankedSearchTestSuite::TestUtilities > integration_ranked_searches;
                for (map< AssetMetadataMapping*, string >::iterator amm_it = unit_asset_metadata_mappings.begin();
                    unit_asset_metadata_mappings.end() != amm_it;
                    ++amm_it)
                {
                    RankedSearchTestSuite::TestUtilities testUtilities;
                    testUtilities.className = "RankedSearchImpl{ AccessManagerImpl(NULL, ";
                    testUtilities.className += amm_it->second;
		    testUtilities.className += ", NULL) }";
                    testUtilities.accessManager = new AccessManagerImpl(NULL, amm_it->first, NULL);

                    RankedSearch* rs = new RankedSearchImpl;
                    rs->setAccessManager( testUtilities.accessManager );

                    integration_ranked_searches[ rs ] = testUtilities;
                }

                map< AccessManager*, AccessManagerTestSuite::TestUtilities > unit_access_managers;
                for (map< AssetLocator*, string >::iterator al_it = unit_asset_locators.begin();
                     unit_asset_locators.end() != al_it;
                     ++al_it)
                {
                    for (map< AssetMetadataMapping*, string >::iterator amm_it = unit_asset_metadata_mappings.begin();
                         unit_asset_metadata_mappings.end() != amm_it;
                         ++amm_it)
                    {
                        for (map< RankedSearch*, RankedSearchTestSuite::TestUtilities >::iterator rs_it = unit_ranked_searches.begin();
                             unit_ranked_searches.end() != rs_it;
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
                            testUtilities.className += rs_it->second.className;
                            testUtilities.className += " }";

                            AccessManager* am = new AccessManagerImpl( al_it->first, amm_it->first, rs_it->first );
                            unit_access_managers[ am ] = testUtilities; 
                        }
                    }
                }

                map< IQuery*, QueryInterfaceTestSuite::TestUtilities > unit_query_interfaces;
                {
                    QueryInterfaceTestSuite::TestUtilities testUtilities;
                    testUtilities.className = "IQueryImpl{ AccessManagerImpl }";
                    testUtilities.accessManager = new AccessManagerImpl;

                    unit_query_interfaces[ new IQueryImpl( testUtilities.accessManager ) ] = testUtilities;
                }

                map< IQuery*, QueryInterfaceTestSuite::TestUtilities > integration_query_interfaces;
                for (std::map< AccessManager*, AccessManagerTestSuite::TestUtilities >::iterator am_it = unit_access_managers.begin();
                    unit_access_managers.end() != am_it;
                    ++am_it)
                {
                    QueryInterfaceTestSuite::TestUtilities testUtilities;
                    testUtilities.className = "QueryInterfaceImpl{ ";
                    testUtilities.className += am_it->second.className;
		    testUtilities.className += " }";
                    testUtilities.accessManager = am_it->first;

                    IQuery* qi = new IQueryImpl( testUtilities.accessManager );

                    integration_query_interfaces[ qi ] = testUtilities;
                }

		// Demonstrates the ability to use multiple test suites
		Test::Suite ts;

                // + Asset Locator Tests
                for (map< AssetLocator*, string >::iterator it = unit_asset_locators.begin();
                     unit_asset_locators.end() != it;
                     ++it)
                {
                    ts.add(auto_ptr<Test::Suite>(new AssetLocatorTestSuite( it->first, it->second )));
		}

                // + Asset Metadata Mapping Tests
                for (map< AssetMetadataMapping*, string >::iterator it = unit_asset_metadata_mappings.begin();
                     unit_asset_metadata_mappings.end() != it;
                     ++it)
                {
                    ts.add(auto_ptr<Test::Suite>(new AssetMetadataMappingTestSuite( it->first, it->second )));
		}

                // + Ranked Search Tests
                for (map< RankedSearch*, RankedSearchTestSuite::TestUtilities >::iterator it = unit_ranked_searches.begin();
                     unit_ranked_searches.end() != it;
                     ++it)
                {
                    ts.add(auto_ptr<Test::Suite>(new RankedSearchTestSuite( it->first, it->second )));
		}

                for (map< RankedSearch*, RankedSearchTestSuite::TestUtilities >::iterator it = integration_ranked_searches.begin();
                     integration_ranked_searches.end() != it;
                     ++it)
                {
                    ts.add(auto_ptr<Test::Suite>(new RankedSearchTestSuite( it->first, it->second )));
		}

                // + Access Manager Tests
                for (map< AccessManager*, AccessManagerTestSuite::TestUtilities >::iterator it = unit_access_managers.begin();
                     unit_access_managers.end() != it;
                     ++it)
                {
                    ts.add(auto_ptr<Test::Suite>(new AccessManagerTestSuite( it->first, it->second )));
		}

                // + Query Interface Tests
                for (map< IQuery*, QueryInterfaceTestSuite::TestUtilities >::iterator it = unit_query_interfaces.begin();
                     unit_query_interfaces.end() != it;
                     ++it)
                {
                    ts.add(auto_ptr<Test::Suite>(new QueryInterfaceTestSuite( it->first, it->second )));
		}


                for (map< IQuery*, QueryInterfaceTestSuite::TestUtilities >::iterator it = integration_query_interfaces.begin();
                     integration_query_interfaces.end() != it;
                     ++it)
                {
                    ts.add(auto_ptr<Test::Suite>(new QueryInterfaceTestSuite( it->first, it->second )));
		}

		// Run the tests
		auto_ptr<Test::Output> output(cmdline(argc, argv));
		ts.run(*output, true);

                // Teardown
                for (map< AssetLocator*, string >::iterator it = unit_asset_locators.begin();
                     unit_asset_locators.end() != it;
                     ++it)
                {
                    delete it->first;
                }

                for (map< AssetMetadataMapping*, string >::iterator it = unit_asset_metadata_mappings.begin();
                     unit_asset_metadata_mappings.end() != it;
                     ++it)
                {
                    delete it->first;
                }

                for (map< RankedSearch*, RankedSearchTestSuite::TestUtilities >::iterator it = unit_ranked_searches.begin();
                     unit_ranked_searches.end() != it;
                     ++it)
                {
                    delete it->first;
                }

                for (map< RankedSearch*, RankedSearchTestSuite::TestUtilities >::iterator it = integration_ranked_searches.begin();
                     integration_ranked_searches.end() != it;
                     ++it)
                {
                    delete it->first;
                }

                for (map< AccessManager*, AccessManagerTestSuite::TestUtilities >::iterator it = unit_access_managers.begin();
                     unit_access_managers.end() != it;
                     ++it)
                {
                    delete it->first;
                }

                for (map< IQuery*, QueryInterfaceTestSuite::TestUtilities >::iterator it = unit_query_interfaces.begin();
                     unit_query_interfaces.end() != it;
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

