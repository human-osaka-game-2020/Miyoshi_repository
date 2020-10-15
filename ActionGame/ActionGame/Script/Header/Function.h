#ifndef FUNCTION_H
#define FUNCTION_H

/// <summary>
/// フェードイン
/// </summary>
<<<<<<< HEAD
/// <param name="fadePower">フェードインの速さ</param>
/// <param name="fadeColor">フェードの色 GetColor関数を推奨</param>
void FadeIn(float fadePower, int fadeColor = GetColor(0, 0, 0));
=======
/// <param name="fademode">フェードの種類</param>
/// <param name="fadePower">フェードの速さ</param>
/// <param name="fadeColor">フェードする色</param>
/// <param name="waitTime">フェードの待ち時間(フレーム)</param>
/// <returns>true == 処理終了, false == 処理中</returns>
bool Fade(FadeMode fademode ,unsigned int fadePower, int fadeColor, int waitTime );
>>>>>>> 69c635c... 繝ｪ繝輔ぃ繧ｯ繧ｿ繝ｪ繝ｳ繧ｰ

/// <summary>
/// フェードアウト
/// </summary>
<<<<<<< HEAD
/// <param name="fadePower">フェードアウトの速さ</param>
/// <param name="fadeColor">フェードの色 GetColor関数を推奨</param>
void FadeOut(float fadePower, int fadeColor = GetColor(0, 0, 0));
=======
/// <param name="fadePower">フェードの速さ</param>
/// <param name="fadeColor">フェードインする前の色</param>
/// <param name="waitTime">フェードが始まる前に待つ時間(フレーム)</param>
/// <returns>true == 処理終了, false == 処理中</returns>
bool FadeIn(unsigned int fadePower, int fadeColor = GetColor(0, 0, 0), int waitTime = 0 );
>>>>>>> 69c635c... 繝ｪ繝輔ぃ繧ｯ繧ｿ繝ｪ繝ｳ繧ｰ

/// <summary>
/// カラーフェード
/// </summary>
<<<<<<< HEAD
/// <param name="fadePower">色の切り替わる速さ</param>
/// <param name="startColor">元の色 GetColor関数を推奨</param>
/// <param name="endColor">目標の色 GetColor関数を推奨</param>
void ColorFade(float fadePower, int startColor, int endColor);
=======
/// <param name="fadePower">フェードの速さ</param>
/// <param name="fadeColor">フェードアウトした後の色</param>
/// <param name="waitTime">フェードが終わった後に待つ時間(フレーム)</param>
/// <returns>true == 処理終了, false == 処理中</returns>
bool FadeOut(unsigned int fadePower, int fadeColor = GetColor(0, 0, 0), int waitTime = 0 );
>>>>>>> 69c635c... 繝ｪ繝輔ぃ繧ｯ繧ｿ繝ｪ繝ｳ繧ｰ

#endif // !FUNCTION_H
