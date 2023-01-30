#ifdef TEST
#include "unity.h"
#include "ticTacToe.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_runExampleTest(void)
{
    /* arrange */
    int result;
    int input = 1;

    /* act */
    result = something(input);

    /* assert */
    TEST_ASSERT_EQUAL_INT(1, result);
}

#endif // TEST