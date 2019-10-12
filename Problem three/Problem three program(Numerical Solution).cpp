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
#define M 42
#define N 4
#define pi 3.1415926535  
using namespace std;  
int main()  
{  
	ofstream fout;  
	fout.open("Problem three date(Numerical Solution).csv"); 
    double L1=20.0,L2=1.0,h=10,a=1000,m=0.5,n=0.5,tf=10,tw=50;
    double esp=1.0,Bi=h*L2/2/a;
	double t[M][N],T[M][N];  
	memset(t,0,sizeof(t));  
    memset(T,0,sizeof(T));  
    for(int i=2;i<=M;i++)  
        for(int j=1;j<=3;j++)
            t[i][j]=30;
    for(int j=1;j<=N;j++)
        t[1][j]=50;
    while(esp>1e-6)
    {
    	for(int i=0;i<N;i++)
   			for(int j=0;j<M;j++)
    			T[i][j]=t[i][j];
    	for(int i=2;i<=M-1;i++)
    	{
    		t[i][N]=(n*a/(m*2)*(t[i+1][N]+t[i-1][N])+m*a/n*t[i][N-1]+h*tf*m)/(n*a/m+m*a/n+h*m);
			t[i][1]=(n*a/(m*2)*(t[i+1][1]+t[i-1][1])+m*a/n*t[i][2]+h*tf*m)/(n*a/m+m*a/n+h*m);
			t[i][2]=0.25*(t[i-1][2]+t[i+1][2]+t[i][1]+t[i][3]);
			t[M][2]=(m/2*a*t[M][3]/n+m/2*a*t[M][1]/n+n*a*t[M-1][2]/m+n*h*tf)/(m*a/n+n*a/m+n*h);
			t[M][N]=(n/2*a*t[M-1][N]/m+m/2*a*t[M][N-1]/n+m/2*h*tf+n/2*h*tf)/(n/2*a/m+m/2*a/n+m/2*h+n/2*h);
			t[M][1]=(n/2*a/m*t[M-1][1]+m/2*a*t[M][2]/n+m/2*h*tf+n/2*h*tf)/(n/2*a/m+m/2*a/n+m/2*h+n/2*h);
		}
		esp=0;
		for(int i=0;i<N;i++)
   			for(int j=0;j<M;j++)
    			esp+=abs(T[i][j]-t[i][j]);
  		esp/=(N*M);
		cout<<esp<<endl;
	}
	
    double Q=(t[2][1]-t[1][1])/m*n/2*a+(t[2][3]-t[1][3])/m*n/2*a+(t[2][2]-t[1][2])/m*n*a;
    cout<<Q<<endl;
    for(int j=0;j<=N-2;j++)  
    {  
       for(int i=1;i<=M-1;i++)  
            fout<<t[i][j]<<',';  
        fout<<endl;  
    } 
    fout.close();  
    return 0;  
} 
