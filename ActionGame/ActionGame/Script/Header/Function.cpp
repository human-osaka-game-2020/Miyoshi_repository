#include "Common.h"

void FadeIn(float fadePower, int fadeColor) {
	if (fadePower < 0) {
		fadePower *= -1;
	}
}

void FadeOut(float fadePower, int fadeColor) {
	if (fadePower < 0) {
		fadePower *= -1;
	}
}

void ColorFade(float fadePower, int startColor, int endColor) {
	if (fadePower < 0) {
		fadePower *= -1;
	}
}