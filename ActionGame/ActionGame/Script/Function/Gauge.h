
#ifndef GAUGE_H
#define GAUGE_H

#include "../Common.h"

class Gauge{
public:
	Gauge( Position position_, Size size_, int frontColor_, int backColor_, Direction direction_, int* valuePointer_, int maxValue_, bool isValueDraw_ = false, int valueColor_ = Color::black );
	~Gauge(){};

public:
	void Control();
	void Draw();

private:
	Position position;
	Size size;
	int frontColor;
	int backColor;
	Direction direction;
	int* pCurrentValue;
	int maxValue;
	double drawPercentage;
	bool isValueDraw;
	int valueColor;

};

#endif // !GAUGE_H
