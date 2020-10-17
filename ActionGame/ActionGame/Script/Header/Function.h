#ifndef FUNCTION_H
#define FUNCTION_H

enum FadeMode {
	FadeIn,
	FadeOut,
	FadeNone
};

/// <summary>
/// フェードイン/アウト
/// </summary>
/// <param name="fademode">フェードの種類</param>
/// <param name="fadePower">フェードの速さ</param>
/// <param name="waitTime">+フェードが終わった後に待つ時間(ms)</param>
/// <param name="fadeColor">+フェードの色</param>
/// <returns>true == 処理終了, false == 処理中</returns>
bool Fade(FadeMode fademode ,unsigned int fadePower, int waitTime = 0, int fadeColor = 0);

#endif // !FUNCTION_H
