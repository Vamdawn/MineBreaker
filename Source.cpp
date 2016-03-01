#include<Windows.h>
//#pragma comment(linker,"/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    /*HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    // 获取标准输出设备句柄
    CONSOLE_SCREEN_BUFFER_INFO bInfo; // 窗口缓冲区信息
    GetConsoleScreenBufferInfo(hOut, &bInfo);
    // 获取窗口缓冲区信息
    char strTitle[255];
    GetConsoleTitle(strTitle, 255); // 获取窗口标题
    printf("当前窗口标题是：%s\n", strTitle);
    SetConsoleTitle("控制台窗口操作"); // 设置窗口标题
    COORD size = { 80, 25 };
    SetConsoleScreenBufferSize(hOut, size); // 重新设置缓冲区大小
    SMALL_RECT rc = { 0, 0, 80 - 1, 25 - 1 }; // 重置窗口位置和大小
    SetConsoleWindowInfo(hOut, true, &rc);
    getchar();*/
    
    //system("START /B /WAIT MineBreaker.exe");
    //WinExec("cmd.exe", SW_HIDE);
    long pixel;
    char h[30];
    int tt[8][8];
    HDC A = ::GetDC(NULL);
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            pixel = GetPixel(A,j*16+16, i*16+102);
            _itoa_s(pixel, h, 16);
            if (pixel > 15000000)
            {
                tt[j][i] = 0;
            }
            else
            {
                pixel = GetPixel(A, j * 16 + 24, i * 16 + 112);
                if (pixel==12632256)
                {tt[j][i] = -1; }
                else if (pixel == 16711680)
                {  tt[j][i] = 1; }
                else if (pixel == 32768)
                { tt[j][i] = 2; }
                
                _itoa_s(pixel, h, 16);
                cout << pixel << endl;
                cout << h << endl;
            }
           
        }
    }
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            cout << j <<' '<< i <<' '<< tt[j][i] << endl;
        }
    }
   
    DeleteDC(A);
    //CloseHandle(hOut); // 关闭标准输出设备句柄
    system("pause");

    return 0;
}



