#include "Highway.h"
#include "Bridge.h"

Highway::Highway()
{
	indexOfminBridgeNode = -1;
	Bridge* dummy = new Bridge(-1, nullptr); // dummy head for the linked list
	head = tail = dummy;
}

void Highway::addBridge(const Bridge& bridge)
{
	Bridge* newBridge = new Bridge(bridge);
	tail->setNext(newBridge);
	tail = newBridge;
}

void Highway::printBridges() const
{
	Bridge* curr = head->getNext();
	while (curr != nullptr)
	{
		cout << curr->getHeight() << " ";
		curr = curr->getNext();
	}
}

