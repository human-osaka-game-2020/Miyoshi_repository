#ifndef FUNCTION_H
#define FUNCTION_H

enum FadeMode {
	Mode_FadeNone,
	Mode_FadeIn,
	Mode_FadeOut
};

enum KeyState {
	Key_NotPressed = 0,
	Key_Pressed = 1,
	Key_Released = -1
};

/// <summary>
/// �t�F�[�h�����̒��g
/// </summary>
/// <param name="fademode">�t�F�[�h�̎��</param>
/// <param name="fadePower">�t�F�[�h�̑���</param>
/// <param name="fadeColor">�t�F�[�h����F</param>
/// <param name="waitTime">�t�F�[�h�̑҂�����(�t���[��)</param>
/// <returns>true == �����I��, false == ������</returns>
bool Fade( FadeMode fademode, unsigned int fadePower, int fadeColor, int waitTime );

/// <summary>
/// �t�F�[�h�C��
/// </summary>
/// <param name="fadePower">�t�F�[�h�̑���</param>
/// <param name="fadeColor">�t�F�[�h�C������O�̐F</param>
/// <param name="waitTime">�t�F�[�h���n�܂�O�ɑ҂���(�t���[��)</param>
/// <returns>true == �����I��, false == ������</returns>
bool FadeIn( unsigned int fadePower, int fadeColor = GetColor( 0, 0, 0 ), int waitTime = 0 );

/// <summary>
/// �t�F�[�h�A�E�g
/// </summary>
/// <param name="fadePower">�t�F�[�h�̑���</param>
/// <param name="fadeColor">�t�F�[�h�A�E�g������̐F</param>
/// <param name="waitTime">�t�F�[�h���I�������ɑ҂���(�t���[��)</param>
/// <returns>true == �����I��, false == ������</returns>
bool FadeOut( unsigned int fadePower, int fadeColor = GetColor( 0, 0, 0 ), int waitTime = 0 );

/// <summary>
/// �L�[�̓��͏�Ԃ��X�V����
/// :���t���[���Ăяo��
/// </summary>
/// <returns>0�ȊO�̓G���[</returns>
int UpdateKeyState();

/// <summary>
/// �L�[�̓��͏�Ԃ��擾����
/// </summary>
/// <param name="keyCode">���͏�Ԃ��擾�������L�[�̃L�[�R�[�h</param>
/// <returns>-1:�����ꂽ 0:������Ă��Ȃ� 1:�����ꂽ 2�ȏ�:������Ă���t���[����</returns>
int GetKeyStatus( int keyCode );

#endif // !FUNCTION_H
