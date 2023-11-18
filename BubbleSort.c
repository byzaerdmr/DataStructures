#include<stdio.h>

void BubbleSort(int arr[], int size) {

	int i,j,temp;

	for (i= 0;i< (size - 1);i++) {

		for (j = 0;j < (size - i-1);j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j ] = arr[j+1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {

	int size;

	printf("Please enter a array size: ");
	scanf("%d", &size);

	int arr[25];

	printf("Please enter array values: \n");
	for (int i = 0;i < size;i++) {
		scanf("%d", &arr[i]);
	}

	printf("Array: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}

	BubbleSort(arr, size);

	printf("\nThe sort is array: ");
	for (int i = 0; i < size;i++) {
		printf(" %d ", arr[i]);
	}


	return 0;
}
