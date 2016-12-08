
#include "../Vector/Vector.h"

int main() {
	Vector<double, 4> A({ 1, 2, 3, 4 });
	Vector<double, 4> B({ 2, 1, 0, 1 });
	Vector<double, 4> D;
	auto e = (A - B) * (A + B);
	D = e;
	cout << D << endl; // [-3,3,9,15]
	B = { 3, 0, 2, 5 };
	cout << e << endl; // [-8,4,5,-9]
	B = { 4, 3, 3, -2 };
	cout << e[1] << endl; // -5
}