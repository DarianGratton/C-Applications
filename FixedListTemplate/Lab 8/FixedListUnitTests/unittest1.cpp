#include "CppUnitTest.h"
#include "../Lab 8/InvalidIndexException.h"
#include "../Lab 8/FixedList.h"

#include <vector>

#pragma once

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FixedListUnitTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(FindFirstOccurence)
		{
			FixedList<int> list;
			list.add(9);
			list.add(8);
			list.add(9);
			int first_index = list.getFirstIndex(9);
			Assert::AreEqual(0, first_index);
		}

		TEST_METHOD(AddVectors)
		{
			FixedList <std::vector<int>, 10> list;
			std::vector<int> v1;
			v1.push_back(2);
			list.add(v1);
			Assert::AreEqual(list.get(0).at(0), 2);
		}

		TEST_METHOD(GetElementIndex)
		{
			FixedList<std::string, 12> list;
			list.add("Hello");
			list.add("World");
			list.add("Hello");
			std::string world = "World";
			Assert::AreEqual(list.get(1), world);
		}

		TEST_METHOD(NumberOfElementsInArray)
		{
			FixedList<int, 12> list;
			list.add(9);
			list.add(8);
			list.add(9);
			size_t n = 3;
			Assert::AreEqual(n, list.size());
		}

		TEST_METHOD(RemoveElement)
		{
			FixedList<int, 12> list;
			list.add(9);
			list.add(8);
			Assert::AreEqual(list.get(0), 9);
			list.remove(9);
			Assert::AreEqual(list.get(0), 8);
		}

		TEST_METHOD(OverloadedBracketOperator)
		{
			FixedList<int, 12> list;
			list.add(9);
			Assert::AreEqual(list[0], 9);
		}

		TEST_METHOD(InvalidIndexExceptionThrown)
		{
			FixedList<int, 12> list;
			list.add(9);
			Assert::ExpectException<InvalidIndexException>([&]
			{
				list.get(12);
			}); 
		}

		TEST_METHOD(AddIsFullEqualsFalse)
		{
			FixedList<int, 1> list;
			list.add(3);
			Assert::IsFalse(list.add(9));
		}

	};
}