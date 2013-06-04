/*
 * CommandLineTest.cpp
 *
 *  Created on: May 23, 2013
 *      Author: ed
 */

#include "DescriptionInterface.h"
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

	DescriptionInterface di = new DescriptionInterfaceImpl(); 

	cout << "1) removeAsset" << endl;
	cout << "2) addLevelOfDetail" << endl;
	cout << "3) removeLevelOfDetail" << endl;
	cout << "4) updateLevelOfDetail" << endl;
	cout << "5) removeLocation" << endl;
	cout << "6) viewLevelOfDetail" << endl;
	cout << "7) augmentAsset" << endl;
	cout << "8) unaugmentAsset" << endl;
	cout << "9) Quit" << endl;

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


			cout<<"Please enter assetName, lod, and location separated by space"<<endl;

			cin>>pAssetName>>pLOD>>pLocation;

			cout << "Calling removeLevelOfDetail(" << pAssetName <<"," << pLOD << "," << pLocation <<")" << endl;


		 di.removeLevelOfDetail( pAssetName,pLOD,pLocation);




			break;


		case 4:

			cout << "updateLevelOfDetail( std::string assetName, unsigned int lod, std::string location )" << endl;

			cout<<"Please enter assetName, lod, and location separated by space"<<endl;

			cin>>pAssetName>>pLOD>>pLocation;

			cout << "Calling updateLevelOfDetail(" << pAssetName <<"," << pLOD << "," << pLocation <<")" << endl;



			di.updateLevelOfDetail( pAssetName, pLOD, pLocation);


			break;

		case 5:
			cout << "removeLocation( std::string location )" << endl;

			cout<<"Please enter location "<<endl;

			cin>>pLocation;
			cout<< "Calling removeLocation(" << pLocation << ")" << endl;

			  di.removeLocation(pLocation );

			break;

		case 6:
			cout << "viewLevelsOfDetail( std::string assetName )" << endl;

			cout<<"Please enter assetName "<<endl;
			cin>>pAssetName;
			cout<< "Calling viewLevelsOfDetail(" << pAssetName << ")" << endl;

		  di.viewLevelsOfDetail( pAssetName );

			break;

		case 7:
			cout<<"augmentAsset( std::string assetName, std::string metadataName )"<<endl;
			cout<<"Please enter assetName and metadataName seperated by space"<<endl;

			cin>>pAssetName>>pMetadataName;
			cout<< "Calling augmentAsset(" << pAssetName << " ," << pMetadataName <<")" << endl;

	  di.augmentAsset( pAssetName, pMetadataName );

			break;

		case 8:
			cout<<"unaugmentAsset( std::string assetName, std::string metadataName )"<<endl;
			cout<<"Please enter assetName and metadataName seperated by space"<<endl;

			cin>>pAssetName>>pMetadataName;
			cout<< "Calling unaugmentAsset(" << pAssetName << " ," << pMetadataName <<")" << endl;

		 di.unaugmentAsset( pAssetName, pMetadataName );

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

