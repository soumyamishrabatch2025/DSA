#include <stdio.h>

void selectionSort(int arr[], int n) {
    //write your code here...

	for (int i = 0; i < n-1; i++) {

		int min_index = i;

		for (int j = min_index; j < n; j++) {
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}

		int min_value = arr[min_index];

		for (int k = min_index; k > i; k--) {
			arr[k] = arr[k-1];
		}
		arr[i] = min_value;
	}

	for( int j = 0; j < n/2; j++) {
		int temp = arr[j];
		arr[j] = arr[n-j-1];
		arr[n-j-1] = temp;
	}
    
}

int main() {
    int n;

    // Input number of elements in the array
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array in descending order using selection sort
    selectionSort(arr, n);

    // Output the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
