// Programmer: Kevin Kim
// Instructor: Professor Raheja
// Course: CS 4080-03
// Date: 22 October 2023
// Description: This is the C version (version #1) for the Programming Project 1
//              that uses a regular stack dynamic 2D array for representing matrices.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// function prototypes.
bool verifyUserInput(int userInput);
void enterMatrix(float **matrix, int row, int col);
void printMatrix(float **matrix, int row, int col);
bool checkAdditionPermissibility(int row1, int col1, int row2, int col2);
bool checkMultiplicationPermissibility(int col1, int row2);
void addition(float **matrix1, float **matrix2, float **result, int row, int col);
void subtraction(float **matrix1, float **matrix2, float **result, int row, int col);
void multiplication(float **matrix1, float **matrix2, float **result, int row1, int col2, int row2);

int main()
{
    int userInput, row1, col1, row2, col2;
    float **m1, **m2;

    printf("\nPlease enter the row size for matrix #1: ");
    scanf("%d", &row1);
    do
    {
        if (verifyUserInput(row1))
        {
            break;
        }
    } while (verifyUserInput(row1) == false);

    printf("Please enter the column size for matrix #1: ");
    scanf("%d", &col1);
    do
    {
        if (verifyUserInput(col1))
        {
            break;
        }
    } while (verifyUserInput(col1) == false);

    // create the first matrix using the row and the column values.
    printf("\nInitializing Matrix #1...\n");
    float matrix1[row1][col1];
    enterMatrix(matrix1, row1, col1);

    printf("\nPlease enter the row size for matrix #2: ");
    scanf("%d", &row2);
    do
    {
        if (verifyUserInput(row2))
        {
            break;
        }
    } while (verifyUserInput(row2) == false);

    printf("Please enter the column size for matrix #2: ");
    scanf("%d", &col2);
    do
    {
        if (verifyUserInput(col2))
        {
            break;
        }
    } while (verifyUserInput(col2) == false);

    // create the second matrix using the row and the column values.
    printf("\nInitializing Matrix #2...\n");
    printf("%d %d %d %d", row1, col1, row2, col2); // okay till here
    float matrix2[row2][col2];
    enterMatrix(matrix2, row2, col2);

    // then, present a menu that allows the user to
    // select the operation they want to test.
    do
    {
        printf("\nPlease select from the following options:\n");
        printf("(1) Add the matrices.\n");
        printf("(2) Subtract the matrices.\n");
        printf("(3) Multiply the matrices.\n");
        printf("(4) Select two new matrices.\n");
        printf("(5) Exit the program.\n");
        scanf("%d", &userInput);

        switch (userInput)
        {
        case 1:
        {
            // check to see if addition is permissible on the two matrices.
            if (!checkAdditionPermissibility(row1, col1, row2, col2))
            {
                printf("Error: addition is not permissible on the current matrices.");
                printf(" Please enter two new matrices to perform an addition.\n");
                break;
            }
            // perform addition on two matrices and print out the result.
            float result[row1][col1];
            addition(matrix1, matrix2, result, row1, col1);
            printMatrix(result, row1, col1);
        }
        break;
        case 2:
        {
            // check to see if subtraction is permissible on the two matrices.
            if (!checkAdditionPermissibility(row1, col1, row2, col2))
            {
                printf("Error: subtraction is not permissible on the current matrices.");
                printf(" Please enter two new matrices to perform a subtraction.\n");
                break;
            }
            // perform subtraction on two matrices and print out the result.
            float result[row1][col1];
            subtraction(matrix1, matrix2, result, row1, col1);
            printMatrix(result, row1, col1);
        }
        break;
        case 3:
        {
            printf("%d %d %d %d", row1, col1, row2, col2);
            // check to see if multiplication is permissible on the two matrices.
            if (!checkMultiplicationPermissibility(col1, row2))
            {
                printf("Error: multiplication is not permissible on the two matrices.");
                printf(" Please enter two new matrices to perform a multiplication.\n");
                break;
            }
            // perform multiplication on two matrices and print out the result.
            float result[row1][col2];
            multiplication(matrix1, matrix2, result, row1, col2, row2);
            printMatrix(result, row1, col2);
        }
        break;
        case 4:
        {
            // provide the user an option to select two new matrices.
            printf("\nPlease enter the row size for matrix #1: ");
            scanf("%d", &row1);
            do
            {
                if (verifyUserInput(row1))
                {
                    break;
                }
            } while (verifyUserInput(row1) == false);

            printf("\nPlease enter the column size for matrix #1: ");
            scanf("%d", &col1);
            do
            {
                if (verifyUserInput(col1))
                {
                    break;
                }
            } while (verifyUserInput(col1) == false);

            // create the first matrix using the row and the column values.
            printf("\nInitializing Matrix #1...");
            float matrix1[row1][col1];
            enterMatrix(matrix1, row1, col1);

            printf("\nPlease enter the row size for matrix #2: ");
            scanf("%d", &row2);
            do
            {
                if (verifyUserInput(row2))
                {
                    break;
                }
            } while (verifyUserInput(row2) == false);

            printf("\nPlease enter the column size for matrix #2: ");
            scanf("%d", &col2);
            do
            {
                if (verifyUserInput(col2))
                {
                    break;
                }
            } while (verifyUserInput(col2) == false);

            // create the second matrix using the row and the column values.
            printf("\nInitializing Matrix #2...");
            float matrix2[row2][col2];
            enterMatrix(matrix2, row2, col2);
        }
        break;
        case 5:
            printf("Terminating the program... Good bye!\n");
            return 0;
        default:
            printf("Please enter a number from 1 to 5.\n");
        }

        // NOTE: have the menu in a loop so that the user can test any
        // other operation unless they choose to exit the menu.
    } while (userInput != 5);
} // end of main.

// this function is used to sanitize user inputs.
bool verifyUserInput(int userInput)
{
    if (userInput % 1 != 0)
    {
        printf("ERROR: Invalid user input... Please enter an integer.\n");
        return false;
    }
    else if (userInput < 1 || userInput > 100)
    {
        printf("ERROR: Invalid user input... ");
        printf("Please enter a value less than 100 for the matrix size...\n");
        return false;
    }

    // return true if the user input is valid.
    return true;
}

// this method allows the user to enter the size and the elements for a matrix.
void enterMatrix(float **matrix, int row, int col)
{
    float temp;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Please enter a floating point value for Row #%d and Column #%d:\n", (i + 1), (j + 1));
            scanf("%f", &temp);

            // verify that the input value is a floating point value.
            if (temp == (float)temp)
            {
                printf("%f", temp);
                *(*(matrix + i) + j) = temp;
            }
        }
    }
}

// this function will print out the result of the operation after it is performed.
void printMatrix(float **matrix, int row, int col)
{
    printf("\nPrinting out the result...\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// this method will check whether addition or subtraction will be permissible
// on the two matrices entered by the user.
// NOTE: both addition and subtraction are permissible only if the two
// matrices have the same dimensions.
bool checkAdditionPermissibility(int row1, int col1, int row2, int col2)
{
    if (row1 != row2 || col1 != col2)
    {
        return false;
    }

    // return true if two n x n matrices have the equal size.
    return true;
}

// this method will check whether addition or subtraction will be permissible
// on the two matrices entered by the user.
// NOTE: both addition and subtraction are permissible only if the two
// matrices have the same dimensions.
bool checkMultiplicationPermissibility(int col1, int row2)
{
    if (col1 != row2)
    {
        return false;
    }

    // return true if multiplication can be performed on the two matrices.
    return true;
}

// this function performs matrix addition.
void addition(float **matrix1, float **matrix2, float **result, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// this function performs matrix subtraction.
void subtraction(float **matrix1, float **matrix2, float **result, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// this function performs matrix multiplication.
void multiplication(float **matrix1, float **matrix2, float **result, int row1, int col2, int row2)
{
    // perform matrix multiplication on the two matrices.
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            // first, initialize the new matrix to 0.
            result[i][j] = 0;

            for (int k = 0; k < row2; k++)
            {
                // then, start multiplying two matrices before
                // storing the products in the new matrix.
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}
