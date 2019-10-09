import numpy as np
#import matplotlib.pyplot as plt
#import optimiz

N = 101;
M = 51;
L1 = 3.0;
L2 = 2.0;
esp = 1.0;
#t = np.zeros(M, N);
t = [[0 for i in range(M)] for j in range(N)];
T = t;
for i in range(2,M-1):
    for j in range(2,N-1):
        t[i, j] = 70;
for i in range(1,M):
    t[i, N] = 60;
    t[i, 1] = 60;
for j in range(1,M):
    t[1, j] = 60;
t[M, j] = 60 + 20 * sin(pi * (j - 1) / (N - 1));
k = 0;
while esp > 1e-4:
    k = k + 1;
    for i in range(2,M-1):
        for j in range(2,N-1):
            t[i, j] = 0.25 * (t[i + 1, j] + t[i - 1, j] + t[i, j + 1] + t[i, j - 1]);
    for i in range(2,M-1):
        for j in range(2,N-1):
            esp = abs(t[i, j] - T[i, j]);
    T=t;
    pass
i = 2;
j = 2;
for x in range(0 , 0.6 / (N - 1) , 0.6):
    for y in range(0 , 0.4 / (M - 1) , 0.4):
        plt.scatter(x,y,t[i,j],25,"red");
        i = i + 1;
        j = j + 1;
plt.show();
