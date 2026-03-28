#include <stdio.h>

int sequentialSearch(int a[], int n, int x) {
    int i = 0;
    int found = 0;
    while (i < n && found == 0) {
        if (x == a[i]) {
            found = 1;
        } else {
            i++;
        }
    }
    return found;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5, x = 30;
    if (sequentialSearch(arr, n, x))
        printf("Found!\n");
    else
        printf("Not Found!\n");
    return 0;
}