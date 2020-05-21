#include "RomanData.h"
#include <iostream>

RomanData::RomanData()
{
}

RomanData::RomanData(char *RomanNumber)
{
	dataValid  = true;
	for (int i = 0; i < strlen(RomanNumber); i++)
	{
		switch (RomanNumber[i])
		{

		case 'V':  // valid roman numeral
		case 'I':  // Valid roman numeral
			break;
		default: // anything else 
			dataValid = false;
			break;
		}
	}


}

bool RomanData::isDataValid()
{
	return dataValid;
}
