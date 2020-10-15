#ifndef FUNCTION_H
#define FUNCTION_H

/// <summary>
/// �t�F�[�h�C��
/// </summary>
/// <param name="fadePower">�t�F�[�h�C���̑���</param>
/// <param name="fadeColor">�t�F�[�h�̐F GetColor�֐��𐄏�</param>
void FadeIn(float fadePower, int fadeColor = GetColor(0, 0, 0));

/// <summary>
/// �t�F�[�h�A�E�g
/// </summary>
/// <param name="fadePower">�t�F�[�h�A�E�g�̑���</param>
/// <param name="fadeColor">�t�F�[�h�̐F GetColor�֐��𐄏�</param>
void FadeOut(float fadePower, int fadeColor = GetColor(0, 0, 0));

/// <summary>
/// �J���[�t�F�[�h
/// </summary>
/// <param name="fadePower">�F�̐؂�ւ�鑬��</param>
/// <param name="startColor">���̐F GetColor�֐��𐄏�</param>
/// <param name="endColor">�ڕW�̐F GetColor�֐��𐄏�</param>
void ColorFade(float fadePower, int startColor, int endColor);

#endif // !FUNCTION_H
