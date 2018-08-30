
/*

https://www.acmicpc.net/problem/1912
문제
 

n개의 정수로 이루어진 임의의 수열이 주어진다. 우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다. 단, 수는 한 개 이상 선택해야 한다.

예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자. 여기서 정답은 12+21인 33이 정답이 된다.




입력
 

첫째 줄에 정수 n(1 ≤ n ≤ 100,000)이 주어지고 둘째 줄에는 n개의 정수로 이루어진 수열이 주어진다. 수는 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수이다.




출력
 

첫째 줄에 답을 출력한다.






예제 입력 1 복사 
 10
10 -4 3 1 5 6 -35 12 21 -1




예제 출력 1 복사 
 33






 



*/

#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int arr[100001];
int dp[100001];
int findarr(int tc) {
	int count = dp[0];
	for (int i = 1; i < tc; i++)
	{

		if (arr[i] >= 0) {
			if (dp[i - 1] < 0) {
				dp[i] = arr[i];
				count += arr[i];
			}
			else {
				count += arr[i];
				if(dp[i-1] < count)
					dp[i] = count;
				else {
					dp[i] = dp[i - 1];
				}
			}
		}
		else {
			
			if (dp[i - 1] < 0) {
				count = 0;
				if (dp[i - 1] > arr[i]) {
					dp[i] = dp[i - 1]; 
				}
				else {
					dp[i] = arr[i];
				}
			}
			else {
				dp[i] = dp[i - 1];
				count += arr[i];
				if (count < 0)
					count = 0;
			}
		}
	}
	return dp[tc - 1];
}
int main()
{
	int TC;
	
	scanf("%d", &TC);
	for (int i = 0; i < TC; i++)
	{
		scanf("%d", &arr[i]);
	}
	dp[0] = arr[0];
	printf("%d",findarr(TC));
	return 0;
}