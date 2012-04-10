#include "GridRows.h"

GridRows::GridRows(int fullRowCapacity)
{
    rows = new QLinkedList<QLinkedList<bool> *>();
    fullRowCount = fullRowCapacity;
}

bool GridRows::addBlock(int row)
{
    QLinkedList<QLinkedList<bool> *>::iterator i = rows->begin();

    while (i == rows->end())
    {
        rows->push_back(new QLinkedList<bool>());
        int currRow;
        for (i = rows->begin(), currRow = 0; currRow < row && i != rows->end(); i++)
        {
            currRow++;
        }
    }

    **i << true;

    return (*i)->count() == fullRowCount;
}

GridRows::~GridRows()
{
    delete [] rows;
}
