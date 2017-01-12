#pragma once

struct Add {
	template<typename T> static T apply(T l, T r) {
		return l + r;
	}
};

struct Subtract {
	template<typename T> static T apply(T l, T r) {
		return l - r;
	}
};

struct Multiply {
	template<typename T> static T apply(T l, T r) {
		return l * r;
	}
};

struct Divide {
	template<typename T> static T apply(T l, T r) {
		return l / r;
	}
};

struct ScalarProduct {
	template<typename Left, typename Right> static typename Left::value_type apply(const Left& left, const Right& right) {
		typedef typename Left::value_type value_type;
		value_type res;
		for (size_t i = 0; i < left.size(); i++) {
			res += left[i] * right[i];
		}
		return res;
	}
};