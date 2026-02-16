#include <iostream>
#include <catch2/catch_test_macros.hpp>
#include "main.cpp"

TEST_CASE("Test List Class" "[List]") {
	SECTION("test PushBack") {
		List list1;
		INFO("PushBack not add element");
		list1.PushBack(1);
		CHECK(list1.Size() == 1);
		list1.PushBack(2);
		CHECK(list1.Size() == 2);
	}
	SECTION("test PushFront") {
		List list1;
		INFO("PushFront not add element");
		list1.PushFront(1);
		CHECK(list1.Size() == 1);
		list1.PushFront(2);
		CHECK(list1.Size() == 2);
	}
	SECTION("test Pop_Front on empty list") {
		List list1;
		CHECK(list1.PopFront() == 1);
	}
	SECTION("test Pop_Back on empty list") {
		List list1;
		CHECK(list1.PopBack() == 1);
	}
	SECTION("all test") {
		List list1;
		list1.PushBack(1);
		CHECK(list1.Size() == 1);
		list1.PushFront(1);
		CHECK(list1.Size() == 2);
		CHECK(list1.PopBack() == 1);
		CHECK(list1.PopFront() == 1);
		list1.Clear();
		CHECK(list1.Size() == 0);
	}
}