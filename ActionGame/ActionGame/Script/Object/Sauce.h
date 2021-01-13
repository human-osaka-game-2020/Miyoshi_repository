
#ifndef SAUCE_H
#define SAUCE_H

#include "../Common.h"
#include "ObjectBase.h"

class Sauce : public ObjectBase{
public:
	Sauce( ObjectData data_ ){ data = data_; }
	~Sauce(){};

public:
	void Control();
	void Draw();

	ObjectData GetData() const { return data; }

	ObjectTag GetTag() const { return data.tag; }
	void SetTag( ObjectTag tag_ ) { data.tag = tag_; }

private:
	ObjectData data;
};

#endif // !BLOCK_H

