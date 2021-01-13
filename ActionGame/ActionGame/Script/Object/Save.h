
#ifndef SAVE_H
#define SAVE_H

#include "../Common.h"
#include "ObjectBase.h"

class Save : public ObjectBase{
public:
	Save( ObjectData data_ ){ data = data_; }
	~Save(){};

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

