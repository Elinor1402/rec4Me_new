#include <stdio.h>
#include <stdlib.h>

void mergeSort(int arr[], int size);
int* merge(int a1[], int n1, int a2[], int n2);
void printArray(int arr[], int size);
void copyArr(int dest[], int src[], int size);

int findCanmdidate(int a[], int size)
{
	int maj_index = 0, count = 1, i;
	for (i = 1; i < size; i++)
	{
		if (count == 0) { maj_index = i, count = 1; }
		else
		{
			if (a[maj_index] == a[i])count++;
			else count--;
		}
	}
	if (count == 0) return -1;
	else return maj_index;

}
void main()
{
	int arr[] = { 4,3,3,3,4,2,3,5,3,3,4,3,2};
	int maj_index = findCanmdidate(arr, 13);

	/*printf("Array before sort: ");
	printArray(arr, 10);
	mergeSort(arr, 10);
	printf("Array after sort: ");
	printArray(arr, 10);*/
}

void mergeSort(int arr[], int size)
{
	int* tmpArr = NULL;
	if (size <= 1)
		return;

	mergeSort(arr, size / 2);
	mergeSort(arr + size / 2, size - size / 2);
	tmpArr = merge(arr, size / 2, arr + size / 2, size - size / 2);
	if (tmpArr)
	{
		copyArr(arr, tmpArr, size); // copy values from tmpArr to arr
		free(tmpArr);
	}
	else
	{
		printf("Memory allocation failure!!!\n");
		exit(1);	// end program immediately with code 1 (indicating an error)
	}
}

int* merge(int a1[], int size1, int a2[], int size2) {
	int ind1, ind2, resInd;
	int* res = (int*)malloc((size1 + size2) * sizeof(int));

	if (res)
	{
		ind1 = ind2 = resInd = 0;

		while ((ind1 < size1) && (ind2 < size2)) {
			if (a1[ind1] <= a2[ind2]) {
				res[resInd] = a1[ind1];
				ind1++;
			}
			else {
				res[resInd] = a2[ind2];
				ind2++;
			}
			resInd++;
		}

		while (ind1 < size1) {
			res[resInd] = a1[ind1];
			ind1++;
			resInd++;
		}
		while (ind2 < size2) {
			res[resInd] = a2[ind2];
			ind2++;
			resInd++;
		}
	}
	return res;
}

void printArray(int arr[], int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void copyArr(int dest[], int src[], int size)
{
	int i;

	for (i = 0; i < size; i++)
		dest[i] = src[i];
}