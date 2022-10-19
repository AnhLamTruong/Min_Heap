#include <iostream>
#include "Min_Heap.h"
using namespace std;
int main() {
    Min_Heap h(12);
    h.insert_value(3);
    h.insert_value(2);
    h.delete_Key(1);
    h.insert_value(15);
    h.insert_value(5);
    h.insert_value(4);
    h.insert_value(45);
    h.insert_value(34);
    cout<<h.pop_Min()<<" "<<endl;
    cout<<h.get_Min()<< " "<<endl;
    h.decrease_index_value(2,1);
    h.delete_Key(1);
    cout<<h.get_Min();

//    cout << "Hello, World!" << endl;
    return 0;
}
