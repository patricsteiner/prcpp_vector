#pragma once

#include <iostream>
#include "Operations.h"

using namespace std;

template<typename Left, typename Op, typename Right> class Expression {
	const Left& m_left;
	const Right& m_right;

public:
	typedef typename Left::value_type value_type;

	Expression(const Left& l, const Right& r) : m_left{ l }, m_right{ r } {}
	size_t size() const { return m_left.size(); }

	value_type operator[](int i) const {
		return Op::apply<value_type>(m_left[i], m_right[i]);
	}

	template <typename T> bool operator==(const T& other) {
		for (size_t i = 0; i < size(); i++) if ((*this)[i] != other[i]) return false;
		return true;
	}

	const Expression<Left, Op, Right>* operator*() const {
		return this;
	}

	operator value_type() {
		return Op::apply<value_type>((value_type)m_left, (value_type)m_right);
	}

	friend ostream& operator<<(ostream& os, const Expression& e) {
		os << "[";
		if (e.size() > 0) os << e[0];
		for (size_t i = 1; i < e.size(); i++) {
			os << ", " << e[i];
		}
		return os << "]";
	}
};

template<typename Op, typename Right> class Expression<typename Right::value_type, Op, Right> {
	const typename Right::value_type m_left;
	const Right& m_right;

public:
	typedef typename Right::value_type value_type;

	Expression(const value_type& s, const Right& r) : m_left{ s }, m_right{ r } {}
	size_t size() const { return m_right.size(); }

	value_type operator[](int i) const {
		return Op::apply<value_type>(m_left, m_right[i]);
	}

	template <typename T> bool operator==(const T& other) {
		for (size_t i = 0; i < size(); i++) if ((*this)[i] != other[i]) return false;
		return true;
	}

	operator value_type() {
		return Op::apply<value_type>(m_left, (value_type)m_right);
	}

	const Expression* operator*() const {
		return this;
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

template<typename Left, typename Op> class Expression<Left, Op, typename Left::value_type> {
	const Left& m_left;
	const typename Left::value_type m_right;

public:
	typedef typename Left::value_type value_type;

	Expression(const Left& l, const value_type& s) : m_left{ l }, m_right{ s } {}
	size_t size() const { return m_left.size(); }

	value_type operator[](int i) const {
		return Op::apply<value_type>(m_left[i], m_right);
	}

	template <typename T> bool operator==(const T& other) {
		for (size_t i = 0; i < size(); i++) if ((*this)[i] != other[i]) return false;
		return true;
	}

	operator value_type() {
		return Op::apply<value_type>((value_type)m_left, m_right);
	}

	const Expression* operator*() const {
		return this;
	}

	friend ostream& operator<<(ostream& os, const Expression& e) {
		os << "[";
		if (e.size() > 0) os << e[0];
		for (size_t i = 1; i < e.size(); i++) {
			os << ", " << e[i];
		}
		return os << "]";
	}
};

template<typename Left, typename Right> class Expression<Left, ScalarProduct, Right> {
	const Left& m_left;
	const Right& m_right;

public:
	typedef double value_type;

	Expression(const Left& l, const Right& r) : m_left{ l }, m_right{ r } {}
	size_t size() const { return 1; }

	value_type operator[](int i) const {
		return ScalarProduct::apply<Left, Right>(m_left, m_right);
	}

	bool operator==(const value_type& other) {
		return (value_type)*this == other;
	}

	operator double() {
		return ScalarProduct::apply<Left, Right>(m_left, m_right);
	}

	friend ostream& operator<<(ostream& os, const Expression& e) {
		return os << e[0] << endl;
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
Expression<Left, ScalarProduct, Right> operator*(const Left& l, const Right* r) {
	return Expression<Left, ScalarProduct, Right>(l, *r);
}

template<typename Left, typename Right>
Expression<Left, Divide, Right> operator/(const Left& l, const Right& r) {
	return Expression<Left, Divide, Right>(l, r);
}