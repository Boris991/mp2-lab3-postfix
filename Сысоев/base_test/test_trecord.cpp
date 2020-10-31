#include "TRecord.h"
#include "gtest.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
TEST(TRecord, can_copy_record)
{
    TRecord<int>f1("a", 10);
    TRecord<int>f2(f1);
    EXPECT_EQ(10, f2.GetValue());
}