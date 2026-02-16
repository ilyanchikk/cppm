#include <iostream>
#include <catch2/catch_test_macros.hpp>
#include "main.cpp"

TEST_CASE("Test List Class" "[List]") {
	SECTION("empty list") {
		List list1;
		
		INFO("empty list Empty() false");
		REQUIRE(list1.Empty() == true);
		CHECK(list1.Size() == 0);
	}
	SECTION("add 3 elements in list") {
		List list1;

		list1.PushFront(1);
		list1.PushFront(2);
		list1.PushFront(3);

		INFO(" Size list != 3");
		REQUIRE(list1.Size() == 3);
	}
	SECTION("CLear list") {
		List list1;

		list1.PushFront(1);
		list1.PushFront(2);

		list1.Clear();
		INFO("List not clear!");
		REQUIRE(list1.Size() == 0);
	}
}