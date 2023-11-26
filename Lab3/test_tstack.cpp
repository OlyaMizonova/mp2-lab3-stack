#include"TStack.h"
#include "gtest.h"


TEST(TStack_a, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack_a<int> ts(3));
}

//TEST(TStack_a, cant_create_too_large_stack)
//{
//  ASSERT_ANY_THROW(TStack_a<int> m(INT_MAX));
//}

TEST(TStack_a, throws_when_create_stack_with_negative_length)
{
  ASSERT_ANY_THROW(TStack_a<int> m(-5));
}

TEST(TStack_a, can_create_copied_stack)
{
  TStack_a<int> m(5);

  ASSERT_NO_THROW(TStack_a<int> m1(m));
}

//TEST(TStack_a, can_get_leng)
//{
//	TStack_a<int> m(5);
//	EXPECT_EQ(m.GetSize(),5);
//}

TEST(TStack_a, can_set_and_get_element)
{
	TStack_a<int> m(5);
	ASSERT_NO_THROW(m.push(1));
	EXPECT_EQ(m.pop(), 1);
}


TEST(Tstack, new_stack_is_empty)
{
	TStack_a<int> s(3);

	EXPECT_EQ(1, s.is_empty());
}


TEST(Tstack, throws_when_use_pop_for_empty_stack)
{
	TStack_a<int> s(3);
	ASSERT_ANY_THROW(s.pop());
}

TEST(Tstack, throws_when_use_push_to_overflow_stack)
{
	TStack_a<int> s(2);
	s.push(1);
	s.push(1);
	ASSERT_ANY_THROW(s.push(1));
}

TEST(Tstack, throws_when_top_for_empty_stack)
{
	TStack_a<int> s(3);

	ASSERT_ANY_THROW(s.top());
}

TEST(Tstack, return_true_when_full_stack)
{
	TStack_a<int> s(3);
	for(int i = 0; i < 3; i++){
		s.push(i);
	}
	EXPECT_EQ(1, s.is_full());
}
TEST(Tstack, return_false_when_not_full_stack)
{
	TStack_a<int> s(3);
	EXPECT_EQ(0, s.is_full());
}
TEST(Tstack, return_true_when_empty_stack)
{
	TStack_a<int> s(3);
	EXPECT_EQ(1, s.is_empty());
}
TEST(Tstack, return_false_when_not_empty_stack)
{
	TStack_a<int> s(3);
	s.push(1);
	EXPECT_EQ(0, s.is_empty());
}
