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

void test_isPlayerAlive_healthLowerZero(void)
{
    //arrange
    int health = -1;
    //act
    //assert
    TEST_ASSERT_FALSE(playerAlive(health));
}

void test_playerIsDamaged(void)
{
    //arrange
    int health = 100;
    int damage = 10;
    int armor = 0;
    int expectedHealth = 90;
    //act
    health = playerHealth(health, damage, armor);
    //assert
    TEST_ASSERT_EQUAL(expectedHealth, health);
}

void test_playerIsNotOverhealed(void){
    //arrange
    int health = 100;
    int armor = 0;
    int heal = -10;
    int expectedHealth = 100;
    //act
    health = playerHealth(health, heal, armor);
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
    int health = 50, result;
    //act
    enemy test = {health};
    result = getEnemyInt(&test.health);
    //assert
    TEST_ASSERT_EQUAL(health, result);
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
    result = getEnemyInt(&test.damage);
    TEST_ASSERT_EQUAL(damage, result);
}

void test_get_setEnemyArmor(void){
    int armor = 4, result;
    enemy test = {50, 4, armor*2};
    setEnemyArmor(&test.armor, armor);
    result = getEnemyInt(&test.armor);
    TEST_ASSERT_EQUAL(armor, result);
}

void test_PlayerAttacksEnemy_DoesDamage(void)
{
    //arrange
    int playerDamage = 10;
    int enemyHealth = 50;
    int enemyArmor = 4;
    //health - (damage - armor)
    int expectedEnemyHealth = 44;
    //act
    enemy test = {enemyHealth, 4, enemyArmor};
    test.health = enemyDamaged(test, playerDamage);
    //assert
    TEST_ASSERT_EQUAL(expectedEnemyHealth, test.health);
}

void test_PlayerAttacksEnemy_DoesMinDamage(void)
{
    //arrange
    int playerDamage = 10;
    int enemyHealth = 50;
    int enemyArmor = 10;
    //health - (damage - armor)
    int expectedEnemyHealth = 49;
    //act
    enemy test = {enemyHealth, 4, enemyArmor};
    test.health = enemyDamaged(test, playerDamage);
    //assert
    TEST_ASSERT_EQUAL(expectedEnemyHealth, test.health);
}

//A better way to get the value of a struct, REFACTORING if it works
void test_getterWithParams(void)
{
    int health = 50, armor = 4, damage = 4, attack = 5;
    enemy test = {health, damage, armor, attack};
    TEST_ASSERT_EQUAL(health, getEnemyInt(&test.health));
    TEST_ASSERT_EQUAL(armor, getEnemyInt(&test.armor));
    TEST_ASSERT_EQUAL(damage, getEnemyInt(&test.damage));
    TEST_ASSERT_EQUAL(attack, getEnemyInt(&test.attack));
}
void test_switchingTurns(void)
{
    //arrange
    int currentTurn = 0, result;
    //act
    result = switchTurns(currentTurn);
    //assert
    TEST_ASSERT_EQUAL(1,result);
}

void test_FightPlayerWins(void)
{
    //arange
    int playerHealth = 100, playerDamage = 10, playerArmor = 4, playerAttack = 5;
    int enemyHealth = 1, enemyDamage = 4, enemyArmor = 4, enemyAttack = 5;
    int result;
    //arrange
    enemy test = {enemyHealth, enemyDamage, enemyArmor, enemyAttack};
    result = fight(playerHealth, playerDamage, playerArmor, playerAttack, test);
    //assert
    TEST_ASSERT_EQUAL(1, result);
}

void test_FightEnemyWins(void)
{
    //arange
    int playerHealth = 1, playerDamage = 10, playerArmor = 4, playerAttack = 5;
    int enemyHealth = 100, enemyDamage = 4, enemyArmor = 4, enemyAttack = 5;
    int result;
    //arrange
    enemy test = {enemyHealth, enemyDamage, enemyArmor, enemyAttack};
    result = fight(playerHealth, playerDamage, playerArmor, playerAttack, test);
    //assert
    TEST_ASSERT_EQUAL(0, result);
}


#endif // TEST
