#include "pch.h"

#include "../ConvertRomanDecimal/RomanData.h"

struct ValidTestData
{
    char* romanNumber;
    int expectedValue;
};



ValidTestData data[] = { {"VI",6}, {"IV",4}, {"X",10 } };

TEST(RomanInput, TestValidData) 
{
    
    
    int length = sizeof(data) / sizeof(ValidTestData);
  
    for (int i = 0; i < length; i++)
    {
        RomanData test(data[i].romanNumber);

        EXPECT_TRUE(test.isDataValid()) << "At Index " << i << " Roman Number : " << data[i].romanNumber;

    }
    
    


    RomanData testVI("VI");
//  EXPECT_EQ(1, 1);
  EXPECT_TRUE(testVI.isDataValid());

  RomanData testIV("IV");
  EXPECT_TRUE(testIV.isDataValid());

  RomanData testIII("III");
  EXPECT_TRUE(testIV.isDataValid());

}

TEST(RomanInput, TestInvalidData)
{
    RomanData testVIII("VIIII");
    //  EXPECT_EQ(1, 1);
    EXPECT_FALSE(testVIII.isDataValid());
}