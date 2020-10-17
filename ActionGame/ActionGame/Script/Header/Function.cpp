#include "Common.h"

bool Fade(FadeMode fademode, unsigned int fadePower, int waitTime, int fadeColor) {
	
	static int alpha = 0;
	static bool endFade = false;

	if (fademode == FadeMode::FadeOut) {
		fadePower *= -1;
		if (alpha == 0) {
			alpha = 256;
		}
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	if (fadeColor != 0) {
		DrawBox(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, fadeColor, true);
	}
	alpha += (fadePower);

	if (fademode == FadeMode::FadeIn) {
		if (alpha > 256) {
			alpha = 0;
			endFade = true;
		}
	}
	else if (fademode == FadeMode::FadeOut) {
		if (alpha < 1) {
			alpha = 256;
			endFade = true;
		}
	}

	if (endFade == true) {
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		WaitTimer(waitTime);
		endFade = false;
		return true;
	}

	return false;

}
