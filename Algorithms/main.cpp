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

using namespace std;

vector<int> bubbleSort(vector<int>);
vector<int> getInputArray();
void printArray(vector<int>);
void getChoice();

int main(int argc, const char * argv[]) {
    int choice; bool invalid = false;
    vector<int> A;
    cout << "Please select one category below: " << endl;
    cout << "1: Bubble Sort" << endl;
    cout << "2: Insertion Sort" << endl;
    cout << "3: Selection Sort" << endl;
    cout << "4: Merge Sort" << endl;
    cout << "5: Quick Sort" << endl;

    do {
        cin >> choice;
        A = getInputArray();
        switch(choice) {
            case 1:
                cout << "Running bubble sort..." << endl;
                A = bubbleSort(A);
                break;
            case 2:
                cout << "Running insertion sort..." << endl;
                A = insertionSort(A);
                break;
            case 3:
                cout << "Running selection sort..." << endl;
                A = selectionSort(A);
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                invalid = true;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please try again." << endl;
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
    cout << "After sorting: " << endl;
    for(int i : A) {
        cout << i << " ";
    }
    cout << endl;
}

