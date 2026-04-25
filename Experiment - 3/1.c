#include <stdio.h>

// Function to merge two subarrays
// void merge(int arr[], int left, int mid, int right) {
void merge(int arr[], int start, int mid, int end) {

// write your code here
	int i, j, k;

	int n1 = mid - start + 1;
	int n2 = end - mid;

	int left[n1], right[n2];

	for (i = 0; i < n1; i++) {
		left[i] = arr[start + i];
	}

	for (j = 0; j < n2; j++) {
		right[j] = arr[mid + 1 + j];
	}

		i = 0;
		j = 0;
		k = start;

	while (i < n1 && j < n2) {
		if (left[i] <= right[j]) {
			arr[k] =left[i];
			i++;
		} else {
			arr[k] = right[j];
			j++;
		}
		k++;
		
	}

	while (i < n1) {
		arr[k] = left[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = right[j];
		j++;
		k++;
	}
	
	



}

// Function to implement merge sort
void mergeSort(int arr[], int left, int right) {

  // write your code here

	if (left < right) {
		
	int mid = (left + right) / 2;

	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);

	merge(arr, left, mid, right);
	}
  
   
}

// Function to print an array
void printArray(int arr[], int size) {

// write your code here
	for (int i = 0; i < size; i++) {
		printf("%d ",arr[i]);
	}
	printf("\n");


}

int main() {
    int n;
    
    // Input the size of the array
    printf("");
    scanf("%d", &n);
    
    int arr[n];
    
    // Input the elements of the array
    printf("");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the original array
    printf("");
    printArray(arr, n);

    // Sort the array using merge sort
    mergeSort(arr, 0, n - 1);
    
    // Print the sorted array
    printf("");
    printArray(arr, n);

    return 0;
}
