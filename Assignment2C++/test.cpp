#include "pch.h"
#include "gtest/gtest.h"
#include "OList.h"
#include <sstream>

TEST(OlistTest, insertElementToEmptyList) {
	OList list;

	list.insert(42);

	ASSERT_TRUE(list.contains(42));
}

TEST(OlistTest, insertElementToNonEmptyList) {
	OList list;

	list.insert(42); // make list not empty
	list.insert(73); // insert into not empty list

	ASSERT_TRUE(list.contains(73));
}

TEST(OlistTest, insertMultipleElements) {
	OList list;

	list.insert(42); // make list not empty
	list.insert(73); // insert into not empty list

	ASSERT_TRUE(list.contains(73));
	ASSERT_TRUE(list.contains(42));
}

TEST(OlistTest, insertDuplicateElements01) {
	OList list;

	list.insert(42); // make list not empty

	ASSERT_FALSE(list.insert(42));
}

TEST(OlistTest, insertDuplicateElements02) {
	OList list;

	list.insert(42); // make list not empty
	list.insert(1);
	list.insert(2);
	list.insert(3);
	list.insert(1);

	ASSERT_FALSE(list.insert(1));
}

TEST(OlistTest, removeElement01) {
	// set up
	OList list;
	list.insert(42);
	list.insert(1);
	list.insert(7);
	list.insert(73);

	// execute
	list.remove(42);

	//validate
	ASSERT_FALSE(list.contains(42));
}


TEST(OlistTest, removeFirstElement01) {
	// set up
	OList list;

	list.insert(1);
	list.insert(7);
	list.insert(73);

	// execute
	list.remove(1);

	//validate
	ASSERT_FALSE(list.contains(1));
}


TEST(OlistTest, removeLastElement01) {
	// set up
	OList list;

	list.insert(1);
	list.insert(7);
	list.insert(73);

	// execute
	list.remove(73);

	//validate
	ASSERT_FALSE(list.contains(73));
}




TEST(OlistTest, testIsEmptyPos) {
	// set up
	OList list;


	//validate
	ASSERT_TRUE(list.isEmpty());
}

TEST(OlistTest, testIsEmptyNeg) {
	// set up
	OList list;
	list.insert(1);

	//validate
	ASSERT_FALSE(list.isEmpty());
}


TEST(OlistTest, testSize01) {
	// set up
	OList list;


	//validate
	ASSERT_TRUE(list.size() == 0);
}


TEST(OlistTest, testSize02) {
	// set up
	OList list;
	list.insert(1);

	//validate
	ASSERT_TRUE(list.size() == 1);
}




TEST(OlistTest, testSize03) {
	// set up
	OList list;
	list.insert(1);
	list.insert(2);
	list.insert(3);
	list.insert(4);
	list.insert(5);
	list.insert(6);
	list.remove(6);
	list.remove(1);
	list.remove(4);

	//validate
	ASSERT_TRUE(list.size() == 3);
}


TEST(OlistTest, testClear01) {
	// set up
	OList list;
	list.insert(42);
	list.insert(73);
	list.insert(3);
	list.insert(5);
	list.insert(11);
	list.insert(13);
	list.insert(77);
	list.insert(89);
	list.insert(9);
	list.clear();
	//validate
	ASSERT_TRUE(list.size() == 0);
	ASSERT_TRUE(list.isEmpty());

}


TEST(OlistTest, testClear02) {
	// set up
	OList list;
	list.clear();
	//validate
	ASSERT_TRUE(list.size() == 0);
	ASSERT_TRUE(list.isEmpty());

}


TEST(OlistTest, testOstream01) {
	// set up
	std::stringstream ss;
	OList list;
	list.insert(42);
	list.insert(73);
	list.insert(3);
	list.insert(5);
	list.insert(11);
	list.insert(13);
	list.insert(77);
	list.insert(89);
	list.insert(9);
	std::string expected =
		"{[3], [5], [9], [11], [13], [42], [73], [77], [89]}";

	//validate
	ss << list;

	ASSERT_TRUE(ss.str() == expected);
}


TEST(OlistTest, testOstream02) {
	// set up
	std::stringstream ss;
	OList list;
	std::string expected = "{}";

	//validate
	ss << list;

	ASSERT_TRUE(ss.str() == expected);
}


TEST(OlistTest, testListAdd01) {
	// set up
	OList list1;
	OList list2;

	list1.insert(1);
	list1.insert(73);
	list2.insert(12);
	list2.insert(5);

	//validate
	auto list3 = list1 + list2;

	ASSERT_TRUE(list3.size() == 4);
}

TEST(OlistTest, testListAdd02) {
	// set up
	std::stringstream ss;
	OList list1;
	OList list2;

	list1.insert(1);
	list1.insert(73);
	list1.insert(5);
	list2.insert(12);
	list2.insert(5);
	std::string expected =
		"{[1], [5], [12], [73]}";

	//execute
	auto list3 = list1 + list2;
	ss << list3;

	ASSERT_TRUE(expected == ss.str());
}


TEST(OlistTest, testCopyCtor01) {
	// set up
	std::stringstream ss1;
	std::stringstream ss2;

	OList list1;

	list1.insert(1);
	list1.insert(73);
	list1.insert(42);

	//validate
	auto list2 = list1;
	ss1 << list1;
	ss2 << list2;

	ASSERT_TRUE(ss1.str() == ss2.str());
}




TEST(OlistTest, testMoveCtor01) {

	OList list1;

	list1.insert(1);
	list1.insert(73);
	list1.insert(42);

	//validate
	auto list2 = std::move(list1);


	ASSERT_TRUE(list2.size() == 3);
	ASSERT_TRUE(list1.isEmpty());

}

TEST(OlistTest, testListSub01) {
	// set up
	OList list1;
	OList list2;

	list1.insert(1);
	list1.insert(73);
	list1.insert(42);
	list2.insert(12);
	list2.insert(1);

	//validate
	auto list3 = list1 - list2;

	ASSERT_TRUE(list3.size() == 2);
}

TEST(OlistTest, testListSub02) {
	// set up
	std::stringstream ss;
	OList list1;
	OList list2;

	list1.insert(1);
	list1.insert(73);
	list1.insert(5);
	list2.insert(12);
	list2.insert(5);
	std::string expected =
		"{[1], [73]}";

	//execute
	auto list3 = list1 - list2;
	ss << list3;

	ASSERT_TRUE(expected == ss.str());
}


TEST(OlistTest, testListDiv01) {
	// set up
	std::stringstream ss;
	OList list1;
	OList list2;

	list1.insert(1);
	list1.insert(73);
	list1.insert(5);
	list1.insert(19);
	list1.insert(101);

	list2.insert(12);
	list2.insert(5);
	list2.insert(73);

	std::string expected =
		"{[5], [73]}";

	//execute
	OList list3 = (list1 / list2);
	ss << list3;

	ASSERT_TRUE(expected == ss.str());
}


TEST(OlistTest, testListDiv02) {
	// set up
	std::stringstream ss;
	OList list1;
	OList list2;

	list1.insert(1);
	list1.insert(73);
	list1.insert(5);
	list1.insert(19);
	list1.insert(101);

	list2.insert(12);
	list2.insert(55);
	list2.insert(733);

	std::string expected =
		"{}";

	//execute
	OList list3 = (list1 / list2);
	ss << list3;

	ASSERT_TRUE(expected == ss.str());
}


TEST(OlistTest, testAssignment01) {
	// set up
	std::stringstream ss1;
	std::stringstream ss2;

	OList list1;
	OList list2;

	list1.insert(1);
	list1.insert(73);
	list1.insert(5);
	list1.insert(19);
	list1.insert(101);

	list2.insert(12);
	list2.insert(55);
	list2.insert(73);

	//execute
	list2 = list1;
	ss1 << list1;
	ss2 << list2;

	ASSERT_TRUE(ss1.str() == ss2.str());
}


TEST(OlistTest, testMoveAssignment02) {
	// set up
	std::stringstream ss1_before;
	std::stringstream ss1_after;
	std::stringstream ss2_before;
	std::stringstream ss2_after;

	OList list1;
	OList list2;

	list1.insert(1);
	list1.insert(73);
	list1.insert(5);
	list1.insert(19);
	list1.insert(101);

	list2.insert(12);
	list2.insert(55);
	list2.insert(733);
	ss1_before << list1;
	ss2_before << list2;

	//execute
	list2 = std::move(list1);
	ss1_after << list1;
	ss2_after << list2;

	ASSERT_TRUE(ss2_after.str() == ss1_before.str());
	ASSERT_TRUE(ss1_after.str() == "{}");
}
