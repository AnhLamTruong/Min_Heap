//
// Created by STSC on 10/18/2022.
//

#ifndef MIN_HEAP_MIN_HEAP_H
#define MIN_HEAP_MIN_HEAP_H
#include <iostream>
#include <bits/stdc++.h>
#include <queue> //stl library

using namespace std;

class Min_Heap {
    int *heap_arr; //Dynamic array
    int capacity; //Maximum possible size of min heap
    int heap_size; //Current elements in min heap
public:
    //Constructor
    Min_Heap(int capacity);
    //To Heapify a subtree with the root a index given
    //To access reHeapUp or reHeapDown
    void Min_Heapify(int index);
    void print_Array();
    // To get the parent or left or right index
    int parent(int index){return (index-1)/2;};
    int left(int index){return (index*2+1);};
    int right(int index){return (index*2+2);};

    // To get the min element from the array
    int pop_Min();
    // To get the min element from the array WITHOUT removing it
    int get_Min(){return heap_arr[0];}

    //Decrease the value to the new values at index ...
    void decrease_index_value(int index, int new_val);

    //Delete from index
    void delete_Key(int index);

    //Insert a new value
    void insert_value(int val);

    void swap(int *x, int *y);

};


#endif //MIN_HEAP_MIN_HEAP_H
