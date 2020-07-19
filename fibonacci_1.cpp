#include<iostream>
//自底向上的朴素实现方法
int main()
{
	int n;
	std::cin >> n;
	int *arr = new int[n + 1];
	arr[0] = 0;
	arr[1] = 1;
	for (int t = 2; t < n; ++t)
	{
		arr[t] = arr[t - 1] + arr[t - 2];
	}
	std::cout << arr[n - 1];
	return 0;
}