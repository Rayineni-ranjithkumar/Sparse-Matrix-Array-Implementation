#include <iostream>
using namespace std;
struct Element { // we can store the non-zero elements in elements
    int row;  
    int col;   
    int value; 
};
class SparseMatrix {
private:
    int rows, cols, nonZeroCount;
    Element *elements;
public:
    SparseMatrix(int r, int c, int count) {
        rows = r;
        cols = c;
        nonZeroCount = count;
        elements = new Element[nonZeroCount]; // here we can allocate memory
    }
    ~SparseMatrix() { // this is for destructor to release allocated memory
        delete[] elements;
    }
    //here we are writeing Function to read non-zero elements from user like user giving inputs that function read.
    void readElements() {
        cout << "\nranjith plz Enter the details of non-zero elements:\n";
        cout << "(Row, Column, Value)\n";
        for (int i = 0; i < nonZeroCount; i++) {
            cout << "Element " << i + 1 << ": ";
            cin >> elements[i].row >> elements[i].col >> elements[i].value;
        }
    }
    void displaySparse() { // this is for our Function to display the sparse matrix
        cout << "\nranjith your Sparse Matrix is :\n";
        cout << "Row\tCol\tValue\n";
        for (int i = 0; i < nonZeroCount; i++) {
            cout << elements[i].row << "\t" << elements[i].col << "\t" << elements[i].value << "\n";
        }
    }
    void displayFullMatrix() {  // this is for our Function to display the complete matrix
        cout << "\n ranjith your Full Matrix is :\n";
        int k = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (k < nonZeroCount && elements[k].row == i && elements[k].col == j) {
                    cout << elements[k].value << " "; // Print non-zero value
                    k++; // Move to next non-zero element
                } else {
                    cout << "0 "; // Print zero if no value stored
                }
            }
            cout << "\n";
        }
    }
};
int main() {
    int rows, cols, nonZeroCount;
    cout << "ranjith enter number of rows buddy: ";
    cin >> rows;
    cout << "ranjith Enter number of columns buddy: ";
    cin >> cols;
    cout << "ranjith Enter number of non-zero elements buddy: ";
    cin >> nonZeroCount;
    // here object we are creating for sparse matrix..
    SparseMatrix ourresult(rows, cols, nonZeroCount);
    ourresult.readElements();
    ourresult.displaySparse();
    ourresult.displayFullMatrix();
    return 0;
}
