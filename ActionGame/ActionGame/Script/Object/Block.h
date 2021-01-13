
#ifndef BLOCK_H
#define BLOCK_H

#include "../Common.h"
#include "ObjectBase.h"

class Block : public ObjectBase{
public:
	Block( ObjectData data_ ){ data = data_; }
	~Block(){};

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

