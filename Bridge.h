#ifndef __BRIDGE_H
#define __BRIDGE_H

#include "Header.h"

class Bridge // node of Highway linked list
{
private:
	float height;
	Bridge* next = nullptr;

public:
	Bridge(float height, Bridge* next) { this->height = height; this->next = next; }
	Bridge(const Bridge& other) = default;
	~Bridge() = default;
	Bridge* getNext() const { return next; }
	void setNext(Bridge* next) { this->next = next; }
	float getHeight() const { return height; }
};

#endif
