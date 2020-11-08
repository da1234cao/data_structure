#include <iostream>
#include <vector>
#include "max_heap.h"

using namespace std;

int main(void){
    vector<int> heap={16,4,10,14,7,9,3,2,8,1};

    print_max_heap(heap);
    max_heap_sort(heap);
    print_max_heap(heap);

    return 0;
}