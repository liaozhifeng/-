#include<iostream>
void max_heapify(int[], int);
void max_heapify1(int[], int);
void build_heap(int[]);
void heap_sort(int[]);
int heap_size = 10;
int main()
{
	int heap[10]{ 1,4,10,14,9,7,3,8,6,16 };
	heap_sort(heap);
	for (int t = 0; t < 10; ++t)
		std::cout << heap[t] << ' ';
	return 0;
}
void max_heapify(int arr[], int i)
{
	int l = i << 2;
	int r = i + 1;
	int largest = i;
	if (l <= heap_size && arr[l - 1] > arr[i-1])
		largest = l;
	if (r <= heap_size && arr[largest - 1] < arr[r - 1])
		largest = r;
	if (largest != i)
	{
		std::swap(arr[largest - 1], arr[i-1]);
		max_heapify(arr, largest);
	}
	return;
}
void max_heapify1(int arr[], int i)
{
	while (true)
	{
		int l = i << 1;
		int r = l + 1;
		int largest = i;
		if (l <= heap_size && arr[i - 1] < arr[l - 1])
			largest = l;
		if (r <= heap_size && arr[largest - 1] < arr[r - 1])
			largest = r;
		if (largest != i)
		{
			std::swap(arr[largest - 1], arr[i - 1]);
			i = largest;
		}
		else
			break;
	}
}
void build_heap(int arr[])
{
	for (int t = heap_size / 2; t >0; --t)
	{
		max_heapify1(arr, t);
	}
}
void heap_sort(int arr[])
{
	build_heap(arr);
	for (int t = heap_size; t >= 2; --t)
	{
		std::swap(arr[t - 1], arr[0]);
		--heap_size;
		max_heapify1(arr, 1);
	}
}