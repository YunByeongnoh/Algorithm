
/*

https://www.acmicpc.net/problem/9251
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.

예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.




입력
 

첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.




출력
 

첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를 출력한다.






예제 입력 1 복사 
 ACAYKP
CAPCAK





예제 출력 1 복사 
 4


*/


#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

char str1[1002];
char str2[1002];
int dp[1001][1001];
int cmp(int Big, int Small,char bigc[],char smallc[]) {
	int count = 0;
	
	if (dp[Small][Big])
		return dp[Small][Big];

	for (int i = 1; i <= Small; i++)
	{
		for (int j = 1; j <= Big; j++)
		{
			if (smallc[i] == bigc[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				if (dp[i][j - 1] > dp[i - 1][j])
					dp[i][j] = dp[i][j - 1];
				else
					dp[i][j] = dp[i - 1][j];

			}
		}
	}
	return dp[Small][Big];
}
int main()
{
	char str3[1002] = { 0, };
	char str4[1002] = { 0, };
	int lengthA, lengthB;
	scanf("%[^\n]", str3);
	getchar();
	scanf("%[^\n]", str4);
	for (int i = 0; i < 1001; i++)
	{
		str1[i + 1] = str3[i];
		str2[i + 1] = str4[i];
		if (str3[i] != '\0')
			lengthA = i;
		if (str4[i] != '\0')
			lengthB = i;
	}
	lengthA++;
	lengthB++;
	if(lengthA > lengthB)
		printf("%d",cmp(lengthA, lengthB,str1,str2));
	else
		printf("%d", cmp(lengthB, lengthA,str2,str1));
	
	
	return 0;
}