#include "kNN.hpp"

template<typename T>
void ArrayList<T>::resize() {
//    cout << MAGENTA << "Resizing" << RESET <<  " from [" << YELLOW << capacity << RESET << "]->[" << YELLOW << capacity*2 << RESET << "]" << endl;
    int new_capacity = capacity * 2;
    capacity = new_capacity;

    T* new_data = new T[new_capacity];
    ++COUNT_DELETE;
    memcpy(new_data, data, sizeof(T&) * size);

    delete[] data;
    --COUNT_DELETE;

    data = new_data;
}

template<typename T>
ArrayList<T>::ArrayList() : data(new T[13]), capacity(13), size(0) {
//    cout << MAGENTA << "ArrayList Constructor()" << RESET << endl;
    ++COUNT_DELETE;
}

template<typename T>
ArrayList<T>::ArrayList(int capacity) : data(new T[capacity]), capacity(capacity), size(0) {
//    cout << MAGENTA << "ArrayList Constructor(int capacity)" << RESET << endl;
    ++COUNT_DELETE;
}

template<typename T>
ArrayList<T>::ArrayList(const ArrayList& other) : data(new T[other.capacity]), capacity(other.capacity), size(other.size) {
    cout << MAGENTA << "ArrayList Copy constructor" << RESET << endl;
    ++COUNT_DELETE;
    memcpy(data, other.data, sizeof(T&) * other.size);
}

template<typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& other) {
    cout << MAGENTA << "ArrayList = operator" << RESET << endl;
    if (this != &other) {
        delete[] data;
        --COUNT_DELETE;
        data = new T[other.capacity];
        ++COUNT_DELETE;

        capacity = other.capacity;
        size = other.size;
        memcpy(data, other.data, sizeof(T&) * other.size);
    }
    return *this;
}

template<typename T>
ArrayList<T>::~ArrayList() {
//    cout << MAGENTA << "ArrayList Destructor" << RESET << endl;
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

    memmove(data + index + 1, data + index, sizeof(T&) * (size - index));
    data[index] = value;
    size++;
}

template<typename T>
void ArrayList<T>::remove(int index) {
    if (index < 0 || index >= size) { return; }

    memmove(data + index, data + index + 1, sizeof(T&) * (size - index - 1));
    size--;
}

template<typename T>
T ArrayList<T>::pop() {
    T value = data[size - 1];
    remove(size - 1);
    return value;
}

template<typename T>
T& ArrayList<T>::get(int index) const {
    if (index < 0 || index >= size) {
        throw out_of_range("ArrayList::get(): Out of range");
    }

    return data[index];
}

template<typename T>
T& ArrayList<T>::operator[](const int index) const {
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
    capacity = 13;
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
        cout << MAGENTA << "ArrayList::print(): Empty" << RESET << endl;
        return;
    }
//    cout << RED << "test" << RESET << endl;
    cout << data[0];
    for (int i = 1; i < size; i++) {
        cout << " " << data[i];
    }
    cout << endl;
}

template<typename T>
void ArrayList<T>::info() const {
    std::cout << YELLOW << "ArrayList::Cap : " << capacity << RESET << std::endl;
    std::cout << YELLOW << "ArrayList::Size: " << size     << RESET << std::endl;
    std::cout << YELLOW << "ArrayList::Data: ";
    for (int i = 0; i < size; i++) {
        cout << ' ' << data[i];
    }
    cout << RESET << endl;

    print();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//void Image::loadLabel() {
//
//}

Image::Image() : ArrayList<int>(28 * 28), label(-1) {};

Image::Image(const Image& other) : ArrayList<int>(other), label(other.label) {}; // NOLINT(*-use-equals-default)

Image::Image(int* pixels, int label, int number_of_pixels) : ArrayList<int>(number_of_pixels), label(label) {
    load(pixels, number_of_pixels);
}

Image::Image(int capacity) : ArrayList<int>(capacity), label(-1) {};

Image& Image::operator=(const Image& other) {
    if (this != &other) {
        ArrayList<int>::operator=(other);
        cout << data << endl;
        cout << capacity << endl;
        cout << size << endl;
        cout << label << endl;

        label = other.label;
    }
    return *this;
}

[[maybe_unused]] int Image::getLabel() const {
    return this->label;
}

void Image::setLabel(int _label) {
    if (_label < 0 || _label > 9) {
        throw invalid_argument("Image::setLabel(): Invalid label, got " + to_string(_label));
    }
    this->label = _label;
}

void Image::load(const int* pixels, int number_of_pixels) {
    setLabel(pixels[0]);
    for (int i = 1; i < number_of_pixels + 1; ++i) {
        ArrayList<int>::push_back(pixels[i]);
    }
}

void Image::load(istringstream& iss, int number_of_pixels) {
    string token;
    getline(iss, token, ',');

    setLabel(stoi(token));

    for (int i = 1; i < number_of_pixels + 1; ++i) {
        getline(iss, token, ',');
        ArrayList<int>::push_back(stoi(token));
    }
}

int&  Image::operator[](int index) const {
    return ArrayList<int>::operator[](index);
}

char get_char(int pixel, bool grey = true, bool highQuality = true) {
    if (grey) { pixel = 255 - pixel; }

    const string chars_1 = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'.";
    const string chars_2 = "@%#*+=-:. ";
    const string chars = highQuality ? chars_1 : chars_2;

    int charIndex = pixel * (int) chars.size() / 256;

    charIndex = min(charIndex, (int) chars.size() - 1);

    return chars[charIndex];
}

void Image::print() const {
    cout << YELLOW << "Image::Label: " << label << RESET << endl;
    for (int i = 0; i < size; ++i) {
        cout << get_char(get(i)) << ' ';
        if ((i + 1) % (int) sqrt(size) == 0) { cout << endl; }
    }

    cout << endl;
}

double Image::distance(const Image& a, const Image& b) {
    int sum = 0;
    for (int i = 0; i < a.size; ++i) {
        int temp = a[i] - b[i];
        sum += temp * temp;
    }
    return sqrt((double) sum);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template
class ArrayList<int>;

template
class ArrayList<int*>;

template
class ArrayList<string>;

template
class ArrayList<ArrayList<int>*>;

template
class ArrayList<Image*>;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Dataset::Dataset() {
    cout << MAGENTA << "Dataset constructor" << RESET << endl;
    data = new ArrayList<Image*>();
    ++COUNT_DELETE;
    featureLabel = new ArrayList<string>(784);
    ++COUNT_DELETE;
}

Dataset::~Dataset() {
    cout << MAGENTA << "Dataset destructor" << RESET << endl;
    for (Image* i : *data) delete i;
    delete data;
    --COUNT_DELETE;
    delete featureLabel;
    --COUNT_DELETE;
}

//Dataset::Dataset(const Dataset& other) {
//    cout << MAGENTA << "Dataset copy constructor" << RESET << endl;
//
//    ++COUNT_DELETE;
//}

void Dataset::loadLabel(istringstream& iss) {
    cout << MAGENTA << "Dataset::loadLabel()" << RESET << endl;
    string token;
    while(getline(iss,token,',')){
        featureLabel->push_back(token);
    }
}

bool Dataset::loadFromCSV(const char* fileName) {
    cout << MAGENTA << "Dataset::loadFromCSV()" << RESET << endl;
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << RED << "Error: " << RESET << "Cannot open file " << fileName << endl;
        return false;
    }

    string line;
    getline(file, line);
    istringstream labelstream(line);        // Load label
    loadLabel(labelstream);

    while (getline(file, line)) { // load each row in dataset
        istringstream iss(line);
        string token;

        auto* row = new Image(784);
        row->load(iss);
        data->push_back(row);
    }

    file.close();

    cout << fileName << endl;
    cout << "Total image in dataset: " << CYAN << data->length() << RESET << endl;

    return true;
}

void Dataset::printHead(int nRows, int nCols) const {
    if (nRows < 0 || nCols < 0) {
        cout << YELLOW << "Dataset::printHead(" << nRows << ", " << nCols << ")" << RESET << endl;
        return;
    }
    if (nRows > data->length()) { nRows = data->length(); }
    if (nCols > featureLabel->length()) { nCols = featureLabel->length(); }
    cout << MAGENTA << "Dataset::printHead(" << nRows << ", " << nCols << ")" << RESET << endl;

    cout << (*featureLabel)[0];
    for (int i = 1; i < nCols; ++i) {
        cout << ' ' << (*featureLabel)[i];
    }
    cout << '\n';

    for (int i = 0; i < nRows; ++i) {
        Image* current = (*data)[i];
        cout << current->getLabel();
        for (int j = 0; j < nCols - 1; ++j) {
            cout << ' ' << (*current)[j];
        }
        cout << '\n';
    }
}

void Dataset::printTail(int nRows, int nCols) const {
    if (nRows < 0 || nCols < 0) {
        cout << YELLOW << "Dataset::printTail(" << nRows << ", " << nCols << ")" << RESET << endl;
        return;
    }
    if (nRows > data->length()) { nRows = data->length(); }
    if (nCols >= featureLabel->length()) { nCols = featureLabel->length(); }

    cout << MAGENTA << "Dataset::printTail(" << nRows << ", " << nCols << ")" << RESET << endl;

    int startCol = featureLabel->length() - nCols;
    int endCol = featureLabel->length();
    int startRow = data->length() - nRows;
    int endRow = data->length();

    cout << (*featureLabel)[startCol];
    for (int i = startCol + 1; i < endCol; ++i) {
        cout << ' ' << (*featureLabel)[i];
    }
    cout << '\n';

    if (startCol <= 0) { startCol = 1; }

    for (int i = startRow; i < endRow; ++i) {
        Image* current = (*data)[i];
        if (startCol == 1) { cout << current->getLabel() << ' '; }
        cout << (*current)[startCol - 1];
        for (int j = startCol; j < endCol - 1; ++j) {
            cout << ' ' << (*current)[j];
        }
        cout << '\n';
    }
}

void Dataset::getShape(int& nRows, int& nCols) const {
    nRows = data->length();
    nCols = featureLabel->length();
}

void Dataset::columns() const {
    cout << MAGENTA << "Dataset::columns()" << RESET << endl;
    cout << (*featureLabel)[0];
    for (int i = 1; i < featureLabel->length(); ++i) {
        cout << ' ' << (*featureLabel)[i];
    }
    cout << '\n';
}

bool Dataset::drop(int axis, int index, const std::string& columns) {
    cout << MAGENTA << "Dataset::drop(" << axis << ", " << index << ", " << columns << ")" << RESET << endl;

    if (axis == 0) {
        if (index < 0 || index >= data->length()) { return false; }
        delete (*data)[index];
        data->remove(index);
    } else if (axis == 1) {
        if (columns.empty()) { return false; }

        int colIndex = -1;
        for (int i = 0; i < featureLabel->length(); ++i) {
            if ((*featureLabel)[i] == columns) {
                colIndex = i-1;
                break;
            }
        }
        cout << RED << "colIndex: " << colIndex << RESET << endl;
        if (colIndex == -1) { return false; }

        for (int i = 0; i < data->length(); ++i) {
            (*data)[i]->remove(colIndex);
        }
        featureLabel->remove(colIndex);

    } else {
        return false;
    }

    return true;
}





