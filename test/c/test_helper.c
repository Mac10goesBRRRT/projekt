#ifdef TEST
#include "unity.h"
#include "helper.h"
#include "mock_helper.h"

void setUp(void)
{
}

void teardown(void)
{
}

//Just to test the mock
void test_randomInt(void)
{
    int expected = 42;
    randomInt_ExpectAndReturn(expected);
    TEST_ASSERT_EQUAL_INT(expected, randomInt());
}


#endif//Test