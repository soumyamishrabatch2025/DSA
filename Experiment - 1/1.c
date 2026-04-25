//Type your content here

#include <stdio.h>
#include <stdlib.h>

int main() {

	int n, key, flag;
	scanf("%d", &n);
	int * arr = (int*) malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	scanf("%d", &key);
	
	for (int i = 0; i < n; i++) {
		if (key == arr[i]){
			printf("found at position %d\n", i);
			return 0;
		}
	}
	printf("%d not found\n", key);
	return 0;
}