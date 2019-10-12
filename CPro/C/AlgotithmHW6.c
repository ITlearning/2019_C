#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int A[], int p, int q, int r) {
    int i = p; int j = q+1; int t = 1; int tmp[r];
    while(i <= q && j <= r) {
        if(A[i] <= A[j]) {
            tmp[t++] = A[i++];
        }else {
            tmp[t++] = A[j++];
        }
    }
    while(i <= q) {
        tmp[t++] = A[i++];
    }
    while(i <= r) {
        tmp[t++] = A[j++];
    }
    i = p; t = 1;
    while(i <= r) {
        A[i++] = tmp[t++];
    }

}

void mergeSort(int A[], int p, int r) {
    if(p < r) {
        int q = (p+r)/2;
        mergeSort(A,p,q);
        mergeSort(A,q+1,r);
        merge(A,p,q,r);
    }
}

int main() {
    int mergeInput[100000], quickInput[100000];
    srand(time(NULL));

    for(int i = 0; i < 10; i++) {
        int random = rand() % 30000;
        mergeInput[i] = random;
        quickInput[i] = random;
    }
    mergeSort(mergeInput,0,10);
    for(int i = 0; i < 10; i++) {
        printf("%d ",mergeInput[i]);
    }
}