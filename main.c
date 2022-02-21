#include <stdio.h>

void tri_selection(int[],int);
int schtroumpf(int[], int, int[], int);
void delete(int[], int);

int main() {
    const int n = 6, m = 7;
    int T[n], T2[m], a;
    printf("*********************************** Welcome to TP2 ***********************************\n");
    printf("First fill the array with %d integers\n", n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &T[i]);
    }
    while (1){
        printf("\nEnter number of exercise: ");
        scanf("%d", &a);
        switch (a) {
            case 1: tri_selection(T, n); break;
            case 2:
                printf("Please fill the other array\n");
                for (int i = 0; i < m; i++) {
                    printf("Enter Element %d: ", i);
                    scanf("%d", &T2[i]);
                }
                printf("The schtroumpf is %d", schtroumpf(T, n, T2, m)); break;
            case 4:
                delete(T, n); break;
            default:
                printf("Exercise does not exist"); break;
        }
    }
}

int minimum(int T[], int n, int i) {
    int min = 0;
    for (; i < n; i++) {
        if(min < T[i])
            min = i;
    }
    return min;
}

int permuter(int T[], int i, int j){
    int aux = T[i];
    T[i] = T[j];
    T[j] = aux;
    return T;
}

void write(int T[], int n){
    for (int i = 0; i < n; i++) {
        printf("%d ", T[i]);
    }
}

void tri_selection(int T[],int n){
    printf("\n******************************* Exercise 1: selection sort *******************************\n");
    for (int i = 0; i < n; ++i) {
        int j = minimum(T, n, i);
        permuter(T, i, j);
    }
    write(T, n);
}

void fill(int T[], int n){
    for (int i = 0; i < n; i++) {
        printf("\nEnter Element %d: ", i);
        scanf("%d", T[i]);
    }
}

int schtroumpf(int T[], int n, int T2[], int m){
    printf("\n******************************* Exercise 2: schtroumpf of 2 arrays *******************************\n");
    int s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            s += T[i] * T2[j];
        }
    }

    return s;
}

void delete(int T[], int n){
    printf("\n******************************* Exercise 4: Delete an element in an array *******************************\n");
    int pos;
    printf( " Define the position of the array element where you want to delete: ");
    scanf(" %d", &pos);
    if(pos >= n + 1)
    {
        printf (" \n Deletion is not possible in the array.");
    }
    else
    {
        for(int i = pos - 1; i < n - 1; i++)
        {
            T[i] = T[i + 1];
        }

        printf(" \n The resultant array is: \n");

        // display the final array
        for (int i = 0; i < n - 1; i++)
        {
            printf(" arr[%d] = ", i);
            printf(" %d \n", T[i]);
        }
    }
}
