#include "TetrisScoreKeeper.h"

TetrisScoreKeeper::TetrisScoreKeeper()
{
    currentScore = 0;
    scoredTetrisPreviously = false;
}

void TetrisScoreKeeper::addPoints(int points)
{
    currentScore += points;
}

void TetrisScoreKeeper::scoreRows(int rows)
{
    // Tetris
    if (rows == 4)
    {
        if (scoredTetrisPreviously)
        {
            addPoints(1200);
        }
        else
        {
            addPoints(800);
        }
        scoredTetrisPreviously = true;
    }
    else
    {
        scoredTetrisPreviously = false;
        addPoints(rows * 100);
    }
}

long int TetrisScoreKeeper::getCurrentScore()
{
    return currentScore;
}
