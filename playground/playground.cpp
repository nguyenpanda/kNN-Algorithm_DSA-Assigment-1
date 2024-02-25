//
// Created by Hà Tường Nguyên on 2/25/24.
//

#include "playground.h"

template<typename T>
class List {
    T* data;
    int size;

public:
    List(T* data, int size) {
        this->data = data;
        this->size = size;
    }

    T* begin() {
        return data;
    }

    T* end() {
        return data + size;
    }

    const T* begin() const {
        return data;
    }

    const T* end() const {
        return data + size;
    }

};

int main() {
    cout << GREEN << "START" << RESET << endl;

    int data[] = {1, 2, 3, 4, 5};

    List<int> list_0(data, 5);

    for (auto it = list_0.begin(); it != list_0.end(); ++it) {
        cout << *it << " ";
    }

    cout << "---" << endl;

    for (int& i : list_0) {
        cout << i << " ";
    }

    cout << GREEN << "END" << RESET << endl;
    return 0;
}
