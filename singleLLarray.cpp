#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

// Node structure
struct Node {
    int data;
    int next; // Index of the next node in the array
};

class SinglyLinkedListArray {
private:
    Node list[MAX_SIZE]; // Array to store nodes
    int head; // Index of the head node
    int freeList; // Index of the first free node

public:
    // Constructor
    SinglyLinkedListArray() {
        head = -1;
        freeList = 0;
        for (int i = 0; i < MAX_SIZE - 1; ++i) {
            list[i].next = i + 1; // Linking all nodes to form the free list
        }
        list[MAX_SIZE - 1].next = -1; // Marking the last node as the end of the free list
    }

    // Function to insert a new node at the beginning of the list
    void insert(int value) {
        if (freeList != -1) { // If there's space available in the array
            int newIndex = freeList; // Index of the new node
            freeList = list[freeList].next; // Update the free list

            list[newIndex].data = value;
            list[newIndex].next = head;
            head = newIndex;
        } else {
            cout << "No space available to insert new node." << endl;
        }
    }

    // Function to display the linked list
    void display() {
        int current = head;
        cout << "Linked List: ";
        while (current != -1) {
            cout << list[current].data << " ";
            current = list[current].next;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedListArray myList;

    // Insert some nodes
    myList.insert(5);
    myList.insert(10);
    myList.insert(15);
    myList.insert(20);

    // Display the list
    myList.display();

    return 0;
}
