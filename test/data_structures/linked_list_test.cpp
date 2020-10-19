#include <gtest/gtest.h>
extern "C" {
	#include <CS101/linked_list.h>
}

TEST(LinkedList, NewSuccess)
{
	struct CS101_linked_list *list = linked_list_new();
	ASSERT_NE(list, nullptr);
	linked_list_free(list);
}

TEST(LinkedList, AppendAndGet)
{
	struct CS101_linked_list *list = linked_list_new();
	linked_list_append(list, 1);
	linked_list_append(list, 2);
	EXPECT_EQ(linked_list_get(list, 0), 1);
	EXPECT_EQ(linked_list_get(list, 1), 2);
	linked_list_free(list);
}

TEST(LinkedList, Remove)
{
	struct CS101_linked_list *list = linked_list_new();
	linked_list_append(list, 1);
	linked_list_append(list, 2);
	linked_list_append(list, 3);
	linked_list_append(list, 4);
	linked_list_remove(list, 0);
	linked_list_remove(list, 2);
	EXPECT_EQ(linked_list_get(list, 0), 2);
	EXPECT_EQ(linked_list_get(list, 1), 3);
	linked_list_free(list);
}

TEST(LinkedList, Set)
{
	struct CS101_linked_list *list = linked_list_new();
	linked_list_append(list, 1);
	linked_list_append(list, 2);
	linked_list_set(list, 99, 0);
	linked_list_set(list, -1, 1);
	EXPECT_EQ(linked_list_get(list, 0), 99);
	EXPECT_EQ(linked_list_get(list, 1), -1);
	linked_list_free(list);
}

TEST(LinkedList, Insert)
{
	struct CS101_linked_list *list = linked_list_new();
	linked_list_append(list, 1);
	linked_list_append(list, 2);
	linked_list_insert(list, 3, 0);
	linked_list_insert(list, 4, 2);
	linked_list_insert(list, 5, 4);
	EXPECT_EQ(linked_list_get(list, 0), 3);
	EXPECT_EQ(linked_list_get(list, 1), 1);
	EXPECT_EQ(linked_list_get(list, 2), 4);
	EXPECT_EQ(linked_list_get(list, 3), 2);
	EXPECT_EQ(linked_list_get(list, 4), 5);
	linked_list_free(list);
}
