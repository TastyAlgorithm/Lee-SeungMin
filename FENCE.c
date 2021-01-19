#include <stdio.h>
#pragma warning(disable:4996)
int H[2000];
int main(void)
{
    int C;
    scanf("%d", &C);


    for (int i = 0; i < C; i++) {
        int Case[20000];
        int N,H;
        scanf("%d", &N);

        H = (int*)malloc(sizeof(int) * N);
        for (int j = 0; j < N; j++) {
            scanf("%d", (H+j));
        }

        printf("%d\n", func(N, 0, (N - 1)));
        free(H);
    }

}

int three_comp(int a, int b, int c)
{
    return ( a > b ? a :( b > c ? b : c));
}

int func(int num, int L, int R) {
    if (num == 1) { return H[L]; }
    //Threshold 1

    else if (num == 2) {
        if (H[L] == H[R]) { return H[L] * 2; }
        else if (H[L] < H[R]) {
            if (H[R] > H[L] * 2) { return H[R]; }
            else { return (H[L] * 2); }
        }

        else {
            if (H[L] > H[R] * 2) { return H[L]; }
            else { return (H[R] * 2); }
        }
    }
    //Threshold 2


    int M = num / 2;
    int r1, r2, r3;

    r1 = func(M, L, L + M - 1);
    r2 = func(num-M, L+M, R);
    r3 = centre(num, M, L, R);

    return three_comp(r1, r2, r3);
}

int centre(int num, int M, int L, int R) {
    int r;
    int max = -1;

    for (int i = 0; i < M; i++) {
        int chk = 0;

        for (int j = 1; j <= (M - i); j++) {
            if (H[L + i] <= H[L + i + j]) { chk++; }
            else { break; }
        }//check leftside condition

        if (chk == (M - i)) {
            r = rect(L + i,num);
            if (max < r) { max = r; }
        }// calculate area
    }//left->right
}

int rect(int S, int num) {
    int W_R = 0, W_L = 0;

    for (int i = S; i < num; i++) {
        if (H[S] <= H[i + 1]) { W_R++; }
        else { break; }
    }//left->right
    
    for (int i = S; i > 0; i--) {
        if (H[S] <= H[i - 1]) { W_L++; }
        else { break; }
    }//right->left

    return ((W_R + W_L + 1) * H[S]);
}
