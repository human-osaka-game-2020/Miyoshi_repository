
#include "SceneBase.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "ResultScene.h"

FadeMode SceneBase::fadeMode = FadeMode::None;
SceneList SceneBase::currentScene = SceneList::Title;

SceneBase* SceneBase::sc_title  = nullptr;
SceneBase* SceneBase::sc_onPlay = nullptr;
SceneBase* SceneBase::sc_result = nullptr;
SceneBase* SceneBase::pSceneBase = nullptr;
SceneList SceneBase::previousScene = SceneList::Title;

SceneBase::SceneBase() {

}

SceneBase::~SceneBase() {

}

enum SceneList SceneBase::GetCurrentScene() {
	return currentScene;
}

void SceneBase::ReleaseScene() {
	delete pSceneBase;
	pSceneBase = nullptr;
}

void SceneBase::CreateScene() {
	// シーン処理を始める前のシーンを取得する
	previousScene = currentScene;

	// 移行先のシーンがnullならnewする
	if ( pSceneBase != nullptr ) return;

	switch ( currentScene )
	{
	case SceneList::Title:
		pSceneBase = new TitleScene();
		break;
	case SceneList::OnPlay:
		pSceneBase = new GameScene();
		break;
	case SceneList::Result:
		pSceneBase = new ResultScene();
		break;
	default:
		break;
	}
}

void SceneBase::ExecuteScene() {
	// シーンの処理
	if ( pSceneBase == nullptr ) return;
	pSceneBase->Execute();
}

void SceneBase::ReleaseCurrentScene() {
	// シーンに変化があるなら今のシーンはdeleteする
	if( previousScene != currentScene ) {
		delete pSceneBase;
		pSceneBase = nullptr;
		InitGraph();
		InitSoundMem();
	}
}

void SceneBase::SceneFade( SceneList destinationScene, int fadePower, int fadeColor, int waitTime) {
	if ( fadeMode == FadeMode::In ) {
		if ( FadeIn( fadePower, fadeColor, waitTime ) ) {
			fadeMode = FadeMode::None;
		}
	}
	else if ( fadeMode == FadeMode::Out ) {
		if ( FadeOut( fadePower, fadeColor, waitTime ) ) {
			currentScene = destinationScene;
			fadeMode = FadeMode::In;
		}
	}
}

void SceneBase::SceneFade( SceneList destinationScene, int inPower, int outPower, int inColor, int outColor, int inWaitTime, int outWaitTime ) {
	if ( fadeMode == FadeMode::In ) {
		if ( FadeIn( inPower, inColor, inWaitTime ) ) {
			fadeMode = FadeMode::None;
		}
	}
	else if ( fadeMode == FadeMode::Out ) {
		if ( FadeOut( outPower, outColor, outWaitTime ) ) {
			currentScene = destinationScene;
			fadeMode = FadeMode::In;
		}
	}
}
