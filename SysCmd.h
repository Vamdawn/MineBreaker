#ifndef SYS_CMD_H
#define SYS_CMD_H


#include <windows.h>
#include <stdlib.h>
#include <iostream>

#define MOUSEEVENT_LEFTDOWN MLD
#define MOUSEEVENT_LEFTUP MLU
#define MOUSEEVENT_RIGHTDOWN MRD
#define MOUSEEVENT_RIGHTUP MRU

class Mouse
{
public:
	void LeftClick(const int times = 1)
	{
		for(int i = 0; i != times; ++i)
		{
			//mouse_event(MLD, 0, 0, 0, 0);
			//mouse_event(MLU, 0, 0, 0, 0);
			mouse_event(MLD | MLU, 0, 0, 0, 0);
		}
	}
	void RightClick(const int times = 1)
	{
		for(int i = 0; i != times; ++i)
		{
			//mouse_event(MRD, 0, 0, 0, 0);
			//mouse_event(MRU, 0, 0, 0, 0);
			mouse_event(MRD | MRU, 0, 0, 0, 0);
		}
	}
	void Click(const int x, const int y)
	{
		MoveTo(x, y);
		LeftClick();
	}
	void MoveTo(const int x, const int y)		{ SetCursorPos(x, y); }
	int getX()	{ up_info(); return PosX; }
	int getY()	{ up_info(); return PosY; }
private:
	Point Pos;
	int PosX;
	int PosY;

	void up_info()
	{
		::GetPosCursor(&Pos);
		PosX = Pos.X;
		PosY = Pos.Y;
	}
};

class Screen
{
public:
	Screen()
	{
		THIS_HDC = ::GetDC(NULL); 
		DefaultLength = 50; 
		*strPIXEL = new char[DefaultLength];
	}
	~Screen()	
	{ 
		DeleteDC(THIS_HDC);
		delete []strPIXEL;
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
		std::cout << strPIXEL << " -- " << radix << " radix"
	}
private:
	HDC THIS_HDC;
	int PosX;
	int PosY;
	long PIXEL;
	char *strPIXEL;
	int DefaultLength;
};



class KeyBoard;



#endif