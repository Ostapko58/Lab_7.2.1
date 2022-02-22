#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7.2.1/Lab7.2.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int s = 0;
			int a[][6]
			{	{0,8,9,15,6,-5},
				{4,54,9,99,6,45},
				{4,8,9,3,1,-50},
				{9,15,100,16,50,100},
				{15,0,-100,45,54,8},
				{9,15,-6,15,100,3}
			};

			int** arr = new int* [6];
			for (int i = 0; i < 6; i++)
			{
				arr[i] = new int[6];
			}

			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					arr[i][j] = a[i][j];
				}
			}
			s=Calc(arr, 6, 6);
			Assert::AreEqual(s, 7);

			for (int i = 0; i < 6; i++)
			{
				delete[] arr[i];
			}
			delete[] arr; 
			
		}
	};
}
