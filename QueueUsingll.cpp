#include <iostream>
#include <conio.h>
using namespace std;

class Node
{
public:
    int data;
    Node *link;

    Node(int value)
    {
        data = value;
        link = nullptr;
    }
};
class QueueImplementation
{
private:
    Node *front;
    Node *rear;

public:
    QueueImplementation()
    {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int value)
    {
        Node *newnode = new Node(value);
        if (isEmpty())
        {
            front = rear = newnode;
        }
        else
        {
            rear->link = newnode;
            rear = newnode;
        }
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return;
        }

        cout << "Dequeue Item is:" << front->data << endl;
        if (rear == front)
        {
            rear = front = nullptr;
        }
        Node *temp = front;
        front = front->link;
        free(temp);
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
        }
        Node *temp = front;
        cout << "Elements in the Queue are:";
        while (temp != rear)
        {
            cout << temp->data << "\t";
            temp = temp->link;
        }
        cout << rear->data;
        cout << endl;
    }

    void frontElement()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        cout << "Front Element of the queue is :" << front->data << endl;
    }
    void rearElment()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        cout << "Rear Element of the queue is:" << rear->data << endl;
    }

    bool isEmpty()
    {
        if (front == nullptr)
        {

            return true;
        }

        return false;
    }
};
int main()
{
    QueueImplementation Qu;
    Qu.enqueue(1);
    Qu.enqueue(2);
    Qu.enqueue(3);
    Qu.enqueue(4);
    Qu.enqueue(5);
    Qu.enqueue(6);
    Qu.display();
    Qu.dequeue();

    Qu.frontElement();
    Qu.rearElment();
    Qu.display();
    Qu.dequeue();

    Qu.frontElement();
    Qu.rearElment();
    Qu.display();
    Qu.enqueue(7);
    Qu.display();
}