#ifndef FUNCTION_H
#define FUNCTION_H

enum FadeMode {
	Mode_FadeNone,
	Mode_FadeIn,
	Mode_FadeOut
};

enum InputState {
	Input_Invalid = -2,
	Input_Released,
	Input_NotPressed,
	Input_Pressed
};

// �}�E�X�{�^���̓��͏�Ԃ𒲂ׂ�͈�
const int MOUSEBUTTON_UPDATE_RANGE = 5;

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

/// <summary>
/// �L�[�̓��͂𖳎�����
/// </summary>
/// <param name="keyCode">���͂𖳎��������L�[�̃L�[�R�[�h</param>
void KeyInputInvaliding( int keyCode );

/// <summary>
/// �L�[�̓��͂�L���ɂ���
/// </summary>
/// <param name="keyCode">���͂�L���ɂ������L�[�̃L�[�R�[�h</param>
void KeyInputActivating( int keyCode );

/// <summary>
/// �}�E�X�{�^���̓��͏�Ԃ��X�V����
/// :���t���[���Ăяo��
/// </summary>
/// <returns>0�ȊO�̓G���[</returns>
int UpdateMouseButtonState();

/// <summary>
/// �}�E�X�{�^���̓��͏�Ԃ��擾����
/// </summary>
/// <param name="mouseButtonCode">���͏�Ԃ��擾�������}�E�X�{�^���̃R�[�h</param>
/// <returns></returns>
int GetMouseButtonStatus( int mouseButtonCode );

/// <summary>
/// �}�E�X�{�^���̓��͂𖳎�����
/// </summary>
/// <param name="mouseButtonCode">���͂𖳎��������}�E�X�{�^���̃R�[�h</param>
void MouseButtonInputInvaliding( int mouseButtonCode );

/// <summary>
/// �}�E�X�{�^���̓��͂�L���ɂ���
/// </summary>
/// <param name="mouseButtonCode">���͂�L���ɂ������}�E�X�{�^���̃R�[�h</param>
void MouseButtonInputActivating( int mouseButtonCode );

#endif // !FUNCTION_H
