#ifndef MATRIX_H
#define MATRIX_H

template <typename T>
class Node {
public:
	T value;
	Node* nextInRow, * nextInCol;

	Node();
	Node(T& value);
};

template <typename T>
class Matrix
{
private:
	Node* first;
	int rows, cols;

public:
	Matrix();
	Matrix(const array[][MAX], int rows, int cols); //check syntax on this
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

