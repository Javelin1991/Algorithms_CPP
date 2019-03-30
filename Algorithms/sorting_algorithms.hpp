//
//  sorting_algorithms.hpp
//  Algorithms
//
//  Created by HTET NAING on 3/10/19.
//  Copyright © 2019 com.Javelin. All rights reserved.
//

#ifndef sorting_algorithms_hpp
#define sorting_algorithms_hpp

#include <stdio.h>
#include <vector>
#include <iterator>

using std::vector; using std::iterator;

vector<int> bubbleSort(vector<int>);
vector<int> insertionSort(vector<int>);
vector<int> selectionSort(vector<int>);
void mergeSort(vector<int>& A);
void merge(vector<int>& A, vector<int>& left_array, vector<int>& right_array);
void mergeSort_V2(vector<int>& A, int left, int right);
void merge_V2(vector<int>& A, int l, int r);

#endif /* sorting_algorithms_hpp */
