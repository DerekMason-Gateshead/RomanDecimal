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
			break;
		case ROMAN1:  // Valid roman numeral
			nCountRomanOne++;
			if (nCountRomanOne > 3)
			{
				m_bDataValid = false;
			}
			
			break;
		case ROMAN10:

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
