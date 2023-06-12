// platon.kastric@gmail.com

#include <iostream>
#include "Array.cpp"
#include "Matrix.cpp"

int main()
{
    // /*

    // the first way to initialize array
    Array<int> ai1;
    ai1.initialize();
    std::cout << "ai1: "; // print ai1
    ai1.print();
    std::cout << std::endl;

    // the second way to initialize array
    Array<double> ai2(5);
    std::cout << "Enter the values of array (" << ai2.get_size() << "): ";
    std::cin >> ai2;
    std::cout << "ai2: " << ai2 << std::endl << std::endl;

    // the third way to initialize array
    Array<char> ai3(5, 'i');
    std::cout << "ai3: " << ai3 << std::endl << std::endl;

    // create copy of array
    Array<int> a1(4);
    a1[0] = 1; a1[1] = 2; a1[2] = 3; a1[3] = 4;
    std::cout << "a1: " << a1 << std::endl << std::endl;
    Array<int> a2(a1);
    std::cout << "a2 (copy of a1): " << a2 << std::endl << std::endl;

    // delete the third element
    a2.pop(2);
    std::cout << "a2.pop(2)" << std::endl;
    std::cout << "a2: " << a2 << std::endl << std::endl;

    // add element to position 1
    a2.push(-32, 1);
    std::cout << "a2.push(-32, 1)" << std::endl;
    std::cout << "a2: " << a2 << std::endl << std::endl;

    // sort array
    a2.sort();
    std::cout << "a2.sort()" << std::endl;
    std::cout << "a2: " << a2 << std::endl << std::endl;

    // addition
    std::cout << "a1 + a2: " << a1 + a2 << std::endl << std::endl;

    // subtraction
    std::cout << "a1 - a2: " << a1 - a2 << std::endl << std::endl;

    //the second element of a1
    std::cout << "a1[1]: " << a1[1] << std::endl << std::endl;

    // add 5 to the end of the array a1
    a1 += 5;
    std::cout << "a1 += 5: " << a1 << std::endl << std::endl;

    //delete element 1.5 from array 
    a1 -= 2;
    std::cout << "a1 -= 2: " << a1 << std::endl << std::endl;

    //comparison of a1 and a2
    std::cout << "comparison of a1 and a2: " << std::endl;
    if (a1 == a2)
        std::cout << "a1 and a2 are equal" << std::endl;
    else
        std::cout << "a1 and a2 are not equal" << std::endl;

    // */

    // /*

    //the first way to initialize matrix
    Matrix<int> mi1;
    mi1.initialize();
    std::cout << "mi1: " << std::endl; // print mi1
    mi1.print();
    std::cout << std::endl;

    // the second way to initialize matrix
    Matrix<double> mi2(2,3);
    std::cout << "Enter the values of matrix (" << mi2.get_row_number() << "x" << mi2.get_column_number() << "): " << std::endl;
    std::cin >> mi2;
    std::cout << "mi2: " << std::endl << mi2 << std::endl;

    // the third way to initialize matrix
    Matrix<char> mi3(2, 1, 'i');
    std::cout << "mi3: " << std::endl << mi3 << std::endl;

    // create copy of matrix
    Matrix<int> m1(2);
    m1[0][0] = 1; m1[0][1] = 2; m1[1][0] = 3; m1[1][1] = 4;
    std::cout << "m1: " << std::endl << m1 << std::endl;
    Matrix<int> m2(m1);
    std::cout << "m2 (copy of m1): " << std::endl << m2 << std::endl;

    // addition
    std::cout << "m1 + m2: " << std::endl << m1 + m2 << std::endl;

    // subtraction
    std::cout << "m1 - m2: " << std::endl << m1 - m2 << std::endl;

    //comparison of m1 and m2
    std::cout << "comparison of m1 and m2: " << std::endl;
    if (m1 == m2)
        std::cout << "m1 and m2 are equal" << std::endl << std::endl;
    else
        std::cout << "m1 and m2 are not equal" << std::endl << std::endl;

    //resize of matrix m1
    m1.resize(2, 3);
    m1[0][2] = 42;
    m1[1][2] = -3;
    std::cout << "resize of matrix m1" << std::endl;
    std::cout << "m1: " << std::endl << m1 << std::endl;

    // get size of matrix m1
    std::cout << "m1 has " << m1.get_row_number() << " rows and " << m1.get_column_number() << " columns" << std::endl;

    // 1-norm of matrix m1
    std::cout << "1-norm of matrix m1: " << m1.one_norm() << std::endl;

    // infinity-norm of matrix m1
    std::cout << "infinity-norm of matrix m1: " << m1.infinity_norm() << std::endl;

    // determinant of matrix m2
    std::cout << "determinant of matrix m2: " << m2.det() << std::endl;

    // */
}



