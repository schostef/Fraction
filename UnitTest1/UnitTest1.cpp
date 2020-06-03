#include "pch.h"
#include "CppUnitTest.h"
#include "../Fraction/Fraction.cpp"
#include <random>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(simpleTests)
		{
			Fraction f1(3, 8);
			Fraction f2(1, 4);
			Fraction f3(2, 3);
			Fraction f4(6, 7);
			Fraction f5(3, 5);
			Fraction f6(0, 1);
			f2 += f2;
			Assert::IsTrue(Fraction(1, 2) == f2);
			f2 /= 2;
			Assert::IsTrue(Fraction(1, 4) == f2);
			Assert::IsTrue(Fraction(25, 24) == f1 + f3);
			Assert::IsTrue(Fraction(-5, 12) == f2 - f3);
			Assert::IsTrue(Fraction(18, 35) == f5 * f4);
			Assert::IsTrue(Fraction(8, 3) == f3 / f2);
			f6 += f2;
			f6 -= f2;
			Assert::IsTrue(Fraction(0, 1) == f6);
			f6 += f2;
			f6 *= f3;
			f6 /= f3;
			Assert::IsTrue(Fraction(1, 4) == f6);
			Assert::IsTrue(f3 > f2);
			Assert::IsTrue(f1 < f4); 
			Assert::IsTrue(f1 != f4);
			Assert::IsTrue(f1 <= f1);
			Assert::IsTrue(f1 >= f1);
			Assert::IsTrue(Fraction(19, 8) == f1 + 2);
			Assert::IsTrue(Fraction(-11, 4) == f2 - 3);
			Assert::IsTrue(Fraction(8, 3) == f3 * 4);
			Assert::IsTrue(Fraction(6, 35) == f4 / 5);
		}

		TEST_METHOD(randomTests)
		{
			std::random_device rdev;
			std::mt19937 rng(rdev());
			std::uniform_int_distribution<int> dist(-1000, 1000);
			
			for (int i = 0; i < 100; i++)
			{
				int n1 = dist(rng);
				int n2 = dist(rng);
				int d1 = dist(rng);
				int d2 = dist(rng);
				try {
					Fraction f1 = Fraction(n1, d1);
					Fraction f2 = Fraction(n2, d2);
					Fraction f3 = f1 + f2;
					f3 = f3 - f2;
					Assert::IsTrue(f1 == f3);
					f3 += f2;
					f3 -= f2;
					Assert::IsTrue(f1 == f3);
					f3 *= f2;
					f3 /= f1;
					Assert::IsTrue(f2 == f3);
					f3 = f1 * f2;
					f3 = f3 / f2;
					Assert::IsTrue(f1 == f3);
					f3 = f1 * 2;
					f3 -= f1;
					Assert::IsTrue(f1 == f3);
					f3 = f1 + f2 * 2;
					f3 = (f3 - f1) / 2;
					Assert::IsTrue(f2 == f3);
					f3 = f1 + 5;
					f3 -= 5;
					Assert::IsTrue(f1 == f3);
					f3 = f1 * 2 - f2 * 4 + f1 / 4 - f2 / 4;
					f3 = (f3 * 4 + f2 * 17) / 9;
					Assert::IsTrue(f1 == f3);
				}
				catch (std::overflow_error) {}				
			}

			for (int i = 0; i < 100; i++)
			{
				int n1 = dist(rng);
				int n2 = dist(rng);
				int d1 = dist(rng);
				int d2 = dist(rng);
				try {
					Fraction f1 = Fraction(n1, d1);
					Fraction f2 = Fraction(n2, d2);
					Fraction f3{}; 
					f3 += f1;
					f3 += f2;
					f3 -= f2;
					Assert::IsTrue(f1 == f3);
				}
				catch (std::overflow_error) {}
			}

		}
	};
}
