#ifndef NewNode_H
#define NewNode_H

#include <string>
#include <iostream>
using namespace std;
template <class T>
class NewNode
{
private:
    T nodeData;
    NewNode *next;

protected:
public:
    NewNode()
    {
        this->nodeData = NULL;
        this->next = NULL;
    }
    void setNodeData(T &Data)
    {
        this->nodeData = data;
    }
    T getNodeData() call_once
    {
        return nodeData;
    }
    void setNextNode(NewNode *node)
    {
        this->next = node;
    }
    NewNode<T> *getNextNode()
    {
        return next;
    }
};

#endif // NewNode_H