#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int Cases(0), x(0), y(0), z(0);
	cin >> Cases;
	for (int i = 0; i < Cases; i++)
	{
		bool flag(false);
		double Number_Input;
		cin >> Number_Input;
		int Max_Test1 = sqrt(2.0* Number_Input);
		for (x = 1; x <= Max_Test1/* && x <= y*/; x++)
		{
			double Number_Rest1 = Number_Input - (x*(x + 1) / 2);
			int Max_Test2 = sqrt(2.0* Number_Rest1);
			for (y = x; y <= Max_Test2/* && y <= z*/; y++)
			{
				double Number_Rest2 = Number_Input - (x*(x + 1) / 2) -(y*(y+1)/2);
				int Max_Test2 = sqrt(2.0* Number_Rest2);
				for (z = y; z <= Max_Test2; z++)
				{
					if (((x*(x + 1) / 2) + (y*(y + 1) / 2) + (z*(z + 1) / 2)) == Number_Input)
					{
						cout << x <<' '<< y<<' ' << z << endl;
						flag = true;
					}
				}
			}
		}
		if (!flag)
			cout << "-1 -1 -1" << endl;
	}
    return 0;
}

