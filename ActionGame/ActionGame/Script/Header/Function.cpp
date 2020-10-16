#include "Common.h"

bool Fade(FadeMode fademode, unsigned int fadePower, int waitTime, int fadeColor) {
	if (fademode == FadeMode::FadeIn) {
		static int alpha = 0;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
		if (fadeColor != 0) {
			DrawBox(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, fadeColor, true);
		}
		alpha += fadePower;
		if (alpha > 256) {
			alpha = 0;
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

			WaitTimer(waitTime);
			return true;
		}
	}
	else if (fademode == FadeMode::FadeOut) {
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
	}
	return false;

}
