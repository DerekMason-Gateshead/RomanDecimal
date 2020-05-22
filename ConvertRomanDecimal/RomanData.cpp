#include "RomanData.h"
#include <iostream>

#define ROMAN1 'I'
#define ROMAN5 'V'
#define ROMAN10 'X'


#define X_INCREMENT 10
#define V_INCREMENT 5
#define I_INCREMENT 1
#define PRE_VALUE_I_DECREMENT  (VALID_NUMBER_PRE_VALUE * 2)
#define VALID_NUMBER_PRE_VALUE 1
#define MAX_NUMBER_VAULUES		3
#define MAX_NUMBER_FIVEx_VALUES  1

RomanData::RomanData()
{
}


RomanData::RomanData(char *RomanNumber)
{
	int nCountRomanOne = 0;
	int nCountRomanV = 0;
	m_bDataValid  = true;
	for (int i = 0; i < strlen(RomanNumber); i++)
	{
		switch (RomanNumber[i])
		{
		case ROMAN5:  // valid roman numeral V
			m_nDecimalValue += V_INCREMENT;
			nCountRomanV++;

			if (nCountRomanV > MAX_NUMBER_FIVEx_VALUES)
			{
				m_bDataValid = false;
				m_nFaileCode = eFAIL_TOO_MANY_FIVE_BASE_VALUES;
				return;
			}

			// if there where I's prior to the V then fix value
			if (nCountRomanOne > 0)
			{
				if (nCountRomanOne == VALID_NUMBER_PRE_VALUE)
				{
					m_nDecimalValue -= PRE_VALUE_I_DECREMENT;
				}
				else
				{
					m_bDataValid = false;
					m_nFaileCode = eFAIL_TOO_MANY_ONE_BASE_PRE_VALUES;
					return;
				}
			}
			break;

		case ROMAN1:  // Valid roman numeral
			nCountRomanOne++;
			if (nCountRomanOne > MAX_NUMBER_VAULUES)
			{
				m_bDataValid = false;
				m_nFaileCode = eFAIL_TOO_MANY_ONE_BASE_VALUES;
				return;
			}
			m_nDecimalValue += I_INCREMENT;
			break;

		case ROMAN10:
			m_nDecimalValue += X_INCREMENT;
			break;

		default: // anything else 
			m_bDataValid = false;
			break;
		}
	}
}

bool RomanData::isDataValid()
{
	return m_bDataValid;
}

int RomanData::getDecimalValue()
{
	return m_nDecimalValue;
}
