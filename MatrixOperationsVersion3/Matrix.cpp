// Programmer: Kevin Kim
// Instructor: Professor Raheja
// Course: CS 4080-03
// Date: 22 October 2023
// Description: This is the C++ version (version #3) for the Programming Project 1.
#include <iostream>
#include <time.h>
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
        setMatrix(nullptr);
    } // end of default CTOR.

    // this is the parameterized constructor.
    Matrix(int row, int col)
    {
        setRow(row);
        setCol(col);
        matrix = new float *[row];
        for (int i = 0; i < row; ++i)
        {
            matrix[i] = new float[col];
        }
    } // end of parameterized CTOR.

    // this is the destructor.
    ~Matrix()
    {
        for (int i = 0; i < getRow(); i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;

    } // end of DTOR.

    // this is the overloaded opeartor function for addition.
    Matrix operator+(const Matrix &obj) const
    {
        Matrix result(this->getRow(), this->getCol());

        for (int i = 0; i < this->getRow(); i++)
        {
            // add corresponding elements of matrices.
            for (int j = 0; j < this->getCol(); j++)
            {
                result.getMatrix()[i][j] = this->getMatrix()[i][j] + obj.getMatrix()[i][j];
            }
        }

        // return the resulting matrix back to the caller method.
        return result;
    }

    // this is the overloaded opeartor function for subtraction.
    Matrix operator-(const Matrix &obj) const
    {
        Matrix result(this->getRow(), this->getCol());

        for (int i = 0; i < this->getRow(); i++)
        {
            // add corresponding elements of matrices.
            for (int j = 0; j < this->getCol(); j++)
            {
                result.getMatrix()[i][j] = this->getMatrix()[i][j] - obj.getMatrix()[i][j];
            }
        }

        // return the resulting matrix back to the caller method.
        return result;
    }

    // this is the overloaded opeartor function for multiplication.
    Matrix operator*(const Matrix &obj) const
    {
        Matrix result(this->getRow(), obj.getCol());

        for (int i = 0; i < this->getRow(); i++)
        {
            // multiply corresponding elements of matrices.
            for (int j = 0; j < obj.getCol(); j++)
            {
                // first, initialize the new matrix to 0.
                result.getMatrix()[i][j] = 0;

                for (int k = 0; k < obj.getRow(); k++)
                {
                    // then, start multiplying two matrices before
                    // storing the products in the new matrix.
                    result.getMatrix()[i][j] += this->getMatrix()[i][k] * obj.getMatrix()[k][j];
                }
            }
        }

        // return the resulting matrix back to the caller method.
        return result;
    }

    // this is the overloaded operator function for assignment.
    Matrix &operator=(const Matrix &obj)
    {
        if (this != &obj)
        {
            // deallocate existing matrix.
            for (int i = 0; i < getRow(); i++)
            {
                delete[] matrix[i];
            }
            delete[] matrix;

            // Allocate new memory and copy values
            setRow(obj.getRow());
            setCol(obj.getCol());
            matrix = new float *[getRow()];
            for (int i = 0; i < getRow(); i++)
            {
                matrix[i] = new float[getCol()];
                for (int j = 0; j < getCol(); j++)
                {
                    matrix[i][j] = obj.getMatrix()[i][j];
                }
            }
        }
        return *this;
    }

    void setRow(int r) { row = r; }
    void setCol(int c) { col = c; }
    void setMatrix(float **ptr) { matrix = ptr; }
    int getRow() const { return row; }
    int getCol() const { return col; }
    float **getMatrix() const { return matrix; }
}; // end of Matrix class.

// this method allows the user to enter the size and the elements for a matrix.
void enterMatrix(Matrix &matrix, int row, int col)
{
    float temp;

    matrix.setRow(row);
    matrix.setCol(col);
    matrix.setMatrix(new float *[row]);

    for (int i = 0; i < row; i++)
    {
        matrix.getMatrix()[i] = new float[col];

        for (int j = 0; j < col; j++)
        {
            cout << "Please enter a floating point value for Row #" << (i + 1)
                 << " and Column #" << (j + 1) << ": ";
            cin >> temp;

            matrix.getMatrix()[i][j] = temp;
        }
    }
}

// this function generates a random matrix.
void generateRandomMatrix(Matrix &matrix, int n)
{
    int random;
    srand(time(0));
    float temp;
    matrix.setRow(n);
    matrix.setCol(n);
    matrix.setMatrix(new float *[n]);

    // fill up the matrix with random values.
    for (int i = 0; i < n; i++)
    {
        matrix.getMatrix()[i] = new float[n];

        for (int j = 0; j < n; j++)
        {
            random = (rand() % 11) + 0;
            matrix.getMatrix()[i][j] = (float)random;
        }
    }
}

// this method will print out the result of the operation after it is performed.
void printMatrix(Matrix &matrix)
{
    for (int i = 0; i < matrix.getRow(); i++)
    {
        for (int j = 0; j < matrix.getCol(); j++)
        {
            printf("%.2f\t", matrix.getMatrix()[i][j]);
        }
        cout << endl;
    }
    cout << endl;
} // end of printMatrix().

// this function will check whether addition or subtraction will be permissible
// on the two matrices entered by the user.
// NOTE: both addition and subtraction are permissible only if the two
// matrices have the same dimensions.
bool checkAdditionPermissibility(Matrix &matrix1, Matrix &matrix2)
{
    // check to see if both matrix1 and matrix 2 have the same dimensions.
    if (matrix1.getRow() != matrix2.getRow() || matrix1.getCol() != matrix2.getCol())
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
bool checkMultiplicationPermissibility(Matrix &matrix1, Matrix &matrix2)
{
    // check to see if the number of columns in the first matrix is equal
    // to the number of rows in the second matrix.
    if (matrix1.getCol() != matrix2.getRow())
    {
        return false;
    }

    // return true if two matrices have the same dimensions.
    return true;
} // end of checkMultiplicationPermissibility().

// this driver program tests three different operations with matrices.
int main()
{
    int userInput = 0, row, col;
    Matrix matrix1, matrix2, result;
    clock_t timer;
    double time;

    cout << "\nPlease enter the row size for matrix #1: ";
    cin >> row;
    cout << "Please enter the column size for matrix #1: ";
    cin >> col;

    // create the first matrix using the row and the column values.
    cout << "\nInitializing Matrix #1..." << endl;
    // enterMatrix(matrix1, row, col); // uncomment this line to allow user input.
    generateRandomMatrix(matrix1, row);

    cout << "\nPlease enter the row size for matrix #2: ";
    cin >> row;
    cout << "Please enter the column size for matrix #2: ";
    cin >> col;

    // create the second matrix using the row and the column values.
    cout << "\nInitializing Matrix #2..." << endl;
    // enterMatrix(matrix2, row, col); // uncomment this line to allow user input.
    generateRandomMatrix(matrix2, row);

    // display the matrices before performing any operations.
    cout << "\nDisplaying Matrix #1: \n";
    printMatrix(matrix1);
    cout << "Matrix #2: \n";
    printMatrix(matrix2);

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
            if (!(checkAdditionPermissibility(matrix1, matrix2)))
            {
                cout << "Error: addition is not permissible on the current matrices."
                     << " Please enter two new matrices to perform an addition.\n";
                break;
            }
            // perform addition on two matrices and print out the result.
            result = matrix1 + matrix2;
            printMatrix(result);
            break;
        case 2:
            // check to see if subtraction is permissible on the two matrices.
            if (!(checkAdditionPermissibility(matrix1, matrix2)))
            {
                cout << "Error: subtraction is not permissible on the current matrices."
                     << " Please enter two new matrices to perform a subtraction.\n";
                break;
            }
            // perform subtraction on two matrices and print out the result.
            result = matrix1 - matrix2;
            printMatrix(result);
            break;
        case 3:
            // check to see if multiplication is permissible on the two matrices.
            if (!(checkMultiplicationPermissibility(matrix1, matrix2)))
            {
                cout << "Error: multiplication is not permissible on the two matrices."
                     << " Please enter two new matrices to perform a multiplication.\n";
                break;
            }
            // perform multiplication on two matrices and print out the result.
            timer = clock();
            result = matrix1 * matrix2;
            timer = clock() - timer;
            time = ((double)timer) / CLOCKS_PER_SEC;
            cout << "\nMatrix Multiplication finished performing in " << time << " seconds.\n";
            printMatrix(result);
            break;
        case 4:
            // provide the user an option to select two new matrices.
            cout << "\nPlease enter the row size for matrix #1: ";
            cin >> row;
            cout << "Please enter the column size for matrix #1: ";
            cin >> col;

            // create the first matrix using the row and the column values.
            cout << "\nInitializing Matrix #1..." << endl;
            // enterMatrix(matrix1, row, col); // uncomment this line to allow user input.
            generateRandomMatrix(matrix1, row);

            cout << "\nPlease enter the row size for matrix #2: ";
            cin >> row;
            cout << "Please enter the column size for matrix #2: ";
            cin >> col;

            // create the second matrix using the row and the column values.
            cout << "\nInitializing Matrix #2..." << endl;
            // enterMatrix(matrix2, row, col); // uncomment this line to allow user input.
            generateRandomMatrix(matrix2, row);

            // display the matrices before performing any operations.
            cout << "\nDisplaying Matrix #1: \n";
            printMatrix(matrix1);
            cout << "Matrix #2: \n";
            printMatrix(matrix2);
            break;
        case 5:
            cout << "Terminating the program... Good bye!\n";
            return 0;
        default:
            cout << "Please enter a number from 1 to 5.\n";
        }

        // NOTE: have the menu in a loop so that the user can test any
        // other operation unless they choose to exit the menu.
    } while (userInput != 5);

    return 0;
} // end of main.