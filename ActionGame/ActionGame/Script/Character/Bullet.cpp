
#include "Bullet.h"

void Bullet::Control(){
	switch( data.direction ){
	case Direction::Left: data.position.x -= data.speed; break;
	default: data.position.x += data.speed; break;
	}
}

void Bullet::Draw(){
	LoadGraphScreen( data.position.x + data.size.width, data.position.y + data.size.height, data.sprite, true );
}
