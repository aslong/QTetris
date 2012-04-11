#include <QLinkedList>
#include "Block.h"

#ifndef GRID_ROWS
#define GRID_ROWS
class GridRows
{
    private:
        QLinkedList<QLinkedList<Block *> *> *rows;
        int fullRowCount;
    public:
        GridRows(int fullRowCapacity);
        ~GridRows();
        bool addBlock(int row, Block *blockToAdd);
        QLinkedList<Block *> * getRowOfBlocks(int row);
        void removeRow(int row);
        int numberRowsTracked();
};
#endif
