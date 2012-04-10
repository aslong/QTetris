#include <QLinkedList>

#ifndef GRID_ROWS
#define GRID_ROWS
class GridRows
{
    private:
        QLinkedList<QLinkedList<bool> *> *rows;
        int fullRowCount;
    public:
        GridRows(int fullRowCapacity);
        ~GridRows();
        bool addBlock(int row);
        
};
#endif
