#ifndef myNewQue_H
#define myNewQue_H

#include <string>
#include <iostream>
#include "newNode.h"
using namespace std;
template <class T>
class myNewQue
{
private:
    NewNode<T> *front;
    NewNode<T> *rear;
    int count;
protected:
    // member variables
public:
    // constructors
    myNewQue()
    {
        this->front = nullptr;
        this->rear = nullptr;
        this->count = 0;
    }
    myNewQue(NewNode *node)
    {

        this->front = rear = node;
        if (node)
        {
            count = 1;
        }
        else
        {
            count = 0;
        }
    }
    void enque(NewNode<T> *node)
    {
        if (!node)
        {
            return;
        }
        else
        {
            if (!front)
            {
                this->front = rear = node;
            }
            else
            {
                rear->setNextNode(node);
                rear = node;
            }
            count++;
        }
    }
    void deque()
    {
        if (!front)
        {
            return;
        }
        newNode<T> *temp = front;
        front = front->getNextNode();
        delete temp;
        if (!front)
        {
            front = rear;
        }
        count--;
    }
    NewNode<T> *getFront()
    {
        return front;
    }
    bool isEmpty()
    {
        return front == NULL;
    }
    bool isFull()
    {
        return false;
    }
    int size()
    {
        return count;
    }
    void printQueData()
    {
        cout << "=== Printing queque Data === \n";
        NewNode<T> *temp = front;
        while (temp)
        {
            T data = temp->getNodeData();
            data.print();
            temp = temp->getNextNode();
        }
    }
};

#endif // myNewQue_H