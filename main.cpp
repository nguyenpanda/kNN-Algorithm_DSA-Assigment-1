#include "kNN.hpp"

using namespace color;
int COUNT_DELETE;

//    tc1();
//void tc1(){
//    Dataset dataset;
//    dataset.loadFromCSV("init_dataset_199.csv");
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

//[[maybe_unused]] void test_constructor(int n = 100) {
//    auto* list_0 = new ArrayList<int>();
//    auto* list_1 = new ArrayList<int>(n);
//    auto* list_2 = new ArrayList<int>(*list_1);
//    auto* list_3 = new ArrayList<int>();
//    *list_3 = *list_2;
//
//    delete list_0;
//    delete list_1;
//    delete list_2;
//    delete list_3;
//    get_COUNT_DELETE();
//}
//[[maybe_unused]] void test_iterator(int n = 30) {
//    auto* list_0 = new ArrayList<int>();
//    cout << CYAN << "push_back method" << RESET << endl;
//    for (int i = 0; i < n; ++i) {
//        list_0->push_back(i);
//    }
//    list_0->info();
//
//    cout << CYAN << "iterator, normal for" << RESET << endl;
//    for (auto it = list_0->begin(); it != list_0->end(); ++it) { // NOLINT(*-loop-convert)
//        cout << *it << " ";
//    }
//    cout << endl;
//
//    cout << CYAN << "iterator, range-base" << RESET << endl;
//    for (int& i : *list_0) {
//        cout << i << " ";
//    }
//    cout << endl;
//
//
//    delete list_0;
//    get_COUNT_DELETE();
//}
//
//[[maybe_unused]] void test_0(int n = 10) {
//    auto* list_0 = new ArrayList<int>();
//
//    cout << CYAN << "push_back method" << RESET << endl;
//    for (int i = 0; i < n; ++i) {
//        list_0->push_back(i);
//    }
//    list_0->info();
//
//    cout << CYAN << "operator []" << RESET << endl;
//    for (int i = 0; i < n; ++i) {
//        cout << (*list_0)[i] << " ";
//    }
//    cout << endl;
//
//    cout << CYAN << "Remove method" << RESET << endl;
//    for (int i = 0; i < n + 1; ++i) {
//        cout << list_0->pop() << endl;
//        list_0->print();
//    }
//
//    delete list_0;
//    get_COUNT_DELETE();
//}
//
//[[maybe_unused]] void test_1(int n = 50) {
//    auto* list_0 = new ArrayList<int>();
//    cout << CYAN << "push_front method" << RESET << endl;
//    for (int i = 0; i < n; ++i) {
//        list_0->push_front(i);
//    }
//    list_0->info();
//
//    auto* list_1 = new ArrayList<int>();
//    cout << CYAN << "insert method" << RESET << endl;
//    for (int i = 0; i < n; ++i) {
//        list_1->insert(i, 2*i);
//    }
//    list_1->info();
//
//    auto* list_2 = new ArrayList<int>();
//    cout << CYAN << "insert method" << RESET << endl;
//    for (int i = 0; i < n / 2; ++i) {
//        list_2->insert(i, 2*i);
//    }
//    list_2->info();
//    for (int i = n / 2; i < n; ++i) {
//        list_2->insert(i + 1, 2*i);
//    }
//    list_2->info();
//
//    delete list_0;
//    delete list_1;
//    delete list_2;
//    get_COUNT_DELETE();
//}
//
//[[maybe_unused]] void test_2(int n = 30) {
//    auto* list_0 = new ArrayList<int>();
//    cout << CYAN << "push_front method" << RESET << endl;
//    for (int i = 0; i < n; ++i) {
//        list_0->push_front(i);
//    }
//    list_0->info();
//
//    list_0->get(0) = -99;
//
//    cout << CYAN << "operator []" << RESET << endl;
//    cout << (*list_0)[0] << " " << (*list_0)[n - 1] << endl;
//
//    cout << CYAN << "Accessing out of range" << RESET << endl;
//    try {
//        cout << (*list_0)[n] << endl;
//    } catch (std::out_of_range& e) {
//        cout << RED << e.what() << RESET << endl;
//    }
//
//    delete list_0;
//    get_COUNT_DELETE();
//}
//
//[[maybe_unused]] void test_3(int n = 20) {
//    auto* list_0 = new ArrayList<int>();
//    cout << CYAN << "insert method" << RESET << endl;
//    for (int i = 0; i < n; ++i) {
//        list_0->insert(i, i * 3);
//    }
//    list_0->info();
//
//    cout << CYAN << "reverse method" << RESET << endl;
//    list_0->reverse();
//    list_0->info();
//
//    auto* list_1 = new ArrayList<int>(21);
//    cout << CYAN << "push_front method" << RESET << endl;
//    for (int i = 0; i < n; ++i) {
//        list_1->push_front(2*i);
//    }
//    list_1->info();
//
//    cout << CYAN << "clear method" << RESET << endl;
//    list_1->clear();
//    list_1->info();
//
//
//    delete list_0;
//    get_COUNT_DELETE();
//}



int main() {
    cout << GREEN << "START!" << RESET << endl;

//    test_constructor();
//    test_iterator();
//    test_0();
//    test_1();
//    test_2();
//    test_3();


    cout << "COUNT_DELETE_FINAL: " << YELLOW_BACKGROUND << COUNT_DELETE << RESET << endl;
    cout << GREEN << "END!" << RESET << endl;
    return 0;
}