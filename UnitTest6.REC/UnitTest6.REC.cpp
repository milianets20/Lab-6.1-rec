#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab6.1 rec/Lab6.1 rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest6REC
{
	TEST_CLASS(UnitTest6REC)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t = 0;
			int arr[8] = { -1, 0, 3, -2, -8, 4, 7, -2 };
			int suma = 0;
			t = Sum(arr, suma, 0, 8);
			Assert::AreEqual(-13, t);
		}
	};
}
