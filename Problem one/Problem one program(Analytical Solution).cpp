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
    double L1,L2,x1,x2;
    double tw1,tw2;
    cout<<"input the number of tw1 and tw2!"<<endl;
    cout<<"tw1=";cin>>tw1;
    cout<<"tw2=";cin>>tw2;
    cout<<"input the number of length!"<<endl;
    cout<<"L1=";cin>>L1;
    cout<<"L2=";cin>>L2;
    float len1=L1/(M-1),len2=L2/(N-1);
    double t[M][N],T[M][N];
    memset(t,0,sizeof(t));
    memset(T,0,sizeof(T));
    for(int i=0;i<M-1;i++)
    {
        t[i][0]=tw1;
        t[i][N-1]=tw1;
    }
    for(int j=0;j<N-1;j++)
    {
        t[0][j]=tw1;
        t[M-1][j]=tw1+tw2*sin(pi*(j-1)/(N-1));
    }
    for (int i=1;i<M-2;i++)
        for (int j=1;j<M-2;j++)
            t[i][j]=tw1+tw2*sin(pi*(j-1)/(N-1))*sinh(pi*(i-1)/(N-1))/sinh(pi*L2/L1);
    for (int i=0;i<M-1;i++)
        for (int j=0;j<N-1;j++)
        {
            
        }
    return 0;
}