﻿#include "Header/Common.h"

// キーが何フレーム入力されているか保存する
InputState keyState[256];

// マウスボタンが何フレーム入力されているか保存する
InputState mouseState[MOUSEBUTTON_UPDATE_RANGE] = {};

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

/// @brief キー/マウスの入力状態を更新する
/// @param isPressed 1 = 押している, 1以外 = 押していない
/// @param inputState キー/マウスの入力状態
/// @return 入力状態の判定結果 InputStateで返す
InputState UpdateInputState( int isPressed, InputState inputState ){
	if ( inputState == InputState::Invalid )return InputState::Invalid;

	if ( isPressed == 1 ){
		if ( inputState == InputState::NotPressed ){
			return InputState::Pressed;
		}
		else if ( inputState == InputState::Pressed || inputState == InputState::Pressing ){
			return InputState::Pressing;
		}
	}
	else{
		if ( inputState == InputState::Pressed || inputState == InputState::Pressing ){
			return InputState::Released;
		}
	}

	return InputState::NotPressed;
}

int UpdateKeyState() {
	char currentKeyState[256];

	if ( GetHitKeyStateAll( currentKeyState ) != 0 ) {
		return -1;
	}

	for ( int i = 0; i < 256; i++ ) {
		keyState[i] = UpdateInputState( currentKeyState[i], keyState[i] );
	}

	return 0;
}

InputState GetKeyStatus( int keyCode ){
	return keyState[keyCode];
}

void KeyInputEnabledToggle( int keyCode ) {
	keyState[keyCode] = ( keyState[keyCode] == InputState::Invalid ) ? InputState::NotPressed : InputState::Invalid;
}

int UpdateMouseButtonState() {
	char currentMouseState[MOUSEBUTTON_UPDATE_RANGE];

	for ( int i = 0; i < MOUSEBUTTON_UPDATE_RANGE; i++ ) {
		currentMouseState[i] = (GetMouseInput() & i);
	}

	for ( int i = 0; i < MOUSEBUTTON_UPDATE_RANGE; i++ ) {
		mouseState[i] = UpdateInputState( currentMouseState[i], mouseState[i] );
	}

	return 0;
}

InputState GetMouseButtonStatus( int mouseButtonCode ) {
	return mouseState[mouseButtonCode];
}

void MouseButtonInputEnabledToggle( int mouseButtonCode ) {
	mouseState[mouseButtonCode] = ( mouseState[mouseButtonCode] == InputState::Invalid ) ? InputState::NotPressed : InputState::Invalid;
}
