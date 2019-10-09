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
#include<iostream>
#include<fstream>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<map>
#include<algorithm>
#define pi 3.1415926535
#define N 10000
#define M 10000
using namespace std;
int main()
{
    ofstream fout;
	fout.open("Problem one data(Analytical Solution).csv");
    double L1,L2,x=0,y=0;
    double tw1,tw2;
    cout<<"input the number of tw1 and tw2!"<<endl;
    cout<<"tw1=";cin>>tw1;
    cout<<"tw2=";cin>>tw2;
    cout<<"input the number of length!"<<endl;
    cout<<"L1=";cin>>L1;
    cout<<"L2=";cin>>L2;
    float len1=L1/(N-1),len2=L2/(M-1);
    double t[M][N],T[M][N];
    memset(t,0,sizeof(t));
    memset(T,0,sizeof(T));
    for(int i=0;i<N;i++)
    {
        t[i][0]=tw1;
        t[i][N-1]=tw1+tw2*sin(pi*(i-1)/(N-1));
    }
    for(int j=0;j<M;j++)
    {
        t[0][j]=tw1;
        t[M-1][j]=tw1;
    }
    for (int i=1;i<M-1;i++)
        for (int j=1;j<M-1;j++)
            t[i][j]=tw1+tw2*sin(pi*(j-1)/(N-1))*sinh(pi*(i-1)/(N-1))/sinh(pi*L2/L1);
 	for(int j=M-1;j>=0;j--)
 	{
  		for(int i=0;i<N;i++)
        {
//            cout<<setiosflags(ios::fixed)<<setprecision(3)<<t[i][j]<<"   ";
            fout<<t[i][j]<<',';
        }
//   		cout<<endl;
        fout<<endl;
  	}
    fout.close();
    return 0;
}
