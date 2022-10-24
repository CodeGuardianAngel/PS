#include <stdio.h>

const int MAX = 100000;
int seive[MAX];

/*
	유클리드 호제법
	- gcd(a,b) = gcd(b, r) r은 a를 b로 나눈 나머지
	r == 0 -> b
*/
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
#if 0
	int N = 100;
	for (int i = 2; i <= N; i++)
	{
		if (seive[i])
			continue;
		
		for (int j = i * i; j <= N; j += i)
		{
			seive[j] = 1;
		}
	}

	for (int i = 2; i <= N; i++)
	{
		if (seive[i])
			continue;

		printf("%d ", i);
	}
#endif
	printf("%d\n", gcd(3,6));
	printf("%d\n", gcd(8,12));

}