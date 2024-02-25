#include "main.hpp"

/* TODO: Please design your data structure carefully so that you can work with the given dataset
 *       in this assignment. The below structures are just some suggestions.
 */

template<typename T>
class List {
public:
    virtual ~List() = default;

    virtual void push_back(T value) = 0;

    virtual void push_front(T value) = 0;

    virtual void insert(int index, T value) = 0;

    virtual void remove(int index) = 0;

    virtual T& get(int index) const = 0;

    virtual int length() const = 0;

    virtual void clear() = 0;

    virtual void print() const = 0;

    virtual void reverse() = 0;
};

//class kNN {
//private:
//    int k;
//    //You may need to define more
//public:
//    kNN(int k = 5);
//    void fit(const Dataset& X_train, const Dataset& y_train);
//    Dataset predict(const Dataset& X_test);
//    double score(const Dataset& y_test, const Dataset& y_pred);
//};
//
//void train_test_split(Dataset& X, Dataset& y, double test_size,
//                        Dataset& X_train, Dataset& X_test, Dataset& y_train, Dataset& y_test);

// Please add more or modify as needed

template<typename T>
class ArrayList : public List<T> {
protected:
    T* data;
    int capacity;
    int size;

    void resize();

public:
    ArrayList();

    explicit ArrayList(int capacity);

    ArrayList(const ArrayList& other);

    ArrayList& operator=(const ArrayList& other);

    ~ArrayList() override;

    int length() const override;

    void remove(int index) override;

    T pop();

    void push_back(T value) override;

    void push_front(T value) override;

    void insert(int index, T value) override;

    T& get(int index) const override;

    virtual T& operator[](int index) const;

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

    void clear() override;

    void reverse() override;

    void print() const override;

    void info() const;
};


class Image : public ArrayList<int> {
private:
    int label;

    void setLabel(int label);

public:
    Image();

    Image(const Image& other);

    Image& operator=(const Image& other);

    int getLabel() const;

    void load(const int* pixels, int number_of_pixels = 28 * 28);

    void load(const string& token, int number_of_pixels = 28 * 28);

    int& operator[](int index) const final;

    void print() const final;

    static double distance(const Image& a, const Image& b) {
        int sum = 0;
        for (int i = 0; i < a.size; ++i) {
            int temp = a[i] - b[i];
            sum += temp * temp;
        }
        return sqrt((double) sum);
    }
};



class Dataset {
private:
    ArrayList<List<int>*>* data;

public:
    Dataset();

    ~Dataset();

//    Dataset(const Dataset& other);

//    Dataset& operator=(const Dataset& other);

    bool loadFromCSV(const char* fileName);

//    void printHead(int nRows = 5, int nCols = 5) const;

//    void printTail(int nRows = 5, int nCols = 5) const;

//    void getShape(int& nRows, int& nCols) const;

//    void columns() const;

//    bool drop(int axis = 0, int index = 0, std::string columns = "");

//    Dataset extract(int startRow = 0, int endRow = -1, int startCol = 0, int endCol = -1) const;
};