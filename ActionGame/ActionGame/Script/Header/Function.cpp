#include "Common.h"

bool Fade(FadeMode fadeMode, unsigned int fadePower, int waitTime, int fadeColor) {
	const int ALPHA_MIN = 0x00;
	const int ALPHA_MAX = 0xFF;
	const int ALPHA_INVALID = -1;

	static int alpha = ALPHA_INVALID;	// 初期値は無効な値にしておく

	if (alpha == ALPHA_INVALID) {
		// ここに入るのは、フェード処理開始フレームのみ
		alpha = (fadeMode == FadeMode::FadeIn) ? ALPHA_MAX : ALPHA_MIN;
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	DrawBox(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, fadeColor, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	if (fadeMode == FadeMode::FadeIn) {
		fadePower *= -1;
	}

	alpha += fadePower;
	if (alpha < ALPHA_MIN || ALPHA_MAX < alpha) {
		alpha = ALPHA_INVALID;
		return true;
	}

	return false;
}
