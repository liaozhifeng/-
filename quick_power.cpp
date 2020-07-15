#include<iostream>
int quick_power(int, int);
int main( )
{
	int x, n;
	std::cin >> x >> n;
	std::cout << quick_power(x, n);
}
int quick_power(int x, int n)
{
	if (n != 1)
	{
		if (n % 2 == 0)
		{
			int t = quick_power(x, n / 2);
			return t * t;
		}
		else
		{
			int t = quick_power(x, (n - 1) / 2);
			return t * t*x;
		}
	}
	else
		return x;
}