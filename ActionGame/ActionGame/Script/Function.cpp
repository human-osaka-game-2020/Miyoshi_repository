﻿#include "Header/Common.h"

// キーが何フレーム入力されているか保存する
int keyState[256];
// マウスボタンが何フレーム入力されているか保存する
int mouseState[MOUSEBUTTON_UPDATE_RANGE] = {};

bool Fade(FadeMode fademode, unsigned int fadePower, int fadeColor, int waitTime ) {

	const int ALPHA_MAX = 255;
	const int ALPHA_MIN = 0;
	const int ALPHA_INVALID = -1;
	
	static int alpha = ALPHA_INVALID;
	static int waitTimeCount = 0;

	if ( alpha == ALPHA_INVALID ) {
		alpha = ( fademode == Mode_FadeIn ) ? ALPHA_MAX : ALPHA_MIN;
	}

	if ( fademode == Mode_FadeIn ) {
		if ( alpha == ALPHA_MAX ) {
			DrawBox ( 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, fadeColor, true );
			waitTimeCount++;
			if ( waitTime > waitTimeCount ) {
				return false;
			}
		}
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	DrawBox(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, fadeColor, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	alpha = ( fademode == Mode_FadeIn ) ? alpha - fadePower : alpha + fadePower;

	if ( alpha < ALPHA_MIN || alpha > ALPHA_MAX ) {
		if ( fademode == Mode_FadeOut ) {
			waitTimeCount++;
			if ( waitTime > waitTimeCount ) {
				return false;
			}
		}
		alpha = ALPHA_INVALID;
		waitTimeCount = 0;
		return true;
	}

	return false;
}

bool FadeIn(unsigned int fadePower, int fadeColor, int waitTime ) {
	return Fade ( Mode_FadeIn, fadePower, fadeColor, waitTime ) ? true : false;
}

bool FadeOut(unsigned int fadePower, int fadeColor, int waitTime ) {
	return Fade ( Mode_FadeOut, fadePower, fadeColor, waitTime ) ? true : false;
}

int UpdateKeyState() {
	char currentKeyState[256];

	if ( GetHitKeyStateAll( currentKeyState ) != 0 ) {
		return -1;
	}

	for ( int i = 0; i < 256; i++ ) {
		if ( keyState[i] != InputState::Invalid ) {
			if ( keyState[i] == InputState::Released ) {
				keyState[i] = InputState::NotPressed;
			}

			if ( currentKeyState[i] == InputState::Pressed ) {
				keyState[i]++;
			}
			else {
				if ( keyState[i] != InputState::NotPressed ) {
					keyState[i] = InputState::Released;
				}
			}
		}
	}

	return 0;
}

int GetKeyStatus( int keyCode ){
	return keyState[keyCode];
}

void ChangeKeyInputInvalidState( int keyCode ) {
	keyState[keyCode] = ( keyState[keyCode] == InputState::Invalid ) ? InputState::NotPressed : InputState::Invalid;
}

int UpdateMouseButtonState() {
	char currentMouseState[MOUSEBUTTON_UPDATE_RANGE];

	for ( int i = 0; i < MOUSEBUTTON_UPDATE_RANGE; i++ ) {
		currentMouseState[i] = (GetMouseInput() & i);
	}

	for ( int i = 0; i < MOUSEBUTTON_UPDATE_RANGE; i++ ) {
		if ( mouseState[i] != InputState::Invalid ) {
			if ( mouseState[i] == InputState::Released ) {
				mouseState[i] = InputState::NotPressed;
			}

			if ( currentMouseState[i] == InputState::Pressed ) {
				mouseState[i]++;
			}
			else {
				if ( mouseState[i] != InputState::NotPressed ) {
					mouseState[i] = InputState::Released;
				}
			}
		}
	}

	return 0;
}

int GetMouseButtonStatus( int mouseButtonCode ) {
	return mouseState[mouseButtonCode];
}

void ChangeMouseInputInvalidState( int mouseButtonCode ) {
	mouseState[mouseButtonCode] = ( mouseState[mouseButtonCode] == InputState::Invalid ) ? InputState::NotPressed : InputState::Invalid;
}
