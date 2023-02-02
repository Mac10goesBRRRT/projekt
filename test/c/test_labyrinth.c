#ifdef TEST
#include "unity.h"
//in example.h wird die Funktion deklariert
#include "labyrinth.h"
#include <stdbool.h>
#include "userinput.h"
#include "mock_userinput.h"

//Vor- bzw. Nachbereitung
void setUp(void)
{
}

void tearDown(void)
{
}


void test_runExampleTest(void)
{ 
    int result;
    int input = 1;
    int hoehe = 3;
    int breite = 3;
    lab laby = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'},
    };

 
    result = printlabyrinth(laby, hoehe, breite);

 
    TEST_ASSERT_EQUAL_INT(0, result);
}


void test_LabyrinthAmZielAngekommen(void){

    bool result;
    int input = 1;
    int hoehe = 3;
    int breite = 3;
    lab laby = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'},
    };

    wegsuchen(laby, &result, 0, 0, 0, 0);
    TEST_ASSERT_EQUAL_INT(1, result);


}

void test_LabyrinthAmZielNichtAngekommen(void){

    bool result = 0;
    int input = 1;
    int hoehe = 3;
    int breite = 3;
    lab laby = {
        {'0', '1', '1'},
        {'1', '0', '1'},
        {'1', '1', '1'},
    };

    wegsuchen(laby, &result, 1, 1, 0, 0);
    TEST_ASSERT_EQUAL_INT(0, result);


}

void test_LabyrinthMarkiert(void){

    char result;
    bool du;
    int input = 1;
    int hoehe = 3;
    int breite = 3;
    lab laby = {
        {'0', '1', '1'},
        {'1', '1', '1'},
        {'1', '1', '1'},
    };

    
    wegsuchen(laby, &du, 0, 0, 0, 0);
    result = laby[0][0];
    printlabyrinth(laby, hoehe, breite);
    TEST_ASSERT_EQUAL_CHAR('X', result);


}

void test_LabyrinthUnten(void){

    bool result;
    int input = 1;
    int hoehe = 3;
    int breite = 3;
    lab laby = {
        {'0', '1', '1'},
        {'0', '1', '1'},
        {'0', '1', '1'},
    };

    wegsuchen(laby, &result, 0, 0, 2, 0);
    printlabyrinth(laby, hoehe, breite);
    TEST_ASSERT_EQUAL_INT(1, result);


}

void test_LabyrinthRechts(void){

    bool result;
    int input = 1;
    int hoehe = 3;
    int breite = 3;
    lab laby = {
        {'0', '0', '0'},
        {'1', '1', '1'},
        {'1', '1', '1'},
    };

    wegsuchen(laby, &result, 0, 0, 0, 2);
    printlabyrinth(laby, hoehe, breite);
    TEST_ASSERT_EQUAL_INT(1, result);
}


void test_LabyrinthOben(void){

    bool result;
    int input = 1;
    int hoehe = 5;
    int breite = 5;
    lab laby = {
        {'0', '1', '0', '0', '0'},
        {'0', '1', '0', '1', '0'},
        {'0', '1', '0', '1', '0'},
        {'0', '1', '0', '1', '0'},
        {'0', '0', '0', '1', '0'},
    };

    wegsuchen(laby, &result, 0, 0, 4, 4);
    printlabyrinth(laby, hoehe, breite);
    TEST_ASSERT_EQUAL_INT(1, result);
}


void test_LabyrinthLinks(void){

    bool result;
    int input = 1;
    int hoehe = 5;
    int breite = 6;
    lab laby = {
        {'0', '1', '0', '0', '0', '0'},
        {'0', '1', '0', '1', '1', '0'},
        {'0', '1', '0', '0', '1', '0'},
        {'0', '1', '1', '0', '1', '0'},
        {'0', '0', '0', '0', '1', '0'},
    };

    wegsuchen(laby, &result, 0, 0, 4, 5);
    printlabyrinth(laby, hoehe, breite);
    TEST_ASSERT_EQUAL_INT(1, result);
}

void test_LabyrinthVerzweigung(void){

    bool result;
    int input = 1;
    int hoehe = 5;
    int breite = 6;
    
    lab laby = {
        {'0', '1', '0', '0', '0', '0'},
        {'0', '1', '0', '1', '1', '0'},
        {'0', '0', '0', '0', '1', '0'},
        {'0', '1', '1', '0', '1', '0'},
        {'0', '1', '0', '0', '1', '0'},
    };

    
    wegsuchen(laby, &result, 0, 0, 4, 5);
    printlabyrinth(laby, hoehe, breite);
    TEST_ASSERT_EQUAL_INT(1, result);
}


void test_LabyrinthSchritte(void){

    bool result;
    int input = 1;
    int hoehe = 5;
    int breite = 6;
    int schritte = 14;
    lab laby = {
        {'0', '1', '0', '0', '0', '0'},
        {'0', '1', '0', '1', '1', '0'},
        {'0', '0', '0', '0', '1', '0'},
        {'0', '1', '1', '0', '1', '0'},
        {'0', '1', '0', '0', '1', '0'},
    };

    printlabyrinth(laby, hoehe, breite); //hier in die funktion die print frage machen
    wegsuchen(laby, &result, 0, 0, 4, 5);
    labyrinthschritte(laby, hoehe, breite, schritte); //die geliche funktion nur mit dem if vergleich und userinput
    TEST_ASSERT_EQUAL_INT(1, result);
    
}

#endif // TEST