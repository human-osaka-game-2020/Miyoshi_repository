
#ifndef BULLET_H
#define BULLET_H

#include "../Common.h"

class Bullet{
public:
	Bullet( CharacterData data_ ){ data = data_; }
	~Bullet(){};

public:
	CharacterData GetCharacterData() const { return data; }
	void Control();
	void Draw();

private:
	CharacterData data;
};
#endif // !BULLET_H
