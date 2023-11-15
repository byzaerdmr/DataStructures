#include <stdio.h>

void insertion(int arr[], int size) {

	int a, b, key;
	for (a = 1;a < size;a++) {

		key = arr[a];

		for (b = a - 1; b >= 0 && key <= arr[b];b--)
			arr[b + 1] = arr[b];
		arr[b + 1] = key;
	}

}

int main() {

	int arr[] = { 21,56,12,4,94,61,2,35 };
	int size = sizeof(arr) / sizeof(arr[0]);
	insertion(arr, size);
	printf("The sorted array is: ");
	for (int i = 0;i < size;i++) {

		printf("%d ",arr[i]);
	}
	return 0;
}
