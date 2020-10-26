#ifndef FUNCTION_H
#define FUNCTION_H

enum FadeMode {
	Mode_FadeNone,
	Mode_FadeIn,
	Mode_FadeOut
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

#endif // !FUNCTION_H
