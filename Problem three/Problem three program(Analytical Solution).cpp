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
	double t[M][N],T[M][N];  
	memset(t,0,sizeof(t));  
    memset(T,0,sizeof(T));  
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
