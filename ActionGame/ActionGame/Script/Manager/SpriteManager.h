
#ifndef SPRITE_MANAGER_H
#define SPRITE_MANAGER_H

#include "../Common.h"
#include "../Singleton.h"

enum GraphName{
	gPlayer,
	gBullet,
	gBlock,
	gEmptyBlock,
	gOkonomiyaki,
	gSauce,
	gSave,
	gWarp,

	GraphMax
};

struct GraphData{
	Size size;
	LPCTSTR path;
};

class SpriteManager : public Singleton<SpriteManager>{
public:
	SpriteManager(){};
	~SpriteManager(){};

public:
	GraphData GetGraphData( GraphName graphName_ ) const { return graphData[graphName_]; }

	int GetGraphHandle( GraphName graphName_ ) const { return graphHandle[graphName_]; }
	void LoadGraphHandle( GraphName graphName_ );

private:
	int graphHandle[GraphName::GraphMax];

	const GraphData graphData[GraphName::GraphMax] = {
		{ 64, 64, "Sprite/Player.png" },
		{ 16, 16, "Sprite/Bullet.png" },
		{ 64, 64, "Sprite/Object/Block.png"},
		{ 64, 64, "Sprite/Object/EmptyBlock.png"},
		{ 64, 64, "Sprite/Object/Okonomiyaki.png"},
		{ 64, 64, "Sprite/Object/Sauce.png"},
		{ 64, 64, "Sprite/Object/Save.png"},
		{ 64, 64, "Sprite/Object/Warp.png"}
	};
};

#endif // !SPRITE_MANAGER_H
