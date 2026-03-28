int LinearSearch(int a[], int n, int item) {
    int i;
    for (i = 0; i < n; i++) {
        if (a[i] == item) {
            return a[i];
        }
    }
    return -1;
}