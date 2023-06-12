// platon.kastric@gmail.com

#ifndef __Array__
#define __Array__

#include <iostream>

template<typename T>
class Array {
    T* a;
    size_t size;
public:
    // create empty array with 1 element
    Array(); 

    // create empty array with n elements
    Array(size_t n); 

    // create array of value's with n elements
    Array(size_t n, T value); 

    // create copy of arr
    Array(const Array<T>& arr); 

    // destructor
    ~Array(); 

    // resize array to size n
    void resize(size_t n); 

    // print all elements of array
    void print() const; 

    // find index of element with value is equal to key
    int find_index(T key) const; 

    // initilize array with size and values from keyboard
    void initialize(); 

    // sort array (bubble sort)
    void sort(); 

    // add one element to the position pos (to the end by default)
    void push(T value, int pos = -1); 

    // delete element at the position pos (the last element by default)
    void pop(int pos = -1); 

    // get size of array
    size_t get_size() const; 

    // element - by - element addition
    template<typename U>
    friend Array<U> operator + (const Array<U>&, const Array<U>&); 
    
    // element - by - element subtraction
    template<typename U>
    friend Array<U> operator - (const Array<U>&, const Array<U>&); 

    // add one element to the end of the array
    Array<T>& operator += (T value); 

    // delete one element from array with value = key
    Array<T>& operator -= (T key); 

    // assignment of array
    Array<T>& operator = (const Array<T>); 

    // comparison of two arrays
    template<typename U>
    friend bool operator == (const Array<U>&, const Array<U>&); 

    // taking an element with a given index
    T& operator [] (int) const; 

    // output on the screen
    template<typename U>
    friend std::ostream& operator << (std::ostream& out, const Array<U>); 

    // input all elements from keyboard
    template<typename U>
    friend std::istream& operator >> (std::istream& in, Array<U>&); 
};

template<typename T>
Array<T>::Array()
{
    a = new T[1];
    size = 1;
}

template<typename T>
Array<T>::Array(size_t n) {
    a = new T[n];
    size = n;
}

template<typename T>
Array<T>::Array(size_t n, T value) {
    a = new T[n];
    size = n;
    for (int i = 0; i < size; i++) {
        a[i] = value;
    }
}

template<typename T>
Array<T>::Array(const Array<T>& arr)
{
    size = arr.size;
    a = new T[size];
    for (int i = 0; i < size; i++) {
        a[i] = arr[i];
    }
}

template<typename T>
Array<T>::~Array()
{
    delete [] a;
}

template<typename T>
void Array<T>::resize(size_t n)
{
    Array<T> temp(*this);
    size = n;
    delete[] a;
    a = new T[size];
    for (int i = 0; i < size && i < temp.size; i++)
        a[i] = temp[i];
}

template<typename T>
void Array<T>::print() const
{
    for (int i = 0; i < size; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}

template<typename T>
int Array<T>::find_index(T key) const
{
    for (int i = 0; i < size; i++) {
        if (a[i] == key) {
            return i;
        }
    }
    return -1;
}

template<typename T>
void Array<T>::initialize()
{
    std::cout << "Enter size of array: ";
    std::cin >> size;
    delete[] a;
    a = new T[size];
    for (int i = 0; i < size; i++) {
        std::cout << i + 1 << ". element: ";
        std::cin >> a[i];
    }
}

template<typename T>
void Array<T>::sort() //bubble sort
{
    for (int i = 0; i < size - 1; i++) {
        T max_el = a[0];
        int max_index = 0;
        for (int j = 0; j < size - i; j++) {
            if (a[j] > max_el) {
                max_el = a[j];
                max_index = j;
            }
        }
        a[max_index] = a[size - i - 1];
        a[size - i - 1] = max_el;
    }
}

template<typename T>
void Array<T>::push(T value, int pos)
{   
    resize(size + 1);
    if (pos == -1) {
        a[size - 1] = value;
    }
    else {
        for (int i = size -1; i > pos; i--) {
            a[i] = a[i - 1];
        }
        a[pos] = value;
    }
}

template<typename T>
void Array<T>::pop(int pos)
{
    if (pos != -1) {
        for (int i = pos; i < size - 1; i++) {
            a[i] = a[i + 1];
        }
    }
    resize(size - 1);
}

template<typename T>
size_t Array<T>::get_size() const
{
    return size;
}

template<typename T>
Array<T>& Array<T>::operator+=(T value)
{
    resize(size + 1);
    a[size - 1] = value;
    return *this;
}

template<typename T>
Array<T>& Array<T>::operator-=(T key)
{
    int i = find_index(key);
    for (; i < size - 1; i++) 
        a[i] = a[i + 1];
    resize(size - 1);
    return *this;
}

template<typename T>
Array<T>& Array<T>::operator = (const Array<T> arr)
{
    delete[] a;
    size = arr.size;
    a = new T[size];
    for (int i = 0; i < size; i++)
        a[i] = arr[i];
    return *this;
}

template<typename T>
T& Array<T>::operator[] (int index) const
{
    return a[index];
}

template<typename U>
Array<U> operator+(const Array<U>& a1, const Array<U>& a2)
{
    Array<U> res;
    if (a1.size > a2.size) {
        res = a1;
        for (int i = 0; i < a2.size; i++)
            res[i] += a2[i];
    }
    else {
        res = a2;
        for (int i = 0; i < a1.size; i++)
            res[i] += a1[i];
    }
    return res;
}

template<typename U>
Array<U> operator-(const Array<U>& a1, const Array<U>& a2)
{
    Array<U> res;
    if (a1.size > a2.size) {
        res = a1;
        for (int i = 0; i < a2.size; i++)
            res[i] -= a2[i];
    }
    else {
        res = a2;
        for (int i = 0; i < a1.size; i++)
            res[i] -= a1[i];
    }
    return res;
}

template<typename U>
bool operator==(const Array<U>& a1, const Array<U>& a2)
{
    if (a1.size != a2.size) {
        return false;
    }
    bool flag = true;
    for (int i = 0; i < a1.size; i++)
        if (a1[i] != a2[i]) {
            flag = false;
            break;
        }
    return flag;
}

template<typename U>
std::ostream& operator<<(std::ostream& out, const Array<U> arr)
{
    for (int i = 0; i < arr.size; i++)
        out << arr[i] << " ";
    return out;
}

template<typename U>
std::istream& operator>>(std::istream& in, Array<U>& arr)
{
    for (int i = 0; i < arr.size; i++)
        in >> arr[i];
    return in;
}

#endif