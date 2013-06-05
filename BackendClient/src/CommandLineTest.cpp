/*
 * CommandLineTest.cpp
 *
 *  Created on: May 23, 2013
 *      Author: ed
 */

#include "DescriptionInterface.h"
#include "DescriptionInterfaceImpl.h"

#include "AccessManager.h"
#include "AccessManagerImpl.h"

#include "CommandLineTest.h"


#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h> 

using namespace cards;
using namespace std; 

int main()
{

	int input;
	string pAssetName, pOldAssetName, pNewAssetName, pMetadataName,pLocation;
	unsigned int pLOD;

        AccessManagerImpl* am = new AccessManagerImpl ();
	IDescriptionImpl di (am); 

	cout << "1) removeAsset" << endl;
	cout << "2) addLevelOfDetail" << endl;
	cout << "3) removeLevelOfDetail" << endl;
	cout << "4) updateLevelOfDetail" << endl;
	cout << "5) viewLevelOfDetail" << endl;
	cout << "6) augmentAsset" << endl;
	cout << "7) unaugmentAsset" << endl;
	cout << "8) Quit" << endl;

	while (true)
	{
		cout << "Enter a command:" << endl;

		cin >> input;

		switch(input)
		{

		case 1:


			cout << "removeAsset( std::string assetName )" << endl;

			cout << "Please enter assetName" << endl;

			cin >> pAssetName;

			cout << "Calling removeAsset(" + pAssetName + ")" << endl;


		di.removeAsset( pAssetName);

			break;

		
		case 2:

			cout << "addLevelOfDetail( std::string assetName, unsigned int lod, std::string location )" << endl;

			cout<<"Please enter assetName, lod, and location separated by space"<<endl;

			cin>>pAssetName>>pLOD>>pLocation;

			cout << "Calling addLevelOfDetail(" << pAssetName <<"," << pLOD << "," << pLocation <<")" << endl;


		di.addLevelOfDetail( pAssetName, pLOD, pLocation); 



			break;

		case 3:


			cout << "removeLevelOfDetail( std::string assetName, unsigned int lod )" << endl;


			cout<<"Please enter assetName and lod separated by space"<<endl;

			cin>>pAssetName>>pLOD;

			cout << "Calling removeLevelOfDetail(" << pAssetName <<"," << pLOD << ")" << endl;


		 di.removeLevelOfDetail( pAssetName,pLOD);




			break;


		case 4:

			cout << "updateLevelOfDetail( std::string assetName, unsigned int lod, std::string location )" << endl;

			cout<<"Please enter assetName, lod, and location separated by space"<<endl;

			cin>>pAssetName>>pLOD>>pLocation;

			cout << "Calling updateLevelOfDetail(" << pAssetName <<"," << pLOD << "," << pLocation <<")" << endl;



			di.updateLevelOfDetail( pAssetName, pLOD, pLocation);


			break;


		case 5:
			cout << "viewLevelsOfDetail( std::string assetName )" << endl;

			cout<<"Please enter assetName "<<endl;
			cin>>pAssetName;
			cout<< "Calling viewLevelsOfDetail(" << pAssetName << ")" << endl;

		  di.viewLevelsOfDetail( pAssetName );

			break;

		case 6:
			cout<<"augmentAsset( std::string assetName, std::string metadataName )"<<endl;
			cout<<"Please enter assetName and metadataName seperated by space"<<endl;

			cin>>pAssetName>>pMetadataName;
			cout<< "Calling augmentAsset(" << pAssetName << " ," << pMetadataName <<")" << endl;

	  di.augmentAsset( pAssetName, pMetadataName );

			break;

		case 7:
			cout<<"unaugmentAsset( std::string assetName, std::string metadataName )"<<endl;
			cout<<"Please enter assetName and metadataName seperated by space"<<endl;

			cin>>pAssetName>>pMetadataName;
			cout<< "Calling unaugmentAsset(" << pAssetName << " ," << pMetadataName <<")" << endl;

		 di.unaugmentAsset( pAssetName, pMetadataName );

			break;
		case 8:

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

