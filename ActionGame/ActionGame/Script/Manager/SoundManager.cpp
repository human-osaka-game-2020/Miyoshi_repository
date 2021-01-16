
#include "SoundManager.h"

void SoundManager::LoadSoundHandle( SoundName soundName_ ){
	soundHandle[soundName_] = LoadSoundMem( soundData[soundName_] );
}