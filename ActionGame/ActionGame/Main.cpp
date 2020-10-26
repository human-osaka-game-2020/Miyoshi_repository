#include "Script/Header/Common.h"

// �Q�[������
void GameProcessing();
// �`�揈��
void DrawProcessing();

Player player;

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetGraphMode ( WINDOW_WIDTH, WINDOW_HEIGHT, 32, 60 );
	ChangeWindowMode ( true ); // �E�B���h�E���[�h�ɕύX

	if (DxLib_Init() == -1)	// �c�w���C�u��������������
	{
		return -1; // �G���[���N�����璼���ɏI��
	}

	// �O���t�B�b�N�̕`���𗠉�ʂɃZ�b�g
	SetDrawScreen(DX_SCREEN_BACK);

	// ���C�����[�v
	while (true)
	{
		GameProcessing();
		DrawProcessing();

		// -1 ���Ԃ��Ă����烋�[�v�𔲂���
		if (ProcessMessage() < 0) break;
		// �����d�r�b�L�[��������Ă����烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;					// �\�t�g�̏I��
}

void GameProcessing() {
	player.Moving();
}

void DrawProcessing() {

	if ( fadeMode == Mode_FadeIn ) {
		if ( FadeIn ( 255 / 60, COLOR_BLUE ) ) {
			fadeMode = Mode_FadeNone;
		}
	}
	else if ( fadeMode == Mode_FadeOut ) {
		if ( FadeOut ( 255 / 60, COLOR_RED, 90 ) ) {
			fadeMode = Mode_FadeNone;
		}
	}
}
