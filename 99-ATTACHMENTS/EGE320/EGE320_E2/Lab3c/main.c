#include <math.h>

//Function Declaration
unsigned int convertBinaryToDecimal(unsigned int);

int main(void)
{
    unsigned int uiBinaryNumber, uiDecimalNumber;

    uiBinaryNumber = 10001001;

    //Passing by value to function
    uiDecimalNumber = convertBinaryToDecimal(uiBinaryNumber);

	return 0;
}

unsigned int convertBinaryToDecimal(unsigned int uiBinNumber)
{
    unsigned int uiDecNumber, uiRemainder, uiIndex;

    uiDecNumber = 0;
    uiRemainder = 0;
    uiIndex = 0;

    while (uiBinNumber != 0)
    {
        //Divide uiBinNumber by 10 to get the remainder
        uiRemainder =  uiBinNumber % 10;

        //Divide uiBinNumber by 10 to get the quotient
        uiBinNumber /=10;

        //Multiply remainder with 2^uiIndex
        uiDecNumber += uiRemainder*pow(2,uiIndex);

        //Increment uiIndex by 1 for next digit
        uiIndex++;
    }
    return uiDecNumber;
}
