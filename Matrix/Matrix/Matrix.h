#ifndef MATRIX_H
#define MATRIX_H

class Node {
public:
	double value;
	Node* nextInRow, * nextInCol;

	Node();
	Node(double& v);
	Node* copyRow(Node* row);
};

class Matrix
{
private:
	Node* m;
	int rows, cols;

public:
	Matrix();
	Matrix(double** array, const int arRows, const int arCols); //check syntax on this
	Matrix(const Matrix& obj);
	Matrix(const Matrix&& obj);
	Matrix& operator=(const Matrix& obj);
	Matrix& operator=(const Matrix&& obj);
	~Matrix();

	Matrix& getRow(int row);
	Matrix& getCol(int col);
	double& getElement(int row, int col);
	Matrix& transpose(const Matrix& obj);
	Matrix& operator+(const Matrix& obj);
	Matrix& operator*(const Matrix& obj);

	//friend ostream& operator<<(ostream& output, const Matrix<T>& obj);

};

#endif MATRIX_H
