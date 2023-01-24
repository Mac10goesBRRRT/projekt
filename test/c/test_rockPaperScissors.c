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
    int result;
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
    int result;
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
    int result;
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

void test_rockPaperScissors_generateComputerInput(void)
{
    /* arrange */
    //Hier die Werte eingeben
    int result;

    /* act */
    //Die Funktion wird ausgeführt
    result = getComputerInput();

    /* assert */
    //Vergleichen
    TEST_ASSERT_EQUAL_INT(ROCK || PAPER || SCISSORS, result);
}

void test_rockPaperScissors_playerGetsBestOutOf3(void)
{
    /* arrange */
    //Hier die Werte eingeben
    int result;
    int roundsToWin = 2;
    int playerWins = 2, computerWins = 1;

    /* act */
    //Die Funktion wird ausgeführt
    result = wasGameWon(roundsToWin, playerWins, computerWins);

    /* assert */
    //Vergleichen
    TEST_ASSERT_EQUAL_INT(PLAYERWINSGAME, result);
}

void test_rockPaperScissors_computerGetsBestOutOf3(void)
{
    /* arrange */
    //Hier die Werte eingeben
    int result;
    int roundsToWin = 2;
    int playerWins = 1, computerWins = 2;

    /* act */
    //Die Funktion wird ausgeführt
    result = wasGameWon(roundsToWin, playerWins, computerWins);

    /* assert */
    //Vergleichen
    TEST_ASSERT_EQUAL_INT(COMPUTERWINSGAME, result);
}

void test_rockPaperScissors_gameWasNotWon(void)
{
    /* arrange */
    //Hier die Werte eingeben
    int result;
    int roundsToWin = 2;
    int playerWins = 1, computerWins = 1;

    /* act */
    //Die Funktion wird ausgeführt
    result = wasGameWon(roundsToWin, playerWins, computerWins);

    /* assert */
    //Vergleichen
    TEST_ASSERT_EQUAL_INT(NOTWONYET, result);
}

void test_rockPaperScissors_validPlayerInput(void)
{
    /* arrange */
    //Hier die Werte eingeben
    bool result;
    int playerInput = 2;

    /* act */
    //Die Funktion wird ausgeführt
    result = validatePlayerInput(playerInput);

    /* assert */
    //Vergleichen
    TEST_ASSERT_EQUAL_INT(true, result);
}

void test_rockPaperScissors_invalidPlayerInput(void)
{
    /* arrange */
    //Hier die Werte eingeben
    bool result;
    int playerInput = 5;

    /* act */
    //Die Funktion wird ausgeführt
    result = validatePlayerInput(playerInput);

    /* assert */
    //Vergleichen
    TEST_ASSERT_EQUAL_INT(false, result);
}

#endif // TEST