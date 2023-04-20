#ifndef __HEAP_H
#define __HEAP_H

#include "Header.h"

class Highway;

class HeapNode // one element in the max Heap
{
private:
	float key; // min height of highway
	int highWayNum; // the number of the Highway
	Highway* highwayPtr; // pointer to highway

public:
	HeapNode(float key = FLT_MAX) { this->key = key; highwayPtr = nullptr; highWayNum = -1; }
	HeapNode(const HeapNode& other) = default;
	~HeapNode() = default;
	Highway* getHighWay() { return highwayPtr; }
	void updateKey(float newKey) { key = newKey; }
	float getKey() const { return key; }
	int getHighWayNum() const { return highWayNum; }
	void setHighWayNum(int num) { highWayNum = num; }
	void setHighwayPtr(Highway* highway) { this->highwayPtr = highway; }
};

#endif // !__HEAP_H

