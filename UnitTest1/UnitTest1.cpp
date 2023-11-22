#include "pch.h"
#include "CppUnitTest.h"
#include "..//glab6.4.rec/lab.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestCountNegativeElements)
        {
            const int size = 6;
            double arr[size] = { 3, -2.0, 2, -4.2, 5, 10 };

            double minElement = findMinAbsoluteElementRecursive(arr, size);
            double sumAfterMin = sumOfAbsoluteElementsAfterMinRecursive(arr, size, minElement);

            Assert::AreEqual(24.2, sumAfterMin, 0.001);

        }
        };
}