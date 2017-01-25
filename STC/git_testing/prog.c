#include <stdio.h>
#define N 1000000

void isqrt (float *a, int n);

int main(){
    float a[N];
    int i;
        for (i=0; i<N; i++) a[i]=1.0e0 + i;
        isqrt(a,N);
        printf("N a(0) a(N-1) : %d %f %f\n", N,a[0],a[N-1]);
}
