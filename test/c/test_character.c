#ifdef TEST
#include "unity.h"
#include "character.h"
Character testCharacter;

void setUp(void)
{
        testCharacter.healthPoints = 0;
}

void tearDown(void)
{
}

void test_setCharacterHealthPoints(void)
{
    TEST_ASSERT_EQUAL_INT(0,testCharacter.healthPoints);
    setCharacterHealthPoints(&testCharacter,50);
    TEST_ASSERT_EQUAL_INT(50,testCharacter.healthPoints);
}

#endif // TEST