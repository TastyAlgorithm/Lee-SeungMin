#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)

int sort_arr(int* arr, int* a) {
    int i, j, temp = 0;
    for (j = 0; j < a; j++) {
        for (i = 0; i < a; i++) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);


    for (int i = 0; i < T; i++) {

        int N;
        scanf("%d", &N);

        int arr_male[10000];
        int arr_female[10000] ;
        int k, j;

        for (k = 0; k < N; k++)
            scanf("%d", &arr_male[k]);

        for (j = 0; j < N; j++)
            scanf("%d", &arr_female[j]);

        sort_arr(arr_male, N);
        sort_arr(arr_female, N);

        for (int w = 0; w < N; w++) {
            printf("%d\n", arr_male[w]);
        }
        for (int y = 0; y < N; y++) {
            printf("%d\n", arr_female[y]);
        }

        int sum = 0;
        for (int l = 0; l < N; l++)
            sum += abs(arr_male[l] - arr_female[l]);

        printf("%d\n", sum);

    }
}
