
#ifndef FUNCTION_H
#define FUNCTION_H

// フェードの状態
enum FadeMode {
	None,	// フェードなし
	In,	// フェードイン中
	Out	// フェードアウト中
};

/// <summary>
/// フェード処理の中身
/// </summary>
/// <param name="fademode">フェードの種類</param>
/// <param name="fadePower">フェードの速さ</param>
/// <param name="fadeColor">フェードする色</param>
/// <param name="waitTime">フェードの待ち時間(フレーム)</param>
/// <returns>true == 処理終了, false == 処理中</returns>
bool Fade( FadeMode fademode, unsigned int fadePower, int fadeColor, int waitTime );

/// <summary>
/// フェードイン
/// </summary>
/// <param name="fadePower">フェードの速さ</param>
/// <param name="fadeColor">フェードインする前の色</param>
/// <param name="waitTime">フェードが始まる前に待つ時間(フレーム)</param>
/// <returns>true == 処理終了, false == 処理中</returns>
bool FadeIn( unsigned int fadePower, int fadeColor = GetColor( 0, 0, 0 ), int waitTime = 0 );

/// <summary>
/// フェードアウト
/// </summary>
/// <param name="fadePower">フェードの速さ</param>
/// <param name="fadeColor">フェードアウトした後の色</param>
/// <param name="waitTime">フェードが終わった後に待つ時間(フレーム)</param>
/// <returns>true == 処理終了, false == 処理中</returns>
bool FadeOut( unsigned int fadePower, int fadeColor = GetColor( 0, 0, 0 ), int waitTime = 0 );

#endif // !FUNCTION_H
