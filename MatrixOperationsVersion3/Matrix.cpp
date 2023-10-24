// Programmer: Kevin Kim
// Instructor: Professor Raheja
// Course: CS 4080-03
// Date: 22 October 2023
// Description: This is the C++ version (version #3) for the Programming Project 1.
#include <iostream>
using namespace std;

// create a class called matrix.
class Matrix
{
    // use a pointer to a pointer as private data.
private:
    int row;
    int col;
    float **matrix;

    // add appropriate member functions and overloaded operator functions to
    // the class for doing the matrix operations.
public:
    // this is the default constructor.
    Matrix()
    {
        setRow(0);
        setCol(0);
        setMatrix();
    } // end of default CTOR.

    // this is the parameterized constructor.
    Matrix(int row, int col)
    {
        setRow(row);
        setCol(col);
        setMatrix(row, col);
    } // end of parameterized CTOR.

    // this is the destructor.
    ~Matrix()
    {
        for (int i = 0; i < getRow(); i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;

        setRow(0);
        setCol(0);
        setMatrix();
    } // end of DTOR.

    // this is the overloaded opeartor function for addition.
    Matrix operator+(Matrix const &obj)
    {
        Matrix result = Matrix();
        result.setRow(this->getRow());
        result.setCol(this->getCol());

        // allocate memory in the heap to store results.
        result.matrix = (float **)malloc(getRow() * sizeof(float *));
        for (int i = 0; i < result.getRow(); i++)
        {
            *(result.matrix + i) = (float *)malloc(result.getCol() * sizeof(float));

            // add corresponding elements of matrices.
            for (int j = 0; j < result.getCol(); j++)
            {
                result.matrix[i][j] = this->getMatrix()[i][j] + obj.matrix[i][j];
            }
        }

        // return the resulting matrix back to the caller method.
        return result;
    }

    // this is the overloaded opeartor function for subtraction.
    Matrix operator-(Matrix const &obj)
    {
        Matrix result = Matrix();
        result.setRow(this->getRow());
        result.setCol(this->getCol());

        // allocate memory in the heap to store results.
        result.matrix = (float **)malloc(getRow() * sizeof(float *));
        for (int i = 0; i < result.getRow(); i++)
        {
            *(result.matrix + i) = (float *)malloc(result.getCol() * sizeof(float));

            // subtract corresponding elements of matrices.
            for (int j = 0; j < result.getCol(); j++)
            {
                result.matrix[i][j] = this->getMatrix()[i][j] - obj.matrix[i][j];
            }
        }

        // return the resulting matrix back to the caller method.
        return result;
    }

    // this is the overloaded opeartor function for multiplication.
    Matrix operator*(Matrix const &obj)
    {
        Matrix result = Matrix();
        result.setRow(this->getRow());
        result.setCol(this->getCol());

        // allocate memory in the heap to store results.
        result.matrix = (float **)malloc(getRow() * sizeof(float *));
        for (int i = 0; i < result.getRow(); i++)
        {
            *(result.matrix + i) = (float *)malloc(result.getCol() * sizeof(float));

            // multiply corresponding elements of matrices.
            for (int j = 0; j < result.getCol(); j++)
            {
                // first, initialize the new matrix to 0.
                result.getMatrix()[i][j] = 0;

                for (int k = 0; k < obj.row; k++)
                {
                    // then, start multiplying two matrices before
                    // storing the products in the new matrix.
                    result.getMatrix()[i][j] += this->getMatrix()[i][k] * obj.matrix[k][j];
                }
            }
        }

        // return the resulting matrix back to the caller method.
        return result;
    }

    // this method will print out the result of the operation after it is performed.
    void printMatrix()
    {
        for (int i = 0; i < getRow(); i++)
        {
            for (int j = 0; i < getCol(); j++)
            {
                cout << *(&getMatrix()[0][0] + (i * getRow() * sizeof(float)) + (j * sizeof(float)))
                     << " ";
            }
            cout << endl;
        }
        cout << endl;
    } // end of printMatrix().

    // this function will check whether addition or subtraction will be permissible
    // on the two matrices entered by the user.
    // NOTE: both addition and subtraction are permissible only if the two
    // matrices have the same dimensions.
    bool checkAdditionPermissibility(Matrix const &obj)
    {
        // check to see if both matrix1 and matrix 2 have the same dimensions.
        if (this->getRow() != obj.row || this->getCol() != obj.col)
        {
            return false;
        }

        // return true if two matrices have the same dimensions.
        return true;
    } // end of checkAdditionPermissibility().

    // this function will check whether multiplication will be permissible
    // on the two matrices entered by the user.
    // NOTE: matrix multiplication will be permissible only if the number of
    // columns in the first matrix is equal to the number of rows in the
    // second matrix.
    bool checkMultiplicationPermissibility(Matrix const &obj)
    {
        // check to see if the number of columns in the first matrix is equal
        // to the number of rows in the second matrix.
        if (this->getCol() != obj.row)
        {
            return false;
        }

        // return true if two matrices have the same dimensions.
        return true;
    } // end of checkMultiplicationPermissibility().

    void setRow(int r) { row = r; }
    void setCol(int c) { col = c; }
    void setMatrix()
    {
        matrix = nullptr;
    }
    void setMatrix(int r, int c)
    {
        float temp;

        // allocate memory in the heap to store floating point values in matrix.
        matrix = (float **)malloc(r * sizeof(float *));
        for (int i = 0; i < r; i++)
        {
            *(matrix + i) = (float *)malloc(c * sizeof(float));

            // then, prompt the user to enter the values for the matrix.
            for (int j = 0; j < c; j++)
            {
                cout << "Please enter a floating point value for Row #" << (i + 1)
                     << " and Column #" << (j + 1) << ": ";
                cin >> temp;

                // verify that the input value is a floating point value.
                if (temp == (float)temp)
                {
                    *(&matrix[0][0] + (i * r * sizeof(float)) + (j * sizeof(float))) = temp;
                }
            }
        }
    }
    int getRow() { return row; }
    int getCol() { return col; }
    float **getMatrix() { return matrix; }
};

// this driver program tests three different operations with matrices.
int main()
{
    int userInput = 0, row, col;
    Matrix matrix1, matrix2, result;

    cout << "\nPlease enter the row size for matrix #1: ";
    cin >> row;

    cout << "Please enter the column size for matrix #1: ";
    cin >> col;

    // create the first matrix using the row and the column values.
    cout << "\nInitializing Matrix #1..." << endl;
    matrix1 = Matrix(row, col);

    cout << "\nPlease enter the row size for matrix #2: ";
    cin >> row;

    cout << "\nPlease enter the column size for matrix #2: ";
    cin >> col;

    // create the second matrix using the row and the column values.
    cout << "\nInitializing Matrix #2..." << endl;
    matrix2 = Matrix(row, col);

    // display the matrices before performing any operations.
    cout << "\nDisplaying Matrix #1: \n";
    matrix1.printMatrix();
    cout << "Matrix #2: \n";
    matrix2.printMatrix();

    // then, present a menu that allows the user to
    // select the operation they want to test.
    do
    {
        cout << "\nPlease select from the following options:" << endl
             << "(1) Add the matrices." << endl
             << "(2) Subtract the matrices." << endl
             << "(3) Multiply the matrices." << endl
             << "(4) Select two new matrices." << endl
             << "(5) Exit the program." << endl;
        cin >> userInput;

        switch (userInput)
        {
        case 1:
            // check to see if addition is permissible on the two matrices.
            if (!(matrix1.checkAdditionPermissibility(matrix2)))
            {
                cout << "Error: addition is not permissible on the current matrices."
                     << " Please enter two new matrices to perform an addition.\n";
                break;
            }
            // perform addition on two matrices and print out the result.
            result = matrix1 + matrix2;
            result.printMatrix();
            result.~Matrix();
            break;
        case 2:
            // check to see if subtraction is permissible on the two matrices.
            if (!(matrix1.checkAdditionPermissibility(matrix2)))
            {
                cout << "Error: subtraction is not permissible on the current matrices."
                     << " Please enter two new matrices to perform a subtraction.\n";
                break;
            }
            // perform subtraction on two matrices and print out the result.
            result = matrix1 - matrix2;
            result.printMatrix();
            result.~Matrix();
            break;
        case 3:
            // check to see if multiplication is permissible on the two matrices.
            if (!(matrix1.checkMultiplicationPermissibility(matrix2)))
            {
                cout << "Error: multiplication is not permissible on the two matrices."
                     << " Please enter two new matrices to perform a multiplication.\n";
                break;
            }
            // perform multiplication on two matrices and print out the result.
            result = matrix1 * matrix2;
            result.printMatrix();
            result.~Matrix();
            break;
        case 4:
            // if the user wishes to select two new matrices, destory the current matrices.
            matrix1.~Matrix();
            matrix2.~Matrix();

            // provide the user an option to select two new matrices.
            cout << "\nPlease enter the row size for matrix #1: ";
            cin >> row;

            cout << "\nPlease enter the column size for matrix #1: ";
            cin >> col;

            // create the first matrix using the row and the column values.
            matrix1 = Matrix(row, col);

            cout << "Please enter the row size for matrix #2: \n";
            cin >> row;

            cout << "Please enter the column size for matrix #2: \n";
            cin >> col;

            // create the second matrix using the row and the column values.
            matrix2 = Matrix(row, col);
            break;
        case 5:
            cout << "Terminating the program... Good bye!\n";
            // deallocate memory for the two matrices and then return.
            matrix1.~Matrix();
            matrix2.~Matrix();

            return 0;
        default:
            cout << "Please enter a number from 1 to 5.\n";
        }

        // NOTE: have the menu in a loop so that the user can test any
        // other operation unless they choose to exit the menu.
    } while (userInput != 5);

    // deallocate memory for the two matrices and then return.
    matrix1.~Matrix();
    matrix2.~Matrix();
    return 0;
} // end of main.