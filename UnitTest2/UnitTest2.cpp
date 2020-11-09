	#include "pch.h"
	#include "CppUnitTest.h"
	#include "D:\проги\FirstAlg\FirstAlg\list.h"
	#include <iostream>

	using namespace Microsoft::VisualStudio::CppUnitTestFramework;

	namespace ListTests
	{
		TEST_CLASS(ListTests)
		{
		public:

			TEST_METHOD(CreateTest)
			{
				list* list1 = new list();
				Assert::IsTrue(list1->getSize() == 0);
			}

			TEST_METHOD(PushBackTest1) {
				list* list1 = new list();
				list1->push_back(1);
				Assert::IsTrue(list1->at(0) == 1 && list1->getSize() == 1);
			}

			TEST_METHOD(PushBackTest2) {
				list* list1 = new list();
				list1->push_back(1);
				list1->push_back(2);
				Assert::IsTrue(list1->at(0) == 1 && list1->at(1) == 2 && list1->getSize() == 2);
			}

			TEST_METHOD(PushFrontTest1) {
				list* list1 = new list();
				list1->push_front(1);
				Assert::IsTrue(list1->at(0) == 1 && list1->getSize() == 1);
			}

			TEST_METHOD(PushFrontTest2) {
				list* list1 = new list();
				list1->push_front(1);
				list1->push_front(2);
				Assert::IsTrue(list1->at(0) == 2 && list1->at(1) == 1 && list1->getSize() == 2);
			}

			TEST_METHOD(PopBackTest1) { // 2 elements
				list* list1 = new list();
				list1->push_back(55);
				list1->push_back(232);
				list1->pop_back();
				Assert::IsTrue(list1->at(0) == 55 && list1->getSize() == 1);
			}

			TEST_METHOD(PopBackTest2) { // 1 element
				list* list1 = new list();
				list1->push_back(77);
				list1->pop_back();
				Assert::IsTrue(list1->getSize() == 0);
			}

			TEST_METHOD(PopBackTest3) { // empty list
				list* list1 = new list();
				try {
					list1->pop_back();
				}
				catch (const char* warning) {
					Assert::AreEqual(warning, "List is Empty");
				}
				Assert::IsTrue(list1->getSize() == 0);
			}

			TEST_METHOD(PopFrontTest1) { // 2 elements
				list* list1 = new list();
				list1->push_back(2);
				list1->push_back(1);
				list1->pop_front();
				Assert::IsTrue(list1->at(0) == 1 && list1->getSize() == 1);
			}

			TEST_METHOD(PopFrontTest2) { // 1 element
				list* list1 = new list();
				list1->push_back(1);
				list1->pop_front();
				Assert::IsTrue(list1->getSize() == 0);
			}

			TEST_METHOD(PopFrontTest3) { // empty list
				list* list1 = new list();
				try {
					list1->pop_front();
				}
				catch (const char* warning) {
					Assert::AreEqual(warning, "List is Empty");
				}
				Assert::IsTrue(list1->getSize() == 0);
			}

			TEST_METHOD(InsertTest1) { // check func insert
				list* list1 = new list();
				list1->insert(5, 0);
				Assert::IsTrue(list1->at(0) == 5 && list1->getSize() == 1);
			}

			TEST_METHOD(InsertTest2) { 
				list* list1 = new list();
				try {
					list1->insert(5, 1);
				}
				catch (const char* warning) {
					Assert::AreEqual(warning, "Wrong index");
				}
				Assert::IsTrue(list1->getSize() == 0);
			}

			TEST_METHOD(InsertTest3) {
				list* list1 = new list();
				list1->push_back(1);
				list1->insert(5, 1);
				Assert::IsTrue(list1->at(0) == 1 && list1->at(1) == 5 && list1->getSize() == 2);
			}

			TEST_METHOD(InsertTest4) { 
				list* list1 = new list();
				list1->push_back(2);
				list1->insert(1, 0);
				Assert::IsTrue(list1->at(0) == 1 && list1->at(1) == 2 && list1->getSize() == 2);
			}

			TEST_METHOD(InsertTest5) { 
				list* list1 = new list();
				list1->push_back(1);
				list1->push_back(3);
				list1->insert(2, 1);
				Assert::IsTrue(list1->at(0) == 1 && list1->at(1) == 2 && list1->at(2) == 3 && list1->getSize() == 3);
			}

			TEST_METHOD(AtTest1) { // check func at
				list* list1 = new list();
				list1->push_back(1);
				list1->push_back(2);
				list1->push_back(3);
				Assert::IsTrue(list1->at(0) == 1 && list1->at(1) == 2 && list1->at(2) == 3);
			}

			TEST_METHOD(AtTest2) {
				list* list1 = new list();
				list1->push_back(1);
				try {
					list1->at(1);
				}
				catch (const char* warning) {
					Assert::AreEqual(warning, "Wrong index");
				}
			}

			TEST_METHOD(RemoveTest1) { // check function remove
				list* list1 = new list();
				try {
					list1->remove(1);
				}
				catch (const char* warning) {
					Assert::AreEqual(warning, "Wrong index");
				}
				Assert::IsTrue(list1->getSize() == 0);
			}

			TEST_METHOD(RemoveTest2) {
				list* list1 = new list();
				list1->push_back(1);
				list1->push_back(2);
				list1->push_back(3);
				list1->remove(2);
				Assert::IsTrue(list1->at(0) == 1 && list1->at(1) == 2 && list1->getSize() == 2);
			}

			TEST_METHOD(RemoveTest3) { 
				list* list1 = new list();
				list1->push_back(3);
				list1->push_back(1);
				list1->push_back(2);
				list1->remove(0);
				Assert::IsTrue(list1->at(0) == 1 && list1->at(1) == 2 && list1->getSize() == 2);
			}

			TEST_METHOD(RemoveTest4) { 
				list* list1 = new list();
				list1->push_back(1);
				list1->push_back(3);
				list1->push_back(2);
				list1->remove(1);
				Assert::IsTrue(list1->at(0) == 1 && list1->at(1) == 2 && list1->getSize() == 2);
			}

			TEST_METHOD(RemoveTest5) { 
				list* list1 = new list();
				list1->push_back(1);
				list1->push_back(2);
				list1->push_back(3);
				try {
					list1->remove(3);
				}
				catch (const char* warning) {
					Assert::AreEqual(warning, "Wrong index");
				}
				Assert::IsTrue(list1->at(0) == 1 && list1->at(1) == 2 && list1->at(2) == 3 && list1->getSize() == 3);
			}

			TEST_METHOD(GetSizeTest1) {
				list* list1 = new list();
				Assert::IsTrue(list1->getSize() == 0);
			}

			TEST_METHOD(GetSizeTest2) {
				list* list1 = new list();
				list1->push_back(1);
				list1->push_back(2);
				list1->push_back(3);
				Assert::IsTrue(list1->getSize() == 3);
			}

			TEST_METHOD(SetTest1) { // check function set
				list* list1 = new list();
				list1->push_back(0);
				list1->push_back(2);
				list1->push_back(3);
				list1->set(0, 1);
				Assert::IsTrue(list1->at(0) == 1 && list1->at(1) == 2 && list1->at(2) == 3 && list1->getSize() == 3);
			}

			TEST_METHOD(SetTest2) { 
				list* list1 = new list();
				list1->push_back(1);
				list1->push_back(2);
				list1->push_back(3);
				try {
					list1->set(3, 4);
				}
				catch (const char* warning) {
					Assert::AreEqual(warning, "Wrong index");
				}
				Assert::IsTrue(list1->at(0) == 1 && list1->at(1) == 2 && list1->at(2) == 3 && list1->getSize() == 3);
			}

			TEST_METHOD(SetTest3) { 
				list* list1 = new list();
				list1->push_back(1);
				list1->push_back(2);
				list1->push_back(3);
				list1->set(0, 1);
				Assert::IsTrue(list1->at(0) == 1 && list1->at(1) == 2 && list1->at(2) == 3 && list1->getSize() == 3);
			}

			TEST_METHOD(SetTest4) { 
				list* list1 = new list();
				list1->push_back(1);
				list1->push_back(2);
				list1->push_back(3);
				list1->set(0, 2);
				list1->set(0, 1);
				Assert::IsTrue(list1->at(0) == 1 && list1->at(1) == 2 && list1->at(2) == 3 && list1->getSize() == 3);
			}

			TEST_METHOD(IsEmptyTest1) {
				list* list1 = new list();
				Assert::IsTrue(list1->isEmpty());
			}

			TEST_METHOD(IsEmptyTest2) {
				list* list1 = new list();
				list1->push_front(1);
				Assert::IsTrue(!list1->isEmpty());
			}

			TEST_METHOD(FindfirstListTest1) { // check func find_first
				list* list1 = new list();
				list* list2 = new list();
				list1->push_back(0);
				list1->push_back(1);
				list1->push_back(2);
				list1->push_back(33);
				list1->push_back(4);
				list1->push_back(5);
				list2->push_back(33);
				list2->push_back(4);
				list2->push_back(5);
				Assert::IsTrue(list1->find_first(list2) == 3);
			}

			TEST_METHOD(FindfirstListTest2) { //the first list consists of a repeating second list
				list* list1 = new list();
				list* list2 = new list();
				list1->push_back(0);
				list1->push_back(1);
				list1->push_back(0);
				list1->push_back(1);
				list1->push_back(0);
				list1->push_back(1);
				list2->push_back(1);
				list2->push_back(0);
				Assert::IsTrue(list1->find_first(list2) == 1);
			}

			TEST_METHOD(FindfirstListTest3) { 
				list* list1 = new list();
				list* list2 = new list();
				list1->push_back(0);
				list1->push_back(1);
				list1->push_back(2);
				list1->push_back(3);
				list1->push_back(4);
				list1->push_back(5);
				list2->push_back(5);
				Assert::IsTrue(list1->find_first(list2) == 5);
			}
		};
	}