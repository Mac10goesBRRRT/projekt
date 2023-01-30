#ifdef TEST
#include "unity.h"
//in example.h wird die Funktion deklariert
#include "labyrinth.h"

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


void test_LabyrinthAmZiel(void){

    int result;
    int input = 1;
    int hoehe = 3;
    int breite = 3;
    lab laby = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'},
    };

    result = wegsuchen(laby, 0, 0, 0, 0);
    TEST_ASSERT_EQUAL_INT(0, result);


}

#endif // TEST