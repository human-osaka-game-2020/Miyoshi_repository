#include "Common.h"

bool FadeIn(unsigned int fadePower, int waitTime, int fadeColor) {
	static int alpha = 0;
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	if (fadeColor != NULL) {
		DrawBox(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, fadeColor, true);
	}
	alpha += fadePower;
	if (alpha > 256) {
		alpha = 0;
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		WaitTimer(waitTime);
		return true;
	}
	return false;
}

bool FadeOut(unsigned int fadePower, int waitTime, int fadeColor) {
	static int alpha = 256;
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	if (fadeColor != NULL) {
		DrawBox(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, fadeColor, true);
	}
	alpha -= fadePower;
	if (alpha < 0) {
		alpha = 256;
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		WaitTimer(waitTime);
		return true;
	}
	return false;
}
