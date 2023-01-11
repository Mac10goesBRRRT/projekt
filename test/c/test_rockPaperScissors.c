#ifdef TEST
#include "unity.h"
//in example.h wird die Funktion deklariert
#include "rockPaperScissors.h"

//Vor- bzw. Nachbereitung
void setUp(void)
{
}

void tearDown(void)
{
}

//Hier läuft der Test
void test_rockPaperScissors_sameResult(void)
{
    /* arrange */
    //Hier die Werte eingeben
    char result; //p=player, c=computer, n=none
    int inputPlayer = 1;
    int inputComputer = inputPlayer;

    /* act */
    //Die Funktion wird ausgeführt
    result = findWinner(inputPlayer, inputComputer);

    /* assert */
    //Vergleichen
    TEST_ASSERT_EQUAL_INT('n', result);
}

#endif // TEST

/*Testcases:
rockPaperScissors_sameResult
rockPaperScissors_differentResultsPlayerWins
rockPaperScissors_differentResultsPlayerLoses
rockPaperScissors_playerGetsBestOutOf3
rockPaperScissors_computerGetsBestOutOf3
rockPaperScissors_outputResult
*/