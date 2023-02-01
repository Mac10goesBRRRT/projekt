#ifdef TEST
#include "unity.h"
#include "ticTacToe.h"
#include <stdbool.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_ticTacToe_validUserInput(void)
{
    /* arrange */
    bool result;
    int row = 2, col = 0;

    /* act */
    result = validateUserInput(row, col);

    /* assert */
    TEST_ASSERT_EQUAL_INT(true, result);
}

void test_ticTacToe_invalidUserInput(void)
{
    /* arrange */
    bool result;
    int row = 1, col = 3;

    /* act */
    result = validateUserInput(row, col);

    /* assert */
    TEST_ASSERT_EQUAL_INT(false, result);
}

void test_ticTacToe_playerWins(void)
{
    /* arrange */
    int result;
    char field[][3] = {
        {'O', 'O', '-'},
        {'-', 'O', '-'},
        {'-', '-', 'O'}
    };

    /* act */
    result = wasGameWon(field);

    /* assert */
    TEST_ASSERT_EQUAL_INT(PLAYER, result);
}

void test_ticTacToe_ComputerWins(void)
{
    /* arrange */
    int result;
    char field[][3] = {
        {'X', '-', '-'},
        {'X', '-', '-'},
        {'X', '-', '-'}
    };

    /* act */
    result = wasGameWon(field);

    /* assert */
    TEST_ASSERT_EQUAL_INT(COMPUTER, result);
}

void test_ticTacToe_NooneWins(void)
{
    /* arrange */
    int result;
    char field[][3] = {
        {'X', 'O', 'O'},
        {'O', 'X', 'X'},
        {'X', 'O', 'O'}
    };

    /* act */
    result = wasGameWon(field);

    /* assert */
    TEST_ASSERT_EQUAL_INT(DRAW, result);
}

void test_ticTacToe_NoWinnerYet(void)
{
    /* arrange */
    int result;
    char field[][3] = {
        {'X', 'O', 'O'},
        {'O', '-', 'X'},
        {'X', 'O', 'O'}
    };

    /* act */
    result = wasGameWon(field);

    /* assert */
    TEST_ASSERT_EQUAL_INT(NOWINNERYET, result);
}

#endif // TEST