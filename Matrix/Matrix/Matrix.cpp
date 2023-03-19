#include "Matrix.h"

Node::Node() {
	value = 0;
	nextInRow = nextInCol = nullptr;
}

Node::Node(double& v) {
	value = v;
	nextInRow = nextInCol = nullptr;
}

Node* Node::copyRow(Node* row) {
	if(row == nullptr)
		return row;
	Node* firstInRow = new Node(row->value);
	firstInRow->nextInRow = copyRow(row->nextInRow);
	return firstInRow;
}

Matrix::Matrix() {
	m = new Node();
	rows = cols = 1;
}

Matrix::Matrix(double** array, const int arRows, const int arCols) {
	m = new Node(array[0][0]);
	rows = arRows;
	cols = arCols;

	Node* saved = m;
	//build first row
	for (int i = 1; i < arCols; i++) {
		Node* newNode = new Node(array[i][0]);
		saved->nextInRow = newNode;
		saved = newNode;
	}

	saved = m;
	Node* rowUp = m;

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

		Node* firstInRow = new Node(array[i][0]);
		saved->nextInCol = firstInRow;
		saved = firstInRow;

		for (int j = 1; j < arCols; j++) {
			Node* newNode = new Node(array[i][j]);
			saved->nextInRow = newNode;
			rowUp->nextInCol = newNode;
			rowUp = rowUp->nextInRow;
		}
	}
}

Matrix::Matrix(const Matrix& obj) {
	Node* endMarker = nullptr;
	Node* prevRow = nullptr;

	m = new Node();
	m->value = obj.m->value;
	rows = obj.rows;
	cols = obj.cols;

	while (m != nullptr) {
		Node* curRow = m->copyRow(m);

		m = m->nextInCol;

		if (endMarker == nullptr) {
			endMarker = curRow;
		}

		if (prevRow != nullptr) {
			for (Node* prevTemp = prevRow, *curTemp = curRow;
				prevTemp->nextInRow != nullptr;
				prevTemp = prevTemp->nextInRow, curTemp = curTemp->nextInRow) {
				
				prevTemp->nextInCol = curTemp;
			}
		}
		prevRow = curRow;
		
	}
}