/*This file is created for sorting. */
#include <stdio.h>
#include <stdlib.h>
#define MAX 15
#define SIZEOFARRAY(A) sizeof(A)/sizeof(A[0])

void print(int a[], int size);

void merge_decesending(int *A, int* AL, int nL, int *AR, int nR) {

    int i = 0, j = 0, k = 0;

    while (i < nL && j < nR) {
        if (AL[i] > AR[j]) {
            A[k++] = AL[i++];

        } else {
            A[k++] = AR[j++];

        }
    }

    while (i < nL) {
        A[k++] = AL[i++];

    }
    while (j < nR) {
        A[k++] = AR[j++];

    }

}

void merge_acesending(int *A, int* AL, int nL, int *AR, int nR) {

    int i = 0, j = 0, k = 0;

    while (i < nL && j < nR) {
        if (AL[i] < AR[j]) {
            A[k++] = AL[i++];

        } else {
            A[k++] = AR[j++];

        }
    }

    while (i < nL) {
        A[k++] = AL[i++];

    }
    while (j < nR) {
        A[k++] = AR[j++];

    }

}
static int cnt = 0;

void mergesort_dec(int *A, int size) {

    int mid, i = 0, k = 0;
    int nL, nR;
    int * AR = NULL, *AL = NULL;
    if (size < 2) {
        return;
    }
    mid = (size) / 2;

    nL = mid;
    nR = size - mid;

    AL = (int *) malloc(sizeof (int)*nL);
    for (i = 0; i < nL; i++) {
        AL[i] = A[k];
        k++;
    }
    //    print(AL, nL);

    AR = (int *) malloc(sizeof (int)*nR);
    for (i = 0; i < nR; i++) {
        AR[i] = A[k];
        k++;
    }
    //    print(AR, nR);

    mergesort_dec(AL, nL);
    //		printf("merge called L %d\n", cnt);
    mergesort_dec(AR, nR);
    //    cnt++;
    //		printf("merge called R %d\n", cnt);
    merge_decesending(A, AL, nL, AR, nR);

    free(AL);
    free(AR);

}

void mergesort_aec(int *A, int size) {

    int mid, i = 0, k = 0;
    int nL, nR;
    int * AR = NULL, *AL = NULL;
    if (size < 2) {
        return;
    }
    mid = (size) / 2;

    nL = mid;
    nR = size - mid;

    AL = (int *) malloc(sizeof (int)*nL);
    for (i = 0; i < nL; i++) {
        AL[i] = A[k];
        k++;
    }
    //    print(AL, nL);

    AR = (int *) malloc(sizeof (int)*nR);
    for (i = 0; i < nR; i++) {
        AR[i] = A[k];
        k++;
    }
    //    print(AR, nR);

    mergesort_aec(AL, nL);
    //		printf("merge called L %d\n", cnt);
    mergesort_aec(AR, nR);
    //    cnt++;
    //		printf("merge called R %d\n", cnt);
    merge_acesending(A, AL, nL, AR, nR);

    free(AL);
    free(AR);

}

// Function to Merge Arrays L and R into A. 
// lefCount = number of elements in L
// rightCount = number of elements in R. 

void Merge(int *A, int *L, int leftCount, int *R, int rightCount) {
    int i, j, k;

    // i - to mark the index of left aubarray (L)
    // j - to mark the index of right sub-raay (R)
    // k - to mark the index of merged subarray (A)
    i = 0;
    j = 0;
    k = 0;

    while (i < leftCount && j < rightCount) {
        if (L[i] < R[j]) A[k++] = L[i++];
        else A[k++] = R[j++];
    }
    while (i < leftCount) A[k++] = L[i++];
    while (j < rightCount) A[k++] = R[j++];
}

// Recursive function to sort an array of integers. 

void MergeSort(int *A, int n) {
    int mid, i, *L, *R;
    if (n < 2) return; // base condition. If the array has less than two element, do nothing. 

    mid = n / 2; // find the mid index. 

    // create left and right subarrays
    // mid elements (from index 0 till mid-1) should be part of left sub-array 
    // and (n-mid) elements (from mid to n-1) will be part of right sub-array
    L = (int*) malloc(mid * sizeof (int));
    R = (int*) malloc((n - mid) * sizeof (int));

    for (i = 0; i < mid; i++) L[i] = A[i]; // creating left subarray
    for (i = mid; i < n; i++) R[i - mid] = A[i]; // creating right subarray

    MergeSort(L, mid); // sorting the left subarray
    MergeSort(R, n - mid); // sorting the right subarray

    cnt++;
    //  printf("merge called %d\n", cnt);
    Merge(A, L, mid, R, n - mid); // Merging L and R into A as sorted list.
    free(L);
    free(R);
}

void print(int a[], int size) {
    int i = 0;
    for (i = 0; i < size; i++) {
        printf("%d,", a[i]);
    }
    printf("\n");
}

void real_sol(int *A, int n) {
    int i = 0, nl = 0, j = 0, k = 0;
    int * neg, *pos;
    if (n < 1)
        return;

    for (i = 0; i < n; i++) {
        if (A[i] < 0)
            nl++;
    }

    neg = (int *) malloc(sizeof (int)*nl);
    pos = (int *) malloc(sizeof (int)*(n - nl));
    for (i = 0; i < n; i++) {

        if (A[i] < 0) {
            neg[j++] = A[i];
        } else {
            pos[k++] = A[i];
        }
    }
    //    print(neg, nl);
    //    print(pos, (n-nl));
    mergesort_dec(neg, nl);
    mergesort_aec(pos, (n - nl));
    //    print(neg, nl);
    //    print(pos, (n-nl));

    i = 0;
    j = 0;
    k = 0;
    while (i < nl && j < (n - nl)) {
        //        if((j) %2 == 0){
        //            A[k++]= pos[j++];
        //        }else{
        //            A[k++] = neg[i++];
        //        }
        A[k] = pos [j];
        A[k + 1] = neg [i];
        k = k + 2;
        i++;
        j++;
    }
    while (i < nl) {
        A[k++] = neg[i++];
    }
    while (j < (n - nl)) {
        A[k++] = pos[j++];
    }

    free(neg);
    free(pos);
    print(A, n);
}

int main() {

    int arr[MAX] = {-6, -5, 0, 4, 5, 6, 1, 2, -4, -3, -2, -1, 3,23,78};
    //    int arr[MAX] = {6, 5, 10, 11, 2, 4, 13, 3, 7, 1, 9, 14, 8};
    int * retA = arr;
    printf("Size of array : %d \n", SIZEOFARRAY(arr));
    print(arr, MAX);
    //MergeSort(arr, 13);


    mergesort_aec(arr, SIZEOFARRAY(arr));
    print(arr, SIZEOFARRAY(arr));
    real_sol(arr, SIZEOFARRAY(arr));
    //    mergesort_dec(arr,13);
    //    print(arr, 13);
    return 0;
}
