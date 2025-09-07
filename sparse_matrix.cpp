#include <iostream>
using namespace std;

// Structure to store non-zero elements
struct Element {
    int row;    // Row index
    int col;    // Column index
    int value;  // Non-zero value
};

class SparseMatrix {
private:
    int rows, cols, nonZeroCount;
    Element *elements; // Dynamic array to store non-zero elements

public:
    // Constructor to initialize matrix details
    SparseMatrix(int r, int c, int count) {
        rows = r;
        cols = c;
        nonZeroCount = count;
        elements = new Element[nonZeroCount]; // Allocate memory
    }

    // Destructor to release allocated memory
    ~SparseMatrix() {
        delete[] elements;
    }

    // Function to read non-zero elements from user
    void readElements() {
        cout << "\nEnter the details of non-zero elements:\n";
        cout << "(Row, Column, Value)\n";
        for (int i = 0; i < nonZeroCount; i++) {
            cout << "Element " << i + 1 << ": ";
            cin >> elements[i].row >> elements[i].col >> elements[i].value;
        }
    }

    // Function to display the sparse matrix representation
    void displaySparse() {
        cout << "\nSparse Matrix Representation:\n";
        cout << "Row\tCol\tValue\n";
        cout << "-------------------------\n";
        for (int i = 0; i < nonZeroCount; i++) {
            cout << elements[i].row << "\t" << elements[i].col << "\t" << elements[i].value << "\n";
        }
    }

    // Function to display the complete matrix
    void displayFullMatrix() {
        cout << "\nFull Matrix Representation:\n";
        cout << "---------------------------\n";
        int k = 0; // Index to track non-zero elements

        // Traverse through each position in the matrix
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

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "Enter number of non-zero elements: ";
    cin >> nonZeroCount;

    // Create sparse matrix object
    SparseMatrix sm(rows, cols, nonZeroCount);

    // Read, store, and display results
    sm.readElements();
    sm.displaySparse();
    sm.displayFullMatrix();

    return 0;
}
