#include<Windows.h>
//#pragma comment(linker,"/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    /*HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    // ��ȡ��׼����豸���
    CONSOLE_SCREEN_BUFFER_INFO bInfo; // ���ڻ�������Ϣ
    GetConsoleScreenBufferInfo(hOut, &bInfo);
    // ��ȡ���ڻ�������Ϣ
    char strTitle[255];
    GetConsoleTitle(strTitle, 255); // ��ȡ���ڱ���
    printf("��ǰ���ڱ����ǣ�%s\n", strTitle);
    SetConsoleTitle("����̨���ڲ���"); // ���ô��ڱ���
    COORD size = { 80, 25 };
    SetConsoleScreenBufferSize(hOut, size); // �������û�������С
    SMALL_RECT rc = { 0, 0, 80 - 1, 25 - 1 }; // ���ô���λ�úʹ�С
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
    //CloseHandle(hOut); // �رձ�׼����豸���
    system("pause");

    return 0;
}



