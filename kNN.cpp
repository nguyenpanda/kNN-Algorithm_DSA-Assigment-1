#include "kNN.hpp"

/*
 *
 */

template<typename T>
void ArrayList<T>::info() const {
    std::cout << YELLOW << "Cap : " << capacity << RESET << std::endl;
    std::cout << YELLOW << "Size: " << size     << RESET << std::endl;
    std::cout << YELLOW << "Data: ";
    print();
    std::cout << RESET << std::endl;
}

template<typename T>
void ArrayList<T>::resize() {
    cout << MAGENTA << "Resizing" << RESET <<  " from [" << YELLOW << capacity << RESET << "]->[" << YELLOW << capacity*2 << RESET << "]" << endl;
    int new_capacity = capacity * 2;
    T* new_data = new T[new_capacity];
    ++COUNT_DELETE;
    memcpy(new_data, data, sizeof(T) * size); // NOLINT(*-sizeof-expression)

    delete[] data;
    --COUNT_DELETE;
    data = new_data;
    capacity = new_capacity;
}

template<typename T>
T& ArrayList<T>::pop() {
    T value = data[size - 1];
    remove(size - 1);
    return value;
}

/*
 *
 */

template<typename T>
ArrayList<T>::ArrayList() : data(new T[12]), capacity(12), size(0) {
    cout << MAGENTA << "Constructor()" << RESET << endl;
    ++COUNT_DELETE;
}

template<typename T>
ArrayList<T>::ArrayList(int capacity) : data(new T[capacity]), capacity(capacity), size(0) {
    cout << MAGENTA << "Constructor(int capacity)" << RESET << endl;
    ++COUNT_DELETE;
}

template<typename T>
ArrayList<T>::ArrayList(ArrayList& other) : data(new T[other.capacity]), capacity(other.capacity), size(other.size) {
    cout << MAGENTA << "Copy constructor" << RESET << endl;
    ++COUNT_DELETE;
    memcpy(&data, &other.data, sizeof(T) * other.size);  // NOLINT(*-sizeof-expression)
}

template<typename T>
ArrayList<T>& ArrayList<T>::operator=(ArrayList<T> const& other) {
    cout << MAGENTA << "= operator" << RESET << endl;
    if (this != &other) {
        delete[] data;
        --COUNT_DELETE;

        capacity = other.capacity;
        size = other.size;
        data = new T[other.capacity];
        ++COUNT_DELETE;

        memcpy(&data, &other.data, sizeof(T) * other.size); // NOLINT(*-sizeof-expression)
    }
    return *this;
}

template<typename T>
ArrayList<T>::~ArrayList() {
    cout << MAGENTA << "Destructor" << RESET << endl;
    delete[] data;
    --COUNT_DELETE;
}

template<typename T>
void ArrayList<T>::push_back(T value) {
    if (size == capacity) { resize(); }
    data[size++] = value;
}

template<typename T>
void ArrayList<T>::push_front(T value) {
    insert(0, value);
}

template<typename T>
void ArrayList<T>::insert(int index, T value) {
    if (index < 0 || index > size) { return; }
    if (size == capacity) { resize(); }

    memmove(data + index + 1, data + index, sizeof(T) * (size - index)); // NOLINT(*-sizeof-expression)
    data[index] = value;
    size++;
}

template<typename T>
void ArrayList<T>::remove(int index) {
    if (index < 0 || index >= size) { return; }

    memmove(data + index, data + index + 1, sizeof(T) * (size - index - 1)); // NOLINT(*-sizeof-expression)
    size--;
}

template<typename T>
T& ArrayList<T>::get(int index) const {
    if (index < 0 || index >= size) {
        throw out_of_range("get(): Out of range");
    }

    return data[index];
}

template<typename T>
T& ArrayList<T>::operator[](int index) {
    return get(index);
}

template<typename T>
int ArrayList<T>::length() const {
    return size;
}

template<typename T>
void ArrayList<T>::clear() {
    delete[] data;
    --COUNT_DELETE;
    data = new T[capacity];
    ++COUNT_DELETE;
    capacity = 12;
    size = 0;
}

template<typename T>
void ArrayList<T>::reverse() {
    int i = 0;
    int j = size - 1;
    while (i < j) {
        swap(data[i++], data[j--]);
    }
}

template<typename T>
void ArrayList<T>::print() const {
    if (size == 0) {
        cout << MAGENTA << "print(): Empty" << RESET << endl;
        return;
    }

    cout << data[0];
    for (int i = 1; i < size; i++) {
        cout << " " << data[i];
    }
    cout << endl;
}


template
class ArrayList<int>;

template
class ArrayList<ArrayList<int>*>;
