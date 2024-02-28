//
// Created by Hà Tường Nguyên on 2/25/24.
//

#include "playground.h"

template<typename T>
class ArrayQueue {
private :
    int capacity;
    int front;
    int rear;
    T* storage;
public :
    explicit ArrayQueue(int capacity) : capacity(capacity), front(-1), rear(-1), storage(new T[capacity]) {};

    ~ArrayQueue() {
        delete[] storage;
    }

    void enQueue(int value) {
        if (isFull()) throw overflow_error("Queue is full");
        if (front == -1) front = 0;
        rear++;
        storage[rear % capacity] = value;
    }

    void deQueue(int& valueOut) {
        if (isEmpty()) throw overflow_error("Queue is empty");
        valueOut = storage[front % capacity];
        front++;
    }

    T deQueue() {
        if (isEmpty()) throw overflow_error("Queue is empty");
        T temp = storage[front % capacity];
        front++;
        return temp;
    }

    int getFront() {
        if (isEmpty()) throw overflow_error("Queue is empty");
        return storage[front % capacity];
    }

    int getRear() {
        if (isEmpty()) throw overflow_error("Queue is empty");
        return storage[rear % capacity];
    }

    T peek() {
        if (isEmpty()) {
            cout << RED << "Queue is empty" << RESET << endl;
            return T();
        }
        return storage[front];
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    int getSize() {
        return rear - front + 1;
    }

    void clear() {
        front = rear = -1;
    }

    void print() {
        if (isEmpty()) {
            cout << RED << "Queue is empty" << RESET << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << storage[i] << ' ';
        }
        cout << endl;
    }
};

int main() {
    cout << GREEN << "START" << RESET << endl;



    cout << GREEN << "END" << RESET << endl;
    return 0;
}
