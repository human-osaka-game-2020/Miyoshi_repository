
#include "Gauge.h"

Gauge::Gauge( Position position_, Size size_, int frontColor_, int backColor_, Direction direction_, int* valuePointer_, int maxValue_, bool isValueDraw_, int valueColor_ ) :
	position( position_ ),
	size( size_ ),
	frontColor( frontColor_ ),
	backColor( backColor_ ),
	direction( direction_ ),
	pCurrentValue( valuePointer_ ),
	maxValue( maxValue_ ),
	drawPercentage( *valuePointer_ / maxValue_ ),
	isValueDraw( isValueDraw_ ),
	valueColor( valueColor_ )
{

}

void Gauge::Control(){
	drawPercentage = static_cast<double>(*pCurrentValue) / maxValue;
}

void Gauge::Draw(){
	Size tempSize = { size.width, size.height };
	Position tempPos = { position.x, position.y };

	// ゲージ背景
	switch( direction ){
	case Direction::Up:
		tempSize.height = size.height * drawPercentage;
		break;
	case Direction::Left:
		tempPos.x = position.x + size.width;
		tempSize.width = -size.width * drawPercentage;
		break;
	case Direction::Right:
		tempSize.width = size.width * drawPercentage;
		break;
	case Direction::Down:
		tempPos.y = position.y + size.height;
		tempSize.height = -size.height * drawPercentage;
		break;
	}

	DrawBox( position.x, position.y, position.x + size.width, position.y + size.height, backColor, true );

	// ゲージ
	DrawBox( tempPos.x, tempPos.y, tempPos.x + tempSize.width, tempPos.y + tempSize.height, frontColor, true );

	// 数値の表示
	if( isValueDraw == true ) DrawFormatString( position.x, position.y + size.height + 5, valueColor, "%d / %d", *pCurrentValue, maxValue );
}
