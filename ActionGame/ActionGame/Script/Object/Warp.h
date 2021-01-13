
#ifndef WARP_H
#define WARP_H

#include "../Common.h"
#include "ObjectBase.h"

class Warp : public ObjectBase{
public:
	Warp( ObjectData data_ ){ data = data_; }
	~Warp(){};

public:
	void Control();
	void Draw();

	ObjectData GetData() const { return data; }

	ObjectTag GetTag() const { return data.tag; }
	void SetTag( ObjectTag tag_ ) { data.tag = tag_; }

private:
	ObjectData data;
};

#endif // !WARP_H

