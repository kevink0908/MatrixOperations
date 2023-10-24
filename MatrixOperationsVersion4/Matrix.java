// Programmer: Kevin Kim
// Instructor: Professor Raheja
// Course: CS 4080-03
// Date: 22 October 2023
// Description: This is the Java version (version #4) for the Programming Project 1.

import java.util.Scanner;

public class Matrix {
    static float[][] matrix1, matrix2;

    // this driver program tests three different operations with matrices.
    public static void main(String[] args) {
        int userInput = 0;
        Scanner keyboard = new Scanner(System.in);
        // prompt the user to enter two matrices.
        enterMatrices();
        // display the matrices before performing any operations.
        System.out.println("Matrix #1: ");
        printMatrices(matrix1);
        System.out.println("Matrix #2: ");
        printMatrices(matrix2);

        // then, present a menu that allows the user to
        // select the operation they want to test.
        do {
            System.out.println("\nPlease select from the following options:");
            System.out.println("(1) Add the matrices.");
            System.out.println("(2) Subtract the matrices.");
            System.out.println("(3) Multiply the matrices.");
            System.out.println("(4) Select two new matrices.");
            System.out.println("(5) Exit the program.");
            userInput = keyboard.nextInt();
            // clear the buffer.
            keyboard.nextLine();

            switch (userInput) {
                case 1:
                    // check to see if addition is permissible on the two matrices.
                    if (!checkAdditionPermissibility(matrix1, matrix2)) {
                        System.out.println(
                                "Error: addition is not permissible on the current matrices. Please enter two new matrices to perform an addition.");
                        break;
                    }
                    // perform addition on two matrices and print out the result.
                    printMatrices(addition(matrix1, matrix2));
                    break;
                case 2:
                    // check to see if subtraction is permissible on the two matrices.
                    if (!checkAdditionPermissibility(matrix1, matrix2)) {
                        System.out.println(
                                "Error: subtraction is not permissible on the current matrices. Please enter two new matrices to perform a subtraction.");
                        break;
                    }
                    // perform subtraction on two matrices and print out the result.
                    printMatrices(subtraction(matrix1, matrix2));
                    break;
                case 3:
                    // check to see if multiplication is permissible on the two matrices.
                    if (!checkMultiplicationPermissibility(matrix1, matrix2)) {
                        System.out.println(
                                "Error: multiplication is not permissible on the two matrices. Please enter two new matrices to perform a multiplication.");
                        break;
                    }
                    // perform multiplication on two matrices and print out the result.
                    printMatrices(multiplication(matrix1, matrix2));
                    break;
                case 4:
                    // provide the user an option to select two new matrices.
                    enterMatrices();
                    break;
                case 5:
                    System.out.println("Terminating the program... Good bye!");
                    System.exit(0);
                default:
                    System.out.println("Please enter a number from 1 to 5.");
            }

            // NOTE: have the menu in a loop so that the user can test any
            // other operation unless they choose to exit the menu.
        } while (userInput != 5);

    }

    // this method allows the user to enter the size and the elements for two
    // matrices.
    protected static void enterMatrices() {
        int row, col;
        Scanner scanner = new Scanner(System.in);

        System.out.print("\nPlease enter the row size for matrix #1: ");
        row = scanner.nextInt();
        // clear the buffer.
        scanner.nextLine();

        System.out.print("Please enter the column size for matrix #1: ");
        col = scanner.nextInt();
        // clear the buffer.
        scanner.nextLine();

        // create the first matrix using the row and the column values.
        matrix1 = new float[row][col];

        System.out.print("Please enter the row size for matrix #2: ");
        row = scanner.nextInt();
        // clear the buffer.
        scanner.nextLine();

        System.out.print("Please enter the column size for matrix #2: ");
        col = scanner.nextInt();
        // clear the buffer.
        scanner.nextLine();

        // create the second matrix using the row and the column values.
        matrix2 = new float[row][col];

        float temp;
        for (int i = 0; i < matrix1.length; i++) {
            for (int j = 0; j < matrix1[0].length; j++) {
                System.out.print("Please enter a floating point value for Matrix #1's Row #" + (i + 1)
                        + " and Column #" + (j + 1) + ": ");
                temp = scanner.nextFloat();
                // clear the buffer.
                scanner.nextLine();

                // verify that the input value is a floating point value.
                if (temp == (float) temp) {
                    matrix1[i][j] = temp;
                }
            }
        }

        for (int i = 0; i < matrix2.length; i++) {
            for (int j = 0; j < matrix2[0].length; j++) {
                System.out.print("Please enter a floating point value for Matrix #2's Row #" + (i + 1)
                        + " and Column #" + (j + 1) + ": ");
                temp = scanner.nextFloat();
                // clear the buffer.
                scanner.nextLine();

                // verify that the input value is a floating point value.
                if (temp == (float) temp) {
                    matrix2[i][j] = temp;
                }
            }
        }

    }

    // this method will print out the result of the operation after it is performed.
    public static void printMatrices(float[][] result) {
        System.out.println("\nPrinting out the result...\n");

        for (int i = 0; i < result.length; i++) {
            for (int j = 0; j < result[0].length; j++) {
                System.out.print(result[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();

    }

    // this method will check whether addition or subtraction will be permissible
    // on the two matrices entered by the user.
    // NOTE: both addition and subtraction are permissible only if the two
    // matrices have the same dimensions.
    private static boolean checkAdditionPermissibility(float[][] matrix1, float[][] matrix2) {
        if (matrix1.length != matrix2.length || matrix1[0].length != matrix2[0].length) {
            return false;
        }

        // return true if two n x n matrices have the equal size.
        return true;

    }

    // this method will check whether multiplication will be permissible
    // on the two matrices entered by the user.
    // NOTE: matrix multiplication will be permissible only if the number of
    // columns in the first matrix is equal to the number of rows in the
    // second matrix.
    private static boolean checkMultiplicationPermissibility(float[][] matrix1, float[][] matrix2) {
        // check to see if the number of columns in the first matrix is equal
        // to the number of rows in the second matrix.
        if (matrix1[0].length != matrix2.length) {
            return false;
        }

        // return true if multiplication can be performed on the two matrices.
        return true;

    }

    // this function performs matrix addition.
    protected static float[][] addition(float[][] matrix1, float[][] matrix2) {
        int row = matrix1.length, col = matrix1[0].length;
        float[][] result = new float[row][col];

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // add corresponding elements of matrices.
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }

        // return the result back to the caller method.
        return result;
    }

    // this function performs matrix subtraction.
    protected static float[][] subtraction(float[][] matrix1, float[][] matrix2) {
        int row = matrix1.length, col = matrix1[0].length;
        float[][] result = new float[row][col];

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // Subtracting corresponding elements of matrices
                result[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }

        // return the result back to the caller method.
        return result;
    }

    // this function performs matrix multiplication.
    protected static float[][] multiplication(float[][] matrix1, float[][] matrix2) {
        int row = matrix1.length, col = matrix2[0].length, row2 = matrix2.length;
        float[][] result = new float[row][col];

        // perform matrix multiplication on the two matrices.
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // first, initialize the new matrix to 0.
                result[i][j] = 0;

                for (int k = 0; k < row2; k++) {
                    // then, start multiplying two matrices before
                    // storing the products in the new matrix.
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }

        // return the result back to the caller method.
        return result;
    }
}
