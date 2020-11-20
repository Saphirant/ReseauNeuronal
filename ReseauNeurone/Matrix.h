#pragma once

#include <vector>
#include <iostream>

template <typename T>
class Matrix
{
public:

	Matrix(Matrix<T> const& matrix_copy);
	Matrix(unsigned int rows, unsigned int cols, T defaultValue = T{});
	Matrix();

	/// FUNCTIONS
	inline unsigned int getRows() const;
	inline unsigned int getColumns() const;

	void setSize(unsigned int i, unsigned int j, T defaultValue = T{});

	void display() const;

	Matrix<T> transpose() const;
	T determinant() const;
	Matrix<T> gaussianElimination() const;

	virtual ~Matrix();

	/// OPERATORS
	//  Arithmetic Operators
	Matrix<T> operator*(Matrix<T> const& a);
	Matrix<T> operator*(T const& a);

	Matrix<T> operator+(Matrix<T> const& a);

	Matrix<T> operator-(Matrix<T> const& a);
	Matrix<T> operator-();

	//  Assignement Operator
	void operator=(Matrix<T> const& a);

	//  Positional Operators
	T& operator()(unsigned int i, unsigned int j);

private:

	unsigned int m_i;
	unsigned int m_j;
	std::vector<T> m_data;
};

template <typename T>
std::ostream& operator<<(std::ostream &flux, Matrix<T> const& a);

/// CONSTRUCTORS

template <typename T>
Matrix<T>::Matrix() :
	m_i(0),
	m_j(0)
{

}

template<typename T>
Matrix<T>::Matrix(unsigned int rows, unsigned int cols, T defaultValue) :
	m_i(rows),
	m_j(cols),
	m_data(std::vector<T>(rows*cols, defaultValue))
{

}

template <typename T>
Matrix<T>::Matrix(Matrix<T> const& matrix_copy)
{
	operator=(matrix_copy);
}

// FUNCTIONS

template <typename T>
void Matrix<T>::display() const
{
	std::cout << "(" << m_i << ", " << m_j << ")\n";
	for (unsigned int i(0); i < m_i; i++) {
		for (unsigned int j(0); j < m_j; j++) {
			std::cout << m_data[i + (j*m_i)] << ' ';
		}
		std::cout << '\n';
	}
}

template <typename T>
inline unsigned int Matrix<T>::getRows() const
{
	return m_i;
}

template <typename T>
inline unsigned int Matrix<T>::getColumns() const
{
	return m_j;
}

template <typename T>
void Matrix<T>::setSize(unsigned int i, unsigned int j, T defaultValue) {
	m_data.clear();
	m_data.resize(i*j, defaultValue);
	m_i = i;
	m_j = j;
}

// arithmetic
template <typename T>
Matrix<T> Matrix<T>::transpose() const {
	Matrix<T> result(m_j, m_i, T{});

	for (unsigned int i(0); i < m_i; i++)
		for (unsigned int j(0); j < m_j; j++) {
			result(j, i) = m_data[i + (j * m_i)];
		}

	return result;
}

template <typename T>
T Matrix<T>::determinant() const {
	if (m_i != m_j)
		throw("Matrix : non-square matrix");

	T line = T{ 0 };
	T part = T{ 0 };
	T offLine;/*

	for(unsigned int offset(0) ; offset<m_i ; offset++){
		offLine = T{1} ;
		for(unsigned int i(0) ; i<m_i ; i++){
			offLine *= m_data[((i+offset)%m_i)+((i)*m_i)] ;
		}
		line += offLine ;
	}

	for(unsigned int offset(0) ; offset<m_i ; offset++){
		offLine = T{1} ;
		for(unsigned int i(m_i) ; i>0 ; i--){
			offLine *= m_data[((m_i-i+offset)%m_i)+((i)*m_i)] ;
		}
		part += offLine ;
	}*/

	return line - part;
}

template <typename T>
Matrix<T> Matrix<T>::gaussianElimination() const {
	Matrix<T> result = this;



	return result;
}

// DESTRUCTOR

template<typename T>
Matrix<T>::~Matrix()
{

}

// OPERATORS

// assignment
template <typename T>
void Matrix<T>::operator=(Matrix<T> const& a) {
	m_i = a.m_i;
	m_j = a.m_j;

	m_data.clear();

	for (unsigned int i(0); i < a.m_i*a.m_j; i++) {
		m_data.push_back(a.m_data[i]);
	}
}

// arithmetic
template <typename T>
Matrix<T> Matrix<T>::operator+(Matrix<T> const& a) {
	Matrix<T> result(a.m_i, a.m_j, T{});

	if (a.m_i != m_i || a.m_j != m_j) {
		throw("Matrix : cant add b to a");
	}

	for (unsigned int i(0); i < m_i; i++)
		for (unsigned int j(0); j < m_j; j++) {
			result(i, j) = a.m_data[i + (j*m_i)] + m_data[i + (j*m_i)];
		}

	return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(Matrix<T> const& a) {

	Matrix<T> result(a.m_i, a.m_j, T{});

	if (a.m_i != m_i || a.m_j != m_j)
		throw("Matrix : cant subtract b to a");

	for (unsigned int i(0); i < m_i; i++)
		for (unsigned int j(0); j < m_j; j++) {
			result(i, j) = m_data[i + (j*m_i)] - a.m_data[i + (j*m_i)];
		}

	return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator-() {
	Matrix<T> result(m_i, m_j, T{});

	for (unsigned int i(0); i < m_i; i++)
		for (unsigned int j(0); j < m_j; j++) {
			result(i, j) = -m_data[i + (j*m_i)];
		}

	return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(Matrix<T> const& a) {

	if (a.m_i != m_j) {
		if (a.m_j == m_i)
			throw("Matrix : cant multiply a and b\nDo you mean b*a ?\n");
		throw("Matrix : cant multiply a and b\n");
	}

	Matrix<T> result(m_i, a.m_j, T{});

	for (unsigned int i(0); i < result.getRows(); i++)
		for (unsigned int j(0); j < result.getColumns(); j++)
			for (unsigned int k(0); k < m_j; k++)
				result(i, j) += a.m_data[k + (j*result.getRows())] * m_data[i + (k*result.getRows())];


	return result;

}

template <typename T>
Matrix<T> Matrix<T>::operator*(T const& a) {

	Matrix<T> result(m_i, m_j, T{});

	for (unsigned int i(0); i < result.getRows(); i++)
		for (unsigned int j(0); j < result.getColumns(); j++)
			result(i, j) = m_data[i + (j*m_i)] * a;

	return result;

}

// boolean

template <typename T>
bool operator==(Matrix<T> const& a, Matrix<T> const& b) {
	if (a.getRows() != b.getRows() ||
		a.getColumns() != b.getColumns())
		return false;

	for (unsigned int i(0); i < a.getRows(); i++)
		for (unsigned int j(0); j < a.getColumns(); j++)
			if (a(i, j) != b(i, j))
				return false;

	return true;
}

template <typename T>
inline bool operator!=(Matrix<T> const& a, Matrix<T> const& b) {
	return !(a == b);
}

// access
template <typename T>
T& Matrix<T>::operator()(unsigned int i, unsigned int j) {
	return (m_data[i + (j*m_i)]);
}

// display x
template <typename T>
std::ostream& operator<<(std::ostream &flux, Matrix<T> const& a) {
	for (int i(0); i < a.getRows(); i++) {
		for (int j(0); j < a.getColumns(); j++) {
			//flux << a[i+(j*a.getRows())] << ' ' ;
		}
		flux << '\n';
	}
	return flux;
}
