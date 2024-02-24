#include "main.hpp"
#include "kNN.hpp"

using namespace color;
int COUNT_DELETE;

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

void test_0() {
    auto* list_0 = new ArrayList<int>();

    int n = 10;

    cout << CYAN << "push_back method" << RESET << endl;
    for (int i = 0; i < n; ++i) {
        list_0->push_back(i);
    }
    list_0->print();

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
}

void test_1() {
    auto* list_0 = new ArrayList<int>();

    int n = 10;

    list_0->push_back(1);
    list_0->info();

    list_0->remove(0);
    list_0->info();
}


int main() {
//    tc1();
    cout << GREEN << "START!" << RESET << endl;

    test_0();
//    test_1();

//    {
//        auto* list_0 = new ArrayList<ArrayList<int>*>();
//
//        for (int i = 0; i < 30; ++i) {
//            list_0->push_back(new ArrayList<int>());
//
//            for (int j = 0; j < 30; ++j) {
//                list_0->get(i)->push_back(j);
//                list_0[]
//            }
//        }
//
//        for (int i = 0; i < 30; ++i) {
//            list_0->get(i)->print();
//        }
//    }

//    cout << COUNT_DELETE << endl;

    cout << GREEN << "END!" << RESET << endl;
    return 0;
}