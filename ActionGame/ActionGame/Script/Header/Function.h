#ifndef FUNCTION_H
#define FUNCTION_H

enum FadeMode {
	FadeIn,
	FadeOut
};

/// <summary>
/// �t�F�[�h�C��
/// </summary>
/// <param name="fademode">�t�F�[�h�̎��</param>
/// <param name="fadePower">�t�F�[�h�̑���</param>
/// <param name="waitTime">+�t�F�[�h���I�������ɑ҂���(ms)</param>
/// <param name="fadeColor">+�t�F�[�h�̐F</param>
/// <returns>true == �����I��, false == ������</returns>
bool Fade(FadeMode fademode ,unsigned int fadePower, int waitTime = 0, int fadeColor = 0);

#endif // !FUNCTION_H
