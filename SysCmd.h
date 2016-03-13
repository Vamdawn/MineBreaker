#ifndef SYS_CMD_H
#define SYS_CMD_H


#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>

class Mouse
{
public:
	void LeftClick(const int times = 1)
	{
		for (int i = 0; i != times; ++i)
		{
			//mouse_event(MLD, 0, 0, 0, 0);
			//mouse_event(MLU, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTDOWN| MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		}
	}
	void RightClick(const int times = 1)
	{
		for (int i = 0; i != times; ++i)
		{
			//mouse_event(MRD, 0, 0, 0, 0);
			//mouse_event(MRU, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_RIGHTDOWN| MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
		}
	}
	void Click(const int x, const int y)
	{
		MoveTo(x * 16 + 16, y * 16 + 102);
		LeftClick();
        //std::cout << "click (" << x << ", " << y << ")" << std::endl;
        Sleep(100);
    }
	void MoveTo(const int x, const int y)		{ SetCursorPos(x, y); }
	int getX()	{ up_info(); return PosX; }
	int getY()	{ up_info(); return PosY; }
private:
	POINT Pos;
	int PosX;
	int PosY;

	void up_info()
	{
		::GetCursorPos(&Pos);
		PosX = Pos.x;
		PosY = Pos.y;
	}
};

class Screen
{
public:
	Screen()
	{
		THIS_HDC = ::GetDC(NULL);
		DefaultLength = 50;
		strPIXEL = new char[DefaultLength];
	}
	~Screen()
	{
		DeleteDC(THIS_HDC);
		delete[]strPIXEL;
	}
	long getPixel(const int x, const int y)
	{
		PosX = x;
		PosY = y;
		return PIXEL = GetPixel(THIS_HDC, x, y);
	}
	void Print(int radix)
	{

		_itoa_s(PIXEL, strPIXEL, DefaultLength, radix);
		std::cout << strPIXEL << " -- " << radix << " radix";
	}
	int number(const int x, const int y)
	{
		long pixel = GetPixel(THIS_HDC, x * 16 + 16, y * 16 + 102);

		if (pixel > 15000000)
		{
			return 99;  //undecovered
		}
		else
		{
			pixel = GetPixel(THIS_HDC, x * 16 + 24, y * 16 + 112);
			if (pixel == 0)
			{
				return -99;  //Mine
			}
			else if (pixel == 12632256)
			{
				return 0;
			}
			else if (pixel == 16711680)
			{
				return 1;
			}
			else if (pixel == 32768)
			{
				return 2;
			}
			else if (pixel == 255)
			{
				return 3;
			}
			else if (pixel == 8388608)
			{
				return 4;
			}
			else if (pixel == 128)
			{
				return 5;
			}
			else if (pixel == 8421376)
			{
				return 6;
			}
		}
	}
private:
	HDC THIS_HDC;
	int PosX;
	int PosY;
	long PIXEL;
	char *strPIXEL;
	int DefaultLength;
};



class KeyBoard
{
public:
    void Press(BYTE value)
    {
        keybd_event(value, 0, 0, 0);
        keybd_event(value, 0, KEYEVENTF_KEYUP, 0);
    }
private:

};


#endif