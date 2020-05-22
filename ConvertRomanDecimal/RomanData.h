#pragma once

enum class eFAILCODE
{
    eSUCCESS = 0,
    eFAIL_INVALID_DATA_VALUE = 1,
    eFAIL_TOO_MANY_ONE_BASE_VALUES = 2,
    eFAIL_TOO_MANY_ONE_BASE_PRE_VALUES = 3,
    eFAIL_TOO_MANY_FIVE_BASE_VALUES = 4,
    eUNINTIALISED
};

class RomanData
{
public:
    // Constructor for RomanData
    RomanData();
    // Constructor for roman data with data input
    RomanData(char *romanNumber);


    bool isDataValid(); // returns if roman data is valid 
    int getDecimalValue();
    eFAILCODE getFailCode() { return m_nFaileCode; }

    void setNumberString(char*);  // this resets the roman number

private:
    bool m_bDataValid = false; // Set if roman data is valid
    int  m_nDecimalValue = 0;

    eFAILCODE m_nFaileCode = eFAILCODE::eUNINTIALISED;
};

