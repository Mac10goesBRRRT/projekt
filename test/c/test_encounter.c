#ifdef TEST
#include "unity.h"

#include "encounter.h"

void setUp(void){

}

void teardown(void){

}

void test_isPlayerAlive_healthGreaterZero(void)
{
    //arrange
    int health = 100;
    //act
    //assert
    TEST_ASSERT_TRUE(playerAlive(health));
}

void test_playerIsDamaged(void)
{
    //arrange
    int health = 100;
    int damage = 10;
    int expectedHealth = 90;
    //act
    health = playerHealth(health, damage);
    //assert
    TEST_ASSERT_EQUAL(expectedHealth, health);
}

void test_playerIsNotOverhealed(void){
    //arrange
    int health = 100;
    int heal = -10;
    int expectedHealth = 100;
    //act
    health = playerHealth(health, heal);
    //assert
    TEST_ASSERT_EQUAL(expectedHealth, health);
}

#endif // TEST
