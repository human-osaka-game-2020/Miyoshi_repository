
#ifndef OKONOMIYAKI_H
#define OKONOMIYAKI_H

#include "../Common.h"
#include "ObjectBase.h"

class Okonomiyaki : public ObjectBase{
public:
	Okonomiyaki( ObjectData data_ ){ data = data_; }
	~Okonomiyaki(){};

public:
	void Control();
	void Draw();

	ObjectData GetData() const { return data; }

	ObjectTag GetTag() const { return data.tag; }
	void SetTag( ObjectTag tag_ ) { data.tag = tag_; }

private:
	ObjectData data;
};

#endif // !OKONOMIYAKI_H

