#ifndef FUNCTION_H
#define FUNCTION_H

/// <summary>
/// �t�F�[�h�C��
/// </summary>
<<<<<<< HEAD
/// <param name="fadePower">�t�F�[�h�C���̑���</param>
/// <param name="fadeColor">�t�F�[�h�̐F GetColor�֐��𐄏�</param>
void FadeIn(float fadePower, int fadeColor = GetColor(0, 0, 0));
=======
/// <param name="fademode">�t�F�[�h�̎��</param>
/// <param name="fadePower">�t�F�[�h�̑���</param>
/// <param name="fadeColor">�t�F�[�h����F</param>
/// <param name="waitTime">�t�F�[�h�̑҂�����(�t���[��)</param>
/// <returns>true == �����I��, false == ������</returns>
bool Fade(FadeMode fademode ,unsigned int fadePower, int fadeColor, int waitTime );
>>>>>>> 69c635c... リファクタリング

/// <summary>
/// �t�F�[�h�A�E�g
/// </summary>
<<<<<<< HEAD
/// <param name="fadePower">�t�F�[�h�A�E�g�̑���</param>
/// <param name="fadeColor">�t�F�[�h�̐F GetColor�֐��𐄏�</param>
void FadeOut(float fadePower, int fadeColor = GetColor(0, 0, 0));
=======
/// <param name="fadePower">�t�F�[�h�̑���</param>
/// <param name="fadeColor">�t�F�[�h�C������O�̐F</param>
/// <param name="waitTime">�t�F�[�h���n�܂�O�ɑ҂���(�t���[��)</param>
/// <returns>true == �����I��, false == ������</returns>
bool FadeIn(unsigned int fadePower, int fadeColor = GetColor(0, 0, 0), int waitTime = 0 );
>>>>>>> 69c635c... リファクタリング

/// <summary>
/// �J���[�t�F�[�h
/// </summary>
<<<<<<< HEAD
/// <param name="fadePower">�F�̐؂�ւ�鑬��</param>
/// <param name="startColor">���̐F GetColor�֐��𐄏�</param>
/// <param name="endColor">�ڕW�̐F GetColor�֐��𐄏�</param>
void ColorFade(float fadePower, int startColor, int endColor);
=======
/// <param name="fadePower">�t�F�[�h�̑���</param>
/// <param name="fadeColor">�t�F�[�h�A�E�g������̐F</param>
/// <param name="waitTime">�t�F�[�h���I�������ɑ҂���(�t���[��)</param>
/// <returns>true == �����I��, false == ������</returns>
bool FadeOut(unsigned int fadePower, int fadeColor = GetColor(0, 0, 0), int waitTime = 0 );
>>>>>>> 69c635c... リファクタリング

#endif // !FUNCTION_H
