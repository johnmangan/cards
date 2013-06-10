#include <iostream>
#include <sstream>
#include <assert.h>
#include <cvrKernel/ScreenBase.h>
#include <cvrConfig/ConfigManager.h>
#include <cvrKernel/PluginHelper.h>
#include <cvrUtil/Intersection.h>
#include "CardsClient.h"

using namespace cvr;

CVRPLUGIN(CardsClient)


CardsClient::CardsClient()
{
	mPluginSubMenu = NULL;
	mSetTags = NULL;
	mFloorPlane = NULL;
	mResetScene = NULL;
	mFinalSceneSubMenu = NULL;
	mSetTerrainTags = NULL;
	mSetBuildingTags = NULL;
	mSetVegetationTags = NULL;
	mCreateScene = NULL;
}

/*virtual*/
CardsClient::~CardsClient()
{
	if (mPluginSubMenu)
		delete mPluginSubMenu;
	
	if (mSetTags)
		delete mSetTags;

	if (mFloorPlane)
		delete mFloorPlane;

	if (mResetScene)
		delete mResetScene;

	if (mFinalSceneSubMenu)
		delete mFinalSceneSubMenu;

	if (mSetTerrainTags)
		delete mSetTerrainTags;

	if (mSetBuildingTags)
		delete mSetBuildingTags;

	if (mSetVegetationTags)
		delete mSetVegetationTags;

	if (mCreateScene)
		delete mCreateScene;

	FreeCreatedSos();
}

void
CardsClient::FreeCreatedSos(void)
{
	for (std::list<cvr::SceneObject*>::iterator iter = mCreatedSos.begin();
		 iter != mCreatedSos.end();
		 ++iter)
		if (*iter)
			delete *iter;

	mCreatedSos.clear();
}

bool
CardsClient::init()
{
	// MENU
	mPluginSubMenu = new cvr::SubMenu("CARDS", "CARDS");
	mSetTags = new cvr::MenuButton("Set Tags");
	mSetTags->setCallback(this);
	mResetScene = new cvr::MenuButton("Reset Scene");
	mResetScene->setCallback(this);

	mFinalSceneSubMenu = new cvr::SubMenu("FINAL SCENE", "FINAL SCENE");
	mSetTerrainTags = new cvr::MenuButton("Set Terrain Tags");
	mSetTerrainTags->setCallback(this);
	mSetBuildingTags = new cvr::MenuButton("Set Building Tags");
	mSetBuildingTags->setCallback(this);
	mSetVegetationTags = new cvr::MenuButton("Set Vegetation Tags");
	mSetVegetationTags->setCallback(this);
	mCreateScene = new cvr::MenuButton("Create Scene");
	mCreateScene->setCallback(this);

	cvr::PluginHelper::addRootMenuItem(mPluginSubMenu);
	mPluginSubMenu->addItem(mSetTags);
	mPluginSubMenu->addItem(mResetScene);

	mPluginSubMenu->addItem(mFinalSceneSubMenu);
	mFinalSceneSubMenu->addItem(mSetTerrainTags);
	mFinalSceneSubMenu->addItem(mSetBuildingTags);
	mFinalSceneSubMenu->addItem(mSetVegetationTags);
	mFinalSceneSubMenu->addItem(mCreateScene);


	// FLOOR PLANE
	mFloorPlane = new cvr::SceneObject("Floor Plane", true, false, true, false, true);

	osg::ref_ptr<osg::Geode> plane_geode( new osg::Geode() );
	osg::ref_ptr<osg::Geometry> plane_geometry( new osg::Geometry() );
	plane_geode->addDrawable(plane_geometry);

	osg::ref_ptr<osg::Vec3Array> verts( new osg::Vec3Array );
	verts->push_back( osg::Vec3( -500, 500, -10) ); // front left
	verts->push_back( osg::Vec3(500, 500, -10) ); // front right
	verts->push_back( osg::Vec3(500,-500, -10) ); // back right
	verts->push_back( osg::Vec3(-500,-500, -10) ); // back left
	plane_geometry->setVertexArray( verts );

	osg::ref_ptr<osg::DrawElementsUInt> indices( new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0) );
	indices->push_back(0);
	indices->push_back(1);
	indices->push_back(2);
	indices->push_back(3);
	plane_geometry->addPrimitiveSet(indices);

	osg::ref_ptr<osg::Vec4Array> colors( new osg::Vec4Array );
	colors->push_back(osg::Vec4(0.1f, 0.1f, 0.43f, 1.0f) );
	plane_geometry->setColorBinding(osg::Geometry::BIND_OVERALL);
	plane_geometry->setColorArray(colors);

	mFloorPlane->addChild(plane_geode);
	cvr::PluginHelper::registerSceneObject(mFloorPlane, "CardsClient");
	mFloorPlane->attachToScene();
	mFloorAttached = true;

    return true;
}

void
CardsClient::AskForTags(std::map<std::string, int>& tags)
{
	std::string input;
	do
	{
		std::string tag = "";
		int weight = 0;
		std::cout << "Enter tags ('f' to finish): ";
		std::cin >> input;
		tag = input;
		if ("f" == input)
			break;

		tags[tag] = 1;
	} while ("f" != input);
}

void
CardsClient::menuCallback(cvr::MenuItem* item)
{
	if (mSetTags == item)
	{
		// Acquire tags and values
		std::map<std::string, int> tags;

		AskForTags(tags);
		if (!tags.empty())
		{
			mCurrentCardsNode = new CardsNode(tags);

			if (!mCurrentCardsNode->HasGeometry())
				mCurrentCardsNode = NULL;
		}
	}
	else if (mResetScene == item)
	{
		FreeCreatedSos();
		if (!mFloorAttached && mFloorPlane)
		{
			mFloorPlane->attachToScene();
			mFloorAttached = true;
		}

	}
	else if (mSetTerrainTags == item)
	{
		mTerrainTags.clear();
		AskForTags(mTerrainTags);
	}
	else if (mSetVegetationTags == item)
	{
		mVegetationTags.clear();
		AskForTags(mVegetationTags);
	}
	else if (mSetBuildingTags == item)
	{
		mBuildingTags.clear();
		AskForTags(mBuildingTags);
	}
	else if (mCreateScene == item)
	{
		FreeCreatedSos();

		if (!mBuildingTags.empty())
		{
			mBuildingNode = new CardsNode(mBuildingTags);
			if (!mBuildingNode->HasGeometry())
				mBuildingNode = NULL;
		}
		else
			mBuildingNode = NULL;

		if (!mTerrainTags.empty())
		{
			mTerrainNode = new CardsNode(mTerrainTags);
			if (!mTerrainNode->HasGeometry())
				mTerrainNode = NULL;
		}
		else
			mTerrainNode = NULL;

		if (!mVegetationTags.empty())
		{
			mVegetationNode = new CardsNode(mVegetationTags);
			if (!mVegetationNode->HasGeometry())
				mVegetationNode = NULL;
		}
		else
			mVegetationNode = NULL;

		if (mFloorAttached && mFloorPlane)
		{
			mFloorPlane->detachFromScene();
			mFloorAttached = false;
		}

		osg::Quat rot(osg::PI/2, osg::Vec3(1,0,0));
//		rot *= osg::Quat(osg::PI/4, osg::Vec3(0,0,1));

		if (mBuildingNode.valid())
		{
			cvr::SceneObject* building_so = new cvr::SceneObject("Scene Object", true, false, false, false, false);
			building_so->setRotation(rot);
			building_so->setScale(0.5f);
			building_so->addChild(mBuildingNode);
			building_so->setPosition(osg::Vec3f(0.f, 0.f, 0.f));
			cvr::PluginHelper::registerSceneObject(building_so, "CardsClient");
			building_so->attachToScene();
			mCreatedSos.push_back(building_so);
		}

		if (mTerrainNode.valid())
		{
			cvr::SceneObject* terrain_so = new cvr::SceneObject("Scene Object", true, false, false, false, false);
			terrain_so->setRotation(rot);
			terrain_so->setScale(0.5f);
			terrain_so->addChild(mTerrainNode);
			terrain_so->setPosition(osg::Vec3f(0.f, 0.f, 0.f));
			cvr::PluginHelper::registerSceneObject(terrain_so, "CardsClient");
			terrain_so->attachToScene();
			mCreatedSos.push_back(terrain_so);
		}

		if (mVegetationNode.valid())
		{
			cvr::SceneObject* vegetation_so = new cvr::SceneObject("Scene Object", true, false, false, false, false);
			vegetation_so->setRotation(rot);
			vegetation_so->setScale(0.5f);
			vegetation_so->addChild(mVegetationNode);
			vegetation_so->setPosition(osg::Vec3f(0.f, 0.f, 0.f));
			cvr::PluginHelper::registerSceneObject(vegetation_so, "CardsClient");
			vegetation_so->attachToScene();
			mCreatedSos.push_back(vegetation_so);
		}

	}
}

/*virtual*/ void
CardsClient::preFrame()
{

}

bool
CardsClient::IntersectWithFloorPlane(osg::Vec3& posOut)
{
	osg::Vec3 pointer_start, pointer_end;
	std::vector<IsectInfo> isecvec;

	pointer_start = cvr::PluginHelper::getHandMat(0).getTrans();
	pointer_end.set(0.0f, 1000000.0f, 0.0f);
	pointer_end = pointer_end * cvr::PluginHelper::getHandMat(0);

	isecvec = CVRUTIL_EXPORT::getObjectIntersection(cvr::PluginHelper::getScene(), pointer_start, pointer_end);

	if (isecvec.size() > 0 )
	{
		for (unsigned int i = 0; i < isecvec.size(); i++)
		{
			if (mFloorPlane->getChildNode(0) == isecvec[i].geode)
			{
				posOut = isecvec[0].point * cvr::SceneManager::instance()->getWorldToObjectTransform();
//				std::cerr << pos.x() << "\t" <<
//							 pos.y() << "\t" <<
//							 pos.z() << "\n";
				return true;
			}
		}
	}

	return false;
}

/*virtual*/ void
CardsClient::postFrame()
{
	
}

bool
CardsClient::processEvent(cvr::InteractionEvent* event)
{
	cvr::KeyboardInteractionEvent* keyboard = event->asKeyboardEvent();

	if (keyboard)
	{
		if (osgGA::GUIEventAdapter::KEY_Space == keyboard->getKey())
		{
			static double last_frame_time = 0.0;

			double elapsed = cvr::PluginHelper::getFrameStartTime() - last_frame_time;
			if (elapsed > 0.33f)
			{
				if (!mCurrentCardsNode.valid())
					std::cerr << "No model found from provided tags!\n";
				else
				{
					osg::Vec3 pos;
					if (IntersectWithFloorPlane(pos))
					{
						cvr::SceneObject* new_so = new cvr::SceneObject("Scene Object", true, false, true, false, false);
						osg::Quat rot(osg::PI/2, osg::Vec3(1,0,0));
//						rot *= osg::Quat(osg::PI, osg::Vec3(0,0,1));
						new_so->setRotation(rot);
						new_so->setScale(100.f);
						new_so->addChild(mCurrentCardsNode);
						new_so->setPosition(pos);
						cvr::PluginHelper::registerSceneObject(new_so, "CardsClient");
						new_so->attachToScene();
						mCreatedSos.push_back(new_so);


						osg::Vec3 min(new_so->getOrComputeBoundingBox().xMin(), new_so->getOrComputeBoundingBox().yMin(), new_so->getOrComputeBoundingBox().zMin());
//						min = new_so->getObjectToWorldMatrix() * min;
//						std::cerr << min.x() << "\t" << min.y() << "\t" << min.z() << "\n";
						if (min.y() < 0.f)
						{
							float move_up = -1.f * min.y() * 100.f;
							osg::Vec3 new_pos = new_so->getPosition() + osg::Vec3(0.f, 0.f, move_up);
							new_so->setPosition(new_pos);
						}

					}
				}

				last_frame_time = cvr::PluginHelper::getFrameStartTime();
			}

			return true;
		}
	}

	return false;
}

