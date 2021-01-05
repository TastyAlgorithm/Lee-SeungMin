#include <stdio.h>
#pragma warning(disable:4996)



void main() {

   int person[100];
   int C, N, K;
   int i, j, Alive, Kill;

   i = 0;
   j = 0;

   Alive = 0;
   Kill = 0;

   scanf("%d", &C);
   

   for (int c = 0; c < C; c++) {

      scanf("%d", &N);
      scanf("%d", &K);

      for (i = 0; i < N; i++) {  //모든 person배열에 1을 대입
         person[i] = 1;
      }

      person[0] = 0;

      for (i = 0; i < N; i++) {

         if (person[i] == 1) Alive++;            //1은 생존자, 0은 사망자를 뜻함

         if (Alive == K) {             //K번째 사람을 0으로 치환

            person[i] = 0;
            Alive = 0;      //다음 K번째 사람을 위해 초기화    

         }

         for (j = 0; j < N; j++) {

            if (person[j] == 0) Kill++;           //죽은 사람수를 계산
            if (Kill == N - 2) {                         //죽은 사람이 총 사람수보다 2명 작으면 생존자는 2명
               break;                            
            }
         }


         if (Kill == N - 2) break;                  //다른 연산으로 죽은 사람의 수가

         Kill = 0;                                                 //바뀔수 있으므로 초기화
         if (i == N - 1) {         //반복을 위한 초기화
            i = 0;
         }



      }

      for (i = 0; i < N; i++) {

         if (person[i] == 1) printf("%d \n", i + 1);           //생존자를 찾아 출력

      }


         
   }
}
