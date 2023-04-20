#ifndef __METRO_H
#define __METRO_H

#include "Header.h"

class Metropolyn // data structure that contains arr of rads and maximum heap
{
private:
	Highway* highWays; // array of highways
	HeapNode* heap; // maximum heap of the minimum bridge heights on each road
	int numOfHighways; // 'm'

public:
	Metropolyn() = default;
	Metropolyn(const Metropolyn& other) = delete;
	~Metropolyn();
	float getHeapRootKey() const;
	const Highway& getHighWay(int index) const;
	void fixHeap(int index);
	void DefusionFixHeap(int index);
	void seepageFixHeap(int index);
	void swap(int index1, int index2);
	void WhichRoad(float height);
	void print(int r);
	void AddBridge(float h, int r); 
	void Init(int m);
};

#endif // !__METRO_H

