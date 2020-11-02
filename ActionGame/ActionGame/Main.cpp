#include "Script/Header/Common.h"

// �Q�[������
void GameProcessing ();
// �`�揈��
void DrawProcessing ();

Player player;

FadeMode fadeMode = Mode_FadeNone;

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain ( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{

	SetGraphMode ( WINDOW_WIDTH, WINDOW_HEIGHT, 32, 60 );
	ChangeWindowMode ( true ); // �E�B���h�E���[�h�ɕύX

	if ( DxLib_Init () == -1 )	// �c�w���C�u��������������
	{
		return -1; // �G���[���N�����璼���ɏI��
	}

	// �O���t�B�b�N�̕`���𗠉�ʂɃZ�b�g
	SetDrawScreen ( DX_SCREEN_BACK );

	// ���C�����[�v
	while ( UpdateKeyState() == 0 )
	{
		// ��ʂ�������
		ClearDrawScreen ();

		GameProcessing ();
		DrawProcessing ();

		// -1 ���Ԃ��Ă����烋�[�v�𔲂���
		if ( ProcessMessage () < 0 ) break;
		// �����d�r�b�L�[��������Ă����烋�[�v���甲����
		if ( CheckHitKey ( KEY_INPUT_ESCAPE ) ) break;

		// ����ʂ̓��e��\��ʂɃR�s�[����
		ScreenFlip ();
	}

	DxLib_End ();				// �c�w���C�u�����g�p�̏I������

	return 0;					// �\�t�g�̏I��
}

void GameProcessing () {
	player.Moving();

	if ( fadeMode == Mode_FadeNone ) {
		if ( CheckHitKey( KEY_INPUT_SPACE ) ) {
			fadeMode = Mode_FadeIn;
		}
		else if ( CheckHitKey( KEY_INPUT_RETURN ) ) {
			fadeMode = Mode_FadeOut;
		}
	}

	if ( GetKeyStatus( KEY_INPUT_A ) == 0 ) {
		DrawString( 10, 100, "������Ă��Ȃ�", COLOR_WHITE );
	}
	else if ( GetKeyStatus( KEY_INPUT_A ) == 1 ) {
		DrawString( 1000, 100, "�����ꂽ", COLOR_GREEN );
	}
	else if ( GetKeyStatus( KEY_INPUT_A ) == -1 ) {
		DrawString( 1000, 100, "�����ꂽ", COLOR_RED );
	}
	else {
		DrawFormatString( 10, 100, COLOR_BLUE, "������Ă��� : %d �t���[��", GetKeyStatus(KEY_INPUT_A) );
	}
}

void DrawProcessing() {
	player.Draw();

	if ( fadeMode == Mode_FadeIn ) {
		if ( FadeIn( 255 / 60, COLOR_BLUE, 30 ) ) {
			fadeMode = Mode_FadeNone;
		}
	}
	else if ( fadeMode == Mode_FadeOut ) {
		if ( FadeOut( 255 / 60, COLOR_RED, 90 ) ) {
			fadeMode = Mode_FadeNone;
		}
	}
}
