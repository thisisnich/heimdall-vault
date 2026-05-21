
int main(void)
{
    unsigned int ui1stNumber, ui2ndNumber, uiTempNumber;

    ui1stNumber = 34;
    ui2ndNumber = 89;
    uiTempNumber = 0;

    uiTempNumber = ui1stNumber; //Value of ui1stNumber assigned to uiTempNumber
    ui1stNumber = ui2ndNumber; //Value of ui2ndNumber assigned to ui1stNumber
    ui2ndNumber = uiTempNumber; //Value of uiTempNumber assigned to ui2ndNumber
    return 0;
}
