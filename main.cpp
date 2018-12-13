/////////////////////////////////////////////////////////////////////////
30. Визначити чи є задана ціла квадратна матриця магічним квадратом,
тобто такою, у якої суми елементів по кожному стовпцю, рядку та кожній із
двох діагоналей рівні між собою.
////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void inputMatrix(int**, int);
void outputMatrix(int**, int);
bool isMagicSquare(int**, int);
int getRowSum(int**, int, int);
int getColumnSum(int**, int, int);
int getDiagSum(int**, int);
int getAnotherDiagSum(int**, int);

int main() {
	int size;
	cout << "Input size: ";
	cin >> size;
	int** matrix = new int*[size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
	}
	inputMatrix(matrix, size);
	outputMatrix(matrix, size);

	int newcount = isMagicSquare(matrix, size);
	
	if (newcount == 0) {
		cout << "This matrix isn't magic square!!!" << endl;
	}
	else cout << "This matrix is magic square!!! Congratulations!!!\n";

	for (int i(0); i < size; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	return 0;
}

void inputMatrix(int** matrix, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> matrix[i][j];
			}
		}
	}

void outputMatrix(int** matrix, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << setw(9) << right << matrix[i][j];
		}
		cout << endl;
	}
}

bool isMagicSquare(int** matrix, int size) {
	int sum = 0;
	bool flag = true;
	sum = getRowSum(matrix, size, 0);

	for (int i = 0; i < size; i++) {
		if (sum != getRowSum(matrix, size, i) || sum != getColumnSum(matrix, size, i)) {
			return false;
		}
	}
	if (sum != getDiagSum(matrix, size) || sum != getAnotherDiagSum(matrix, size)) {
		return false;
	}
	return true;
}

int getRowSum(int** matrix, int size, int row) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += matrix[row][i];
	}
	return sum;
}

int getColumnSum(int** matrix, int size, int column) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += matrix[i][column];
	}
	return sum;
}

int getDiagSum(int** matrix, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += matrix[i][i];
	}
	return sum;
}

int getAnotherDiagSum(int** matrix, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += matrix[size - (i + 1)][i];
	}
	return sum;
}
