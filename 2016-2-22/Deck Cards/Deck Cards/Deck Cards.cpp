// Deck Cards.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;
const int CARD_TOTAL = 52;
const int  CARD_GET =13;
void Deliver_Card(int index, int MyCards[])
{
	MyCards[index] = rand() % CARD_TOTAL;
	//cin >> MyCards[index];
	for (int i =0; i < index; i++)
	{
		if (MyCards[index] == MyCards[i])
		{
			Deliver_Card(index, MyCards);
		}
	}
}
int main()
{
	string suits[] = { "Spades","Hearts","Diamonds","Clubs" };
	string ranks[] = { "Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King" };
	srand(time(0));
	int MyCards[CARD_GET];
	cout << "You have got:" << endl;
	for (int index = 0; index < CARD_GET; index++)
	{
		Deliver_Card(index, MyCards);
		cout << suits[MyCards[index] / 13] << " " << ranks[MyCards[index] % 13] << endl;
	}
    return 0;
}

