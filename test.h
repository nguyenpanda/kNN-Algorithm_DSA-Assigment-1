//
// Created by Hà Tường Nguyên on 2/23/24.
//

#ifndef DSA_ASSIGNMENT_TEST_H
#define DSA_ASSIGNMENT_TEST_H

#include "kNN.hpp"
#include <iomanip>

template<typename T>
class List {
public:
    virtual ~List() = default;
    virtual void push_back(T value) = 0;
//    virtual void push_back(T value) = 0;
//    virtual void push_front(T value) = 0;
//    virtual void insert(int index, T value) = 0;
//    virtual void remove(int index) = 0;
//    virtual T& get(int index) const = 0;
//    virtual int length() const = 0 ;
//    virtual void clear() = 0;
    virtual void print() const = 0;
//    virtual void reverse() = 0;
};


template<typename name>
class Node {
public:
    name data;
    Node<name>* next;
    Node<name>* prev;
    explicit Node(name data, Node<name>* next = nullptr, Node<name>* prev = nullptr)
        : data(data), next(next), prev(prev) {}
};


template<typename T>
class ArrayList : public List<T> {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    ArrayList() : head(nullptr), tail(nullptr), size(0) {}
    ~ArrayList() {
        clear();
    }
    void push_back(T value) override {
        if (head == nullptr) {
            head = tail = new Node<T>(value);
        } else {
            tail->next = new Node<T>(value, nullptr, tail);
            tail = tail->next;
        }
        size++;
    }
    void print() const override {
        Node<T>* cur = head;
        while (cur != nullptr) {
            std::cout << cur->data << " ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }
    void clear() {
        while (head != nullptr) {
            Node<T>* cur = head;
            head = head->next;
            delete cur;
        }
        tail = nullptr;
        size = 0;
    }
    int length() const {
        return size;
    }
    void reverse() {
        Node<T>* cur = head;
        while (cur != nullptr) {
            Node<T>* temp = cur->next;
            cur->next = cur->prev;
            cur->prev = temp;
            cur = temp;
        }
        Node<T>* temp = head;
        head = tail;
        tail = temp;
    }
    void push_front(T value) {
        if (head == nullptr) {
            head = tail = new Node<T>(value);
        } else {
            head->prev = new Node<T>(value, head);
            head = head->prev;
        }
        size++;
    }
    void insert(int index, T value) {
        if (index < 0 || index > size) {
            throw std::out_of_range("Index out of range");
        }
        if (index == 0) {
            push_front(value);
        } else if (index == size) {
            push_back(value);
        } else {
            Node<T>* cur = head;
            for (int i = 0; i < index; i++) {
                cur = cur->next;
            }
            Node<T>* newNode = new Node<T>(value, cur, cur->prev);
            cur->prev->next = newNode;
            cur->prev = newNode;
            size++;
        }
    }
    void remove(int index) {
        if (index < 0 || index >= size) {
            throw std
};



#endif //DSA_ASSIGNMENT_TEST_H
