#include<iostream>
#include<fstream>
#include<cmath>
#include<cstring>
#include<map>
#include<algorithm>
#define pi 3.1415926535
#define N 51
#define M 101
using namespace std;
int main()
{
    double L1,L2;
    double tw1,tw2;
    cout<<"input the number of tw1 and tw2!"<<endl;
    cout<<"tw1=";cin>>tw1;
    cout<<"tw2=";cin>>tw2; 
    double t[M][N];
	double T[M][N];
    memset(t,0,sizeof(t));
    memset(T,0,sizeof(T));
    for(int i=0;i<M-1;i++)
    {
        t[i,0]=tw1;
        t[i,N-1]=tw1;
    }
    for(int j=0;j<N-1;j++)
    {
        t[0,j]=tw1;
        t[M-1,j]=tw1+tw2*sin(pi*(j-1)/(N-1));
    }
    return 0;
}
