// platon.kastric@gmail.com

#ifndef __Matrix__
#define __MAtrix__

#include <iostream>
#include <cassert>
#include <cmath>
#include "Array.cpp"

template<typename T>
class Matrix {
    Array<T>* matrix;
    size_t columns, rows;
    
public:
    // create empty matrix with 1 element
    Matrix();

    // create empty matrix n by n
    Matrix(size_t n);

    // create empty matrix with n rows and m colums
    Matrix(size_t n, size_t m);

    // create matrix of value's with n rows and m colums
    Matrix(size_t n, size_t m, T value);

    // create copy of mat
    Matrix(const Matrix<T>& mat);

    // destructor
    ~Matrix();

    // resize matrix to size (n, m)
    void resize(size_t n, size_t m);

    // print all elements of matrix
    void print() const;

    // initilize matrix with size and values from keyboard
    void initialize();

    // get size the number of columns
    size_t get_column_number() const;

    // get size the number of rows
    size_t get_row_number() const;

    // element - by - element addition
    template<typename U>
    friend Matrix<U> operator + (const Matrix<U>&, const Matrix<U>&);

    // element - by - element subtraction
    template<typename U>
    friend Matrix<U> operator - (const Matrix<U>&, const Matrix<U>&);

    // assignment of matrix
    Matrix<T>& operator = (const Matrix<T>);

    // comparison of two matrices
    template<typename U>
    friend bool operator == (const Matrix<U>&, const Matrix<U>&);

    // taking an element with a given index
    Array<T>& operator [] (int) const;

    // output on the screen
    template<typename U>
    friend std::ostream& operator << (std::ostream& out, const Matrix<U>);

    // input all elements from keyboard
    template<typename U>
    friend std::istream& operator >> (std::istream& in, Matrix<U>&);
    
    // matrix 1-Norm
    T one_norm();
    
    // matrix infinity-Norm
    T infinity_norm();

    // determinant of matrix (only for 2x2 or 3x3 matrix)
    T det();
};

template<typename T>
Matrix<T>::Matrix() {
    matrix = new Array<T>[1];
    columns = 1;
    rows = 1;
}

template<typename T>
Matrix<T>::Matrix(size_t n)
{
    columns = n;
    rows = n;
    matrix = new Array<T>[n];
    for (int i = 0; i < rows; i++)
        matrix[i] = Array<T>(n);
}

template<typename T>
Matrix<T>::Matrix(size_t n, size_t m)
{
    matrix = new Array<T>[n];
    for (int i = 0; i < n; i++)
        matrix[i] = Array<T>(m);
    rows = n;
    columns = m;
}

template<typename T>
Matrix<T>::Matrix(size_t n, size_t m, T value)
{
    matrix = new Array<T>[n];
    for (int i = 0; i < n; i++)
        matrix[i] = Array<T>(m, value);
    rows = n;
    columns = m;
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& mat)
{
    rows = mat.rows;
    columns = mat.columns;
    matrix = new Array<T>[rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = Array<T>(columns);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = mat[i][j];
        }
}

template<typename T>
Matrix<T>::~Matrix()
{
    //for (int i = 0; i < rows; i++)
    //    delete matrix[i];
    delete[] matrix;
}

template<typename T>
void Matrix<T>::resize(size_t n, size_t m)
{
    Matrix<T> temp(*this);
    columns = m;
    rows = n;
    delete[] matrix;
    matrix = new Array<T>[rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = Array<T>(columns);
    for (int i = 0; i < rows && i < temp.rows; i++)
        for (int j = 0; j < columns && i < temp.columns; j++) {
            matrix[i][j] = temp[i][j];
        }
}

template<typename T>
void Matrix<T>::print() const
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template<typename T>
void Matrix<T>::initialize()
{
    delete[] matrix;
    std::cout << "Enter row number: "; std::cin >> rows;
    std::cout << "Enter column number: "; std::cin >> columns;
    matrix = new Array<T>[rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = Array<T>(columns);
    for (int i = 0; i < rows; i++) {
        std::cout << "Enter " << i+1 << ". row: ";
        for (int j = 0; j < columns; j++) {
            std::cin >> matrix[i][j];
        }
    }
}

template<typename T>
size_t Matrix<T>::get_column_number() const
{
    return columns;
}

template<typename T>
size_t Matrix<T>::get_row_number() const
{
    return rows;
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T> mat)
{
    resize(mat.rows, mat.columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = mat[i][j];
        }
    }
    return *this;
    
}

template<typename T>
Array<T>& Matrix<T>::operator [] (int index) const
{
    return matrix[index];
}

template<typename T>
T Matrix<T>::one_norm()
{
    T max_column = 0;
    for (int j = 0; j < columns; j++) {
        T column_sum = 0;
        for (int i = 0; i < rows; i++)
            column_sum += abs(matrix[i][j]);
        if (column_sum > max_column)
            max_column = column_sum;
    }
    return max_column;
}

template<typename T>
T Matrix<T>::infinity_norm()
{
    T max_row = 0;
    for (int i = 0; i < rows; i++) {
        T row_sum = 0;
        for (int j = 0; j < columns; j++)
            row_sum += abs(matrix[i][j]);
        if (row_sum > max_row)
            max_row = row_sum;
    }
    return max_row;
}

template<typename T>
T Matrix<T>::det()
{
    assert(columns == rows);
    if (columns == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
    }
    else if (columns == 3) {
        return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) +
            matrix[0][1] * (matrix[1][2] * matrix[2][0] - matrix[1][0] * matrix[2][2]) +
            matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][1]);
    }
    else
        std::cerr << "Sorry, but det() function calculates deterninant only for 2x2 and 3x3 matrices";

    
}

template<typename U>
Matrix<U> operator+(const Matrix<U>& m1, const Matrix<U>& m2)
{
    assert(m1.rows == m2.rows && m1.columns == m2.columns);
    Matrix<U> res(m1.rows, m1.columns);
    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m1.columns; j++) {
            res[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return res;
}

template<typename U>
Matrix<U> operator-(const Matrix<U>& m1, const Matrix<U>& m2)
{
    assert(m1.rows == m2.rows && m1.columns == m2.columns);
    Matrix<U> res(m1.rows, m1.columns);
    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m1.columns; j++) {
            res[i][j] = m1[i][j] - m2[i][j];
        }
    }
    return res;
}

template<typename U>
bool operator==(const Matrix<U>& m1, const Matrix<U>& m2)
{
    bool flag = true;
    if (m1.rows != m2.rows || m1.columns != m2.columns)
        return false;
    else {
        for (int i = 0; i < m1.rows; i++) {
            for (int j = 0; j < m1.columns; j++) {
                if (m1[i][j] != m2[i][j]) {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                break;
        }
    }
    return flag;
}

template<typename U>
std::ostream& operator<<(std::ostream& out, const Matrix<U> mat)
{
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.columns; j++) {
            out << mat[i][j] << " ";
        }
        out << std::endl;
    }
    return out;
}

template<typename U>
std::istream& operator>>(std::istream& in, Matrix<U>& mat) 
{
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.columns; j++) {
            in >> mat[i][j] ;
        }
    }
    return in;
}

#endif