#include "stack.h"
#include <gtest.h>
TEST(TStack, can_create_default_stack)
{
    ASSERT_NO_THROW(TStack<int> st);
}
TEST(TStack, can_create_stack_with_positive_length)
{
    ASSERT_NO_THROW(TStack<int> st(5));
}
TEST(TStack, can_not_create_stack_with_negative_lenght)
{
    ASSERT_ANY_THROW(TStack<int>st(-5));
}
TEST(TStack, can_not_create_stack_with_large_lenght)
{
    ASSERT_ANY_THROW(TStack<int>st(101));
}
TEST(TStack, can_copy_stack)
{
    TStack<int> st(5);
    ASSERT_NO_THROW(TStack<int>st2(st));
}
TEST(TStack, can_copy_stack_2)
{
    TStack<int> st(5);
    TStack<int>st2(10);
    ASSERT_NO_THROW(st = st2);
}
TEST(TStack, can_push_element_to_stack)
{
    TStack <int> st(1);
    st.push(5);
    EXPECT_EQ(5, st.Top());
}
TEST(TStack, stack_is_empty)
{
    TStack <int> st(1);
    EXPECT_EQ(1, st.isempty());
}
TEST(TStack, stack_is_full)
{
    TStack <int> st(1);
    st.push(4);
    EXPECT_EQ(1, st.isfull());
}
