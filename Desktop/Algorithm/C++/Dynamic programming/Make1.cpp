
/*



문제
 

정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.
1.X가 3으로 나누어 떨어지면, 3으로 나눈다.
2.X가 2로 나누어 떨어지면, 2로 나눈다.
3.1을 뺀다.

정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.




입력
 

첫째 줄에 1보다 크거나 같고, 106보다 작거나 같은 자연수 N이 주어진다.




출력
 

첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.






예제 입력 1 복사 
 2





예제 출력 1 복사 
 1







예제 입력 2 복사 
 10





예제 출력 2 복사 
 3


*/
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int memo[1000001];
int MakeOne(int m) {

	for (int i = 4; i <= m; i++)
	{
		if (i % 3 == 0) {
			memo[i] = min(memo[i / 3] + 1, memo[i - 1] + 1);
		}
		else if (i % 2 == 0) {
			memo[i] = min(memo[i / 2] + 1, memo[i - 1] + 1);
		}

		else
			memo[i] = memo[i - 1] + 1;
		
	}
	return memo[m];
}
int main()
{
	int TC;
	scanf("%d",&TC);
	memo[0] = 0;
	memo[1] = 0;
	memo[2] = 1;
	memo[3] = 1;
	printf("%d", MakeOne(TC));
	return 0;
}