#include <iostream>
using namespace std;

class MyCircularQueue {
private:
    int *queue;
    int front, rear, size, capacity;

public:
    MyCircularQueue(int k) {
        capacity = k;
        queue = new int[k];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~MyCircularQueue() {
        delete[] queue;
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % capacity;
        queue[rear] = value;
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    int Front() {
        return isEmpty() ? -1 : queue[front];
    }

    int Rear() {
        return isEmpty() ? -1 : queue[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

int main() {
    MyCircularQueue cq(3); // capacity = 3

    cout << cq.enQueue(10) << endl; // true
    cout << cq.enQueue(20) << endl; // true
    cout << cq.enQueue(30) << endl; // true
    cout << cq.enQueue(40) << endl; // false (queue full)

    cout << cq.Rear() << endl;      // 30
    cout << cq.isFull() << endl;    // true
    cout << cq.deQueue() << endl;   // true
    cout << cq.enQueue(40) << endl; // true
    cout << cq.Rear() << endl;      // 40

    return 0;
}
