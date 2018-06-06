#include <stdio.h>

int max_arr(int a[]){
	int size = sizeof(a)/sizeof(a[0]) ;
	if (size ==0) return -1;
	int index = 0;
	int max = a[0];
	for (int i=1; i<size;i++){
		 if (max < a[i]){
			 max = a[i];

		 }
	}
	return max;
}


