#include "RomanData.h"
#include <iostream>

#define ROMAN1 'I'
#define ROMAN5 'V'
#define ROMAN10 'X'
#define ROMAN50 'L'

#define L_INCREMENT 50
#define X_INCREMENT 10
#define V_INCREMENT 5
#define I_INCREMENT 1

#define PRE_VALUE_I_DECREMENT  (VALID_NUMBER_PRE_VALUE * 2)
#define PRE_VALUE_X_DECREMENT  (X_INCREMENT * 2)
#define VALID_NUMBER_PRE_VALUE 1
#define MAX_NUMBER_VAULUES		3
#define MAX_NUMBER_FIVEx_VALUES  1 



RomanData::RomanData()
{
}


RomanData::RomanData(char *RomanNumber)
{
	setNumberString(RomanNumber);

}

bool RomanData::isDataValid()
{
	return m_bDataValid;
}

int RomanData::getDecimalValue()
{
	return m_nDecimalValue;
}

/*
* Adds new number replacing existing numner
*/
void RomanData::setNumberString(char *RomanNumber)
{
	m_nCountRomanOne = 0;
	m_nCountRomanV = 0;
	m_nCountRomanX = 0;
	m_nCountRomanL = 0;
	m_eCurrentValue = CURRENT_ROMAN_VALUE::Undef;
	m_nDecimalValue = 0;
	m_bDataValid = true;


	for (int i = 0; i < strlen(RomanNumber); i++)
	{
		switch (RomanNumber[i])
		{
		case ROMAN5:  // valid roman numeral V
			m_nDecimalValue += V_INCREMENT;
			m_nCountRomanV++;

			if (m_nCountRomanV > MAX_NUMBER_FIVEx_VALUES)
			{
				m_bDataValid = false;
				m_nFaileCode = eFAILCODE::eFAIL_TOO_MANY_FIVE_BASE_VALUES;
				return;
			}

			// if there where I's prior to the V then fix value
			if (m_nCountRomanOne > 0)
			{
				if (m_nCountRomanOne == VALID_NUMBER_PRE_VALUE)
				{
					m_nDecimalValue -= PRE_VALUE_I_DECREMENT;
					m_nCountRomanOne = 0;
				}
				else
				{
					m_bDataValid = false;
					m_nFaileCode = eFAILCODE::eFAIL_TOO_MANY_ONE_BASE_PRE_VALUES;
					return;
				}
			}

			m_eCurrentValue == CURRENT_ROMAN_VALUE::V;
			break;

		case ROMAN1:  // Valid roman numeral
			m_nCountRomanOne++;
			if (m_nCountRomanOne > MAX_NUMBER_VAULUES)
			{
				m_bDataValid = false;
				m_nFaileCode = eFAILCODE::eFAIL_TOO_MANY_ONE_BASE_VALUES;
				return;
			}
			m_nDecimalValue += I_INCREMENT;
			m_eCurrentValue = CURRENT_ROMAN_VALUE::I;
			break;

		case ROMAN10:
			m_nDecimalValue += X_INCREMENT;
			m_nCountRomanX++;

			switch (m_eCurrentValue)
			{
			case CURRENT_ROMAN_VALUE::I:
			{
				if (m_nCountRomanOne == VALID_NUMBER_PRE_VALUE)
				{
					m_nDecimalValue -= PRE_VALUE_I_DECREMENT;
					m_nCountRomanOne = 0;
				}
				else
				{
					m_bDataValid = false;
					m_nFaileCode = eFAILCODE::eFAIL_TOO_MANY_ONE_BASE_PRE_VALUES;
				}
				break;
			}
			default:
				break;
			}
			m_eCurrentValue = CURRENT_ROMAN_VALUE::X;
			break;

		case ROMAN50:
			
			m_nDecimalValue += L_INCREMENT;
			m_nCountRomanL++;
			
			switch (m_eCurrentValue)
			{
			case CURRENT_ROMAN_VALUE::X:
				if (m_nCountRomanX == VALID_NUMBER_PRE_VALUE)
				{
					m_nDecimalValue -= PRE_VALUE_X_DECREMENT;
					m_nCountRomanX = 0;
				}
				else
				{
					m_bDataValid = false;
					m_nFaileCode = eFAILCODE::eFAIL_TOO_MANY_ONE_BASE_PRE_VALUES;
				}
				break;
			default:
				break;
			}
			
			m_eCurrentValue = CURRENT_ROMAN_VALUE::L;
			break;

		default: // anything else 
			m_bDataValid = false;
			m_nFaileCode = eFAILCODE::eFAIL_INVALID_DATA_VALUE;
			return;
		}

	}

	if (m_bDataValid)
	{
		m_nFaileCode = eFAILCODE::eSUCCESS;
	}
}
