#include "RomanData.h"
#include <iostream>

#define ROMAN1 'I'
#define ROMAN5 'V'
#define ROMAN10 'X'

RomanData::RomanData()
{
}


RomanData::RomanData(char *RomanNumber)
{
	int nCountRomanOne = 0;
	m_bDataValid  = true;
	for (int i = 0; i < strlen(RomanNumber); i++)
	{
		switch (RomanNumber[i])
		{
		case ROMAN5:  // valid roman numeral
			m_nDecimalValue += 5;

			if (nCountRomanOne > 0)
			{
				if (nCountRomanOne == 1)
				{
					m_nDecimalValue -= 2;
				}
				else
				{
					m_bDataValid = false;
				}
			}
			break;
		case ROMAN1:  // Valid roman numeral
			nCountRomanOne++;
			if (nCountRomanOne > 3)
			{
				m_bDataValid = false;
			}
			m_nDecimalValue += 1;
			break;
		case ROMAN10:
			m_nDecimalValue += 10;
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
