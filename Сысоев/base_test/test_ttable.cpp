#include"TTable.h"
#include "gtest.h"

TEST(TestCaseName2, TestName2) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

TEST(TTable, can_create_table)
{
    TTable<int> a(5);

}
TEST(TTable, can_set_str)
{
    TTable<int> a;
    ASSERT_NO_THROW(a.SetStr("a", 10));

}
TEST(TTable, can_not_create_the_same_names)
{
    TTable<int> a;
    a.SetStr("a", 10);
    ASSERT_NO_THROW(a.SetStr("a", 12));
}
TEST(TTable, can_get_value)
{
    TTable<int> a;
    a.SetStr("a", 10);
    EXPECT_EQ(10, a.Setch_value("a"));
}
TEST(TTable, can_not_serch_value_of_not_existing_name)
{
    TTable<int> a;
    a.SetStr("a", 10);
    ASSERT_NO_THROW(a.Setch_value("a"));
}