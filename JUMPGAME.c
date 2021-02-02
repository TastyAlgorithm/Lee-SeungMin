#include<stdio.h>
#pragma warning(disable:4996)

void init_cache(int(*cache)[101]);

int jump(int(*cache)[101], int(*map)[101], int x, int y, int n);

int main()
{
    int C, t;
    int n, i, j;
    int map[101][101];
    int cache[101][101];
    
    scanf("%d", &C);
    
    for (t = 1; t <= C; t++) {

        init_cache(cache);

        scanf(" %d", &n);
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                scanf(" %d", &map[i][j]);
            }
        }


        if (jump(cache, map, 0, 0, n) > 0)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}

void init_cache(int(*cache)[101])
{
    int i, j;
    for (i = 0; i < 101; i++) {
        for (j = 0; j < 101; j++) {
            cache[i][j] = -1;
        }
    }
}
int jump(int(*cache)[101], int(*map)[101], int x, int y, int n)
{

    if (x < 0 || y < 0 || x >= n || y >= n)     //x또는 y가 범위를 벗어났을때
        return 0;

    int move = map[x][y];
    int* ret = &(cache[x][y]);

    if (x == n - 1 && y == n - 1)       //x와 y가 끝으로 올때
        return 1;

    if (*ret != -1)
        return *ret;

    *ret = 0;

    *ret = jump(cache, map, x + move, y, n) || jump(cache, map, x, y + move, n);

    return *ret;
}
