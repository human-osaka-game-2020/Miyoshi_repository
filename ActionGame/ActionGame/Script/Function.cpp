﻿
#include "Header/Common.h"

// キーが何フレーム入力されているか保存する
InputState keyState[256];

// マウスボタンが何フレーム入力されているか保存する
InputState mouseState[MOUSEBUTTON_UPDATE_RANGE] = {};

bool Fade( FadeMode fademode, unsigned int fadePower, int fadeColor, int waitTime ) {

	const int ALPHA_MAX = 255;
	const int ALPHA_MIN = 0;
	const int ALPHA_INVALID = -1;
	
	static int alpha = ALPHA_INVALID;
	static int waitTimeCount = 0;

	if ( alpha == ALPHA_INVALID ) {
		alpha = ( fademode == FadeMode::In ) ? ALPHA_MAX : ALPHA_MIN;
	}

	if ( fademode == FadeMode::In ) {
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

	alpha = ( fademode == FadeMode::In ) ? alpha - fadePower : alpha + fadePower;

	if ( alpha < ALPHA_MIN || alpha > ALPHA_MAX ) {
		if ( fademode == FadeMode::Out ) {
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
	return Fade ( FadeMode::In, fadePower, fadeColor, waitTime ) ? true : false;
}

bool FadeOut(unsigned int fadePower, int fadeColor, int waitTime ) {
	return Fade ( FadeMode::Out, fadePower, fadeColor, waitTime ) ? true : false;
}

void CheckKeyPushed( bool* pStateArray ){
	char temp[256];

	GetHitKeyStateAll( temp );

	for( int i = 0; i < 256; i++ ){
		pStateArray[i] = ( temp[i] == 1 ) ? true : false;
	}
}

/// @brief キー/マウスの入力状態を更新する
/// @param isPressed 現在キーが押されているか
/// @param inputState キー/マウスの入力状態
/// @return 入力状態の判定結果 InputStateで返す
InputState UpdateInputState( bool isPressed, InputState inputState ){
	if ( inputState == InputState::Invalid )return InputState::Invalid;

	if ( isPressed == true ){
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
	bool currentKeyState[256];

	CheckKeyPushed( currentKeyState );

	for ( int i = 0; i < 256; i++ ) {
		keyState[i] = UpdateInputState( currentKeyState[i], keyState[i] );
	}

	return 0;
}

InputState GetKeyStatus( int keyCode ){
	return keyState[keyCode];
}

void SwitchEnabledKeyInput( int keyCode ) {
	keyState[keyCode] = ( keyState[keyCode] == InputState::Invalid ) ? InputState::NotPressed : InputState::Invalid;
}

int UpdateMouseButtonState() {
	bool currentMouseState[MOUSEBUTTON_UPDATE_RANGE];

	for ( int i = 0; i < MOUSEBUTTON_UPDATE_RANGE; i++ ) {
		currentMouseState[i] = ( ( GetMouseInput() & i ) != 0 ) ? true : false;
		mouseState[i] = UpdateInputState( currentMouseState[i], mouseState[i] );
	}

	return 0;
}

InputState GetMouseButtonStatus( int mouseButtonCode ) {
	return mouseState[mouseButtonCode];
}

void SwitchEnabledMouseButtonInput( int mouseButtonCode ) {
	mouseState[mouseButtonCode] = ( mouseState[mouseButtonCode] == InputState::Invalid ) ? InputState::NotPressed : InputState::Invalid;
}
