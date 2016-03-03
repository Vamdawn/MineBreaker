#ifndef SYS_CMD_H
#define SYS_CMD_H


#include <windows.h>

#define MOUSEEVENT_LEFTDOWN MLD
#define MOUSEEVENT_LEFTUP MLU
#define MOUSEEVENT_RIGHTDOWN MRD
#define MOUSEEVENT_RIGHTUP MRU

class Mouse
{
public:
	void LeftClick(const int times)
	{
		for(int i = 0; i != times; ++i)
		{
			mouse_event(MLD, 0, 0, 0, 0);
			mouse_event(MLU, 0, 0, 0, 0);
		}
	}
	void RightClick(const int times)
	{
		for(int i = 0; i != times; ++i)
		{
			mouse_event(MRD, 0, 0, 0, 0);
			mouse_event(MRU, 0, 0, 0, 0);
		}
	}
	void Move(const int x, const int y)		{ SetCursorPos(x, y); }
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

class KeyBoard;



#endif