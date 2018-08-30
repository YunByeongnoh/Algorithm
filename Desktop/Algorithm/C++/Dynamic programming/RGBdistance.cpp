/*


문제
 

RGB거리에 사는 사람들은 집을 빨강, 초록, 파랑중에 하나로 칠하려고 한다. 
또한, 그들은 모든 이웃은 같은 색으로 칠할 수 없다는 규칙도 정했다. 
집 i의 이웃은 집 i-1과 집 i+1이다. 처음 집과 마지막 집은 이웃이 아니다.

각 집을 빨강으로 칠할 때 드는 비용, 초록으로 칠할 때 드는 비용, 
파랑으로 드는 비용이 주어질 때, 모든 집을 칠할 때 드는 비용의 최솟값을 
구하는 프로그램을 작성하시오.




입력
 

첫째 줄에 집의 수 N이 주어진다. N은 1,000보다 작거나 같다. 
둘째 줄부터 N개의 줄에 각 집을 빨강으로 칠할 때, 초록으로 칠할 때, 
파랑으로 칠할 때 드는 비용이 주어진다. 비용은 1,000보다 작거나 같은 자연수이다.




출력
 

첫째 줄에 모든 집을 칠할 때 드는 비용의 최솟값을 출력한다



예제 입력 1 복사 
 3
26 40 83
49 60 57
13 89 99





예제 출력 1 복사 
 96



*/



#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001][3] = { 0, };
int memo[1001][3] = { 0, };
int Min = 0;
void RGBdistance(int i, int n, int color, int sum) {
	if (i == n) {
		if (Min == 0) {
			Min = sum;
		}
		if (Min > sum && Min !=0)
			Min = sum;
		return;
	}
	for (int j = 1; j < n; j++)
	{
		memo[j][0] = min(memo[j - 1][1] + arr[j][0], memo[j - 1][2] + arr[j][0]);
		memo[j][1] = min(memo[j - 1][0] + arr[j][1], memo[j - 1][2] + arr[j][1]);
		memo[j][2] = min(memo[j - 1][0] + arr[j][2], memo[j - 1][1] + arr[j][2]);
	}

	

}

int main()
{
	int TC;
	scanf("%d", &TC);
	
	
	for (int i = 0; i < TC; i++)
	{
		getchar();
		scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);

	}
	for (int i = 0; i < 3; i++)
	{
		memo[0][i] = arr[0][i];
	}
	RGBdistance(1, TC, 0, 0);
	RGBdistance(1, TC, 1, 0);
	RGBdistance(1, TC, 2, 0);
	
	printf("%d", min(memo[TC-1][0], min(memo[TC-1][1],memo[TC-1][2])));

	return 0;
}