#include <iostream>
#include <queue>
using namespace std;
#define max 5

class QueueOperations
{
public:
    int queue[max];
    int front = -1;
    int rear = -1;

    void enqueue(int item)
    {
        if (((rear + 1) % max) == front) // checks if queue is full or not -> this step affect only when rear=max-1;
        {
            cout << "Queue overflow" << endl;
        }
        else if (front == -1 && rear == -1)
        {
            front = rear = 0; // means both front and rear is pointing same index so item will be enqued
            queue[rear] = item;
            cout << "Enqued item is:" << item << endl;
        }
        else
        {
            rear = (rear + 1) % max;
            queue[rear] = item; // after first element is enqued then we should always enqueue item from
                                // rear so in circular queue it should point to index o after last index.
            cout << "Enqued item is:" << item << endl;
        }
    }
    void dequeue()
    {
        if (front == -1 & rear == -1)
        {
            cout << "Queue is underflow" << endl;
        }
        else if (front == rear)
        {
            cout << "Deque item is:" << queue[front] << endl;
            front = rear = -1; // both front and rear is same so after dequeing queue will be empty
        }
        else
        {
            cout << "Deque item is:" << queue[front] << endl;
            front = (front + 1) % max; // after dequeuing index shifts to next as we always deque from front so we increase the index of front
        }
    }
    void peek()
    {
        if (front == -1 & rear == -1)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << "Front of the queue is:" << queue[front] << endl;
        }
    }
    void display()
    {
        if (front == -1 & rear == -1)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << "Queue items are:" << endl;
            int i = front;
            while (i != rear) // stating from front to index equal to rear after that queue will be empty
            {
                cout << queue[i] << "\t";
                i = (i + 1) % max;
            }
            cout << queue[rear] << "\t";
            cout << "\n";
        }
    }
};

int main()
{
    QueueOperations qu;
    qu.enqueue(1);
    qu.enqueue(2);
    qu.enqueue(3);
    qu.enqueue(4);
    qu.enqueue(5);
    qu.peek();
    qu.display();
    qu.dequeue();
    qu.dequeue();
    qu.dequeue();
    qu.enqueue(6);
    qu.enqueue(7);
    qu.enqueue(8); // now this doesnt result in queue overflow
    qu.display();
}