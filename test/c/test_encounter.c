#ifdef TEST
#include "unity.h"

#include "encounter.h"
#include "playerinput.h"
#include "mock_playerinput.h"
#include "helper.h"
#include "mock_helper.h"
#include "character.h"

Character testcharacter;
Character testcharacter2;

void setUp(void)
{
    testcharacter.dexterity = 5;
    testcharacter.healthPoints = 100;
    testcharacter.maxHealthPoints = 100;
    testcharacter.weaponDamage = 10;
    testcharacter.armor = 4;
    //testcharacter.characterAttack = 5;

    testcharacter2.healthPoints = -1;
}

void teardown(void)
{
}

void test_isPlayerAlive_healthGreaterZero(void)
{
    // arrange
    bool result;
    // act
    result = playerAlive(&testcharacter);
    // assert
    TEST_ASSERT_TRUE(result);
}

void test_isPlayerAlive_healthLowerZero(void)
{
    // arrange
    bool result;
    // act
    result = playerAlive(&testcharacter2);

    // assert
    TEST_ASSERT_FALSE(result);
}

void test_playerIsDamaged(void)
{
    // arrange
    int damage = 10;
    // act
    // assert
    TEST_ASSERT_EQUAL(getCharacterMaxHealthPoints(&testcharacter)-damage, playerDamaged(&testcharacter, damage));
}

void test_playerIsNotOverhealed(void)
{
    // arrange
    int heal = 10;
    // act
    // assert
    TEST_ASSERT_EQUAL(getCharacterMaxHealthPoints(&testcharacter), playerHealed(&testcharacter,heal));
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
    int enemyHealth = 1, enemyDamage = 4, enemyArmor = 4, enemyMaxHealth = 5;
    int result;
    // aCt
    playerInputChar_ExpectAndReturn('a');
    enemy test = {enemyHealth, enemyDamage, enemyArmor, enemyMaxHealth};
    result = fight(&testcharacter, &test);
    // assert
    TEST_ASSERT_EQUAL(1, result);
}

void test_FightEnemyWins(void)
{
    // arange
    setCharacterHealthPoints(&testcharacter, 1);
    setCharacterWeaponDamage(&testcharacter, 10);
    setCharacterArmor(&testcharacter, 4);
    int enemyHealth = 100, enemyDamage = 4, enemyArmor = 4, enemyMaxHealth = 100;
    int result;
    // act
    playerInputChar_ExpectAndReturn('a');
    randomInt_ExpectAndReturn(1);
    enemy test = {enemyHealth, enemyDamage, enemyArmor, enemyMaxHealth};
    result = fight(&testcharacter, &test);
    // assert
    TEST_ASSERT_EQUAL(0, result);
}

void test_FightPlayerChoosesAttack(void)
{
    // arrange
    int enemyHealth = 6, enemyDamage = 4, enemyArmor = 4, enemyMaxHealth = 100;
    int result;
    // act
    playerInputChar_ExpectAndReturn('a');
    enemy test = {enemyHealth, enemyDamage, enemyArmor, enemyMaxHealth};
    fight(&testcharacter, &test);
    result = getEnemyHealth(&test);
    // assert
    TEST_ASSERT_EQUAL(0, result);
}

void test_FightPlayerHeals_thenAttacks_Wins(void)
{
    // arrange
    setCharacterHealthPoints(&testcharacter, 2);
    setCharacterWeaponDamage(&testcharacter, 10);
    setCharacterArmor(&testcharacter, 4);
    int enemyHealth = 11, enemyDamage = 4, enemyArmor = 4, enemyMaxHealth = 100;
    int result;
    // act
    enemy test = {enemyHealth, enemyDamage, enemyArmor, enemyMaxHealth};
    playerInputChar_ExpectAndReturn('h');
    randomInt_ExpectAndReturn(1);
    playerInputChar_ExpectAndReturn('a');
    randomInt_ExpectAndReturn(1);
    playerInputChar_ExpectAndReturn('a');
    result = fight(&testcharacter, &test);
    // assert
    TEST_ASSERT_EQUAL(1, result);
}

void test_FightPlayerFlees(void)
{
    // arrange
    setCharacterHealthPoints(&testcharacter, 10);
    setCharacterWeaponDamage(&testcharacter, 10);
    setCharacterArmor(&testcharacter, 4);
    int enemyHealth = 11, enemyDamage = 4, enemyArmor = 4, enemyMaxHealth = 100;
    int result;
    // act
    enemy test = {enemyHealth, enemyDamage, enemyArmor, enemyMaxHealth};
    playerInputChar_ExpectAndReturn('f');
    result = fight(&testcharacter, &test);
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

void test_enemyChoosesHeal(void)
{
    //arange
    bool result;
    int enemyHealth = 50, enemyDamage = 4, enemyArmor = 4, enemyMaxHealth = 100;
    enemy test = {enemyHealth, enemyDamage, enemyArmor, enemyMaxHealth};
    //act
    randomInt_ExpectAndReturn(39); //39%20 = 19 , 19 + 1 = 20
    result = enemyChoosesHeal(&test);
    //assert
    TEST_ASSERT_TRUE(result);

}

void test_enemyDoesNotChoosesHeal(void)
{
    //arange
    bool result;
    int enemyHealth = 50, enemyDamage = 4, enemyArmor = 4, enemyMaxHealth = 100;
    enemy test = {enemyHealth, enemyDamage, enemyArmor, enemyMaxHealth};
    //act
    randomInt_ExpectAndReturn(14); //14%20 = 14 , 14 + 1 = 15
    result = enemyChoosesHeal(&test);
    //assert
    TEST_ASSERT_FALSE(result);

}

void test_enemyChoosesHeal_ThenAttackWins(void)
{
    //arange
    int result;
    setCharacterHealthPoints(&testcharacter, 10);
    setCharacterWeaponDamage(&testcharacter, 10);
    setCharacterArmor(&testcharacter, 5);
    int enemyHealth = 6, enemyDamage = 10, enemyArmor = 5, enemyMaxHealth = 100;
    enemy test2 = {enemyHealth, enemyDamage, enemyArmor, enemyMaxHealth};
    //act
    playerInputChar_ExpectAndReturn('a');
    randomInt_ExpectAndReturn(39); //39%20 = 19 , 19 + 1 = 20
    playerInputChar_ExpectAndReturn('a');
    randomInt_ExpectAndReturn(0); //0%20 = 0 , 0 + 1 = 1
    result = fight(&testcharacter, &test2);
    //assert
    TEST_ASSERT_EQUAL(0, result);

}

int test_rollInitiative (void) {
    TEST_ASSERT(testcharacter.dexterity + 1 <= rollInitiative(&testcharacter) && testcharacter.dexterity + 20 >= rollInitiative(&testcharacter));
}
#endif // TEST
