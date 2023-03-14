#include "Matrix.h"

template <typename T>
Node<T>::Node() {
	//do we need to do anything for value here?
	nextInRow = nextInCol = nullptr;
}

template <typename T>
Node<T>::Node(T& v) {
	value = v;
	nextInRow = nextInCol = nullptr;
}

template <typename T>
Matrix<T>::Matrix() {
	first = new Node();
	rows = cols = 1;
}

template <typename T>
Matrix<T>::Matrix(const T array[][100], int arRows, int arCols) {

}