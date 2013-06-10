#ifndef CARDS_NODE_H
#define CARDS_NODE_H

#include <vector>
#include <string>
#include <map>
#include <osg/LOD>
#include <QueryInterfaceImpl.h>

class CardsNode : public osg::LOD
{
public:
	CardsNode( std::map<std::string, int>& tagsWithWeights );

	/// Will return false if not hits were made from CARDS
	bool const
	HasGeometry(void) const { return mHasGeom; }

private:
	void
	Load( std::map<std::string, int>& tagsWithWeights );

	void
	QueryCardsForFiles(std::map<std::string, int>& tagsWithWeights, std::vector<std::string>& filesOut);

	bool mHasGeom;

	cards::IQueryImpl mCards;
};

#endif //CARDS_NODE_H
