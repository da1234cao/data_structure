/**
 * 描述：快速排序
*/

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int Partion(vector<int>& v, int low,int high);
int RandomPartion(vector<int>& v, int start, int end);
void RandomQuickSort(vector<int>& v, int start,int end);

int main(void){
    int vector_size=10;
    vector<int> v(vector_size);
    srand((unsigned)time(NULL));
    for(int i=0; i< v.size(); i++){
        v[i]=rand()%100;
    }

    RandomQuickSort(v,0,v.size()-1);

    for(int i=0;i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return 0;
}

void RandomQuickSort(vector<int>& v, int start,int end){
    if(start<end){
        int p = RandomPartion(v,start,end);
        RandomQuickSort(v,start,p-1);
        RandomQuickSort(v,p+1,end);
    }
}

int RandomPartion(vector<int>& v, int start, int end){
    int random_loc = start+rand()%(end-start+1);
    swap(v[start],v[random_loc]);
    return Partion(v,start,end);
}

int Partion(vector<int>& v, int low,int high){
    // 这种写法，是严蔚敏《数据结构》中的写法，很容易理解
    int pivot = v[low];
    while(low<high){
        while(low<high && v[high]>=pivot)
            high--;
        v[low]=v[high];
        while(low<high && v[low]<=pivot)
            low++;
        v[high]=v[low];
    }
    v[low]=pivot;
    return low;
}

/**
 * 这是算法导论中的写法，我看半天没看懂。
 * 调试了下，才明白。。
*/
// int Partition(int* Array, int start, int end)
// {
// 	int pivot = start,j;
// 	for(j = start + 1; j <= end; j++)
// 		if(Array[j] <= Array[start])
// 		{
// 			pivot++;
// 			swap(&Array[pivot], &Array[j]);
// 		}
// 	swap(&Array[start], &Array[pivot]);
// 	return pivot;
// }