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
