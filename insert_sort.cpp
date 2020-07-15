#include<iostream>
void insert_sort(int arr[], int l, int r);
int main()
{
	int arr[10]{ -1,9,8,7,6,5,4,3,2,1};
	insert_sort(arr, 0, 9);
	for (int t = 0; t < 10; ++t)
		std::cout << arr[t];
}
void insert_sort(int arr[], int l, int r)
{
	for (int t = l + 1; t <= r; ++t)
	{
		int key = arr[t];
		int i = t - 1;
		while (key < arr[i] && i >= 0)
		{
			arr[i + 1] = arr[i];
			--i;
		}
		arr[i + 1] = key;
	}

}