#include"TStack.h"
#include "gtest.h"


TEST(TListStack, can_create_stack)
{
  ASSERT_NO_THROW(TListStack<int> ts);
}

//TEST(TListStack, can_create_copied_stack)
//{
//  TListStack<int> m(5);
//
//  ASSERT_NO_THROW(TListStack<int> m1(m));
//}

//TEST(TListStack, can_get_leng)
//{
//	TListStack<int> m(5);
//	EXPECT_EQ(m.GetSize(),5);
//}

TEST(TListStack, can_set_element)
{
	TListStack<int> m;
	ASSERT_NO_THROW(m.push(1));
	m.push(1);
	//EXPECT_EQ(m.pop(), 1);
}
TEST(TListStack, can_get_element)
{
	TListStack<int> m;
	m.push(1);
	EXPECT_EQ(m.pop(), 1);
}


TEST(TListStack, new_stack_is_empty)
{
	TListStack<int> s;

	EXPECT_EQ(1, s.is_empty());
}


TEST(TListStack, throws_when_use_pop_for_empty_stack)
{
	TListStack<int> s;
	ASSERT_ANY_THROW(s.pop());
}

TEST(TListStack, throws_when_top_for_empty_stack)
{
	TListStack<int> s;

	ASSERT_ANY_THROW(s.top());
}

TEST(TListStack, return_true_when_empty_stack)
{
	TListStack<int> s;
	EXPECT_EQ(1, s.is_empty());
}
TEST(TListStack, return_false_when_not_empty_stack)
{
	TListStack<int> s;
	s.push(1);
	EXPECT_EQ(0, s.is_empty());
}
