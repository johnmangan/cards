#include <assert.h>
#include <osgDB/ReadFile>
#include "CardsNode.h"

CardsNode::CardsNode( std::map<std::string, int>& tagsWithWeights )
{
	mHasGeom = false;
	Load(tagsWithWeights);
}

void
CardsNode::Load( std::map<std::string, int>& tagsWithWeights )
{
	std::vector<std::string> files;
	QueryCardsForFiles(tagsWithWeights, files);

	if (files.empty())
		return;

	// Create geom.... the vector of files starts with the lowest LOD model and ends with the highest LOD

	// some hard coded ranges
	assert (files.size() <= 3);
	float lod_max[3] = {1000000.f, 50.f, 20.f};
	float lod_min[3] = {50.f, 20.f, 0.f};

	for (unsigned int i = 0; i < files.size(); i++)
	{
		osg::ref_ptr<osg::Node> model( osgDB::readNodeFile(files[i]) );

		// WARNING:: dumb code here
		if (3 == files.size())
			this->addChild(model, lod_min[i], lod_max[i]);
		else if (2 == files.size())
			this->addChild(model, lod_min[i+1], lod_max[i]);
		else if (1 == files.size())
			this->addChild(model, lod_min[i+2], lod_max[i]);

	}

	mHasGeom = true;
}

void
CardsNode::QueryCardsForFiles(std::map<std::string, int>& tagsWithWeights, std::vector<std::string>& filesOut)
{
	if (!tagsWithWeights.empty())
	{
		std::cout << "Passing to cards:" << std::endl;
		for (std::map<std::string, int>::iterator iter = tagsWithWeights.begin();
			 iter != tagsWithWeights.end();
			 ++iter )
			std::cout << iter->first << "\t" << iter->second << std::endl;
		std::cout << std::endl;


		filesOut = mCards.getFilepaths(tagsWithWeights);

		if (!filesOut.empty())
		{
			std::cout << "CARDS returned:" << std::endl;
			for (unsigned int i = 0; i < filesOut.size(); i++)
				std::cout << filesOut[i] << std::endl;
			std::cout << std::endl;
		}
		else
			std::cout << "CARDS returned nothing." << std::endl << std::endl;
	}

//	for (std::map<std::string, int>::iterator iter = tagsWithWeights.begin();
//		 iter != tagsWithWeights.end();
//		 ++iter)
//	{
//		if ( "boulder" == iter->first)
//		{
//			filesOut.push_back("/home/david/Desktop/CARDS_Models/Boulder/boulder_low.fbx");
//			filesOut.push_back("/home/david/Desktop/CARDS_Models/Boulder/boulder_high.FBX");
//		}
//		else if ( "castle" == iter->first)
//		{
//			filesOut.push_back("/home/david/Desktop/CARDS_Models/Castle/castle.FBX");
//		}
//		else if ( "cube" == iter->first)
//		{
//			filesOut.push_back("/home/david/Desktop/CARDS_Models/Cube/cube_12.obj");
//		}
//		else if ( "palm" == iter->first)
//		{
//			filesOut.push_back("/home/david/Desktop/CARDS_Models/PalmTree/palm_tree.FBX");
//		}
//		else if ( "peach" == iter->first)
//		{
//			filesOut.push_back("/home/david/Desktop/CARDS_Models/PeachTree/peach_tree_low.FBX");
//			filesOut.push_back("/home/david/Desktop/CARDS_Models/PeachTree/peach_tree_mid.FBX");
//			filesOut.push_back("/home/david/Desktop/CARDS_Models/PeachTree/peach_tree_high.FBX");
//		}
//		else if ( "pine" == iter->first)
//		{
//			filesOut.push_back("/home/david/Desktop/CARDS_Models/PineTree/pine_tree_low.FBX");
//			filesOut.push_back("/home/david/Desktop/CARDS_Models/PineTree/pine_tree_mid.FBX");
//			filesOut.push_back("/home/david/Desktop/CARDS_Models/PineTree/pine_tree_high.FBX");
//		}
//		else if ( "sand" == iter->first)
//		{
//			filesOut.push_back("/home/david/Desktop/CARDS_Models/SandCastle/sand_castle.FBX");
//		}
//		else if ( "sphere" == iter->first)
//		{
//			filesOut.push_back("/home/david/Desktop/CARDS_Models/Sphere/unit_sphere_low_8.obj");
//			filesOut.push_back("/home/david/Desktop/CARDS_Models/Sphere/unit_sphere_mid_48.obj");
//			filesOut.push_back("/home/david/Desktop/CARDS_Models/Sphere/unit_sphere_high_840.obj");
//		}
//		else if ( "torus" == iter->first)
//		{
//			filesOut.push_back("/home/david/Desktop/CARDS_Models/Torus/torus_low_36.obj");
//			filesOut.push_back("/home/david/Desktop/CARDS_Models/Torus/torus_mid_150.obj");
//			filesOut.push_back("/home/david/Desktop/CARDS_Models/Torus/torus_high_624.obj");
//		}
//		else if ( "tree" == iter->first)
//		{
//			filesOut.push_back("/home/david/Desktop/CARDS_Models/TreeHouse/tree_house.FBX");
//		}
//	}

	return;
}
