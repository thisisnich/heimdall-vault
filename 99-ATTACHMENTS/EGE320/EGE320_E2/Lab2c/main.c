

/**
 * main.c
 */
int main(void)
{
    char operator;
    float ui1stNumber, ui2ndNumber, uiResult; //Declare with Float data type

    ui1stNumber = 35;
    ui2ndNumber = 68;
    operator = '/';

    switch(operator)
    {
        case '+': //When operator is '+'
            uiResult = ui1stNumber + ui2ndNumber; //Add ui1stNumber and ui2ndNumber
            break;
        case '-': //When operator is '-'
            uiResult = ui1stNumber - ui2ndNumber; //Minus ui1stNumber by ui2ndNumber
            break;
        case '*': //When operator is '*'
            uiResult = ui1stNumber * ui2ndNumber; //Multiply ui1stNumber by ui2ndNumber
            break;
        case '/':  //When operator is '/'
            uiResult = ui1stNumber / ui2ndNumber; //Divide ui1stNumber by ui2ndNumber
            break;
        default: //u can add by yourself in case an error occurs

    }
    return 0;
}
