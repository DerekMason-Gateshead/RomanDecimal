#pragma once

class RomanData
{
public:
    // Constructor for RomanData
    RomanData();
    // Constructor for roman data with data input
    RomanData(char *romanNumber);


    bool isDataValid(); // returns if roman data is valid 

private:
    bool m_bDataValid = false; // Set if roman data is valid
  
};

