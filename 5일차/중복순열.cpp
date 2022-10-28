int number[4];
int N = 10;
void dfs(int n)
{
	if (n == N)
	{
		for (int i = 0; i < N; i++)
		{
			printf("%d ", number[i]);
		}
		printf("\n");
		return;
	}
	
	for (int i = 0; i <= 3; i++)
	{
		number[n] = i;
		dfs(n + 1);
	}
}

int main()
{
	dfs(0);
}
