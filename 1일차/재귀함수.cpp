#include <stdio.h>

/*
	n = 1 -> 1
	sum[n] = sum[n - 1] + n;

	sum[n] = sum[n + 1] + n;
*/
int sum_func(int n)
{
	if (n == 1)
		return 1;
	return sum_func(n - 1) + n;
}

int sum_func2(int n, int N)
{
	if (n == N)
		return n;
	return sum_func2(n + 1, N) + n;
}

/*
	n! = 1 x ... x n

	fact[n] = fact[n - 1] * n

	n == 1 -> 1
*/
int factorial(int n)
{
	if (n == 1)
		return 1;
	return factorial(n - 1) * n;
}

/*
	a^N % 1'000'000'007를 구하라
	제약 조건 : a는 1~100, N은 1~100억
	1초 이내 동작

	pow[N] = pow[N - 1] * a
	N == 1 => a

	100억 => 10억 1초 => 10초
*/
const int MOD = 1e9 + 7;
int pow(int a, int n)
{
	if (n == 1)
		return a;
	return (pow(a, n - 1) * a) % MOD;
}

/*
	N 짝수
		- a^N = (a*a)^(N/2)

	N 홀수
		- a^N = (a*a)^(N/2) * a

	정수 / 정수 = 정수
	11 / 2 = 10
*/
int pow2(int a, int n)
{
	if (n == 1)
		return a;

	int b = a * a % MOD;
	if (n % 2 == 0)
	{
		return (pow2(b, n / 2)) % MOD;
	}
	else
	{
		return (pow2(b, n / 2) * a) % MOD;
	}
}

int pow3(int a, int n)
{
	int ret = 1;

	while (n)
	{
		if (n % 2 == 1)
		{
			ret = ret * a;
		}
		a = a * a;
		n /= 2;
	}
	return ret;
}

int main()
{
#if 0
	int N = 100;
	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		sum += i;
	}

	/*
		int -> 4byte = 32 bit 2^32 => (-2^31 ~ 2^31 - 1)
	*/

	printf("%d %d %d", sum, sum_func(N), sum_func2(1, N));

	int fac = 1;
	N = 10;
	for (int i = 1; i <= N; i++)
	{
		fac = fac * i;
	}

	printf("%d %d", fac, factorial(N));
#endif

	printf("%d", pow3(2, 10));
}
