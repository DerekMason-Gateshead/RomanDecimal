#pragma once

class RomanData
{
public:
    // Constructor for RomanData
    RomanData();
    RomanData(char *romanNumber);
    bool isDataValid();

private:
    bool dataValid = false;
  
};

