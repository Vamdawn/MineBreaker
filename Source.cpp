#include<Windows.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
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
    system("pause");

    return 0;
}



