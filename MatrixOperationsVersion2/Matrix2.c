// Programmer: Kevin Kim
// Instructor: Professor Raheja
// Course: CS 4080-03
// Date: 22 October 2023
// Description: This is the C version (version #2) for the Programming Project 1
//              that uses a pointer to a pointer.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// function prototypes.
float **enterMatrix(int row, int col);
float **generateRandomMatrix(int n);
void printMatrix(float **matrix, int row, int col);
bool checkAdditionPermissibility(int row1, int col1, int row2, int col2);
bool checkMultiplicationPermissibility(int col1, int row2);
float **addition(float **matrix1, float **matrix2, int row, int col);
float **subtraction(float **matrix1, float **matrix2, int row, int col);
float **multiplication(float **matrix1, float **matrix2, int row1, int col2, int row2);
void deleteMatrix(float **ptr, int row);

int main()
{
    int userInput, row1, col1, row2, col2;
    clock_t timer;
    double time;
    float **matrix1, **matrix2, **result;

    printf("\nPlease enter the row size for matrix #1: ");
    scanf("%d", &row1);
    printf("Please enter the column size for matrix #1: ");
    scanf("%d", &col1);

    // create the first matrix using the row and the column values.
    printf("\nInitializing Matrix #1...\n");
    // matrix1 = enterMatrix(row1, col1); // uncomment this line to allow user input.
    matrix1 = generateRandomMatrix(row1);
    printMatrix(matrix1, row1, col1);

    printf("\nPlease enter the row size for matrix #2: ");
    scanf("%d", &row2);
    printf("Please enter the column size for matrix #2: ");
    scanf("%d", &col2);

    // create the second matrix using the row and the column values.
    printf("\nInitializing Matrix #2...\n");
    // matrix2 = enterMatrix(row2, col2); // uncomment this line to allow user input.
    matrix2 = generateRandomMatrix(row2);
    printMatrix(matrix2, row2, col2);

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
            result = addition(matrix1, matrix2, row1, col1);
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
            result = subtraction(matrix1, matrix2, row1, col1);
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
            timer = clock();
            result = multiplication(matrix1, matrix2, row1, col2, row2);
            timer = clock() - timer;
            time = ((double)timer) / CLOCKS_PER_SEC;
            printf("\nMatrix Multiplication finished performing in %lf seconds.", time);
            printMatrix(result, row1, col2);
        }
        break;
        case 4:
        {
            // first, deallocate the memory that was allocated for the
            // two dynamic arrays.
            deleteMatrix(matrix1, row1);
            deleteMatrix(matrix2, row2);

            // provide the user an option to select two new matrices.
            printf("\nPlease enter the row size for matrix #1: ");
            scanf("%d", &row1);
            printf("Please enter the column size for matrix #1: ");
            scanf("%d", &col1);

            // create the first matrix using the row and the column values.
            printf("\nInitializing Matrix #1...\n");
            // matrix1 = enterMatrix(row1, col1); // uncomment this line to allow user input.
            matrix1 = generateRandomMatrix(row1);
            printMatrix(matrix1, row1, col1);

            printf("\nPlease enter the row size for matrix #2: ");
            scanf("%d", &row2);
            printf("Please enter the column size for matrix #2: ");
            scanf("%d", &col2);

            // create the second matrix using the row and the column values.
            printf("\nInitializing Matrix #2...\n");
            // matrix2 = enterMatrix(row2, col2); // uncomment this line to allow user input.
            matrix2 = generateRandomMatrix(row2);
            printMatrix(matrix2, row2, col2);
        }
        break;
        case 5:
            printf("Terminating the program... Good bye!\n");
            deleteMatrix(matrix1, row1);
            deleteMatrix(matrix2, row2);
            return 0;
        default:
            printf("Please enter a number from 1 to 5.\n");
        }

        // NOTE: have the menu in a loop so that the user can test any
        // other operation unless they choose to exit the menu.
    } while (userInput != 5);
} // end of main.

// this method allows the user to enter the size and the elements for a matrix.
float **enterMatrix(int row, int col)
{
    float **matrix = (float **)malloc(row * sizeof(float *));

    float temp;
    for (int i = 0; i < row; i++)
    {
        *(matrix + i) = (float *)malloc(col * sizeof(float));

        for (int j = 0; j < col; j++)
        {
            printf("Please enter a floating point value for Row #%d and Column #%d:\n", (i + 1), (j + 1));
            scanf("%f", &temp);

            matrix[i][j] = temp;
        }
    }

    return matrix;
}

// this function generates a random matrix.
float **generateRandomMatrix(int n)
{
    int random;
    srand(time(0));
    float **matrix = (float **)malloc(n * sizeof(float *));
    float temp;

    // fill up the matrix with random values.
    for (int i = 0; i < n; i++)
    {
        *(matrix + i) = (float *)malloc(n * sizeof(float));

        for (int j = 0; j < n; j++)
        {
            random = (rand() % 11) + 0;
            matrix[i][j] = (float)random;
        }
    }

    return matrix;
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
float **addition(float **matrix1, float **matrix2, int row, int col)
{
    float **result = (float **)malloc(row * sizeof(float *));

    for (int i = 0; i < row; i++)
    {
        *(result + i) = (float *)malloc(col * sizeof(float));

        for (int j = 0; j < col; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
}

// this function performs matrix subtraction.
float **subtraction(float **matrix1, float **matrix2, int row, int col)
{
    float **result = (float **)malloc(row * sizeof(float *));

    for (int i = 0; i < row; i++)
    {
        *(result + i) = (float *)malloc(col * sizeof(float));

        for (int j = 0; j < col; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    return result;
}

// this function performs matrix multiplication.
float **multiplication(float **matrix1, float **matrix2, int row1, int col2, int row2)
{
    float **result = (float **)malloc(row1 * sizeof(float *));

    // perform matrix multiplication on the two matrices.
    for (int i = 0; i < row1; i++)
    {
        *(result + i) = (float *)malloc(col2 * sizeof(float));

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

    return result;
}

void deleteMatrix(float **ptr, int row)
{
    for (int i = 0; i < row; i++)
    {
        free(ptr[i]);
    }
    free(ptr);
}