
#include "Okonomiyaki.h"
#include "../Manager/SpriteManager.h"

void Okonomiyaki::Control(){

}

void Okonomiyaki::Draw(){
	DrawGraph( data.position.x - 18, data.position.y - 18, data.graphHandle, true );
}
