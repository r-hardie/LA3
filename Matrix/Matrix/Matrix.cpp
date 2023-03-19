#include "Matrix.h"

template <typename T>
Node<T>::Node() {
	nextInRow = nextInCol = nullptr;
}

template <typename T>
Node<T>::Node(T& v) {
	value = v;
	nextInRow = nextInCol = nullptr;
}

template<typename T>
Node<T>* Node<T>::copyRow(Node<T> row)
{
	if(row == nullptr)
		return row;
	Node<T>* firstInRow = new Node<T>(row->value);
	firstInRow->nextInRow = copyRow(row->nextInRow);
	return firstInRow;
}

template <typename T>
Matrix<T>::Matrix() {
	m = new Node<T>();
	rows = cols = 1;
}

template <typename T>
Matrix<T>::Matrix(T** array, const int arRows, const int arCols) {
	m = new Node<T>(array[0][0]);
	Node<T>* saved = m;
	//build first row
	for (int i = 1; i < arCols; i++) {
		Node<T>* newNode = new Node<T>(array[i][0]);
		saved->nextInRow = newNode;
		saved = newNode;
	}

	saved = m;
	Node<T>* rowUp = m;

	//fill out rest of matrix
	for(int i = 1; i < arRows; i++) {
		//
		if (saved->nextInRow == nullptr) {
			saved = m;
			int r = 0;
			while (saved->nextInCol != nullptr && r < arCols) {
				saved = saved->nextInCol;
				r++;
			}
		}

		Node<T>* firstInRow = new Node<T>(array[i][0]);
		saved->nextInCol = firstInRow;
		saved = firstInRow;

		for (int j = 1; j < arCols; j++) {
			Node<T>* newNode = new Node<T>(array[i][j]);
			saved->nextInRow = newNode;
			rowUp->nextInCol = newNode;
			rowUp = rowUp->nextInRow;
		}
	}
}

template <typename T>
Matrix<T>::Matrix(const Matrix& obj) {
	Node<T>* endMarker = nullptr;
	Node<T>* prevRow = nullptr;

	m = new Node<T>();
	m->value = obj.m->value;

	while (m != nullptr) {
		Node<T>* curRow = copyRow(obj.m);

		m = m->nextInCol;

		if (endMarker == nullptr) {
			endMarker = curRow;
		}

		if (prevRow != nullptr) {
			for (Node<T>* prevTemp = prevRow, *curTemp = curRow;
				prevTemp->nextInRow != nullptr;
				prevTemp = prevTemp->nextInRow, curTemp = curTemp->nextInRow) {
				
				prevTemp->nextInCol = curTemp;
			}
		}
		prevRow = curRow;
		
	}
}