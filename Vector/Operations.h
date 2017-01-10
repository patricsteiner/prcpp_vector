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
	template<typename T> static double apply(T left_values[], T right_values[], size_t size) {
		double res = 0;
		for (size_t i = 0; i < size; i++) {
			res += left_values[i] * right_values[i];
		}
		return res;
	}
};