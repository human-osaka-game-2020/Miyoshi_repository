
#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include "../Common.h"
#include "../Singleton.h"

enum SoundName{
	sBlockSpawn,
	sBlockDestroy,
	sDeath,
	sJump,
	sDoubleJump,
	sSave,
	sWarp,
	sShoot,
	sReset,
	sClear,
	sSelect,
	sEnter,
	bTitle,
	bGame,
	bResult,
	sGameOver,

	SoundMax
};

class SoundManager : public Singleton<SoundManager>{
public:
	SoundManager(){};
	~SoundManager(){};

public:
	int GetSoundHandle( SoundName soundName_ ) const { return soundHandle[soundName_]; }
	void LoadSoundHandle( SoundName soundName_ );

private:
	int soundHandle[SoundName::SoundMax];

	const LPCTSTR soundData[SoundName::SoundMax] = {
		"Sounds/BlockSpawn.mp3",
		"Sounds/BlockDestroy.mp3",
		"Sounds/Death.mp3",
		"Sounds/Jump.mp3",
		"Sounds/DoubleJump.mp3",
		"Sounds/Save.mp3",
		"Sounds/Warp.mp3",
		"Sounds/Shoot.mp3",
		"Sounds/Reset.mp3",
		"Sounds/ClearJingle.mp3",
		"Sounds/Select.mp3",
		"Sounds/Enter.mp3",
		"Sounds/TitleBGM.mp3",
		"Sounds/GameBGM.mp3",
		"Sounds/ResultBGM.mp3",
		"Sounds/GameOver.mp3"
	};
};

#endif // !SOUND_MANAGER_H
