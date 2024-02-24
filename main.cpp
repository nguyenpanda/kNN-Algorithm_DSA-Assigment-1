#include "main.hpp"
#include "kNN.hpp"

using namespace color;
int COUNT_DELETE;

//    tc1();
//void tc1(){
//    Dataset dataset;
//    dataset.loadFromCSV("mnist.csv");
//    dataset.printHead();
//    dataset.printTail();
//    int nRows, nCols;
//    dataset.getShape(nRows, nCols);
//    cout << "Shape: " << nRows << "x" << nCols << endl;
//
//    kNN knn;
//    Dataset X_train, X_test, y_train, y_test;
//    Dataset feature = dataset.extract(0, -1, 1, -1);
//    Dataset label = dataset.extract(0, -1, 0, 0);
//    train_test_split(feature, label, 0.2, X_train, X_test, y_train, y_test);
//
//    knn.fit(X_train, y_train);
//    Dataset y_pred = knn.predict(X_test);
//    double accuracy = knn.score(y_test, y_pred);
//    cout << "Accuracy: " << accuracy << endl;
//}

void get_COUNT_DELETE() {
    cout << "COUNT_DELETE: " << YELLOW_BACKGROUND << COUNT_DELETE << RESET << endl;
}

void test_constructor(int n = 100) {
    auto* list_0 = new ArrayList<int>();
    auto* list_1 = new ArrayList<int>(n);
    auto* list_2 = new ArrayList<int>(*list_1);
    auto* list_3 = new ArrayList<int>();
    *list_3 = *list_2;

    delete list_0;
    delete list_1;
    delete list_2;
    delete list_3;
    get_COUNT_DELETE();
}

void test_0(int n = 10) {
    auto* list_0 = new ArrayList<int>();

    cout << CYAN << "push_back method" << RESET << endl;
    for (int i = 0; i < n; ++i) {
        list_0->push_back(i);
    }
    list_0->info();

    cout << CYAN << "operator []" << RESET << endl;
    for (int i = 0; i < n; ++i) {
        cout << (*list_0)[i] << " ";
    }
    cout << endl;

    cout << CYAN << "Remove method" << RESET << endl;
    for (int i = 0; i < n + 1; ++i) {
        cout << list_0->pop() << endl;
        list_0->print();
    }
    get_COUNT_DELETE();
    /*
     START!
    push_back method
    Cap : 12
    Size: 10
    Data: 0 1 2 3 4 5 6 7 8 9

    operator []
    0 1 2 3 4 5 6 7 8 9
    Remove method
    9
    0 1 2 3 4 5 6 7 8
    8
    0 1 2 3 4 5 6 7
    7
    0 1 2 3 4 5 6
    6
    0 1 2 3 4 5
    5
    0 1 2 3 4
    4
    0 1 2 3
    3
    0 1 2
    2
    0 1
    1
    0
    0
    print(): Empty
    0
    print(): Empty
    END!
     */
}

void test_1(int n = 50) {
    auto* list_0 = new ArrayList<int>();
    cout << CYAN << "push_front method" << RESET << endl;
    for (int i = 0; i < n; ++i) {
        list_0->push_front(i);
    }
    list_0->info();

    auto* list_1 = new ArrayList<int>();
    cout << CYAN << "insert method" << RESET << endl;
    for (int i = 0; i < n; ++i) {
        list_1->insert(i, 2*i);
    }
    list_1->info();

    auto* list_2 = new ArrayList<int>();
    cout << CYAN << "insert method" << RESET << endl;
    for (int i = 0; i < n / 2; ++i) {
        list_2->insert(i, 2*i);
    }
    list_2->info();
    for (int i = n / 2; i < n; ++i) {
        list_2->insert(i + 1, 2*i);
    }
    list_2->info();
    get_COUNT_DELETE();
    /*
    push_front method
    Resizing from [12]->[24]
    Resizing from [24]->[48]
    Resizing from [48]->[96]
    Cap : 96
    Size: 50
    Data: 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0

    insert method
    Resizing from [12]->[24]
    Resizing from [24]->[48]
    Resizing from [48]->[96]
    Cap : 96
    Size: 50
    Data: 0 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30 32 34 36 38 40 42 44 46 48 50 52 54 56 58 60 62 64 66 68 70 72 74 76 78 80 82 84 86 88 90 92 94 96 98

    insert method
    Resizing from [12]->[24]
    Resizing from [24]->[48]
    Cap : 48
    Size: 25
    Data: 0 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30 32 34 36 38 40 42 44 46 48

    Cap : 48
    Size: 25
    Data: 0 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30 32 34 36 38 40 42 44 46 48
     */
}

void test_2(int n = 30) {
    auto* list_0 = new ArrayList<int>();
    cout << CYAN << "push_front method" << RESET << endl;
    for (int i = 0; i < n; ++i) {
        list_0->push_front(i);
    }
    list_0->info();

    list_0->get(0) = -99;

    cout << CYAN << "operator []" << RESET << endl;
    cout << (*list_0)[0] << " " << (*list_0)[n - 1] << endl;

    cout << CYAN << "Accessing out of range" << RESET << endl;
    try {
        cout << (*list_0)[n] << endl;
    } catch (std::out_of_range& e) {
        cout << RED << e.what() << RESET << endl;
    }
    get_COUNT_DELETE();
    /*
    push_front method
    Resizing from [12]->[24]
    Resizing from [24]->[48]
    Cap : 48
    Size: 30
    Data: 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0

    operator []
    -99 0
    Accessing out of range
    get(): Out of range
     */
}

void test_3(int n = 99) {

    get_COUNT_DELETE();
}

int main() {
    cout << GREEN << "START!" << RESET << endl;

    test_constructor();
//    test_0();
//    test_1();
//    test_2();
//    test_3();

    cout << "COUNT_DELETE_FINAL: " << YELLOW_BACKGROUND << COUNT_DELETE << RESET << endl;
    cout << GREEN << "END!" << RESET << endl;
    return 0;
}