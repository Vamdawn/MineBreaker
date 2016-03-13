#include<Windows.h>
//#pragma comment(linker,"/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#include<iostream>
#include<stdlib.h>
#include"SysCmd.h"
//#include<time.h>

using namespace std;

int main()
{
	Mouse mm;
	Screen ss;
	int tt[8][8];
	for (int i = 0; i < 8; ++i)
	{
		mm.Click(i, i);
		tt[i][i] = ss.number(i, i);
		if (tt[i][i] == -1)
		{
			break;
		}
		else if(tt[i][i] == 99)
		{
			
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
	}


	//CloseHandle(hOut); // 关闭标准输出设备句柄
	system("pause");
	return 0;
}