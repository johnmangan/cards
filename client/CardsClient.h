#ifndef CARDS_CLIENT_PLUGIN_H
#define CARDS_CLIENT_PLUGIN_H

#include <list>
#include <map>
#include <cvrKernel/CVRPlugin.h>
#include <cvrMenu/SubMenu.h>
#include <cvrMenu/MenuButton.h>
#include <cvrKernel/SceneObject.h>
#include "CardsNode.h"


class CardsClient : public cvr::CVRPlugin, public cvr::MenuCallback
{
public:
	
	CardsClient();
	virtual ~CardsClient();

	bool 
	init();	

	virtual void
	preFrame();

	virtual void
	postFrame();
	
	virtual void
	menuCallback(cvr::MenuItem* item);

	virtual bool
	processEvent(cvr::InteractionEvent* event);

private:	
	bool
	IntersectWithFloorPlane(osg::Vec3& posOut);

	void
	FreeCreatedSos(void);

	void
	AskForTags(std::map<std::string, int>& tags);

	cvr::SubMenu*    mPluginSubMenu;
	cvr::MenuButton* mSetTags;
	cvr::MenuButton* mResetScene;

	cvr::SubMenu*    mFinalSceneSubMenu;
	cvr::MenuButton* mSetTerrainTags;
	cvr::MenuButton* mSetBuildingTags;
	cvr::MenuButton* mSetVegetationTags;
	cvr::MenuButton* mCreateScene;

	cvr::SceneObject* mFloorPlane;
	bool mFloorAttached;

	osg::ref_ptr<CardsNode> mCurrentCardsNode;
	std::list<cvr::SceneObject*> mCreatedSos;

	std::map<std::string, int> mBuildingTags;
	std::map<std::string, int> mVegetationTags;
	std::map<std::string, int> mTerrainTags;

	osg::ref_ptr<CardsNode> mBuildingNode;
	osg::ref_ptr<CardsNode> mTerrainNode;
	osg::ref_ptr<CardsNode> mVegetationNode;

};

#endif //CARDS_CLIENT_PLUGIN_H
