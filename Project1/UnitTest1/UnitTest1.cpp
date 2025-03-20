#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Vector.h"
#include "../Project1/Vector.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Vector v(5);
			Assert::AreEqual(5, v.getSize());
			for (int i = 0; i < 5; ++i)
			{
				Assert::AreEqual(0, v.getElement(i));
			}
		}
	};
}
