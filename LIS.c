#include <stdio.h>
#pragma warning(disable:4996)
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int main()
{
	int C;
	scanf("%d", &C);

	for (int i = 0; i < C; i++)
	{
		int N;
		scanf("%d", &N);
		int arr[500];
		int dp[500];
		int ans=0;

		arr[0] = 0;
		dp[0] = 0;
		for (int i = 1; i <= N; i++)
			scanf("%d", &arr[i]);
		for (int i = 1; i <= N; i++) {
			
			for (int j = 0; j < i; j++){
				if (arr[i] > arr[j]) {

					if (dp[i] < dp[j] + 1) // max(dp[i], dp[j]+1)
					{
						dp[i] = dp[j] + 1;
					}
				}
			}

			if (ans < dp[i]) // max(dp[i], dp[j]+1)
			{
				ans = dp[i];
			}
		}

		printf("%d\n", ans);
		for (int i = 1; i <= N; i++)
		{
			arr[i] = 0;
			dp[i] = 0;
		}
	}

	return 0;
}
