
#ifndef OBJECT_BASE_H
#define OBJECT_BASE_H

#include "../Common.h"

class ObjectBase{
public:
	ObjectBase(){};
	~ObjectBase(){};

	virtual void Control() = 0;
	virtual void Draw() = 0;

	virtual ObjectData GetData() const = 0;

	virtual ObjectTag GetTag() const = 0;
	virtual void SetTag( ObjectTag tag_ ) = 0;
};

#endif // !OBJECT_BASE_H
