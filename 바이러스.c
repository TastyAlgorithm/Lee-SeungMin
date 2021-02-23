#include <stdio.h> 
#pragma warning(disable:4996)
int* visit = NULL;  
int** array = NULL; 
int total = 0; 
int cnt = 0; 

void DFS(int v)
{
    visit[v] = 1;  

    for (int i = 0; i < total; i++)
    {
        if (!visit[i] && array[v][i] == 1) 
        {
            cnt++;
            DFS(i);
        }
    }
}

int main()

{
    int connectCnt = 0;
    scanf("%d %d", &total, &connectCnt);
    array = (int**)malloc(sizeof(int*) * total);

    for (int i = 0; i < total; i++)

    {
        array[i] = (int*)(malloc(sizeof(int) * total));
        memset(array[i], 0x00, sizeof(int) * total);
    }

        visit = malloc(sizeof(int) * connectCnt);
    memset(visit, 0x00, sizeof(int) * connectCnt);

    int x, y;

    for (int i = 0; i < connectCnt; i++)
    {
        scanf("%d %d", &x, &y);
        array[x - 1][y - 1] = 1;
        array[y - 1][x - 1] = 1;
    }
    
    DFS(0);

    printf("%d\n", cnt);//감염된 컴퓨터 갯수 

    for(int i = 0; i < connectCnt; i++)
        free(array[i]);

    free(array);
    free(visit);

}
