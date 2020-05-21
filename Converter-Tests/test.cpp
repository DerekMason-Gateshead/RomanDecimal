#include "pch.h"

#include "../ConvertRomanDecimal/RomanData.h"
TEST(RomanInput, TestValidData) 
{
    RomanData testVI("VI");
//  EXPECT_EQ(1, 1);
  EXPECT_TRUE(testVI.isDataValid());
}

TEST(RomanInput, TestInvalidData)
{
    RomanData testVI("VIIII");
    //  EXPECT_EQ(1, 1);
    EXPECT_FALSE(testVI.isDataValid());
}