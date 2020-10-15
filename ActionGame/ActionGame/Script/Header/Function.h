#ifndef FUNCTION_H
#define FUNCTION_H

/// <summary>
/// フェードイン
/// </summary>
/// <param name="fadePower">フェードインの速さ</param>
/// <param name="fadeColor">フェードの色 GetColor関数を推奨</param>
void FadeIn(float fadePower, int fadeColor = GetColor(0, 0, 0));

/// <summary>
/// フェードアウト
/// </summary>
/// <param name="fadePower">フェードアウトの速さ</param>
/// <param name="fadeColor">フェードの色 GetColor関数を推奨</param>
void FadeOut(float fadePower, int fadeColor = GetColor(0, 0, 0));

/// <summary>
/// カラーフェード
/// </summary>
/// <param name="fadePower">色の切り替わる速さ</param>
/// <param name="startColor">元の色 GetColor関数を推奨</param>
/// <param name="endColor">目標の色 GetColor関数を推奨</param>
void ColorFade(float fadePower, int startColor, int endColor);

#endif // !FUNCTION_H
