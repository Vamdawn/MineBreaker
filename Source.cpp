#include<Windows.h>
//#pragma comment(linker,"/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#include<iostream>
#include<stdlib.h>
#include"SysCmd.h"
//#include<time.h>

using namespace std;

int main22()
{
	Mouse mm;
	Screen ss;
	int tt[8][8];
    int x, y;
    while (true)
    {
        cin >> x >> y;
        /*if (x < 0 || x > 8 || y < 0 || y > 8)
            break;
        mm.Click(x, y);*/
        mm.MoveTo(x, y);
    }
	/*for (int i = 0; i < 8; ++i)
	{
		mm.Click(i, i);
		tt[i][i] = ss.number(i, i);
		if (tt[i][i] == 0)
		{
			break;
		}
		else if(tt[i][i] == -99)
		{
            break;
		}
	}
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			tt[j][i] = ss.number(j, i);
			cout << tt[j][i] << ' ';
		}
		cout << endl;
	}*/
	system("pause");
	return 0;
}