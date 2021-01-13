
#include "Save.h"
#include "../Manager/SpriteManager.h"

void Save::Control(){

}

void Save::Draw(){
	DrawGraph( data.position.x, data.position.y, data.graphHandle, true );
}
