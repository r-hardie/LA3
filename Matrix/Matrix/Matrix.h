#ifndef MATRIX_H
#define MATRIX_H

template <typename T>
class Node {
public:
	T value;
	Node* nextInRow, * nextInCol;

	Node();
	Node(T& v);
	Node* copyRow(Node row);
};

template <typename T>
class Matrix
{
private:
	Node* m;
	int rows, cols;

public:
	Matrix();
	Matrix(const T array[][100], int arRows, int arCols); //check syntax on this
	Matrix(const Matrix& obj);
	Matrix(const Matrix&& obj);
	Matrix& operator=(const Matrix& obj);
	Matrix& operator=(const Matrix&& obj);
	~Matrix();

	Matrix& getRow(int row);
	Matrix& getCol(int col);
	T& getElement(int row, int col);
	Matrix& transpose(const Matrix& obj);
	Matrix& operator+(const Matrix& obj);
	Matrix& operator*(const Matrix& obj);

	friend ostream& operator<<(ostream& output, const Matrix& obj);

};

#endif MATRIX_H
