#include "stdafx.h"
#include "..\Vector\Vector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1 {
	TEST_CLASS(Expression) {
public:
	// Aufgabe 1
	TEST_METHOD(VectorVector) {
		Vector<double, 5> A({ 1, 2, 3, 4, 5 });
		Vector<double, 5> B({ 1, 4, 9, 16, 25 });
		Vector<double, 5> C({ 2, 6, 12, 20, 30 });

		Assert::IsTrue(A*A == B);
		Assert::IsTrue(B[4] == (A*A)[4]);

		Assert::IsTrue(B / A == A);
		Assert::IsTrue(A[3] == (B / A)[3]);

		Assert::IsTrue(C == A + B);
		Assert::IsTrue(C[2] == (B + A)[2]);

		Assert::IsTrue(C - A == B);
		Assert::IsTrue(A[1] == (C - B)[1]);

	}

	// Aufgabe 1
	TEST_METHOD(Expr) {
		Vector<double, 5> A({ 1, 2, 3, 4, 5 });
		Vector<double, 5> B({ 1, 4, 9, 16, 25 });
		Vector<double, 5> C({ 2, 6, 12, 20, 30 });

		Assert::IsTrue(A*B*C == C*B*A);
		Assert::IsTrue(A*B*C == B*C*A);
		Assert::IsTrue(A*B*C == B*A*C);

		Assert::IsTrue(B*C / A == B / A*C);
		Assert::IsTrue(C*B / A == B*C / A);

		Assert::IsTrue((A + B)*A == C*A);
		Assert::IsTrue(A*C == A*(B + A));
		Assert::IsTrue(A*(A + B) / A == C);
		Assert::IsTrue((C + B) / A == C / A + B / A);

		Assert::IsTrue((A + B) - B == A);
		Assert::IsTrue(A == (A - B) + B);
		Assert::IsTrue((A + B) - (C - A) == A);
		Assert::IsTrue(A + B + B + A == C + C - B + B - (A + A) + A + A);

		Assert::IsTrue((A*B)[1] == (C / A)[4] + (C / A)[0]);

	}
	
	// Aufgabe 2
	TEST_METHOD(VectorScalar) {
		Vector<double, 5> A({ 1, 2, 3, 4, 5 });
		Vector<double, 5> B({ 0.5, 1.0, 1.5, 2.0, 2.5 });
		Vector<double, 5> C({ 2, 3, 4, 5, 6 });
		Vector<double, 5> D({ 3, 3, 3, 3, 3 });

		Assert::IsTrue(A*0.5 == B);
		Assert::IsTrue(0.5*A == B);
		Assert::IsTrue(B == A*0.5);
		Assert::IsTrue(B == 0.5*A);

		Assert::IsTrue(A / 2.0 == B);
		Assert::IsTrue((2.0 / A)[3] == B[0]);
		Assert::IsTrue(B == A / 2.0);
		Assert::IsTrue(B[1] == (2.0 / A)[1]);

		Assert::IsTrue(A + 1.0 == C);
		Assert::IsTrue(1.0 + A == C);
		Assert::IsTrue(C == A + 1.0);
		Assert::IsTrue(C == 1.0 + A);

		Assert::IsTrue(C - 1.0 == A);
		Assert::IsTrue((5.0 - A)[1] == C[1]);
		Assert::IsTrue(A == C - 1.0);
		Assert::IsTrue(C[0] == (5.0 - A)[2]);

		auto e = (A + C + Vector<double, 5>({ 3, 1, -1, -3, -5 })) / 3.0;
		Assert::IsTrue(e == Vector<double, 5>({ 2, 2, 2, 2, 2 }));
		auto f = A + D;
		A = f;
		Assert::IsTrue(e == D);

		A[1] = 0;
		Assert::IsFalse(e == D);
	}
	
	// Aufgabe 2
	TEST_METHOD(ExprScalar) {
		Vector<double, 5> A({ 1, 2, 3, 4, 5 });
		Vector<double, 5> B({ 1, 4, 9, 16, 25 });
		Vector<double, 5> C({ 2, 6, 12, 20, 30 });

		Assert::IsTrue(A + B + B + A == 2.0*C);
		Assert::IsTrue(C*2.0 == (B + B) + (A + A));
		Assert::IsTrue(3.0*(A + B) - (B + A)*2.0 == C);

		Assert::IsTrue(3.0 + (A + B) - 3.0 == C);
		Assert::IsTrue(2.0*(C - B) / 2.0 + B == (A*4.0 + 4.0*B) / 4.0);

		Assert::IsTrue((A + B) / C == Vector<double, 5>({ 1, 1, 1, 1, 1 }));
		Assert::IsTrue((((A + B) / C)*9.0)[3] == B[2]);
		Assert::IsTrue(B[4] == (25.0*((C + B) / A) / 11.0)[4]);
	}

	// Aufgabe 3
	TEST_METHOD(DotProduct) {
		Vector<double, 5> A({ 1, 2, 3, 4, 5 });
		Vector<double, 5> B({ 1, 4, 9, 16, 25 });
		Vector<double, 5> C({ 2, 6, 12, 20, 30 });
		double d = A**B;

		Assert::IsTrue(d == B**A);
		Assert::IsTrue(double(A**B) == 1.0 + 8 + 27 + 64 + 125);
		d = A**(A + B);
		Assert::IsTrue(d == (B + A)**A);
		d = (B + A)**A;
		Assert::IsTrue(A**(A + B) == d);
		Assert::IsTrue((A**B)*(A + B) / (B**A) == C);
		Assert::IsTrue((A**B)*C - B*(B**A) == A*(A**B));
		Assert::IsTrue((A*A)**(B*B) == (A*B)**(B*A));
		Assert::IsTrue(A**B*2.0 == 2.0*B**A);
		d = A**B*2.0;
		Assert::IsTrue(d == 2.0*B**A);
		d = 2.0*B**A;
		Assert::IsTrue(2.0*B**A == d);
	}
	
	};
}