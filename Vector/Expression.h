#pragma once

#include <iostream>
#include "Operations.h"

using namespace std;

template<typename Left, typename Op, typename Right> class Expression {
	const Left& m_left;
	const Right& m_right;

public:
	typedef typename Left::value_type value_type; //somehow doe snot work http://stackoverflow.com/questions/10863075/member-to-function-pointer-inside-template-class-gives-error-must-be-a-class-or

	Expression(const Left& l, const Right& r) : m_left{ l }, m_right{ r } {}
	size_t size() const { return m_left.size(); }

	value_type operator[](int i) const {
		return Op::apply<value_type>(m_left[i], m_right[i]);
	}

	template <typename T> bool operator==(const T& other) {
		for (size_t i = 0; i < size(); i++) if (*this)[i] != other[i] return false;
		return true;
	}

	friend ostream& operator<<(ostream& os, const Expression& e) {
		os << "[";
		// TODO: somehow iterate over this shit
		os << e[0] << ", " << e[1] << ", " << e[2] << ", " << e[3];
		return os << "]";
	}
};

template<Vector, typename Op, typename Right> class Expression {
	//TODO need this specialization???? prolly not.... 
	typedef typename Left::value_type value_type;
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