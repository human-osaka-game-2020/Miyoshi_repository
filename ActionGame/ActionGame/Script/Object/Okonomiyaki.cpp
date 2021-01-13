
#include "Okonomiyaki.h"
#include "../Manager/SpriteManager.h"

void Okonomiyaki::Control(){

}

void Okonomiyaki::Draw(){
	DrawGraph( data.position.x, data.position.y, data.graphHandle, true );
}
