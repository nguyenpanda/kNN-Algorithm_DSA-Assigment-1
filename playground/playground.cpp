//
// Created by Hà Tường Nguyên on 2/25/24.
//

#include "playground.h"

template<class T>
class DLinkedList {
public:
    class Node; // Forward declaration

protected:
    Node* head;
    Node* tail;
    int count;

public:
    DLinkedList() : head(nullptr), tail(nullptr), count(0) {};

    void add(const T& e);

    void add(int index, const T& e);

    int size();

    void toString() const;
public:
    class Node {
    private:
        T data;
        Node* next;
        Node* previous;

        friend class DLinkedList<T>;

    public:
        Node() {
            this->previous = nullptr;
            this->next = nullptr;
        }

        explicit Node(const T& data) {
            this->data = data;
            this->previous = nullptr;
            this->next = nullptr;
        }
    };
};

template<class T>
void DLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    Node* newNode = new Node(e);

    if (count == 0) {
        head = tail = newNode;
        ++count;
        return;
    }

    tail->next = newNode;
    newNode->previous = tail;
    tail = newNode;
    ++count;
}

template<class T>
void DLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */

    if (count == 0) {
        add(e);
        return;
    }

    Node* newNode = new Node(e);
    Node* current;

    if (index <= (int) count / 2) {
        current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        newNode->next = current->next;
        newNode->previous = current;
        current->next = newNode;
        current = current->next;
        current->previous = newNode;
    } else {
        current = tail;
        for (int i = count; i > index + 1; --i) {
            current = current->previous;
        }
        newNode->previous = current->previous;
        newNode->next = current;
        current->previous = newNode;
        current = current->previous;
        current->next = newNode;
    }
    ++count;
}

template<class T>
int DLinkedList<T>::size() {
    /* Return the length (size) of list */
    return count;
}

template<typename T>
void DLinkedList<T>::toString() const {
    if (head == nullptr) {
        cout << "Empty" << endl;
        return;
    }

    Node* current = head;
    for (int i = 0; i < count - 1; ++i) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}



int main() {
    cout << GREEN << "START" << RESET << endl;

    cout << sizeof(char) << endl;



//    DLinkedList<int> list;
//    int size = 10;
//    for(int idx=0; idx < size; idx++){
//       list.add(0, idx);
//       list.toString();
//    }
//    cout << " -- " << endl;
//    list.toString();

    cout << GREEN << "END" << RESET << endl;

    return 0;
}


//template<typename T>
//class ArrayQueue {
//private :
//    int capacity;
//    int front;
//    int rear;
//    T* storage;
//public :
//    explicit ArrayQueue(int capacity) : capacity(capacity), front(-1), rear(-1), storage(new T[capacity]) {};
//
//    ~ArrayQueue() {
//        delete[] storage;
//    }
//
//    void enQueue(int value) {
//        if (isFull()) throw overflow_error("Queue is full");
//        if (front == -1) front = 0;
//        rear++;
//        storage[rear % capacity] = value;
//    }
//
//    void deQueue(int& valueOut) {
//        if (isEmpty()) throw overflow_error("Queue is empty");
//        valueOut = storage[front % capacity];
//        front++;
//    }
//
//    T deQueue() {
//        if (isEmpty()) throw overflow_error("Queue is empty");
//        T temp = storage[front % capacity];
//        front++;
//        return temp;
//    }
//
//    int getFront() {
//        if (isEmpty()) throw overflow_error("Queue is empty");
//        return storage[front % capacity];
//    }
//
//    int getRear() {
//        if (isEmpty()) throw overflow_error("Queue is empty");
//        return storage[rear % capacity];
//    }
//
//    T peek() {
//        if (isEmpty()) {
//            cout << RED << "Queue is empty" << RESET << endl;
//            return T();
//        }
//        return storage[front];
//    }
//
//    bool isEmpty() {
//        return front == -1 || front > rear;
//    }
//
//    bool isFull() {
//        return rear == capacity - 1;
//    }
//
//    int getSize() {
//        return rear - front + 1;
//    }
//
//    void clear() {
//        front = rear = -1;
//    }
//
//    void print() {
//        if (isEmpty()) {
//            cout << RED << "Queue is empty" << RESET << endl;
//            return;
//        }
//        cout << "Queue: ";
//        for (int i = front; i <= rear; i++) {
//            cout << storage[i] << ' ';
//        }
//        cout << endl;
//    }
//};