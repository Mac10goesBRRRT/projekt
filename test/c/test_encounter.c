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

void test_setEnemyHealth(void){
    //arrange
    int health = 50, result;
    //act
    enemy test = {health*2};
    setEnemyHealth(&test.health, health);
    //assert
    TEST_ASSERT_EQUAL(health, test.health);
}

void test_getEnemyHealth(void){
    //arrange
    int health = 50;
    //act
    enemy test = {health};
    //assert
    TEST_ASSERT_EQUAL(health, getEnemyHealth(test));
}

void test_setEnemyDamage(void){
    int damage = 4, result;
    enemy test = {50, damage*2};
    setEnemyDamage(&test.damage, damage);
    TEST_ASSERT_EQUAL(damage, test.damage);
}

void test_getEnemyDamage(void){
    int damage = 4, result;
    enemy test = {50, damage};
    result = getEnemyDamage(test);
    TEST_ASSERT_EQUAL(damage, result);
}

void test_get_setEnemyArmor(void){
    int armor = 4, result;
    enemy test = {50, 4, armor*2};
    setEnemyArmor(&test.armor, armor);
    result = getEnemyArmor(test);
    TEST_ASSERT_EQUAL(armor, result);
}
#endif // TEST
