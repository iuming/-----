//The MIT License (MIT)
//
//Copyright (c) 2014 Samuel Vishesh Paul
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in all
//copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//SOFTWARE.
#include<bits/stdc++.h> 
#define N 100
#define M 100
#define pi 3.1415926535
using namespace std;
int main()
{
	ofstream fout;
	fout.open("Problem two data(Numerical Solution).csv");
 	int i,j,l,num=1;
 	float cha,x,y,x2,y2;
 	float t[N][M],a[N][M];
	for(i=0;i<N;i++)
   		for(j=0;j<M;j++)
    		t[i][j]=0;
	for(j=0;j<M;j++)
 	{
  		t[0][j]=25;
  		t[M-1][j]=25;
	}
 	for(i=0;i<N;i++)
 	{
  		t[i][0]=25;
  		t[i][N-1]=5;
 	}
 	x=1.0/(N-1);
 	y=1.0/(M-1);
 	cha=1;
 	while(cha>1e-6)
 	{
  		for(i=0;i<N;i++)
   			for(j=0;j<M;j++)
    			a[i][j]=t[i][j];
  		for(i=1;i<N-1;i++)
   			for(j=1;j<M-1;j++)
   			{
			   	x2=pow(x,2);y2=pow(y,2);
    			t[i][j]=0.5*y2*(t[i+1][j]+t[i-1][j])/(x2+y2)+0.5*x2*(t[i][j+1]+t[i][j-1])/(x2+y2);
    		}
  		cha=0;
  		for(i=0;i<N;i++)
   			for(j=0;j<M;j++)
    			cha=cha+abs(a[i][j]-t[i][j]);
  		cha=cha/(N*M);
  		cout<<num++<<' '<<cha<<endl;
 	}
 	for(j=M-1;j>=0;j--)
 	{
  		for(i=0;i<N;i++)
   			fout<<t[i][j]<<',';
   		fout<<endl;
   	}
  	fout.close();
  	return 0;
} 
