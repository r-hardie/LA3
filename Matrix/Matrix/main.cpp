#include "Matrix.h"
#include <iostream>
using namespace std;

int main() {

	//default constructor
	Matrix<int>* emptyMatrix = new Matrix<int>();

	//parameterized constructor
	const int arrayRows = 5;
	const int arrayCols = 3;

	int** testArray = new int* [arrayRows];
	for (int i = 0; i < arrayRows; i++) {
		testArray[i] = new int[arrayCols];
	}
	for (int i = 0; i < arrayRows; i++) {
		for (int j = 0; j < arrayCols; j++) {
			testArray[i][j] = i + j;
		}
	}

	for (int i = 0; i < arrayRows; i++) {
		for (int j = 0; j < arrayCols; j++) {
			cout << testArray[i][j];
		}
	}




	//Matrix<int>* arrayMatrix = new Matrix<int>(testArray, arrayRows, arrayCols);


	//copy constructor

	return 0;
}