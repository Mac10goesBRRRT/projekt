#ifdef TEST
#include "unity.h"
//in example.h wird die Funktion deklariert
#include "raetselronja.h"
#include "userinput.h"
#include "mock_userinput.h"

//Vor- bzw. Nachbereitung
void setUp(void)
{
}

void tearDown(void)
{
}

//Hier läuft der Test
void test_runRaetselTest(void){
    /* arrange */
    //Hier die Werte eingeben
    int result;
    int input[] = {0,1,2,3};
    int loesung = 4;
    int n = 4;

    /* act */
    //Die Funktion wird ausgeführt
    userInput_ExpectAndReturn(4);
    result = zahlenraetsel(input, loesung, n);

    /* assert */
    //Vergleichen
    TEST_ASSERT_EQUAL_INT(1, result);
}

void test_runRaetselTestFalsch(void){

int result;
int input[] = {0,1,2,3};
int loesung = 4;
int n = 4;

userInput_ExpectAndReturn(5);
result = zahlenraetsel(input, loesung, n);

TEST_ASSERT_EQUAL_INT(0, result);

}

void test_runRaetselTestrichtig(void){

userInput_ExpectAndReturn(198);
int result = raetselaufruf(1);

TEST_ASSERT_EQUAL_INT(1, result);

}

#endif // TEST