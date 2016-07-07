#include "Mines.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "SysCmd.h"
#include<Windows.h>

using namespace std;

void update(Screen &S, vector<vector<Mines> > &Mine_List, const int size);
void update(Screen &S, vector<vector<Mines> > &Mine_List, const int size, const int x, const int y, const int state);
bool Plan_A(Mouse &M, Screen &S, vector<vector<Mines> > &Mine_List, const int size);
bool InArea(const int x, const int y);
bool testWin(Mouse &M, Screen &S, vector<vector<Mines> > &Mine_List, const int size);
void Print(Screen &S, vector<vector<Mines> > &Mine_List, const int size);

void update(Screen &S, vector<vector<Mines> > &Mine_List, const int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (Mine_List[i][j].state == 99)
            {
                int state = S.number(i, j);
                if (state != 99 )
                {
                    Mine_List[i][j].state = state;
                }
            }     
        }
    }
}

void update(Screen &S, vector<vector<Mines> > &Mine_List, const int size, const int x, const int y, const int state)
{
    Mine_List[x][y].state = state;
}

bool Plan_A(Mouse &M,Screen &S, vector<vector<Mines> > &Mine_List, const int size)
{
    bool flag = false;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (Mine_List[i][j].state >= 1 && Mine_List[i][j].state <= 8)
            {
                int Sum_Mine = 0;
                int Sum_Unknown = 0;
                //get info around
                for (int a = -1; a <= 1; ++a)
                {
                    for (int b = -1; b <= 1; ++b)
                    {
                        if (InArea(i + a, j + b))
                        {
                            if (Mine_List[i + a][j + b].state == -1)
                                ++Sum_Mine;
                            else if (Mine_List[i + a][j + b].state == 99)
                                ++Sum_Unknown;
                        }
                    }
                }
                //can be click
                if (Sum_Unknown == Mine_List[i][j].state - Sum_Mine && Sum_Unknown != 0)
                {
                    flag = true;
                    for (int a = -1; a <= 1; ++a)
                    {
                        for (int b = -1; b <= 1; ++b)
                        {
                            if (InArea(i + a, j + b))
                            {
                                if (Mine_List[i + a][j + b].state == 99)
                                {
                                    update(S, Mine_List, size, i + a, j + b, -1);
                                }
                            }
                        }
                    }
                }
                else if (Sum_Mine == Mine_List[i][j].state && Sum_Unknown != 0)
                {
                    flag = true;
                    for (int a = -1; a <= 1; ++a)
                    {
                        for (int b = -1; b <= 1; ++b)
                        {
                            if (InArea(i + a, j + b))
                            {
                                if (Mine_List[i + a][j + b].state == 99)
                                {
                                    M.Click(i + a, j + b);
                                    update(S, Mine_List, size); //need optimization
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return flag;
    //flag == false means cannot find a fully right way
}

bool InArea(const int x, const int y)
{
    return 0 <= x && x <= 7 && 0 <= y && y <= 7;
}

bool testWin(Mouse &M, Screen &S, vector<vector<Mines> > &Mine_List, const int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (Mine_List[i][j].state == 99)
            {
                return false;
            }
        }
    }
    return true;
}

void Print(Screen &S, vector<vector<Mines> > &Mine_List, const int size)
{
    cout << endl;
    for (int j = 0; j < size; ++j)
    {
        for (int i = 0; i < size; ++i)
        {
            cout << Mine_List[i][j].state << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    enum Level{easy, middle, difficult};
    const int size = 8; // easy-size
    const int Restart_PosX = 80,
        Restart_PosY = 70;

    vector<vector<Mines> > Mine_List(size);
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            Mines *M = new Mines;
            M->x = i; M->y = j; M->state = 99;
            Mine_List[i].push_back(*M);
        }
    }
    //init complete

    Mouse M;
    Screen S;
    KeyBoard Key;
    bool Fail = false;
    bool Win = false;
    
    int times = 0;

    while (!Win)
    {
        cout << "Let's killing begin!!!" << endl;
        cout << "Test----" << ++times << endl;
        for (int i = 0; i < size; ++i)
        {
            M.Click(i, i);
            int n = S.number(i, i);
            if (n == 0)
            {
                cout << "decovered in (" << i << ", " << i << ")" << endl;
                break;
            }
            else if (n == -99)
            {
                Fail = true;
                cout << "A Mine is clicked in the random click" << endl;
                break;
            }
        }
        update(S, Mine_List, size);
        while (!Win && !Fail)
        {
            if (!Plan_A(M, S, Mine_List, size))
            {
                bool NoWay = true;  //cannot find a fully right way
                //conduct random click
                cout << "cannot find a fully right way" << endl;
                for (int i = 0; i < size; ++i)
                {
                    if (NoWay)
                    {
                        for (int j = 0; j < size; ++j)
                        {
                            //cout << Mine_List[i][j].state << " ";
                            if (Mine_List[i][j].state == 99)
                            {
                                M.Click(i, j);
                                cout << "random click at (" << i << ", " << j << ")" << endl;
                                NoWay = false;
                                if (S.number(i, j) == -99)
                                {
                                    cout << "A Mine is clicked in the random click" << endl;
                                    Fail = true;
                                }
                                else
                                    update(S, Mine_List, size);
                                break;
                            }
                        }
                    }
                    //cout << endl;
                }
            }
            update(S, Mine_List, size);
            Win = testWin(M, S, Mine_List, size);
            //cout << "complete one big circle, pause for 2 sec..." << endl;
            //Sleep(2000);
            Key.Press(VK_RETURN);
            Key.Press(VK_ESCAPE);
        }
        if (Fail)
        {
            cout << "We failed. Game over" << endl;
            cout << "Restart int 5 sec: " << endl;
            Sleep(5000);
            for (int i = 0; i < size; ++i)
            {
                for (int j = 0; j < size; ++j)
                {
                    Mine_List[i][j].state = 99;
                }
            }
            Fail = false;
            M.MoveTo(Restart_PosX, Restart_PosY);
            M.LeftClick();
        }
        else if (Win)
        {
            cout << "Yes We Win :-)" << endl;
        }
    }
    system("pause");
    return 0;
}