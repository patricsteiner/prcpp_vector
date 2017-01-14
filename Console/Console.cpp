
#include "../Vector/Vector.h"

int main(){
	Vector<double, 5> A({ 1, 2, 3, 4, 5 });
	Vector<double, 5> B({ 1, 4, 9, 16, 25 });
	Vector<double, 5> C({ 2, 6, 12, 20, 30 });
	double d = A**B;
	cout << d << endl;
	d = A**(A + B);
	cout << d << endl;
	d = (B + A)**A;
	cout << d << endl;
	d = A**B*2.0;
	cout << d << endl;
	d = (A ** B)*(A ** B);
	cout << d << endl;
	return 0;
}

int main2() {
	Vector<double, 4> A({ 1, 2, 3, 4 });
	Vector<double, 4> B({ 2, 1, 0, 1 });
	auto e = (2.0*(A - B) / 2.0 + B + 5.0) * (A - 4.0 + 4.0*B) / 4.0;
	cout << e << endl;
	return 0;
}

int main1() {
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
	return 0;
}