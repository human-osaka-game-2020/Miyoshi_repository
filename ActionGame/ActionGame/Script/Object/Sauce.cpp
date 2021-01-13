
#include "Sauce.h"
#include "../Manager/SpriteManager.h"

void Sauce::Control(){

}

void Sauce::Draw(){
	DrawGraph( data.position.x, data.position.y, data.graphHandle, true );
}
