
#include "Warp.h"
#include "../Manager/SpriteManager.h"

void Warp::Control(){

}

void Warp::Draw(){
	DrawGraph( data.position.x, data.position.y, data.graphHandle, true );
}
