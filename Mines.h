#ifndef MINES_H
#define MINES_H

struct Mines
{
    int x;
    int y;
    int state;
    //positive number present the number of mines around it
    //positive number -99 present it is just a mine
    //99 present it's unknown
    //-1 is judged a Mines
};




#endif // !MINES_H
