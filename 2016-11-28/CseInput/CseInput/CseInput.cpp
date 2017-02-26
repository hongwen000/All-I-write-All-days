// CseInput.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>  
using namespace std;
#define DELAY 2
#define WAITTIME 3000
void Press(short ch)
{
	BYTE low = ch & 0xFF;
	BYTE high = ch >> 8;
	switch (high)
	{
	case 0x01:
		keybd_event(VK_SHIFT, 0, 0, 0);
		break;
	case 0x02:
		keybd_event(VK_CONTROL, 0, 0, 0);
		break;
	case 0x04:
		keybd_event(VK_MENU, 0, 0, 0);
		break;
	default:
		break;
	}
	keybd_event(low, 0, 0, 0);
	Sleep(DELAY / 2);
	keybd_event(low, 0, KEYEVENTF_KEYUP, 0);
	Sleep(DELAY / 2);
	switch (high)
	{
	case 0x01:
		keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
		break;
	case 0x02:
		keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
		break;
	case 0x04:
		keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0);
		break;
	default:
		break;
	}

}
int main()
{
	cout << "请把源代码文件拖到这个窗口里，按回车继续" << endl;
	string ScrFile;
	cin >> ScrFile;
	ifstream Scr(ScrFile);
	Sleep(WAITTIME);
	while (!Scr.eof())
	{
		char ch = Scr.get();
		if (ch == '\r')
			continue;
		Press(VkKeyScan(ch));
	}
}
