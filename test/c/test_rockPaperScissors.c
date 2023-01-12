#ifdef TEST
#include "unity.h"
//in example.h wird die Funktion deklariert
#include "rockPaperScissors.h"

//Vor- bzw. Nachbereitung
void setUp(void)
{
}

void tearDown(void)
{
}

//Hier läuft der Test
void test_rockPaperScissors_sameResult(void)
{
    /* arrange */
    //Hier die Werte eingeben
    char result;
    int inputPlayer = ROCK;
    int inputComputer = inputPlayer;

    /* act */
    //Die Funktion wird ausgeführt
    result = findWinner(inputPlayer, inputComputer);

    /* assert */
    //Vergleichen
    TEST_ASSERT_EQUAL_INT(NOWINNER, result);
}

void test_rockPaperScissors_differentResultsPlayerWins(void)
{
    /* arrange */
    //Hier die Werte eingeben
    char result;
    int inputPlayer = ROCK;
    int inputComputer = SCISSORS;

    /* act */
    //Die Funktion wird ausgeführt 
    result = findWinner(inputPlayer, inputComputer);

    /* assert */
    //Vergleichen
    TEST_ASSERT_EQUAL_INT(PLAYERWINSROUND, result);

     /* arrange */
    //Hier die Werte eingeben
    inputPlayer = PAPER;
    inputComputer = ROCK;

    /* act */
    //Die Funktion wird ausgeführt 
    result = findWinner(inputPlayer, inputComputer);

    /* assert */
    //Vergleichen
    TEST_ASSERT_EQUAL_INT(PLAYERWINSROUND, result);

      /* arrange */
    //Hier die Werte eingeben
    inputPlayer = SCISSORS;
    inputComputer = PAPER;

    /* act */
    //Die Funktion wird ausgeführt 
    result = findWinner(inputPlayer, inputComputer);

    /* assert */
    //Vergleichen
    TEST_ASSERT_EQUAL_INT(PLAYERWINSROUND, result);
}

void test_rockPaperScissors_differentResultsPlayerLoses(void)
{
    /* arrange */
    //Hier die Werte eingeben
    char result;
    int inputPlayer = ROCK;
    int inputComputer = PAPER;

    /* act */
    //Die Funktion wird ausgeführt 
    result = findWinner(inputPlayer, inputComputer);

    /* assert */
    //Vergleichen
    TEST_ASSERT_EQUAL_INT(COMPUTERWINSROUND, result);

     /* arrange */
    //Hier die Werte eingeben
    inputPlayer = PAPER;
    inputComputer = SCISSORS;

    /* act */
    //Die Funktion wird ausgeführt 
    result = findWinner(inputPlayer, inputComputer);

    /* assert */
    //Vergleichen
    TEST_ASSERT_EQUAL_INT(COMPUTERWINSROUND, result);

      /* arrange */
    //Hier die Werte eingeben
    inputPlayer = SCISSORS;
    inputComputer = ROCK;

    /* act */
    //Die Funktion wird ausgeführt 
    result = findWinner(inputPlayer, inputComputer);

    /* assert */
    //Vergleichen
    TEST_ASSERT_EQUAL_INT(COMPUTERWINSROUND, result);
}

#endif // TEST

/*Testcases:
rockPaperScissors_sameResult
rockPaperScissors_differentResultsPlayerWins
rockPaperScissors_differentResultsPlayerLoses
rockPaperScissors_playerGetsBestOutOf3
rockPaperScissors_computerGetsBestOutOf3
rockPaperScissors_outputResult
rockPaperScissors_invalidInput
*/