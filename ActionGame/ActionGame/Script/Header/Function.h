#ifndef FUNCTION_H
#define FUNCTION_H

/// <summary>
/// フェードイン
/// </summary>
/// <param name="fadePower">フェードインの速さ</param>
/// <param name="waitTime">フェードアウトが終わった後に待つ時間(ms)</param>
/// <param name="fadeColor">フェードの色</param>
/// <returns>true == 処理終了, false == 処理中</returns>
bool FadeIn(unsigned int fadePower, int waitTime = 0, int fadeColor = NULL);

/// <summary>
/// フェードアウト
/// </summary>
/// <param name="fadePower">フェードアウトの速さ</param>
/// <param name="waitTime">フェードアウトが終わった後に待つ時間(ms)</param>
/// <param name="fadeColor">フェードの色</param>
/// <returns>true == 処理終了, false == 処理中</returns>
bool FadeOut(unsigned int fadePower, int waitTime = 0, int fadeColor = NULL);

#endif // !FUNCTION_H
