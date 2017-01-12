#pragma once

#include <array>
#include "Expression.h"

using namespace std;

template <typename T, size_t S> class Vector : public std::array<T, S> {
public:
	Vector() {};

	Vector(const std::initializer_list<T>& data) {
		size_t s = __min(data.size(), S);
		auto it = data.begin();
		for (size_t i = 0; i < s; i++) this->at(i) = *it++;
	}

	const T& operator[](size_t pos) const {
		return this->at(pos);
	}

	T& operator[](size_t pos) {
		return this->at(pos);
	}

	template <typename Left, typename Op, typename Right> Vector<T, S>& operator=(const Expression<Left, Op, Right>& e) {
		for (size_t i = 0; i < size(); i++) (*this)[i] = e[i];
		return *this;
	}

	template <typename T> bool operator==(const T& other) {
		for (size_t i = 0; i < size(); i++) if ((*this)[i] != other[i]) return false;
		return true;
	}

	friend ostream& operator<<(ostream& os, const Vector& v) {
		os << "[";
		auto it = v.begin();
		auto end = v.end();
		if (it != end) os << *it++;
		while (it != end) os << ", " << *it++;
		return os << "]";
	}

	const Vector<T, S>* operator*() const {
		return this;
	}
};