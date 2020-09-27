#include <iostream>

const int partition(int* const arr, const int low, const int high)
{
	int middle = (low + high) / 2;

	if (arr[middle] < arr[low])
		std::swap(arr[low], arr[middle]);
	if (arr[high] < arr[low])
		std::swap(arr[low], arr[high]);
	if (arr[middle] < arr[high])
		std::swap(arr[high], arr[middle]);

	int pivot = arr[high];
	unsigned int i = low, j = low;

	for (; j < high; j++)
	{
		if (arr[j] < pivot)
		{
			std::swap(arr[i], arr[j]);
			i += 1;
		}
	}

	std::swap(arr[i], arr[high]);

	return i;
}

void quicksort(int* const arr, const int low, const int high)
{
	if (low < high)
	{
		int p = partition(arr, low, high);
		quicksort(arr, low, p - 1);
		quicksort(arr, p + 1, high);
	}
}

void printArray(const int* const arr, const int length)
{
	for (unsigned int i = 0; i < length; i++)
		std::cout << arr[i] << std::endl;
	std::cout << std::endl;
}

int main()
{
	const unsigned int sizeOfArray = 7;
	int arr[sizeOfArray] = {1, 1, 12, 4, 18, 7, 6};
	
	printArray(arr, sizeOfArray);

	quicksort(arr, 0, sizeOfArray - 1);

	printArray(arr, sizeOfArray);

	system("pause");
	return 0;
}