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
	fout.open("Problem three date(Analytical Solution).csv"); 
    double L1=20.0,L2=1.0,h=10,a=1000,m=0.5,n=0.5,tf=10,tw=50;
    double Bi=h*L2/2/a;
	double t[M][N];  
	memset(t,0,sizeof(t));   
    for(int i=2;i<=M;i++)  
        for(int j=1;j<=3;j++)
            t[i][j]=30;
    for(int j=1;j<=N;j++)
        t[1][j]=50;
    for(int i=2;i<=M;i++)
        for(int j=1;j<=N;j++)
            t[i][j]=tf+(tw-tf)*((cosh(sqrt(Bi)*(L1-(i-1)*0.5)/L2*2)+sqrt(Bi)*sinh(sqrt(Bi)*(L1-(i-1)*0.5)/L2*2))/(cosh(sqrt(Bi)*L1/L2*2)+sqrt(Bi)*sinh(sqrt(Bi)*L1/L2*2)));
    double Q=(t[2][1]-t[1][1])/m*n/2*a+(t[2][3]-t[1][3])/m*n/2*a+(t[2][2]-t[1][2])/m*n*a;
    cout<<Q<<endl;
    for(int j=1;j<=N-1;j++)  
    {  
       for(int i=1;i<=M-1;i++)  
            fout<<t[i][j]<<',';  
        fout<<endl;  
    } 
    fout.close();  
    return 0;  
} 