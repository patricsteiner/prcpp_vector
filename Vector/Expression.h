#pragma once

#include <iostream>
#include "Operations.h"

using namespace std;

template<typename Left, typename Op, typename Right> class Expression {
	const Left& m_left;
	const Right& m_right;

public:
	typedef typename Left::value_type value_type; // http://stackoverflow.com/questions/10863075/member-to-function-pointer-inside-template-class-gives-error-must-be-a-class-or

	Expression(const Left& l, const Right& r) : m_left{ l }, m_right{ r } {}
	size_t size() const { return m_left.size(); }

	value_type operator[](int i) const {
		return Op::apply<value_type>(m_left[i], m_right[i]);
	}

	template <typename T> bool operator==(const T& other) {
		for (size_t i = 0; i < size(); i++) if ((*this)[i] != other[i]) return false;
		return true;
	}

	friend ostream& operator<<(ostream& os, const Expression& e) {
		os << "[";
		if (e.size() > 0) os << e[0];
		for (int i = 1; i < e.size(); i++) {
			os << ", " << e[i];
		}
		return os << "]";
	}
};

template<typename Op, typename Right> class Expression<double, Op, Right> {
	//TODO: do i really need to copy paste all methods and fields?
	//TODO: could i use sth more generic than double?
	const double m_left;
	const Right& m_right;

public:
	typedef double value_type; 

	Expression(const double s, const Right& r) : m_left{ s }, m_right{ r } {}
	size_t size() const { return m_right.size(); }

	value_type operator[](int i) const {
		return Op::apply<value_type>(m_left, m_right[i]);
	}

	template <typename T> bool operator==(const T& other) {
		for (size_t i = 0; i < size(); i++) if ((*this)[i] != other[i]) return false;
		return true;
	}

	friend ostream& operator<<(ostream& os, const Expression& e) {
		os << "[";
		if (e.size() > 0) os << e[0];
		for (int i = 1; i < e.size(); i++) {
			os << ", " << e[i];
		}
		return os << "]";
	}
};

template<typename Left, typename Op> class Expression<Left, Op, double> {
	const Left& m_left;
	const double m_right;

public:
	typedef double value_type;

	Expression(const Left& l, const double s) : m_left{ l }, m_right{ s } {}
	size_t size() const { return m_left.size(); }

	value_type operator[](int i) const {
		return Op::apply<value_type>(m_left[i], m_right);
	}

	template <typename T> bool operator==(const T& other) {
		for (size_t i = 0; i < size(); i++) if ((*this)[i] != other[i]) return false;
		return true;
	}

	friend ostream& operator<<(ostream& os, const Expression& e) {
		os << "[";
		if (e.size() > 0) os << e[0];
		for (int i = 1; i < e.size(); i++) {
			os << ", " << e[i];
		}
		return os << "]";
	}
};


template<typename Left, typename Right>
Expression<Left, Add, Right> operator+(const Left& l, const Right& r) {
	return Expression<Left, Add, Right>(l, r);
}

template<typename Left, typename Right>
Expression<Left, Subtract, Right> operator-(const Left& l, const Right& r) {
	return Expression<Left, Subtract, Right>(l, r);
}

template<typename Left, typename Right>
Expression<Left, Multiply, Right> operator*(const Left& l, const Right& r) {
	return Expression<Left, Multiply, Right>(l, r);
}

template<typename Left, typename Right>
Expression<Left, Divide, Right> operator/(const Left& l, const Right& r) {
	return Expression<Left, Divide, Right>(l, r);
}