#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

template <typename T>
class MyVector {
public:

    MyVector(int capacity = 1);
    ~MyVector();
    MyVector(const MyVector<T>& other); // Copy constructor
    int getCapacity() const { return capacity; }
    void push_back(const T& value);
    T pop_back(void);    
    void print()const;
    T& at(int index);

    void clear();
    void getSize() const;
    void push_front(const T& value);
    void insert(int pos, const T& value);


private:
    void allocate_memory(int memory_size);
    
    int *elements;
    int size;
    int capacity;



};







#endif