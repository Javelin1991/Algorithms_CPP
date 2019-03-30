//
//  main.cpp
//  Algorithms
//
//  Created by HTET NAING on 3/10/19.
//  Copyright © 2019 com.Javelin. All rights reserved.
//

#include <iostream>
#include <iterator>
#include <array>
#include <vector>
#include "sorting_algorithms.hpp"
#include <stdlib.h>

using std::iterator; using std:: vector;
using std::cin; using std::cout;

vector<int> getInputArray();
void printArray(vector<int>);
void getChoice();

int main(int argc, const char * argv[]) {
    int choice; bool invalid = false;
    vector<int> A;
    cout << "Please select one category below: " << '\n';
    cout << "1: Bubble Sort" << '\n';
    cout << "2: Insertion Sort" << '\n';
    cout << "3: Selection Sort" << '\n';
    cout << "4: Merge Sort" << '\n';
    cout << "5: Quick Sort" << '\n';
    do {
        cin >> choice;
        A = getInputArray();
        int left = 0;
        int right = A.size()-1;
        switch(choice) {
            case 1:
                cout << "Running bubble sort..." << '\n';
                A = bubbleSort(A);
                break;
            case 2:
                cout << "Running insertion sort..." << '\n';
                A = insertionSort(A);
                break;
            case 3:
                cout << "Running selection sort..." << '\n';
                A = selectionSort(A);
                break;
            case 4:
                cout << '\n';
                cout << "Please select one merge sort below " << '\n';
                cout << "1: Merge sort with the help of extra memory " << '\n';
                cout << "2: Merge sort with in-place merging " << '\n';
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                int select;
                cin >> select;
                if (select == 1) {
                    cout << '\n';
                    cout << "Running merge sort with the help of extra memory..." << '\n';
                    mergeSort(A);
                } else {
                    cout << '\n';
                    cout << "Running merge sort with in-place merging..." << '\n';
                    mergeSort_V2(A, left, right);
                }
                break;
            case 5:
                break;
            default:
                invalid = true;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid input. Please try again." << '\n';
        }
    } while (invalid);
    printArray(A);
    return 0;
}

vector<int> getInputArray() {
    vector<int> A;
    int input;
    cout << "Please enter input array separarted by a space: ";
    while(cin >> input) {
        A.push_back(input);
    }
    return A;
}

void printArray(vector<int> A) {
    cout << "After sorting: " << '\n';
    for(int i : A) {
        cout << i << " ";
    }
    cout << '\n';
}
