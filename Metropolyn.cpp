#include "Metropolyn.h"
#include "Highway.h"
#include "Heap.h"

Metropolyn::~Metropolyn()
{
	Bridge* curr, * temp;
	for (int i = 0; i < numOfHighways; i++) // destroying the linked lists of each highway
	{
		curr = highWays[i].getHead();
		while (curr != nullptr)
		{
			temp = curr->getNext();
			delete curr;
			curr = temp;
		}
	}
	delete highWays;
	delete heap;
}

void Metropolyn::print(int r) // Suppose that k is the number of bridges on road r - so the function's runtime is Theta(k)
{
	highWays[r - 1].printBridges(); // Theta(k)
}

void Metropolyn::Init(int m) // function runtine: O(m)
{
	numOfHighways = m; // Theta(1)
	highWays = new Highway[m]; // Theta(1)
	heap = new HeapNode[m]; // Theta(1)
	for (int i = 0; i < m; i++) // Theta(m)
	{
		// At initialization each element in the array points to its counterpart on the stack
		heap[i].setHighWayNum(i + 1); // Theta(1)
		heap[i].setHighwayPtr(&(highWays[i])); // Theta(1)
		highWays[i].setIndexOfminBridgeNode(i); // Theta(1)
	}
}

void Metropolyn::AddBridge(float h, int r) // function runtine: O(logm)
{
	highWays[r - 1].addBridge(Bridge(h, nullptr)); // Theta(1) - adding new node to the linked list
	if (heap[highWays[r - 1].getIndexOfminBridgeNode()].getKey() > h) // Theta(1)
	{
		heap[highWays[r - 1].getIndexOfminBridgeNode()].updateKey(h); // Theta(1)
		fixHeap(highWays[r - 1].getIndexOfminBridgeNode()); // There are m elements in the heap -> O(logm)
	}
}
 
void Metropolyn::fixHeap(int index)
{
	int left = (2 * index + 1);
	int right = (2 * index + 2);
	int parent = (index - 1) / 2;
	if (parent >= 0 && heap[parent].getKey() < heap[index].getKey()) // In the case where heap[index] needs to "move up" in the heap
		DefusionFixHeap(index);
	if ((left < numOfHighways && heap[parent].getKey() < heap[left].getKey())
		|| (right < numOfHighways && heap[parent].getKey() < heap[right].getKey())) // In the case where heap[index] needs to "go down" in the heap
		seepageFixHeap(index);
}

void Metropolyn::DefusionFixHeap(int index)
{
	int parent = (index - 1) / 2;
	if (parent >= 0 && heap[parent].getKey() < heap[index].getKey())
	{
		swap(index, parent);
		DefusionFixHeap(parent);
	}
}

void Metropolyn::seepageFixHeap(int index)
{
	int max;
	int left = (2 * index + 1);
	int right = (2 * index + 2);
	if (left < numOfHighways && heap[left].getKey() > heap[index].getKey())
		max = left;
	else max = index;
	if (right < numOfHighways && heap[right].getKey() > heap[max].getKey())
		max = right;
	if (max != index)
	{
		swap(index, max);
		seepageFixHeap(max);
	}
}

void Metropolyn::swap(int index1, int index2)
{
	HeapNode temp(heap[index1]);
	heap[index1].getHighWay()->setIndexOfminBridgeNode(index2);
	heap[index1] = heap[index2];
	heap[index2].getHighWay()->setIndexOfminBridgeNode(index1);
	heap[index2] = temp;
}

float Metropolyn::getHeapRootKey() const { return heap[ZERO].getKey(); }

const Highway& Metropolyn::getHighWay(int index) const { return highWays[index]; }

void Metropolyn::WhichRoad(float height) // function runtine : Theta(1)
{
	if (height < getHeapRootKey()) // Theta(1)
		cout << "The truck can drive on highway number " << heap[ZERO].getHighWayNum() << endl; // Theta(1)
	else // Theta(1)
		cout << "0" << endl; // Theta(1)
}

