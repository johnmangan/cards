/*
 * CommandLineTest.cpp
 *
 *  Created on: May 23, 2013
 *      Author: ed
 */

#include <AccessManagerImpl.h>
#include <DescriptionInterfaceImpl.h>


#include <CommandLineTest.h>


#include <stdio.h>
#include <iostream>
#include <sstream>
#include <stdlib.h> 
#include <iomanip>

using namespace cards;
using namespace std; 

CommandLineTest::CommandLineTest( IDescription* iDesc )
: di( iDesc )
{
    options.push_back("Remove Asset");
    options.push_back("Add LOD to Asset");
    options.push_back("Remove LOD from Asset");
    options.push_back("Update LOD of Asset");
    options.push_back("Get LODs of Asset");
    options.push_back("Augment Asset with Metadata");
    options.push_back("Unaugment Metadata from Asset");
    options.push_back("Quit");
}

void CommandLineTest::printMenu()
{
    unsigned int longest_option = 0;
    for (unsigned int i = 0; i < options.size(); ++i)
        if (options[i].length() > longest_option)
            longest_option = options[i].length();

    for (unsigned int i = 0; i < (options.size() + 1) / 2; ++i)
    {
        cout << '|' << i << "| " << left << setfill(' ') << setw(longest_option) << options[i] << ' ';

        unsigned int j = i + options.size()/2;
        if (j == options.size())
        {
            cout << endl;
            break;
        }

        cout << '|' << j << "| " << left << setfill(' ') << setw(longest_option) << options[j] << endl;
    }
    cout << endl;
}

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

void CommandLineTest::handleInput(unsigned int& input)
{

	string mAssetName, mOldAssetName, mNewAssetName, mMetadataName,mLocation;
	unsigned int pLOD;

	vector<string> LODVector;

        //AccessManagerImpl* am = new AccessManagerImpl ();

	cout << "Enter a command:" << endl;

	
	string inputString; 

	cin >> inputString;

	if (!is_number(inputString))
	{
		input = 8;
	}
	else
	{
		input = atoi(inputString.c_str()); 
	}

        if (input < options.size())
            cout << options[input] << endl << setfill('-') << setw(options[input].length()) << "-" << endl;

	switch(input)
	{
		case 0:

		cout << "Please enter assetName" << endl;

		cin >> mAssetName;

		di->removeAsset( mAssetName);

		break;

		case 1:

		cout<<"Please enter assetName, lod, and location separated by space"<<endl;

		

		cin>>mAssetName>>pLOD>>mLocation;

		di->addLevelOfDetail( mAssetName, pLOD, mLocation); 



		break;

		case 2:

		cout<<"Please enter assetName and lod separated by space"<<endl;

		cin>>mAssetName>>pLOD;

	
		 di->removeLevelOfDetail( mAssetName,pLOD);

		break;


		case 3:

		cout<<"Please enter assetName, lod, and location separated by space"<<endl;

		cin>>mAssetName>>pLOD>>mLocation;

		di->updateLevelOfDetail( mAssetName, pLOD, mLocation);

		break;

		case 4:

		cout<<"Please enter assetName "<<endl;
		cin>>mAssetName;



		LODVector =  di->getLevelsOfDetail( mAssetName );


		for(unsigned int i = 0; i < LODVector.size(); ++i)
		{
		    cout<< i << ": " << LODVector[i]<<endl;    
		}

		break;

		case 5:

		cout<<"Please enter assetName and metadataName seperated by space"<<endl;

		cin>>mAssetName>>mMetadataName;

		di->augmentAsset( mAssetName, mMetadataName );

		break;

		case 6:
		cout<<"Please enter assetName and metadataName seperated by space"<<endl;

		cin>>mAssetName>>mMetadataName;
		
		di->unaugmentAsset( mAssetName, mMetadataName );

		break;
		
		case 7:

			exit(0);

			break; 

		default:

			cout << "Command not found" << endl;
		
	}

}

int main()
{
	CommandLineTest command_line_test( new IDescriptionImpl() ); 

	unsigned int input; 
	//int QuitChoice = 9; 
	while(true)
	{
	    command_line_test.printMenu();
	    command_line_test.handleInput(input); 
	} 
}

