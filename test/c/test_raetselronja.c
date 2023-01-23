#ifdef TEST
#include "unity.h"
//in example.h wird die Funktion deklariert
#include "raetselronja.h"
#include "userinput.h"
#include "mock_userinput.h"
#include "randomnumber.h"
#include "mock_randomnumber.h"

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

int input[] = {1,2};
int loesung = 198;
int n = 2;

userInput_ExpectAndReturn(198);
int result = zahlenraetsel(input, loesung, n); 

TEST_ASSERT_EQUAL_INT(1, result);

}


void test_runRaetselTestAufruf(void){

    userInput_ExpectAndReturn(1);
    userInput_ExpectAndReturn(1);
    int result = raetselaufruf();

TEST_ASSERT_EQUAL_INT(1, result);

}


void test_runRaetselTestArmduecken(void){

int spieler = 10;
int gegner = 25;
int result = armdruecken(gegner, spieler);

TEST_ASSERT_EQUAL_INT(0, result);

}

void test_runRaetselTestBJ(void){

    int spieler = 0;
    int geber = 0;
    int janein = 0;

    userInput_ExpectAndReturn(1);
    randnum_ExpectAndReturn(10);
    randnum_ExpectAndReturn(8);
    userInput_ExpectAndReturn(1);
    randnum_ExpectAndReturn(10);
    randnum_ExpectAndReturn(10);
    userInput_ExpectAndReturn(1);
    
    

    int result = blackjack(spieler, geber, janein);
    TEST_ASSERT_EQUAL_INT(1, result);
}




#endif // TEST