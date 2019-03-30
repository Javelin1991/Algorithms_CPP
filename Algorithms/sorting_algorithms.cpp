//
//  sorting_algorithms.cpp
//  Algorithms
//
//  Created by HTET NAING on 3/10/19.
//  Copyright © 2019 com.Javelin. All rights reserved.
//

#include "sorting_algorithms.hpp"
#include <vector>
#include <iostream>

using std::vector; using std::cout;

vector<int> bubbleSort(vector<int> A) {
    vector<int>::size_type n = A.size();
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
    vector<int>::size_type n = A.size();
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
    vector<int>::size_type n = A.size();
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

void mergeSort(vector<int>& A) {
    if (A.size() <= 1) {
        return;
    } else {
        vector<int>::size_type mid = A.size() / 2;
        vector<int> left_array;
        vector<int> right_array;

        for (vector<int>::size_type j = 0; j < mid;j++) {
            left_array.push_back(A[j]);
        }
        for (vector<int>::size_type j = mid; j < (A.size()); j++) {
            right_array.push_back(A[j]);
        }
        mergeSort(left_array);
        mergeSort(right_array);
        merge(A, left_array, right_array);
    }
}

void mergeSort_V2(vector<int>& A, int l, int r) {
    if (r == l) {
        return;
    } else {
        int mid = (l+r)/2;
        mergeSort_V2(A, l, mid);
        mergeSort_V2(A, mid+1, r);
        merge_V2(A, l, r);
    }
}

void merge_V2(vector<int>& A, int l, int r) {
    
    if (r == l) {
        return;
    }
    
    int mid = (l+r)/2;
    int start = l;
    int start2 = mid+1;
    
    while(start <= mid && start2 <= r) {
        //when l and r are both zero, but start = 0 and start2 = 1
        //the algorithm will go wrong because, when both l and r are zero
        //it means we should not do anyth since there's only one item left
        // when left index = 0 and right index = 0, it refers to the same item in the array
        if (A[start] < A[start2]) {
            start++;
        } else if (A[start2] < A[start]) {
            int temp = A[start2];
            for(int j=start2; j>start; j--) {
                A[j] = A[j-1];
            }
            A[start] = temp;
            start++;
            start2++;
            mid++;
        } else {
            if (start == mid && start2 == r) {
                return;
            }
            start++;
            int temp = A[start2];
    
            for(int j=start2; j>start; j--) {
                A[j] = A[j-1];
            }
            A[start] = temp;
            start++;
            start2++;
            mid++;
        }
    }
}

void merge(vector<int>& A, vector<int>& left_array, vector<int>& right_array) {
    vector<int>::size_type left = left_array.size();
    vector<int>::size_type right = right_array.size();
    int i = 0, j = 0, k = 0;

    while (j < left && k < right)
    {
        if (left_array[j] <= right_array[k]) {
            A[i] = left_array[j];
            j++;
        }
        else {
            A[i] = right_array[k];
            k++;
        }
        i++;
    }
    while (j < left) {
        A[i] = left_array[j];
        j++; i++;
    }
    while (k < right) {
        A[i] = right_array[k];
        k++; i++;
    }
}
