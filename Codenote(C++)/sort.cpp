void mergesort(int arr[], int size) {
    if (size == 1) return;
    int mid = size / 2;
    mergesort(arr, mid);
    mergesort(arr + mid, size - mid);

    int* buf = new int[size];
    int i = 0; int j = mid; int k = 0;
    while ((i < mid) && (j < size)) {
        buf[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
    }

    while (i < mid) buf[k++] = arr[i++];
    while (j < size) buf[k++] = arr[j++];

    for (int i = 0; i < size; ++i)
        arr[i] = buf[i];

    delete buf;
}


void quicksort(int arr[], int left, int right) {
    if (left < right) {
        int p = left; int i = left + 1; int j = right;
        while (i <= j) {
            while (arr[p] >= arr[i]) i++;
            while (arr[p] < arr[j]) j--;
            if (i < j)
                swap(arr[i], arr[j]);
        }
        swap(arr[p], arr[j]);

        quicksort(arr, left, j - 1);
        quicksort(arr, j + 1, right);
    }
}
