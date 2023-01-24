#ifdef TEST
#include "unity.h"
#include "rockPaperScissors.h"

//Vor- bzw. Nachbereitung
void setUp(void)
{
}

void tearDown(void)
{
}


void test_rockPaperScissors_sameResult(void)
{
    /* arrange */
    int result;
    int inputPlayer = ROCK;
    int inputComputer = inputPlayer;

    /* act */
    result = findWinner(inputPlayer, inputComputer);

    /* assert */
    TEST_ASSERT_EQUAL_INT(NOWINNER, result);
}


void test_rockPaperScissors_playerWinsRound(void)
{
    /* arrange */
    int result;

    int inputPlayer = ROCK;
    int inputComputer = SCISSORS;

    /* act */
    result = findWinner(inputPlayer, inputComputer);

    /* assert */
    TEST_ASSERT_EQUAL_INT(PLAYERWINSROUND, result);


    /* arrange */
    inputPlayer = PAPER;
    inputComputer = ROCK;

    /* act */
    result = findWinner(inputPlayer, inputComputer);

    /* assert */
    TEST_ASSERT_EQUAL_INT(PLAYERWINSROUND, result);

    
    /* arrange */
    inputPlayer = SCISSORS;
    inputComputer = PAPER;

    /* act */
    result = findWinner(inputPlayer, inputComputer);

    /* assert */
    TEST_ASSERT_EQUAL_INT(PLAYERWINSROUND, result);
}


void test_rockPaperScissors_computerWinsRound(void)
{
    /* arrange */
    int result;
    int inputPlayer = ROCK;
    int inputComputer = PAPER;

    /* act */
    result = findWinner(inputPlayer, inputComputer);

    /* assert */
    TEST_ASSERT_EQUAL_INT(COMPUTERWINSROUND, result);

    
    /* arrange */
    inputPlayer = PAPER;
    inputComputer = SCISSORS;

    /* act */
    result = findWinner(inputPlayer, inputComputer);

    /* assert */
    TEST_ASSERT_EQUAL_INT(COMPUTERWINSROUND, result);

    
    /* arrange */
    inputPlayer = SCISSORS;
    inputComputer = ROCK;

    /* act */
    result = findWinner(inputPlayer, inputComputer);

    /* assert */
    TEST_ASSERT_EQUAL_INT(COMPUTERWINSROUND, result);
}


void test_rockPaperScissors_generateComputerInput(void)
{
    /* arrange */
    int result;

    /* act */
    result = getComputerInput();

    /* assert */
    TEST_ASSERT_INT_WITHIN(1, 1, result);
}


void test_rockPaperScissors_playerWinsGame(void)
{
    /* arrange */
    int result;
    int roundsToWin = 2;
    int playerWins = 2, computerWins = 1;

    /* act */
    result = wasGameWon(roundsToWin, playerWins, computerWins);

    /* assert */
    TEST_ASSERT_EQUAL_INT(PLAYERWINSGAME, result);
}


void test_rockPaperScissors_computerWinsGame(void)
{
    /* arrange */
    int result;
    int roundsToWin = 2;
    int playerWins = 1, computerWins = 2;

    /* act */
    result = wasGameWon(roundsToWin, playerWins, computerWins);

    /* assert */
    TEST_ASSERT_EQUAL_INT(COMPUTERWINSGAME, result);
}


void test_rockPaperScissors_gameWasNotWon(void)
{
    /* arrange */
    int result;
    int roundsToWin = 2;
    int playerWins = 1, computerWins = 1;

    /* act */
    result = wasGameWon(roundsToWin, playerWins, computerWins);

    /* assert */
    TEST_ASSERT_EQUAL_INT(NOTWONYET, result);
}


void test_rockPaperScissors_validPlayerInput(void)
{
    /* arrange */
    bool result;
    int playerInput = 2;

    /* act */
    result = validatePlayerInput(playerInput);

    /* assert */
    TEST_ASSERT_EQUAL_INT(true, result);
}


void test_rockPaperScissors_invalidPlayerInput(void)
{
    /* arrange */
    bool result;
    int playerInput = 5;

    /* act */
    result = validatePlayerInput(playerInput);

    /* assert */
    TEST_ASSERT_EQUAL_INT(false, result);
}

#endif // TEST