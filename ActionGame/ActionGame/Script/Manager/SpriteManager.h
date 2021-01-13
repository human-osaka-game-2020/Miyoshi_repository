
#ifndef SPRITE_MANAGER_H
#define SPRITE_MANAGER_H

#include "../Common.h"
#include "../Singleton.h"

enum GraphName{
	gPlayer,
	gBullet,

	GraphMax
};

struct GraphData{
	float width;
	float height;
	LPCTSTR path;
};

class SpriteManager : public Singleton<SpriteManager>{
public:
	SpriteManager(){};
	~SpriteManager(){};

public:
	int GetGraphHandle( GraphName graphName_ ) const { return graphHandle[graphName_]; }
	void LoadGraphHandle( GraphName graphName_ );

private:
	int graphHandle[GraphName::GraphMax];
};

const GraphData graphData[GraphName::GraphMax] = {
	{ 64, 64, "Sprite/Player.png" },
	{ 16, 16, "Sprite/Bullet.png" }
};

#endif // !SPRITE_MANAGER_H
