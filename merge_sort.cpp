#include<iostream>
#include<climits>
void merge_sort(int arr[], int l, int r);
void merge(int[], int, int, int);
int main()
{
	int arr[10]{ 10,9,8,7,6,5,4,3,2,1};
	merge_sort(arr, 0, 9);
	for (int t = 0; t < 10; ++t)
		std::cout << arr[t];
}
void merge_sort(int arr[], int l, int r)
{
	if (l < r)
	{
		int mid = (l + r) / 2;
		merge_sort(arr, l, mid);
		merge_sort(arr, mid + 1, r);
		merge(arr, l, mid, r);
	}
}
void merge(int arr[], int l, int mid, int r)
{
	int len1 = mid - l + 1;
	int len2 = r - mid;
	int *left = new int[len1 + 1];
	int *right = new int[len2 + 1];
	for (int t = 0; t < len1; ++t)
		left[t] = arr[l + t];
	for (int t = 0; t < len2; ++t)
		right[t] = arr[mid + 1 + t];
	left[len1] = INT_MAX;
	right[len2] = INT_MAX;
	int i = 0; int j = 0;
	for (int t = l; t <= r; ++t)
	{
		if (left[i] < right[j])
		{
			arr[t] = left[i];
			++i;
		}
		else
		{
			arr[t] = right[j];
			++j;
		}
	}
}
