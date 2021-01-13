
#include "Block.h"
#include "../Manager/SpriteManager.h"

void Block::Control(){
	SpriteManager* sprIns = SpriteManager::GetInstance();

	if( data.tag == ObjectTag::EmptyBlock_o ){
		data.graphHandle = sprIns->GetGraphHandle( GraphName::gEmptyBlock );
		data.tag = ObjectTag::Air_o;
	}
	else if( data.tag == ObjectTag::SkeletonBlock_o ){
		data.graphHandle = sprIns->GetGraphHandle( GraphName::gBlock );
		data.tag = ObjectTag::Block_o;
	}
}

void Block::Draw(){
	DrawGraph( data.position.x, data.position.y, data.graphHandle, true );
}
