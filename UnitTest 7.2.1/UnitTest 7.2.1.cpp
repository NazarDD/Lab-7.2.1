#include "pch.h"
#include "CppUnitTest.h"
#include <stdio.h>
#include "../Lab 7.2.1/Lab 7.2.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YourProjectTests
{
    TEST_CLASS(MatrixFunctionsTest)
    {
    public:
        TEST_METHOD(TestFindLargestOfMinimums)
        {
            int matrix[3][3] = { { 40, 13, 28 },
                                { 30, 36, 18 },
                                { 30, 40, 52 } };
            int* matrixPtr[3];
            for (int i = 0; i < 3; ++i) {
                matrixPtr[i] = matrix[i];
            }

            int result = FindLargestOfMinimums(matrixPtr, 3, 3);

            int expected = 30;

            Assert::AreEqual(result, expected);
        }
    };
}
