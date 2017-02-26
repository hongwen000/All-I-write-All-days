#include<stdio.h>
int main()
{
	int m,b,c;
	b=0;
	for(m=1500;m<=3000;m++)
	{
		if(m%4!=0)
			c=0;
		else if(m%100!=0)
			c=1;
		else if(m%400!=0)
			c=0;
		else 
			c=1;
		if(c==1) 
		{
			printf("%d ",m);
			b=b+1;
			if(b%8==0)
				printf("\n");
		}
	}
}
