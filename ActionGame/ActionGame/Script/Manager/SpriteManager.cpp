
#include "SpriteManager.h"

void SpriteManager::LoadGraphHandle( GraphName graphName_ ){
	graphHandle[graphName_] = LoadGraph( graphData[graphName_].path );
}
