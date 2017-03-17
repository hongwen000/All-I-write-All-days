// asfasfe.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include<stdio.h>
#include<string.h>
static char ch;
int flag = 0;
void nextchar()
{
	if (ch == 'Z')
		ch = 'A';
	else
	{
		ch++;
	}
}
void lastchar()
{
	if (ch == 'A')
		ch = 'Z';
	else
	{
		ch--;
	}
}
int main()
{
	int how_many_lines = 0;
	scanf("%d %c", &how_many_lines, &ch);
	for (int the_line_number_now = 0; the_line_number_now < how_many_lines; the_line_number_now++)
	{
		int next_direction = 1;

		int how_many_spaces = how_many_lines - the_line_number_now - 1;
		int how_many_outputed = 0;
		while (how_many_outputed<how_many_spaces)
		{
			printf(" ");
			how_many_outputed++;
		}
		int how_many_chars = 2 * the_line_number_now + 1;
		int how_many_char_outputed = 0;
		while (how_many_char_outputed<how_many_chars)
		{
			printf("%c",ch);
			how_many_char_outputed++;
			if (how_many_char_outputed == the_line_number_now + 1 && how_many_outputed+how_many_char_outputed != how_many_spaces+how_many_chars)
			{
				next_direction = 1 - next_direction;
			}
			if(how_many_outputed + how_many_char_outputed != how_many_spaces + how_many_chars){
				if (next_direction)
					nextchar();
				else
				{
					lastchar();
				}
			}

		}
		if (the_line_number_now != 0)
		{
			next_direction = 1;
			nextchar();
		}
		printf("\n");
	}
	return 0;
}
