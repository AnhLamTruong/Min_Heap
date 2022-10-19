//
// Created by STSC on 10/18/2022.
//

#include "Min_Heap.h"



Min_Heap::Min_Heap(int cap) {
    heap_size=0;
    capacity=cap;
    heap_arr=new int[cap];
}

void Min_Heap::Min_Heapify(int index) {
    int l=left(index);
    int r=right(index);
    int smallest= index;
    if (l < heap_size && heap_arr[l] < heap_arr[index])
        smallest = l;
    if (r < heap_size && heap_arr[r] < heap_arr[smallest])
        smallest = r;
    if (smallest != index)
    {
        swap(&heap_arr[index], &heap_arr[smallest]);
        Min_Heapify(smallest);
    }
}

int Min_Heap::pop_Min() {
    if (heap_size <= 0){
        cout<<"\n No values \n";
        return INT_MIN;
    }
    if(heap_size==1){
        heap_size--;
        return heap_arr[0];
    }
    int root=heap_arr[0];
    heap_arr[0]=heap_arr[heap_size-1];
    heap_size--;
    Min_Heapify(0);
    return root;
}

//Decrease value of key at index 'i' to new_val. Assuming that new_val is smaller than heap_arr[i]
void Min_Heap::decrease_index_value(int index, int new_val) {
    heap_arr[index]=new_val;
    while (index != 0 && heap_arr[parent(index)] > heap_arr[index]){
        swap(&heap_arr[index],&heap_arr[parent(index)]);
        index=parent(index);
    }
}

void Min_Heap::delete_Key(int index) {
    decrease_index_value(index, INT_MIN);
    pop_Min();
}

void Min_Heap::insert_value(int val) {
    if (heap_size == capacity) {
        cout << "\n Overflow: Could not do Anything :(\n";
        return;
    }
    //Book keeping
    //Case 1: Insert the new new value at the end
    heap_size++;
    int i = heap_size - 1;
    heap_arr[i] = val;

    //Fix the min heap right away when the rules is violated
    // Parents greater than children
    //Must smaller
    while (i != 0 && heap_arr[parent(i)] > heap_arr[i]){
        swap(&heap_arr[i],&heap_arr[parent(i)]);
        i=parent(i);
    }

}

void Min_Heap::swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
