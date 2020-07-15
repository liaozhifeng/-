#include<iostream>
int binary_search(int arr[], int, int, int);
int main()
{
	int arr[10]{1,2,3,4,5,6,7,8,9};
	std::cout << binary_search(arr, 0, 9, 2);
}
int binary_search(int arr[], int l, int r, int target)
{
	int mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (arr[mid] > target)
		{
			r = mid - 1;
		}
		else if (arr[mid] < target)
		{
			l = mid + 1;
		}
		else
			return mid;
	}
	return -1;
}
