#include "pch.h"

#include "../ConvertRomanDecimal/RomanData.h"

struct ValidTestData
{
    char* romanNumber;
    int expectedValue;
};

struct InvalidData
{
    char* romanNumber;
    eFAILCODE failcode;
};

ValidTestData data[] = { {"VI",6}, 
                         {"IV",4}, 
                         {"X",10 },
                         {"III", 3} };

InvalidData  invalidTestData[] = { {"VIIII", eFAILCODE::eFAIL_TOO_MANY_ONE_BASE_VALUES},
                                  {"IIII", eFAILCODE::eFAIL_TOO_MANY_ONE_BASE_VALUES},
                                  {"IIV", eFAILCODE::eFAIL_TOO_MANY_ONE_BASE_PRE_VALUES},
                                   {"VV", eFAILCODE::eFAIL_TOO_MANY_FIVE_BASE_VALUES} };





TEST(RomanInput, TestValidData) 
{
    
    
    int length = sizeof(data) / sizeof(ValidTestData);
  
    for (int i = 0; i < length; i++)
    {
        RomanData test(data[i].romanNumber);

        EXPECT_TRUE(test.isDataValid()) << "At Index " << i << " Roman Number : " << data[i].romanNumber;

    }
    
}

TEST(RomanInput, TestValidValue)
{
    int length = sizeof(data) / sizeof(ValidTestData);

    for (int i = 0; i < length; i++)
    {
        RomanData test(data[i].romanNumber);

        EXPECT_EQ(test.getDecimalValue(), data[i].expectedValue) 
                    << "At Index " << i << " Roman Number : " << data[i].romanNumber;

    }

}

TEST(RomanInput, TestInvalidDataFailCodeTests)
{
    int length = sizeof(invalidTestData) / sizeof(InvalidData);

    for (int i = 0; i < length; i++)
    {
        RomanData  invalid(invalidTestData[i].romanNumber);

        EXPECT_EQ(invalidTestData[i].failcode, invalid.getFailCode())
                         << "At index " << i << " Roman Numner " << invalidTestData[i].romanNumber;
    }
}

TEST(RomanInput, TestInvalidData)
{
    int length = sizeof(invalidTestData) / sizeof(InvalidData);

    for (int i = 0; i < length; i++)
    {
        RomanData  invalid(invalidTestData[i].romanNumber);

        EXPECT_FALSE(invalid.isDataValid()) << "At index " << i << " Roman Numner " << invalidTestData[i].romanNumber;
    }
}