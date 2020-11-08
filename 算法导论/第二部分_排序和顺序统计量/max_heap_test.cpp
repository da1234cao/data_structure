#include <iostream>
#include <vector>
#include "max_heap.h"

using namespace std;

int main(void){
    vector<int> map={16,4,10,14,7,9,3,2,8,1};

    print_max_heap(map);
    max_heap_sort(map);
    print_max_heap(map);

    return 0;
}