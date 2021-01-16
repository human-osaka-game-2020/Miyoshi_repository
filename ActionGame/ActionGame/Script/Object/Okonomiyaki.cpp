
#include "Okonomiyaki.h"
#include "../Manager/SpriteManager.h"

void Okonomiyaki::Control(){

}

void Okonomiyaki::Draw(){
	DrawGraph( data.position.x - 16, data.position.y - 16, data.graphHandle, true );
}
