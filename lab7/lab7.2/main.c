#include <stdio.h>
#define MAX_LEN 100

void selectionSort(int V[], int N);
void shellSort(int V[], int N);
void insertionSort(int V[], int N);

int main() {
    FILE *fp;
    int matrix[MAX_LEN][MAX_LEN], S, i, j, len;

    fp = fopen("../sort.txt", "r");
    if (fp == NULL)
        return 1;
    fscanf(fp, "%d", &S);

    for (i=0;i<S;i++){
        fscanf(fp, "%d", &len);
        for (j=0;j<len;j++)
            fscanf(fp, "%d ", &matrix[i][j]);
        insertionSort(matrix[i], len);
        selectionSort(matrix[i], len);
        shellSort(matrix[i], len);
    }
    fclose(fp);
    return 0;
}


void selectionSort(int V[], int N){
    int i, j, temp, min, swap=0, outit=0, innit=0, total=0;

    for(i=0;i<N-1;i++){
        outit++;
        min = i;
        innit++;
        for (j=i+1;j<N;j++) {
            innit++;
            if (V[j] < V[min])
                min = j;
        }
        total+=innit;
        if (min != i){
            temp = V[min];
            V[min] = V[i];
            V[i] = temp;
            swap++;
        }
    }
    total+=outit;
    printf("\n\nSelection Sort Algorithm\n");
    printf("\n the number of swaps: %d\n"
           " the number of iterations of the outer loop: %d\n"
           " per each iteration of the outer loop, the number of iterations of the inner loop: %d\n"
           " the total number of iterations: %d\n", swap, outit, innit, total);

}

void shellSort(int V[], int N){
    int h=1, i, j, temp, swap=0, outit=0, extra, innit, total=0;
    while (h<N/3)
        h = 3*h+1;
    while (h >= 1){
        outit++;
        extra=0;
        for(i = h; i<N; i++){
            extra++;
            j=i;
            temp = V[i];
            innit=0;
            while (j>= h && temp < V[j-h]){
                V[j] = V[j-h];
                j -= h;
                swap++;
                innit++;
            }
            V[j] = temp;
            total+= innit;
        }
        h /= 3;
        total+=extra;
        outit+=extra;
    }

    printf("\n\nInsertion Sort Algorithm\n");
    printf("\n the number of swaps: %d\n"
           " the number of iterations of the outer loop: %d\n"
           " per each iteration of the outer loop, the number of iterations of the inner loop: %d\n"
           " the total number of iterations: %d\n", swap, outit, innit, total);
}

void insertionSort(int V[], int N){
    int i, j, key,swap=0, outit=0, innit, total=0;

    for (i=1;i<N;i++){
        outit++;
        key = V[i];
        j=i-1;
        innit=0;
        while (j<=0 && V[j]>V[i]){
            V[j+1]=V[j];
            j--;
            innit++;
            swap++;
        }
        total+=innit;
        V[j+1]=key;
        swap++;
    }
    total+=outit;
    printf("\n\nInsertion Sort Algorithm\n");
    printf("\n the number of swaps: %d\n"
           " the number of iterations of the outer loop: %d\n"
           " per each iteration of the outer loop, the number of iterations of the inner loop: %d\n"
           " the total number of iterations: %d\n", swap, outit, innit, total);
}