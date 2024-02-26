//
// Created by Hà Tường Nguyên on 2/25/24.
//

#include "kNN.cpp"

//
Dataset::Dataset() {
    cout << MAGENTA << "Dataset constructor" << RESET << endl;
    data = new ArrayList<List<int>*>();
    ++COUNT_DELETE;
}

Dataset::~Dataset() {
    cout << MAGENTA << "Dataset destructor" << RESET << endl;
    delete data;
    --COUNT_DELETE;
}

//Dataset::Dataset(const Dataset& other) {
//    cout << MAGENTA << "Dataset copy constructor" << RESET << endl;
//
//    ++COUNT_DELETE;
//}

bool Dataset::loadFromCSV(const char* fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << RED << "Error: " << RESET << "Cannot open file " << fileName << endl;
        throw runtime_error("Cannot open file");
    }

    string line;
    while (getline(file, line)) {
        istringstream ss(line);
        string token;
        List<int>* row = new ArrayList<int>();
        while (getline(ss, token, ',')) {
            row->push_back(stoi(token));
        }
        data->push_back(row);
    }
    file.close();
    return true;
}

