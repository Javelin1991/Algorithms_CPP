//
//  sorting_algorithms.cpp
//  Algorithms
//
//  Created by HTET NAING on 3/10/19.
//  Copyright © 2019 com.Javelin. All rights reserved.
//

#include "sorting_algorithms.hpp"
#include <vector>
using std::vector;

vector<int> bubbleSort(vector<int> A) {
    size_t n = A.size();
    for(int i=0; i<n-1; i++) {
        bool swapped = false;
        for(int j=0; j<n-i-1; j++) {
            if (A[j] > A[j+1]) {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                swapped = true;
            }
        }
        if (!swapped) return A;
    }
    return A;
}

vector<int> selectionSort(vector<int> A) {
    size_t n = A.size();
    for(int i=0; i<n-1; i++) {
        int min_index = i;
        for(int j=i+1; j<n; j++) {
            if (A[j] < A[min_index]) {
                min_index = j;
            }
        }
        int temp = A[i];
        A[i] = A[min_index];
        A[min_index] = temp;
    }
    return A;
}

vector<int> insertionSort(vector<int> A) {
    size_t n = A.size();
    for(int i=1; i<n; i++) {
        int j = i;
        int key = A[j];
        while (j > 0 && A[j-1] > key) {
            A[j] = A[j-1];
            j--;
        }
        A[j] = key;
    }
    return A;
}
