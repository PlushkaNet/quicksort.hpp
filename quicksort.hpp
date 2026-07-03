// SPDX-License-Identifier: MIT
/*
 * Copyright (C) 2026 PlushkaNet (github.com/PlushkaNet)
 */

namespace qs {
    template <typename T>
    void memswap(T *a, T *b) {
        T c = *a;
        *a = *b;
        *b = c;
    }

    template <typename T>
    void quicksort_s(T *arr, int start, int end) { // [start, end)
        if((end-start) <= 1) return;
        T pivot = arr[(start+end)/2];
        int i = start;
        for(int j = start; j < end; j++) {
            if(arr[j] < pivot)
                memswap<T>(&arr[i++], &arr[j]);
        }
        quicksort_s<T>(arr, start, i);
        for(int j = i; j < end; j++) {
            if(arr[j] == pivot)
                memswap<T>(&arr[i++], &arr[j]);
        }
        quicksort_s<T>(arr, i, end);
    }

    template <typename T>
    bool is_sorted(T *arr, int len) {
        if(len <= 1) return true;
        for(int i = 1; i < len; i++) {
            if(arr[i-1] > arr[i]) return false;
        }
        return true;
    }

    template <typename T>
    void reverse(T *arr, int len) {
        if(len <= 1) return;
        for(int i = 0; i < (len/2); i++) {
            memswap(&arr[i], &arr[len-i-1]);
        }
    }

    template <typename T>
    bool is_sorted_reverse(T *arr, int len) {
        if(len <= 1) return true;
        for(int i = len-1; i > 0; i--) {
            if(arr[i] > arr[i-1]) return false;
        }
        return true;
    }

    template <typename T>
    void quicksort(T *arr, int len) {
        quicksort_s<T>(arr, 0, len);
    }
}
