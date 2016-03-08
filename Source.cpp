#include<Windows.h>
//#pragma comment(linker,"/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#include<iostream>
#include<stdlib.h>
//#include<time.h>

using namespace std;
void click(int x, int y);
void image(int j, int i, int**tt);
int check(int x, int y, int t);
int main()
{
	
	int **tt;
	tt = new int*[8];
	for (int i = 0; i < 8; ++i)
	{
		tt[i] = new int[8];
	}
	for (int i = 0; i < 8; ++i)
	{
		click(i, i);
		image(i, i, tt);
		if (tt[i][i]==-1)
		{
			break;
		}
		else(tt[i][i] == 99)
		{
			return 0;
		}
	}
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			image(j, i,tt);
			cout << tt[j][i] <<' ';
		}
		cout << endl;
	}

	
	//CloseHandle(hOut); // 关闭标准输出设备句柄
	system("pause");
	return 0;
}
void click(int x, int y)
{
	SetCursorPos(x * 16 + 24,y * 16 + 112);
	mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}
void image(int j, int i,int**tt)
{
	long pixel;
	char h[30];

	HDC A = ::GetDC(NULL);
	pixel = GetPixel(A, j * 16 + 16, i * 16 + 102);
	_itoa_s(pixel, h, 16);

		   if (pixel > 15000000)
			{
				tt[j][i] = 0;
			}

			else
			{
				pixel = GetPixel(A, j * 16 + 24, i * 16 + 112);
				if (pixel == 0)
				{
					tt[j][i] = 99;
				}
				else if (pixel == 12632256)
				{
					tt[j][i] = -1;
				}
				else if (pixel == 16711680)
				{
					tt[j][i] = 1;
				}
				else if (pixel == 32768)
				{
					tt[j][i] = 2;
				}
				else if (pixel == 255)
				{
					tt[j][i] = 3;
				}
				else if (pixel == 8388608)
				{
					tt[j][i] = 4;
				}
				else if (pixel == 128)
				{
					tt[j][i] = 5;
				}
				else if (pixel == 8421376)
				{
					tt[j][i] = 6;
				}

			
	          }
	DeleteDC(A);
}
