#include <stdio.h>
#pragma warning(disable:4996)

int main()
{
    int T, N, M;
    int a, b;
    scanf("%d", &T);
    for(int i=0;i<T;i++)
    {
        scanf("%d %d", &N, &M);
        for (int j = 0; j < M; j++)
        {
            scanf("%d %d", &a, &b);
        }
        printf("%d\n", N - 1);
    }
}
