#include<stdio.h>
#include<math.h>
int main()
{
	double t[101][51],tw1=10,tw2=20,t0=20;
	int i,j,n;
	for(i=0;i<=100;i++)
	{
		t[i][0]=tw2;
		t[i][50]=tw1;
	}
	for(j=1;j<50;j++)
	{
		t[0][j]=tw1;
		t[100][j]=tw1;
	}
	for(j=1;j<50;j++)
	{
		for(i=1;i<100;i++)
		{
			t[i][j]=t0;
		}
	}
	for(n=1;n<=1000;n++)
	{
		for(j=1;j<50;j++)
		{
			for(i=1;i<100;i++)
			{
				t[i][j]=0.25*(t[i-1][j]+t[i+1][j]+t[i][j+1]+t[i][j-1]);
			}
		}
	}
	for(j=0;j<=50;j++)
	{
		for(i=0;i<=100;i++)
		{
		printf("%f ",t[i][j]);
		}
		printf("\n");
	}
	for (i=0; i<=100 ;i++)
	{ 
		for (j=50;j>=0;j--)
		{
			printf("%f\t",t[i][j]);
		}
			printf("\n");
	} 
 } 

