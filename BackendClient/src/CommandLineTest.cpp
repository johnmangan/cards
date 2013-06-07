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
#include <string>
#include <stdlib.h> 
#include <vector> 

using namespace cards;
using namespace std; 

CommandLineTest::CommandLineTest( IDescription* iDesc )
: di( iDesc )
{
}

void CommandLineTest::printMenu()
{

	cout << "1) remove Asset" << "\t" << "Get LODs of Assets" <<  endl;
	cout << "2) add LOD to Asset" << endl;
	cout << "3) remove LOD from Asset" << endl;
	cout << "4) update LOD of Asset" << endl;
	cout << "5) getLevelOfDetail" << endl;
	cout << "6) augmentAsset" << endl;
	cout << "7) unaugmentAsset" << endl;
	//cout << "8) Print Menu" << endl; 
	cout << "8) Quit" << endl;
}

void CommandLineTest::handleInput(int & input)
{

	string mAssetName, mOldAssetName, mNewAssetName, mMetadataName,mLocation;
	unsigned int pLOD;

	vector<string> LODVector;

        //AccessManagerImpl* am = new AccessManagerImpl ();

	cout << "Enter a command:" << endl;


	cin >> input;

	switch(input)
	{
		case 1:

		cout << "removeAsset" << endl;

		cout << "Please enter assetName" << endl;

		cin >> mAssetName;

		di->removeAsset( mAssetName);

		break;

		case 2:

		cout << "addLevelOfDetail" << endl; 

		cout<<"Please enter assetName, lod, and location separated by space"<<endl;

		cin>>mAssetName>>pLOD>>mLocation;

cout << di <<  endl; 
		di->addLevelOfDetail( mAssetName, pLOD, mLocation); 



		break;

		case 3:

		cout << "removeLevelOfDetail" << endl; 

		cout<<"Please enter assetName and lod separated by space"<<endl;

		cin>>mAssetName>>pLOD;

	
		 di->removeLevelOfDetail( mAssetName,pLOD);

		break;


		case 4:

		cout << "updateLevelOfDetail" << endl; 

			
		cout<<"Please enter assetName, lod, and location separated by space"<<endl;

		cin>>mAssetName>>pLOD>>mLocation;

		di->updateLevelOfDetail( mAssetName, pLOD, mLocation);

		break;

		case 5:

		cout << "getLevelsOfDetail" << endl; 

		cout<<"Please enter assetName "<<endl;
		cin>>mAssetName;



		LODVector =  di->getLevelsOfDetail( mAssetName );


cout << di << "\t" << LODVector.size() << endl; 
		for(unsigned int i = 0; i < LODVector.size(); ++i)
		{
		    cout<< i << ": " << LODVector[i]<<endl;    
		}

		break;

		case 6:

		cout << "augmentAsset" << endl; 

		cout<<"Please enter assetName and metadataName seperated by space"<<endl;

		cin>>mAssetName>>mMetadataName;

		di->augmentAsset( mAssetName, mMetadataName );

		break;

		case 7:
			
		cout << "unaugmentAsset" << endl; 
		
cout<<"Please enter assetName and metadataName seperated by space"<<endl;

		cin>>mAssetName>>mMetadataName;
		
		di->unaugmentAsset( mAssetName, mMetadataName );

		break;
		
		case 8:

			cout << "Quitting CommandLine" << endl;
			exit(0);

			break; 

		default:

			cout << "Number not found" << endl;
		
	}

}

int main()
{
	CommandLineTest command_line_test( new IDescriptionImpl() ); 

	int input; 
	//int QuitChoice = 9; 
	while(true)
	{
	    command_line_test.printMenu();
	    command_line_test.handleInput(input); 
	} 
}


/*

int main()
{

	int input;
	string mAssetName, mOldAssetName, mNewAssetName, mMetadataName,mLocation;
	unsigned int pLOD;

	vector<string> LODVector;
	vector<string>::iterator LODIterator;

        //AccessManagerImpl* am = new AccessManagerImpl ();
	IDescriptionImpl* di = new IDescriptionImpl(); 

	cout << "1) removeAsset" << endl;
	cout << "2) addLevelOfDetail" << endl;
	cout << "3) removeLevelOfDetail" << endl;
	cout << "4) updateLevelOfDetail" << endl;
	cout << "5) getLevelOfDetail" << endl;
	cout << "6) augmentAsset" << endl;
	cout << "7) unaugmentAsset" << endl;
	cout << "8) Print Menu" << endl; 
	cout << "9) Quit" << endl;

	while (true)
	{
		cout << "Enter a command:" << endl;

		cin >> input;

		switch(input)
		{

		case 1:

		cout << "removeAsset" << endl;

		//	cout << "removeAsset( std::string assetName )" << endl;

			cout << "Please enter assetName" << endl;

			cin >> mAssetName;

		//	cout << "Calling removeAsset(" + mAssetName + ")" << endl;


		di->removeAsset( mAssetName);

			break;

		
		case 2:

cout << "addLevelOfDetail" << endl; 

			//cout << "addLevelOfDetail( std::string assetName, unsigned int lod, std::string location )" << endl;

			cout<<"Please enter assetName, lod, and location separated by space"<<endl;

			cin>>mAssetName>>pLOD>>mLocation;

		//	cout << "Calling addLevelOfDetail(" << mAssetName <<"," << pLOD << "," << mLocation <<")" << endl;


		di->addLevelOfDetail( mAssetName, pLOD, mLocation); 



			break;

		case 3:

cout << "removeLevelOfDetail" << endl; 


			cout << "removeLevelOfDetail( std::string assetName, unsigned int lod )" << endl;


			cout<<"Please enter assetName and lod separated by space"<<endl;

			cin>>mAssetName>>pLOD;

		//	cout << "Calling removeLevelOfDetail(" << mAssetName <<"," << pLOD << ")" << endl;


		 di->removeLevelOfDetail( mAssetName,pLOD);




			break;


		case 4:

cout << "updateLevelOfDetail" << endl; 

			//cout << "updateLevelOfDetail( std::string assetName, unsigned int lod, std::string location )" << endl;

			cout<<"Please enter assetName, lod, and location separated by space"<<endl;

			cin>>mAssetName>>pLOD>>mLocation;

		//	cout << "Calling updateLevelOfDetail(" << mAssetName <<"," << pLOD << "," << mLocation <<")" << endl;



			di->updateLevelOfDetail( mAssetName, pLOD, mLocation);


			break;


		case 5:

cout << "getLevelsOfDetail" << endl; 

		//	cout << "getLevelsOfDetail( std::string assetName )" << endl;

			cout<<"Please enter assetName "<<endl;
			cin>>mAssetName;
		//	cout<< "Calling getLevelsOfDetail(" << mAssetName << ")" << endl;



	LODVector =  di->getLevelsOfDetail( mAssetName );

	for(LODIterator = LODVector.begin(); 
		LODIterator != LODVector.end();
		LODIterator++)
	{
	    cout<< LODIterator - LODVector.begin() << " " << *LODIterator<<endl;    
	}

			break;

		case 6:

cout << "augmentAsset" << endl; 

		//	cout<<"augmentAsset( std::string assetName, std::string metadataName )"<<endl;
			cout<<"Please enter assetName and metadataName seperated by space"<<endl;

			cin>>mAssetName>>mMetadataName;
		//	cout<< "Calling augmentAsset(" << mAssetName << " ," << mMetadataName <<")" << endl;

	  di->augmentAsset( mAssetName, mMetadataName );

			break;

		case 7:
			
cout << "unaugmentAsset" << endl; 
//cout<<"unaugmentAsset( std::string assetName, std::string metadataName )"<<endl;
			cout<<"Please enter assetName and metadataName seperated by space"<<endl;

			cin>>mAssetName>>mMetadataName;
		//	cout<< "Calling unaugmentAsset(" << mAssetName << " ," << mMetadataName <<")" << endl;

		 di->unaugmentAsset( mAssetName, mMetadataName );

			break;

		case 8:

			cout << "1) removeAsset" << endl;
			cout << "2) addLevelOfDetail" << endl;
			cout << "3) removeLevelOfDetail" << endl;
			cout << "4) updateLevelOfDetail" << endl;
			cout << "5) getLevelOfDetail" << endl;
			cout << "6) augmentAsset" << endl;
			cout << "7) unaugmentAsset" << endl;
			cout << "8) Print Menu" << endl; 
			cout << "9) Quit" << endl;

			break; 

		case 9:

			cout << "Quitting CommandLineTest" << endl;
			exit(0);

			break;

		

			 

		default:

			cout << "Number not found" << endl;
			continue;

		}

	}

		return 0;
	}
*/
