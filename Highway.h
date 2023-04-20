#ifndef __HIGHWAY_H
#define __HIGHWAY_H

#include "Header.h"

class Bridge;
class HeapNode;

class Highway 
{
private:
	Bridge* head;
	Bridge* tail;
	int indexOfminBridgeNode; // in the role of a pointer to element of the maximum Heap

public:
	Highway();
	Highway(const Highway& other) = delete;
	~Highway() = default;
	void addBridge(const Bridge& bridge);
	void printBridges() const;
	int getIndexOfminBridgeNode() { return indexOfminBridgeNode; }
	void setIndexOfminBridgeNode(int index) { indexOfminBridgeNode = index; }
	Bridge* getHead() { return head; }
};

#endif // !__HIGHWAY_H

