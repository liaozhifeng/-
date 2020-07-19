#include<iostream>
int ** fibonacci(int);
int **arr;
int main()
{
	arr = new int*[2];
	arr[0] = new int[2];
	arr[1] = new int[2];
	arr[0][0] = arr[0][1] = arr[1][0] = 1;
	arr[1][1] = 0;
	int n;
	std::cin >> n;
	int** result = fibonacci(n);
	std::cout << result[0][1];
}
int** fibonacci(int n)
{
	if (n == 1)
		return arr;
	else
	{
		auto temp = fibonacci(n / 2);
		int **a = new int *[2];
		a[0] = new int[2];
		a[1] = new int[2];
		for (int t = 0; t < 2; ++t)
		{
			for (int i = 0; i < 2; ++i)
			{
				a[t][i] = temp[t][0] * temp[0][i] + temp[t][1] * temp[1][i];
			}
		}
		if (n % 2 != 0)
		{
			int n1, n2, n3, n4;
			n1 = a[0][0] + a[0][1];
			n2 = a[0][0];
			n3 = a[1][0] + a[1][1];
			n4 = a[1][0];
			a[0][0] = n1;
			a[0][1] = n2;
			a[1][0] = n3;
			a[1][1] = n4;
		}
		delete[]temp[0];
		delete[]temp[1];
		delete[]temp;
		return a;
	}
}