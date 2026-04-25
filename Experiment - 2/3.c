#include <stdio.h>

void insertionSort(int a[], int n) {

	for (int i = 1; i < n; i++) {
		int insertIndex = i;
		int currentValue = a[i];
		int j = i - 1;

		while ( j >= 0 && a[j] > currentValue) {
			a[j + 1] = a[j];
			insertIndex = j;
			j--;
		}

		a[insertIndex] = currentValue;
	}

	
}

int main() {
    int a[20], n, i;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    insertionSort(a, n);

    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
