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

        // then, present a menu that allows the user to
        // select the operation they want to test.
        do {
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
                    if (!checkPermissibility(matrix1, matrix2)) {
                        System.out.println(
                                "Error: addition is not permissible on the two matrices. Please enter two new matrices.");
                        break;
                    }
                    // perform addition on two matrices and print out the result.
                    addition(null, null);
                    printMatrices();
                    break;
                case 2:
                    // check to see if subtraction is permissible on the two matrices.
                    if (!checkPermissibility(matrix1, matrix2)) {
                        System.out.println(
                                "Error: subtraction is not permissible on the two matrices. Please enter two new matrices.");
                        break;
                    }
                    // perform subtraction on two matrices and print out the result.
                    subtraction(null, null);
                    printMatrices();
                    break;
                case 3:
                    // check to see if multiplication is permissible on the two matrices.
                    if (!checkPermissibility(matrix1, matrix2)) {
                        System.out.println(
                                "Error: multiplication is not permissible on the two matrices. Please enter two new matrices.");
                        break;
                    }
                    // perform multiplication on two matrices and print out the result.
                    multiplication(null, null, userInput);
                    printMatrices();
                    break;
                case 4:
                    // provide the user an option to select two new matrices.
                    enterMatrices();
                    break;
                case 5:
                    System.out.println("Terminating the program... Good bye!");
                    System.exit(0);
                default:
                    System.out.println("Please enter a number from 1 to.");
            }

            // NOTE: have the menu in a loop so that the user can test any
            // other operation unless they choose to exit the menu.
        } while (userInput != 5);

    }

    // this method allows the user to enter the size and the elements for two
    // matrices.
    protected static void enterMatrices() {
        int size1, size2;
        Scanner scanner = new Scanner(System.in);

        System.out.println("Please enter the size for an n x n matrix #1: ");
        size1 = scanner.nextInt();
        // clear the buffer.
        scanner.nextLine();

        System.out.println("Please enter the size for an n x n matrix #2: ");
        size2 = scanner.nextInt();
        // clear the buffer.
        scanner.nextLine();

        // create two n x n matrices.
        float temp;
        matrix1 = new float[size1][size1];
        matrix2 = new float[size2][size2];

        for (int i = 0; i < matrix1.length; i++) {
            for (int j = 0; i < matrix1[0].length; j++) {
                System.out.println("Please enter a floating point value for Matrix #1's Row #" + (i + 1)
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
            for (int j = 0; i < matrix2[0].length; j++) {
                System.out.println("Please enter a floating point value for Matrix #2's Row #" + (i + 1)
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

        // close the scanner to avoid resource leak.
        scanner.close();

    }

    // this method will print out the result of the operation after it is performed.
    public static void printMatrices(float[][] result) {
        System.out.println("Printing out the result...\n");

        for (int i = 0; i < result.length; i++) {
            for (int j = 0; j < result[0].length; j++) {
                System.out.print(result[i][j] + " ");
            }
            System.out.println();
        }

    }

    // this method will check whether a certain opereation will be permissible
    // on the two matrices entered by the user.
    // NOTE: we will only permit operations on two equal sized matrices for this
    // project.
    private static boolean checkPermissibility(float[][] matrix1, float[][] matrix2) {
        if (matrix1.length != matrix2.length || matrix1[0].length != matrix2[0].length) {
            return false;
        }

        // return true if two n x n matrices have the equal size.
        return true;

    }

    // this function performs matrix addition.
    protected static int[][] addition(float[][] matrix1, float[][] matrix2) {
        int n = matrix1.length;
        float[][] result = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // add corresponding elements of matrices.
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }

        // return the result back to the caller method.
        return result;
    }

    // this function performs matrix subtraction.
    protected static int[][] subtraction(float[][] matrix1, float[][] matrix2) {
        int n = matrix.length;
        float[][] result = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Subtracting corresponding elements of matrices
                result[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }

        // return the result back to the caller method.
        return result;
    }

    protected static int[][] multiplication(float[][] matrix1, float[][] matrix2) {
        int n = matrix1.length;
        float[][] result = new int[n][n];

        // perform matrix multiplication on the two matrices.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // first, initialize the new matrix to 0.
                result[i][j] = 0.0;

                for (int k = 0; k < n; k++) {
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
