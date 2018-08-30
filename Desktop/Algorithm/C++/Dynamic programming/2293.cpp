
/*
2293번

문제
 

n가지 종류의 동전이 있다. 각각의 동전이 나타내는 가치는 다르다. 이 동전들을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 그 경우의 수를 구하시오. (각각의 동전은 몇 개라도 사용할 수 있다.)




입력
 

첫째줄에 n, k가 주어진다. (1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000) 다음 n개의 줄에는 각각의 동전의 가치가 주어진다. 동전의 가치는 100,000보다 작거나 같은 자연수이다.




출력
 

첫째 줄에 경우의 수를 출력한다. 경우의 수는 2^31보다 작다.






예제 입력 1 복사 
 3 10
1
2
5





예제 출력 1 복사 
 10


*/

#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;



int main()
{
	int coin[101] = { 0, };
	int ar[10001] = { 0, };
	int n, k, value, MAX = 0, check;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &value);
		coin[i] = value;
			
	}

	ar[0] = 1;
	for (int i = 0; i <= 101; i++)
	{
		if (coin[i] >0 ) {
			for (int j = 1; j <= k; j++)
			{
				if(coin[i] <= j )
					ar[j]+= ar[j - coin[i]];
					
			}
		}
	}

	
	printf("%d", ar[k]);
	return 0;
}