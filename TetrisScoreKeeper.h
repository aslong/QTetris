#ifndef TETRIS_SCORE_KEEPER
#define TETRIS_SCORE_KEEPER
class TetrisScoreKeeper
{
    public:
        static TetrisScoreKeeper& getInstance()
        {
            static TetrisScoreKeeper instance;

            return instance;
        }
        void addPoints(int points);
        long int getCurrentScore();
        void scoreRows(int rows);
    private:
        long int currentScore;
        bool scoredTetrisPreviously;
        TetrisScoreKeeper();
        TetrisScoreKeeper(TetrisScoreKeeper const&);
        void operator=(TetrisScoreKeeper const&);
};
#endif
