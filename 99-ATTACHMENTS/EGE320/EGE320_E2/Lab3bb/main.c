

/**
 * main.c
 */
int main(void)
{
    unsigned int uiNumber, uiDigitCount;

    uiNumber = 2136516;
    uiDigitCount = 0;

    while(uiNumber != 0)
    {
        uiNumber /= 10;
        uiDigitCount ++;
    }

	return 0;
}
