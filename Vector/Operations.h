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