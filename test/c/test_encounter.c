#ifdef TEST
#include "unity.h"

#include "encounter.h"
#include "playerinput.h"
#include "mock_playerinput.h"



void setUp(void){

}

void teardown(void){

}

void test_isPlayerAlive_healthGreaterZero(void)
{
    //arrange
    int health = 100;
    bool result;
    //act
    result = playerAlive(health);
    //assert
    TEST_ASSERT_TRUE(result);
}

void test_isPlayerAlive_healthLowerZero(void)
{
    //arrange
    int health = -1;
    bool result;
    //act
    result = playerAlive(health);

    //assert
    TEST_ASSERT_FALSE(result);
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
    setEnemyHealth(&test, health);
    result = test.health;
    //assert
    TEST_ASSERT_EQUAL(health, result);
}

void test_getEnemyHealth(void){
    //arrange
    int health = 50, result;
    //act
    enemy test = {health};
    result = getEnemyHealth(&test);
    //assert
    TEST_ASSERT_EQUAL(health, result);
}

void test_setEnemyDamage(void){
    //arrange
    int damage = 4, result;
    enemy test = {50, damage*2};
    //act
    setEnemyDamage(&test, damage);
    result = test.damage;
    //assert
    TEST_ASSERT_EQUAL(damage, result);
}

void test_getEnemyDamage(void){
    //arrange
    int damage = 4, result;
    //act
    enemy test = {50, damage};
    result = getEnemyDamage(&test);
    //assert
    TEST_ASSERT_EQUAL(damage, result);
}

void test_get_setEnemyArmor(void){
    //arrange
    int armor = 4, result;
    enemy test = {50, 4, armor*2};
    //act
    setEnemyArmor(&test, armor);
    result = getEnemyArmor(&test);
    //assert
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
    enemyDamaged(&test, playerDamage);
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
    enemyDamaged(&test, playerDamage);
    //assert
    TEST_ASSERT_EQUAL(expectedEnemyHealth, test.health);
}

//A better way to get the value of a struct, REFACTORING if it works
void test_getterWithParams(void)
{
    //arrange
    int health = 50, armor = 4, damage = 4, attack = 5;
    int healthResult, armorResult, damageResult, attackResult;
    enemy test = {health, damage, armor, attack};
    //act
    healthResult = getEnemyHealth(&test);
    armorResult = getEnemyArmor(&test);
    damageResult = getEnemyDamage(&test);
    attackResult = getEnemyAttack(&test);
    //assert
    TEST_ASSERT_EQUAL(health, healthResult);
    TEST_ASSERT_EQUAL(armor, armorResult);
    TEST_ASSERT_EQUAL(damage, damageResult);
    TEST_ASSERT_EQUAL(attack, attackResult);
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
    //aCt
    playerInput_ExpectAndReturn('a');
    enemy test = {enemyHealth, enemyDamage, enemyArmor, enemyAttack};
    result = fight(playerHealth, playerDamage, playerArmor, playerAttack, &test);
    //assert
    TEST_ASSERT_EQUAL(1, result);
}

void test_FightEnemyWins(void)
{
    //arange
    int playerHealth = 1, playerDamage = 10, playerArmor = 4, playerAttack = 5;
    int enemyHealth = 100, enemyDamage = 4, enemyArmor = 4, enemyAttack = 5;
    int result;
    //act
    playerInput_ExpectAndReturn('a');
    enemy test = {enemyHealth, enemyDamage, enemyArmor, enemyAttack};
    result = fight(playerHealth, playerDamage, playerArmor, playerAttack, &test);
    //assert
    TEST_ASSERT_EQUAL(0, result);
}

void test_FightPlayerChoosesAttack(void){
    //arrange
    int playerHealth = 100, playerDamage = 10, playerArmor = 4, playerAttack = 5;
    int enemyHealth = 100, enemyDamage = 4, enemyArmor = 4, enemyAttack = 5;
    int result;
    //act
    playerInput_ExpectAndReturn('a');
    enemy test = {enemyHealth, enemyDamage, enemyArmor, enemyAttack};
    fight(playerHealth, playerDamage, playerArmor, playerAttack, &test);
    result = getEnemyHealth(&test);
    //assert
    TEST_ASSERT_EQUAL(94, result);
    
}


#endif // TEST
