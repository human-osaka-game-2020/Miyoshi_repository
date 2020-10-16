#ifndef FUNCTION_H
#define FUNCTION_H

/// <summary>
/// �t�F�[�h�C��
/// </summary>
/// <param name="fadePower">�t�F�[�h�C���̑���</param>
/// <param name="waitTime">�t�F�[�h�A�E�g���I�������ɑ҂���(ms)</param>
/// <param name="fadeColor">�t�F�[�h�̐F</param>
/// <returns>true == �����I��, false == ������</returns>
bool FadeIn(unsigned int fadePower, int waitTime = 0, int fadeColor = NULL);

/// <summary>
/// �t�F�[�h�A�E�g
/// </summary>
/// <param name="fadePower">�t�F�[�h�A�E�g�̑���</param>
/// <param name="waitTime">�t�F�[�h�A�E�g���I�������ɑ҂���(ms)</param>
/// <param name="fadeColor">�t�F�[�h�̐F</param>
/// <returns>true == �����I��, false == ������</returns>
bool FadeOut(unsigned int fadePower, int waitTime = 0, int fadeColor = NULL);

#endif // !FUNCTION_H
