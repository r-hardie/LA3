#include "Matrix.h"
#include <iostream>
using namespace std;

int main() {

	//default constructor
	Matrix<int>* emptyMatrix = new Matrix<int>();

	//parameterized constructor
	const int arrayRows = 5;
	const int arrayCols = 3;

		//int testArray[5][3] = {
		//	1,2,3,
		//	4,5,6,
		//	7,8,9,
		//	10,11,12,
		//	13,14,15
		//};	
	
	int* testArray = new array[5][3];


	testArray = {
		1,2,3,
		4,5,6,
		7,8,9,
		10,11,12,
		13,14,15
	};



	Matrix<int>* arrayMatrix = new Matrix<int>(testArray, arrayRows, arrayCols);


	//copy constructor

	return 0;
}