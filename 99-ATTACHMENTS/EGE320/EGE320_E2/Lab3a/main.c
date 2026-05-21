

/**
 * main.c
 */
int main(void)
{
    unsigned int uiArray[5] = {5, 20, 15, 40, 30};
    unsigned int uiCounter;

    for(uiCounter=1; uiCounter<5; uiCounter++ )   //Loop through the array
    {
        if(uiArray[0]<uiArray[uiCounter]) //Check which element is larger
        {
            uiArray[0] = uiArray[uiCounter]; //Store larger number to uiArray[0]
        }
    }

	return 0;
}
