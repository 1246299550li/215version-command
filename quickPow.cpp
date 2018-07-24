long long quickPow(long long a, long long b, long long mod)
{
	long long ans = 1;
	while (b)
	{
		if (b & 1)
			ans = ans * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ans;
}