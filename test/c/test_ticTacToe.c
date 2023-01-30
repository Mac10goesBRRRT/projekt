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

#endif // TEST