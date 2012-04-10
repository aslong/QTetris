#include "GridRows.h"

GridRows::GridRows(int fullRowCapacity)
{
    rows = new QLinkedList<QLinkedList<bool> *>();
    fullRowCount = fullRowCapacity;
}

bool GridRows::addBlock(int row)
{
    if (rows->count() <= row)
    {
        for (int i = rows->count(); i <= row; i++)
        {
            rows->append(new QLinkedList<bool>());
        }
    }

    QLinkedList<QLinkedList<bool> *>::iterator i = rows->begin();
    int currRow = 0;

    for (i = rows->begin(); currRow < row && i != rows->end(); i++)
    {
        currRow++;
    }

    **i << true;
    
    return (*i)->count() == fullRowCount;
}

GridRows::~GridRows()
{
    delete [] rows;
}
