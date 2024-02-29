#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//front end function for getting data from user
int** front_enterMatrix(int &rows, int &columns) {

	rows = 0, columns = 0;
	cout << "TO GET STARTED PLEASE ENTER ROWS AND COLUMNS OF MATRIX" << endl;

	//creating matrix
	while (rows <= 0 && columns <= 0) {
		cout << "Enter number of rows: ";
		cin >> rows;
		cout << "Enter number of columns: ";
		cin >> columns;
		if (rows > 0 && columns > 0) {
			break;
		}
		else {
			cout << "Input is not valid" << endl;
		}
	}
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[columns];
	}

	//asking user for entering matrix personally or from file
	char user_enterMatrix = '0';
	while (user_enterMatrix != 'y' || user_enterMatrix != 'n') {
		cout << "How would you like to enter matrix (personally/from file)" << endl;
		cout << "For entering data personally enter y." << endl;
		cout << "For entering data from file enter n." << endl;
		cout << "-->";
		cin >> user_enterMatrix;
		if (user_enterMatrix == 'y' || user_enterMatrix == 'n') {
			break;
		}
		else {
			cout << "Enter valid Input. Enter y or n" << endl;
		}
	}

	//personally entering matrix
	if (user_enterMatrix == 'y') {

		//getting data from user
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				cout << "Enter number for Matrix[" << i << "][" << j << "] :";
				cin >> matrix[i][j];
			}
		}

	}
	//entering matrix from file
	else if (user_enterMatrix == 'n') {

		//getting filename from user
		string filename, fileExtension = ".txt";
		cout << "Enter file name: ";
		cin >> filename;
		string file = filename + fileExtension;

		//opening file for reading
		int temp;
		ifstream fin_entermatrix(file);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				fin_entermatrix >> temp;
				matrix[i][j] = temp;
			}
		}
	}
	return matrix;
}

//front end function for display
void front_displayMatrix(int **matrix, int rows, int columns){
	//asking user to display matrix on console or on file
	char user_displayMatrix = '0';
	while (user_displayMatrix != 'y' || user_displayMatrix != 'n') {
		cout << "You can display Matrix on console or on file" << endl;
		cout << "To Display on console press y" << endl;
		cout << "To Display on file press n" << endl;
		cout << "-->";
		cin >> user_displayMatrix;
		if (user_displayMatrix == 'y' || user_displayMatrix == 'n') {
			break;
		}
		else {
			cout << "Enter valid input. Enter y or n" << endl;
		}
	}
	//to display on console
	if (user_displayMatrix == 'y') {
		cout << "Output Matrix: " << endl;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	//to display on file
	else if (user_displayMatrix == 'n') {
		cout << "All Matrices displayed on file will be stored in one file named display.txt" << endl;
		ofstream fout("display.txt", ios::app);
		fout << endl;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				fout << matrix[i][j] << " ";
			}
			fout << endl;
		}
	}

}

//function for displaying menu and getting user choice of function
void displayMenu() {
	cout << "-------------------------------------------------------------" << endl;
	cout << "\t\t\t Welcome To Start Menu \t\t\t" << endl;
	cout << endl;
	cout << "\t\t All The Functions You Can Perform On Matrices Are Listed Below" << endl;
	cout << endl;
	cout << "1. Sum of all values of matrix (enter 1)." << endl;
	cout << "2. Product of all values of matrix (enter 2)." << endl;
	cout << "3. Row wise average (enter 3)." << endl;
	cout << "4. Columns wise average (enter 4)." << endl;
	cout << "5. Average of whole matrix (enter 5)." << endl;
	cout << "6. Row wise sorting (enter 6)." << endl;
	cout << "7. Column wise sorting (enter 7)." << endl;
	cout << "8. Scalar matrix addition (enter 8)." << endl;
	cout << "9. Addition of two matrices (enter 9)." << endl;
	cout << "10. Scalar matrix substraction (enter 10)." << endl;
	cout << "11. Substraction of two matrices (enter 11)." << endl;
	cout << "12. Scalar matrix multiplication (enter 12)." << endl;
	cout << "13. Multiplication of two matrices (enter 13)." << endl;
	cout << "14. Scalar matrix division (enter 14)." << endl;
	cout << "15. Matrix Transpose (enter 15)." << endl;
	cout << "16. Matrix Determinent of only 2x2 matrix (enter 16)." << endl;
	cout << "17. Matrix Inverse (enter 17)." << endl;
	cout << endl;
	cout << "To Display this Menu again enter 18" << endl;
	cout << "Enter -1 to exit" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << endl << endl;

}

//Functionality requirements
//function for sum of all matrix values
int sumMatrix(int **matrix, int rows, int columns){
	int sum = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			sum += matrix[i][j];
		}
	}
	return sum;
}

//function for product of all matrix values
int productMatrix(int **matrix, int rows, int columns){
	int product = 1;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			product *= matrix[i][j];
		}
	}
	return product;
}

//function for getting average row wise
void rowWiseAverage(int **matrix, int rows, int columns){
	double* arrRows = new double[rows];
	int sum = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			sum += matrix[i][j];
		}
		*(arrRows + i) = double(sum) / double(columns);
		sum = 0;
	}
	cout << "Row Wise Average: " << endl;
	for (int i = 0; i < rows; i++) {
		cout << arrRows[i] << " ";
	}
	cout << endl;
	delete[] arrRows;
}

//function for getting average column wise
void columnWiseAverage(int **matrix, int rows, int columns){
	double* arrColumns = new double[columns];
	int sum = 0;
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {
			sum += matrix[j][i];
		}
		*(arrColumns + i) = double(sum) / double(rows);
		sum = 0;
	}
	cout << "Column Wise Average: " << endl;
	for (int i = 0; i < rows; i++) {
		cout << arrColumns[i] << " ";
	}
	cout << endl;
	delete[] arrColumns;
}

//function for getting average of whole matrix
double wholeMatrixAverage(int **matrix, int rows, int columns){
	double AvgMatrix = 0;
	int sum = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			sum += matrix[i][j];
		}
	}
	double size = rows * columns;
	AvgMatrix = double(sum) / size;
	return AvgMatrix;
}

//function for sorting row wise
void rowWiseSorting(int** matrix, int rows, int columns) {

	char user_sorting = '0';
	while (user_sorting != 'a' || user_sorting != 'd') {
		cout << "You can sort row wise in ascending or descending order" << endl;
		cout << "For ascending order enter a" << endl;
		cout << "For descending order enter d" << endl;
		cout << "-->";
		cin >> user_sorting;
		if (user_sorting == 'a' || user_sorting == 'd') {
			break;
		}
		else {
			cout << "Enter valid input. Enter a or d" << endl;
		}
	}

	int temp = 0, temp1 = 0, temp2 = 0;
	//creating duplicate array with rows size as size of array
	int* arrRows = new int[columns];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			arrRows[j] = matrix[temp1][j];		//copying row from original array to duplicate array
		}
		temp1++;
		if (user_sorting == 'a') {
			for (int i = 0; i < columns - 1; i++) {
				int min_index = i;
				for (int j = i + 1; j < columns; j++) {
					if (arrRows[j] < arrRows[min_index]) {		//sorting duplicate array
						min_index = j;
					}
				}
				temp = arrRows[i];
				arrRows[i] = arrRows[min_index];
				arrRows[min_index] = temp;
			}
		}
		else if (user_sorting == 'd') {
			for (int i = 0; i < columns - 1; i++) {
				int min_index = i;
				for (int j = i + 1; j < columns; j++) {
					if (arrRows[j] > arrRows[min_index]) {		//sorting duplicate array
						min_index = j;
					}
				}
				temp = arrRows[i];
				arrRows[i] = arrRows[min_index];
				arrRows[min_index] = temp;
			}
		}
		for (int i = 0; i < columns; i++) {
			matrix[temp2][i] = arrRows[i];		//storing sorted duplicate array to original row
		}
		temp2++;
	}
	delete[] arrRows;
	cout << "Row wise sorting done" << endl;
	front_displayMatrix(matrix, rows, columns);
}

//function for sorting column wise
void columnWiseSorting(int** matrix, int rows, int columns) {

	char user_sorting = '0';
	while (user_sorting != 'a' || user_sorting != 'd') {
		cout << "You can sort column wise in ascending or descending order" << endl;
		cout << "For ascending order enter a" << endl;
		cout << "For descending order enter d" << endl;
		cout << "-->";
		cin >> user_sorting;
		if (user_sorting == 'a' || user_sorting == 'd') {
			break;
		}
		else {
			cout << "Enter valid input. Enter a or d" << endl;
		}
	}

	int temp = 0, temp1 = 0, temp2 = 0;
	//creating duplicate array with rows size as size of array
	int* arrColumns = new int[rows];
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {
			arrColumns[j] = matrix[j][temp1];		//copying row from original array to duplicate array
		}
		temp1++;
		if (user_sorting == 'a') {
			for (int i = 0; i < rows - 1; i++) {
				int min_index = i;
				for (int j = i + 1; j < rows; j++) {
					if (arrColumns[j] < arrColumns[min_index]) {		//sorting duplicate array
						min_index = j;
					}
				}
				temp = arrColumns[i];
				arrColumns[i] = arrColumns[min_index];
				arrColumns[min_index] = temp;
			}
		}
		else if (user_sorting == 'd') {
			for (int i = 0; i < rows - 1; i++) {
				int min_index = i;
				for (int j = i + 1; j < rows; j++) {
					if (arrColumns[j] > arrColumns[min_index]) {		//sorting duplicate array
						min_index = j;
					}
				}
				temp = arrColumns[i];
				arrColumns[i] = arrColumns[min_index];
				arrColumns[min_index] = temp;
			}
		}
		for (int i = 0; i < rows; i++) {
			matrix[i][temp2] = arrColumns[i];		//storing sorted duplicate array to original row
		}
		temp2++;
	}
	delete[] arrColumns;
	cout << "Columns wise sorting done" << endl;
	front_displayMatrix(matrix, rows, columns);
}

//function for adding two matrices
void addTwoMatrix() {
	int rows = 0, columns = 0;
	//getting input from user
	cout << "First Matrix: " << endl;
	int** sumMatrix1 = front_enterMatrix(rows, columns);
	cout << "Second Matrix: " << endl;
	int** sumMatrix2 = front_enterMatrix(rows, columns);
	cout << "Original Matrices: " << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << sumMatrix1[i][j] << " ";
		}
		cout << '\t';
		for (int j = 0; j < columns; j++) {
			cout << sumMatrix2[i][j] << " ";
		}
		cout << endl;
	}
	//adding two matrices
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			sumMatrix1[i][j] += sumMatrix2[i][j];
		}
	}
	cout << "Sum of two Matrices are: " << endl;
	front_displayMatrix(sumMatrix1, rows, columns);
	//deleting matrix
	for (int i = 0; i < rows; i++) {
		delete[] sumMatrix1[i];
	}
	delete[] sumMatrix1;
	for (int i = 0; i < rows; i++) {
		delete[] sumMatrix2[i];
	}
	delete[] sumMatrix2;
}

//function for substracting two matrices
void substractTwoMatrix() {
	int rows = 0, columns = 0;
	cout << "First Matrix: " << endl;
	int** subMatrix1 = front_enterMatrix(rows, columns);
	cout << "Second Matrix: " << endl;
	int** subMatrix2 = front_enterMatrix(rows, columns);
	//getting input from user
	cout << "Original Matrices: " << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << subMatrix1[i][j] << " ";
		}
		cout << '\t';
		for (int j = 0; j < columns; j++) {
			cout << subMatrix2[i][j] << " ";
		}
		cout << endl;
	}
	//adding two matrices
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			subMatrix1[i][j] -= subMatrix2[i][j];
		}
	}
	cout << "Difference of two Matrices are: " << endl;
	front_displayMatrix(subMatrix1, rows, columns);
	//deleting matrix
	for (int i = 0; i < rows; i++) {
		delete[] subMatrix1[i];
	}
	delete[] subMatrix1;
	for (int i = 0; i < rows; i++) {
		delete[] subMatrix2[i];
	}
	delete[] subMatrix2;
}

//function for multiplying two matrices
void multiplyTwoMatrix() {
	//getting number of rows and columns from user
	int rows1 = 0, columns1 = 0;
	while (rows1 == 0 && columns1 == 0) {
		cout << "Enter number of rows for first matrix: ";
		cin >> rows1;
		cout << "Enter number of columns for first matrix: ";
		cin >> columns1;
		if (rows1 > 0 && columns1 > 0) {
			break;
		}
		else {
			cout << "Enter number of rows and columns greater than zero" << endl;
		}
	}
	int rows2 = 0, columns2 = 0;
	while (rows2 == 0 && columns2 == 0) {
		cout << "Enter number of rows for second matrix: ";
		cin >> rows2;
		cout << "Enter number of columns for second matrix: ";
		cin >> columns2;
		if (rows2 > 0 && columns2 > 0) {
			if (rows1 == columns2 && columns1 == rows2) {
				break;
			}
			else {
				cout << "Multiplication is not possible" << endl;
			}
		}
		else {
			cout << "Enter number of rows and columns greater than zero" << endl;
		}
	}
	int** firstMatrix = new int* [rows1];
	for (int i = 0; i < rows1; i++) {
		firstMatrix[i] = new int[columns1];
	}
	int** secMatrix = new int* [rows2];
	for (int i = 0; i < rows2; i++) {
		secMatrix[i] = new int[columns2];
	}
	//getting int input from user for the matrices
	for (int i = 0; i < rows1; i++) {
		for (int j = 0; j < columns1; j++) {
			cout << "Enter number for first Matrix[" << i << "][" << j << "] :";
			cin >> firstMatrix[i][j];
		}
	}
	cout << endl;
	for (int i = 0; i < rows2; i++) {
		for (int j = 0; j < columns2; j++) {
			cout << "Enter number for second Matrix[" << i << "][" << j << "] :";
			cin >> secMatrix[i][j];
		}
	}
	//creating new matrix with rows of first matrix and columns of second matrix
	int** proMatrix = new int* [rows1];
	for (int i = 0; i < rows1; i++) {
		proMatrix[i] = new int[columns2];
	}
	//multiplying two matrices
	for (int i = 0; i < rows1; i++) {
		for (int j = 0; j < columns2; j++) {
			for (int k = 0; k < columns1; k++) {
				proMatrix[i][j] = firstMatrix[i][k] *  secMatrix[k][j];
			}
		}
	}
	cout << "Product Of Two Matrix are: " << endl;
	front_displayMatrix(proMatrix, rows1, columns2);
	for (int i = 0; i < rows1; i++) {
		delete[] firstMatrix[i];
	}
	delete[] firstMatrix;
	for (int i = 0; i < rows2; i++) {
		delete[] secMatrix[i];
	}
	delete[] secMatrix;
	for (int i = 0; i < rows1; i++) {
		delete[] proMatrix[i];
	}
	delete[] proMatrix;
}

//function for calculating determinant
void determinant() {
	int rows = 2, columns = 2;
	int** matrix1 = new int* [rows];
	for (int i = 0; i < rows; i++) {
		matrix1[i] = new int[columns];
	}
	//geting input from user
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << "Enter number for Matrix[" << i << "][" << j << "] :";
			cin >> matrix1[i][j];
		}
	}
	int determinant = 0;
	determinant = (matrix1[0][0] * matrix1[1][1]) - (matrix1[1][0] * matrix1[0][1]);
	cout << "Input Matrix: " << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << matrix1[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "Determinant: " << determinant << endl;
	for (int i = 0; i < rows; i++) {
		delete[] matrix1[i];
	}
	delete[] matrix1;
}

//function for finding transpose of a matrix
void transposeMatrix() {
	int rows = 0, columns = 0;
	int** matrice = front_enterMatrix(rows, columns);
	//transpose have rows equal to columns of original matrix and vice versa
	int** transpose = new int* [columns];
	for (int i = 0; i < columns; i++) {
		transpose[i] = new int[rows];
	}
	int rows2 = columns, columns2 = rows;
	int temp = 0, temp2 = 0;
	//storing values in transpose matrix
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			transpose[temp][temp2] = matrice[i][j];
			temp++;
		}
		temp2++;
		temp = 0;
	}
	//displaying both matrices
	cout << "Original Matrix: " << endl;
	front_displayMatrix(matrice, rows, columns);
	cout << "Transpose of Matrix: " << endl;
	front_displayMatrix(transpose, rows2, columns2);
	//deleting
	for (int i = 0; i < rows; i++) {
		delete[] matrice[i];
	}
	delete[] matrice;
	for (int i = 0; i < rows2; i++) {
		delete[] transpose[i];
	}
	delete[] transpose;
}

//function for scalar matrix addition
void scalarAddition() {
	int rows = 0, columns = 0;
	int scalar = 0;
	//asking user for scalar value
	cout << "Enter a number: ";
	cin >> scalar;

	int** matrix = front_enterMatrix(rows, columns);
	cout << "Original Matrix: " << endl;
	front_displayMatrix(matrix, rows, columns);

	//adding scalar Value in original matrix
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			matrix[i][j] += scalar;
		}
	}

	cout << "Result Matrix: " << endl;
	front_displayMatrix(matrix, rows, columns);
	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}
//function for scalar matrix substraction
void scalarSubstraction() {
	int rows = 0, columns = 0;
	int scalar = 0;
	//asking user for scalar value
	cout << "Enter a number: ";
	cin >> scalar;

	int** matrix = front_enterMatrix(rows, columns);
	cout << "Original Matrix: " << endl;
	front_displayMatrix(matrix, rows, columns);

	//substracting scalar Value in original matrix
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			matrix[i][j] -= scalar;
		}
	}

	cout << "Result Matrix: " << endl;
	front_displayMatrix(matrix, rows, columns);
	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}
//function for scalar matrix multiplication
void scalarMultiplication() {
	int rows = 0, columns = 0;
	int scalar = 0;
	//asking user for scalar value
	cout << "Enter a number: ";
	cin >> scalar;

	int** matrix = front_enterMatrix(rows, columns);
	cout << "Original Matrix: " << endl;
	front_displayMatrix(matrix, rows, columns);

	//multiplying scalar Value in original matrix
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			matrix[i][j] *= scalar;
		}
	}

	cout << "Result Matrix: " << endl;
	front_displayMatrix(matrix, rows, columns);
	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}
//function for scalar matrix division
void scalarDivision() {
	int rows = 0, columns = 0;
	int scalar = 0;
	//asking user for scalar value
	cout << "Enter a number: ";
	cin >> scalar;

	int** matrix = front_enterMatrix(rows, columns);
	cout << "Original Matrix: " << endl;
	front_displayMatrix(matrix, rows, columns);

	//dividing scalar Value in original matrix
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			matrix[i][j] /= scalar;
		}
	}

	cout << "Result Matrix: " << endl;
	front_displayMatrix(matrix, rows, columns);
	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}
//function for finding inverse of a matrix
void matrixInverse() {
	int rows = 2, columns = 2;
	int** matrix1 = new int* [rows];
	for (int i = 0; i < rows; i++) {
		matrix1[i] = new int[columns];
	}
	//geting input from user
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << "Enter number for Matrix[" << i << "][" << j << "] :";
			cin >> matrix1[i][j];
		}
	}
	int determinant = 0;
	determinant = (matrix1[0][0] * matrix1[1][1]) - (matrix1[1][0] * matrix1[0][1]);
	cout << "Inverse of Matrix: " << endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << ((matrix1[(j + 1) % 2][(i + 1) % 2] * matrix1[(j + 2) % 2][(i + 2) % 2]) - (matrix1[(j + 1) % 2][(i + 2) % 2] * matrix1[(j + 2) % 2][(i + 1) % 2])) / determinant << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < rows; i++) {
		delete[] matrix1[i];
	}
	delete[] matrix1;
}

int main() {

	int rows = 0, columns = 0, userChoice = 0;
	bool running = true;
	int** matrix = nullptr;

	displayMenu();

	while (running) {

		//asking user for the function he would like to perform
		cout << "--->";
		cin >> userChoice;
		if(userChoice < 0 && userChoice > 17 && userChoice != -1) {
			cout << "Enter valid input from 1-12 or -1" << endl;
		}
		
		//comapring users choice to functions available
		switch (userChoice) {
		case 1: //sum of matrix values
			matrix = front_enterMatrix(rows, columns);
			cout << "Sum Of Matrix Values: " << sumMatrix(matrix, rows, columns) << endl;
			break;
		case 2: //product of matrix values
			matrix = front_enterMatrix(rows, columns);
			cout << "Product Of Matrix Values: " << productMatrix(matrix, rows, columns) << endl;
			break;
		case 3: //row wise average of matrix
			matrix = front_enterMatrix(rows, columns);
			rowWiseAverage(matrix, rows, columns);
			break;
		case 4: //column wise average of matrix
			matrix = front_enterMatrix(rows, columns);
			columnWiseAverage(matrix, rows, columns);
			break;
		case 5: //average of whole matrix
			matrix = front_enterMatrix(rows, columns);
			cout << "Average of Whole Matrix: " << wholeMatrixAverage(matrix, rows, columns) << endl;
			break;
		case 6: //row wise sorting
			matrix = front_enterMatrix(rows, columns);
			rowWiseSorting(matrix, rows, columns);
			break;
		case 7: //column wise sorting
			matrix = front_enterMatrix(rows, columns);
			columnWiseSorting(matrix, rows, columns);
			break;
		case 8: //scalar matrix addition
			scalarAddition();
			break;
		case 9: //addition of two matrices
			addTwoMatrix();
			break;
		case 10: //scalar matrix substraction
			scalarSubstraction();
			break;
		case 11: //substract two matrices
			substractTwoMatrix();
			break;
		case 12: //scalar matrix multiplication
			scalarMultiplication();
			break;
		case 13: //multiply two matrices
			multiplyTwoMatrix();
			break;
		case 14: //scalar matrix division
			scalarDivision();
			break;
		case 15: //transpose of a matrix
			transposeMatrix();
			break;
		case 16: //determinant of a matrix
			determinant();
			break;
		case 17: //inverse of a matrix
			matrixInverse();
			break;
		case 18: //display menu
			displayMenu();
			break;
		case -1: //exit the program
			running = false;
			break;
		default: //invalid input case
			cout << "Enter valid Input" << endl;
			break;
		}
	}
	
	//deleting matrices
	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	return 0;
}