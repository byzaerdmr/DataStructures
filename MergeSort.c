#include <stdio.h>

void merge(int arr[], int left, int k, int right, int size) {

	int i, j, l = 0;
	int a[50];

	for (i = left, j = k + 1; i <= k && (j <= right);) {
		if (arr[i] < arr[j]) {
			a[l] = arr[i];
			i++;
			l++;
		}
		else {
			a[l] = arr[j];
			j++;
			l++;
		}

	}

	while (i <= k) {
		a[l] = arr[i];
		i++;
		l++;
	}
	while (j <= right) {
		a[l] = arr[j];
		j++;
		l++;
	}
	for (i = left, l = 0;i <= right;i++, l++) {
		arr[i] = a[l];
	}
		
}
void MergeSort(int arr[], int left, int right, int size) {
	int k;
	if (left < right) {
		k = (left + right) / 2;

		MergeSort(arr, left, k, size);
		MergeSort(arr, k + 1, right, size);

		merge(arr, left, k, right, size);
	}
}

int main() {

	int arr[] = { 16,64,78,1,25,53,27,81 };
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("The sorted array is: \n");

	MergeSort(arr, 0, size - 1, size);

	for (int b = 0;b < size;b++){

		printf("%d\n", arr[b]);


	}

	return 0;

}
