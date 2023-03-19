#include "Matrix.h"
#include <iostream>
using namespace std;

int main() {

	//default constructor
	Matrix* emptyMatrix = new Matrix();

	//parameterized constructor
	const int arrayRows = 5;
	const int arrayCols = 3;
	double arrayDataPoint = 0;

	double** testArray = new double* [arrayRows];
	for (int i = 0; i < arrayRows; i++) {
		testArray[i] = new double[arrayCols];
	}
	for (int i = 0; i < arrayRows; i++) {
		for (int j = 0; j < arrayCols; j++) {
			testArray[i][j] = ++arrayDataPoint;
		}
	}

	for (int i = 0; i < arrayRows; i++) {
		for (int j = 0; j < arrayCols; j++) {
			cout << testArray[i][j] << ' ';
		}
	}

	Matrix* arrayMatrix = new Matrix(testArray, arrayRows, arrayCols);


	//copy constructor

	return 0;
}