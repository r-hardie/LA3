#include "Matrix.h"
#include <iostream>

//default constructor
Matrix<int>* emptyMatrix = new Matrix<int>();

//parameterized constructor
int arrayRows = 5;
int arrayCols = 3;
int testArray[arrayRows][arrayCols] = {
	1,2,3,
	4,5,6,
	7,8,9,
	10,11,12,
	13,14,15
};

Matrix<int>* arrayMatrix = new Matrix<int>(testArray[][], arrayRows, arrayCols);


//copy constructor