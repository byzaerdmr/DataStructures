#include<stdio.h>

void SelectionSort(int arr[], int size) {

	int a, b, key, min;

	for (a = 0; a < (size - 1);a++) {

		min = a;
		key = size - 1;

		for (b = a+1;b < size;b++)
		{

			if (arr[b] < arr[min]) {
				min = b;
				

			}
		}
		key = arr[min];
		arr[min] = arr[a];
		arr[a] = key;

		}
	}

int main() {

	int size;

	while (1) {
		printf("Please enter the length of array: ");
		scanf("%d", &size);

		if (size > 20 || size < 1) {
			printf("Invalid array size!\n");
			continue; // Geçersiz boyut durumunda döngüyü başa al
		}
		break; // Geçerli bir boyut girdiyse döngüden çık

	}
	

	int arr[20];

	printf("Please enter the element of array: \n");

	for (int a = 0;a < size;a++) {

		scanf("%d", &arr[a]);

	}
	printf("array: ");
	
	for (int a = 0; a < size;a++) {
		printf("%d ", arr[a]);
	}

	SelectionSort(arr, size);
	printf("\nThe sort array is: \n");
	for (int a = 0; a < size;a++) {
		printf("%d ", arr[a]);
	}

	return 0;
}
