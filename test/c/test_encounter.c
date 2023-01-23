#ifdef TEST
#include "unity.h"

#include "encounter.h"
#include "playerinput.h"
#include "mock_playerinput.h"
#include "helper.h"
#include "mock_helper.h"

void setUp(void)
{
}

void teardown(void)
{
}

void test_isPlayerAlive_healthGreaterZero(void)
{
    // arrange
    int health = 100;
    bool result;
    // act
    result = playerAlive(health);
    // assert
    TEST_ASSERT_TRUE(result);
}

void test_isPlayerAlive_healthLowerZero(void)
{
    // arrange
    int health = -1;
    bool result;
    // act
    result = playerAlive(health);

    // assert
    TEST_ASSERT_FALSE(result);
}

void test_playerIsDamaged(void)
{
    // arrange
    int health = 100;
    int damage = 10;
    int armor = 0;
    int expectedHealth = 90;
    // act
    health = playerHealth(health, damage, armor);
    // assert
    TEST_ASSERT_EQUAL(expectedHealth, health);
}

void test_playerIsNotOverhealed(void)
{
    // arrange
    int health = 100;
    int armor = 0;
    int heal = -10;
    int expectedHealth = 100;
    // act
    health = playerHealth(health, heal, armor);
    // assert
    TEST_ASSERT_EQUAL(expectedHealth, health);
}

void test_setEnemyHealth(void)
{
    // arrange
    int health = 50, result;
    // act
    enemy test = {health * 2};
    setEnemyHealth(&test, health);
    result = test.health;
    // assert
    TEST_ASSERT_EQUAL(health, result);
}

void test_getEnemyHealth(void)
{
    // arrange
    int health = 50, result;
    // act
    enemy test = {health};
    result = getEnemyHealth(&test);
    // assert
    TEST_ASSERT_EQUAL(health, result);
}

void test_setEnemyDamage(void)
{
    // arrange
    int damage = 4, result;
    enemy test = {50, damage * 2};
    // act
    setEnemyDamage(&test, damage);
    result = test.damage;
    // assert
    TEST_ASSERT_EQUAL(damage, result);
}

void test_getEnemyDamage(void)
{
    // arrange
    int damage = 4, result;
    // act
    enemy test = {50, damage};
    result = getEnemyDamage(&test);
    // assert
    TEST_ASSERT_EQUAL(damage, result);
}

void test_get_setEnemyArmor(void)
{
    // arrange
    int armor = 4, result;
    enemy test = {50, 4, armor * 2};
    // act
    setEnemyArmor(&test, armor);
    result = getEnemyArmor(&test);
    // assert
    TEST_ASSERT_EQUAL(armor, result);
}

void test_PlayerAttacksEnemy_DoesDamage(void)
{
    // arrange
    int playerDamage = 10;
    int enemyHealth = 50;
    int enemyArmor = 4;
    // health - (damage - armor)
    int expectedEnemyHealth = 44;
    // act
    enemy test = {enemyHealth, 4, enemyArmor};
    enemyDamaged(&test, playerDamage);
    // assert
    TEST_ASSERT_EQUAL(expectedEnemyHealth, test.health);
}

void test_PlayerAttacksEnemy_DoesMinDamage(void)
{
    // arrange
    int playerDamage = 10;
    int enemyHealth = 50;
    int enemyArmor = 10;
    // health - (damage - armor)
    int expectedEnemyHealth = 49;
    // act
    enemy test = {enemyHealth, 4, enemyArmor};
    enemyDamaged(&test, playerDamage);
    // assert
    TEST_ASSERT_EQUAL(expectedEnemyHealth, test.health);
}

// A better way to get the value of a struct, REFACTORING if it works
void test_getterWithParams(void)
{
    // arrange
    int health = 50, armor = 4, damage = 4, maxHealth = 5;
    int healthResult, armorResult, damageResult, maxHealthResult;
    enemy test = {health, damage, armor, maxHealth};
    // act
    healthResult = getEnemyHealth(&test);
    armorResult = getEnemyArmor(&test);
    damageResult = getEnemyDamage(&test);
    maxHealthResult = getEnemyMaxHealth(&test);
    // assert
    TEST_ASSERT_EQUAL(health, healthResult);
    TEST_ASSERT_EQUAL(armor, armorResult);
    TEST_ASSERT_EQUAL(damage, damageResult);
    TEST_ASSERT_EQUAL(maxHealth, maxHealthResult);
}
void test_switchingTurns(void)
{
    // arrange
    int currentTurn = 0, result;
    // act
    result = switchTurns(currentTurn);
    // assert
    TEST_ASSERT_EQUAL(1, result);
}

void test_FightPlayerWins(void)
{
    // arange
    int playerHealth = 100, playerDamage = 10, playerArmor = 4, playerAttack = 5;
    int enemyHealth = 1, enemyDamage = 4, enemyArmor = 4, enemyMaxHealth = 5;
    int result;
    // aCt
    playerInput_ExpectAndReturn('a');
    enemy test = {enemyHealth, enemyDamage, enemyArmor, enemyMaxHealth};
    result = fight(playerHealth, playerDamage, playerArmor, playerAttack, &test);
    // assert
    TEST_ASSERT_EQUAL(1, result);
}

void test_FightEnemyWins(void)
{
    // arange
    int playerHealth = 1, playerDamage = 10, playerArmor = 4, playerAttack = 5;
    int enemyHealth = 100, enemyDamage = 4, enemyArmor = 4, enemyMaxHealth = 5;
    int result;
    // act
    playerInput_ExpectAndReturn('a');
    enemy test = {enemyHealth, enemyDamage, enemyArmor, enemyMaxHealth};
    result = fight(playerHealth, playerDamage, playerArmor, playerAttack, &test);
    // assert
    TEST_ASSERT_EQUAL(0, result);
}

void test_FightPlayerChoosesAttack(void)
{
    // arrange
    int playerHealth = 100, playerDamage = 10, playerArmor = 4, playerAttack = 5;
    int enemyHealth = 6, enemyDamage = 4, enemyArmor = 4, enemyMaxHealth = 5;
    int result;
    // act
    playerInput_ExpectAndReturn('a');
    enemy test = {enemyHealth, enemyDamage, enemyArmor, enemyMaxHealth};
    fight(playerHealth, playerDamage, playerArmor, playerAttack, &test);
    result = getEnemyHealth(&test);
    // assert
    TEST_ASSERT_EQUAL(0, result);
}

void test_FightPlayerHeals_thenAttacks_Wins(void)
{
    // arrange
    int playerHealth = 2, playerDamage = 10, playerArmor = 4, playerAttack = 10;
    int enemyHealth = 11, enemyDamage = 4, enemyArmor = 4, enemyMaxHealth = 5;
    int result;
    // act
    enemy test = {enemyHealth, enemyDamage, enemyArmor, enemyMaxHealth};
    playerInput_ExpectAndReturn('h');
    playerInput_ExpectAndReturn('a');
    playerInput_ExpectAndReturn('a');
    result = fight(playerHealth, playerDamage, playerArmor, playerAttack, &test);
    // assert
    TEST_ASSERT_EQUAL(1, result);
}

void test_FightPlayerFlees(void)
{
    // arrange
    int playerHealth = 10, playerDamage = 10, playerArmor = 4, playerAttack = 10;
    int enemyHealth = 11, enemyDamage = 4, enemyArmor = 4, enemyMaxHealth = 5;
    int result;
    // act
    enemy test = {enemyHealth, enemyDamage, enemyArmor, enemyMaxHealth};
    playerInput_ExpectAndReturn('f');
    result = fight(playerHealth, playerDamage, playerArmor, playerAttack, &test);
    // assert
    TEST_ASSERT_EQUAL(2, result);
}

void test_randomIntRange(void)
{
    int expected = 4;
    randomInt_ExpectAndReturn(15);
    int result = randomIntRange(1, 6);
    TEST_ASSERT_EQUAL_INT(expected, result);
}

void test_enemyCanHeal(void)
{
    // arrange
    int enemyHealth = 1, enemyDamage = 4, enemyArmor = 4, enemyMaxHealth = 20;
    int healAmount = 10, expectedHealth = 11;
    int result;
    // act
    enemy test = {enemyHealth, enemyDamage, enemyArmor, enemyMaxHealth};
    enemyHeal(&test, healAmount);
    result = getEnemyHealth(&test);
    // assert
    TEST_ASSERT_EQUAL(expectedHealth, result);
}

void test_enemyNoOverheal(void)
{
    // arrange
    int enemyHealth = 1, enemyDamage = 4, enemyArmor = 4, enemyMaxHealth = 5;
    int healAmount = 10, expectedHealth = 5;
    int result;
    // act
    enemy test = {enemyHealth, enemyDamage, enemyArmor, enemyMaxHealth};
    enemyHeal(&test, healAmount);
    result = getEnemyHealth(&test);
    // assert
    TEST_ASSERT_EQUAL(expectedHealth, result);
}

void test_roll_20()
{
    int expected = 20;
    int result;

    randomInt_ExpectAndReturn(39);
    result = randomIntRange(1, 20);

    TEST_ASSERT_EQUAL(expected, result);
}

void test_roll_01()
{
    int expected = 1;
    int result;

    randomInt_ExpectAndReturn(40);
    result = randomIntRange(1, 20);

    TEST_ASSERT_EQUAL(expected, result);
}

void test_map10(){
    int expected1 = 10, expected2 = 0, expected3 = 20;
    int result;
    
    result = map(50, 0, 100, 0, 20);
    TEST_ASSERT_EQUAL(expected1, result);
    result = map(0, 0, 100, 0, 20);
    TEST_ASSERT_EQUAL(expected2, result);
    result = map(100, 0, 100, 0, 20);
    TEST_ASSERT_EQUAL(expected3, result);
}

#endif // TEST
