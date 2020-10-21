/**
 * 描述：找出二维数组的某个峰值
 * 要求：a[i][j]>=a[i-1][j] && a[i][j]>=a[i+1][j] && a[i][j]>=a[i1][j-1] && a[i][j]>=a[i1][j+1]
 * 其中(边界外侧为==负无穷) a[-1][*]==负无穷,a[n][*]==负无穷,a[*][-1]==负无穷,a[*][n]==负无穷,所以二维数组的峰值必然存在
 * 
 * 方法一：暴力法，遍历元素，与上下左右比较
 * 方法二：暴力法，算出每行的最大值放入一个一维辅助数组。辅助数组中的峰值，即为一个峰值。
 * 方法三：分治法，时间复杂度nlogn
 * 方法四：分治法，田字处理，时间复杂度n；这种算法实现略；情况分类比较复杂，边界处理比较麻烦。
 * 边界处理，可以考虑在边界加一层小于所有元素的值。
 * 分类，需要考虑田字的上下左右中六种情况.根据六种情况分别对应两种。
 * 处理起来比较麻烦。
 * 
 * author:dacao
 * write_time:2020/10/19
 * GPL
*/

#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <climits>

using namespace std;

void find_vector_max(const vector<int>& v,int& loc);
void find_peak1(const vector<vector<int>>& mountain,map<pair<int,int>,int>& all_peaks, pair<int,int>& peak);
void find_peak2(const vector<vector<int>>& mountain, pair<int,int>& peak);
void find_peak3_recursive(const vector<vector<int>>& mountain, pair<int,int>& peak,int up,int down);
void find_peak3(const vector<vector<int>>& mountain, pair<int,int>& peak);
// void find_tian_max(const vector<vector<int>>& mountain,pair<int,int>& tian_max,int left,int right,int up,int down);
// void find_peak4_recursive(const vector<vector<int>>& mountain, pair<int,int>& peak,int left,int right,int up,int down);
// void find_peak4(const vector<vector<int>>& mountain, pair<int,int>& peak);
void FindPeak(const vector<vector<int>>& mountain,map<pair<int,int>,int>& all_peaks, pair<int,int>& peak,int mod);

int main(void){
    vector<vector<int>> mountain = {
        {9,3,5,2,4,9,8},
        {7,2,5,1,4,0,3},
        {9,8,9,3,2,4,8},
        {7,6,3,1,3,2,3},
        {9,0,6,0,4,6,4},
        {8,9,8,0,5,3,0},
        {2,1,2,1,1,1,1}
    };
    pair<int,int> peak;//记录峰值位置
    map<pair<int,int>,int> all_peaks;//记录所有峰值位置

    // FindPeak(mountain,all_peaks,peak,1);
    // for(map<pair<int,int>,int>::iterator iter=all_peaks.begin(); iter!=all_peaks.end(); iter++){
    //     printf("the peak location is (%d,%d), heigh is %d\n",iter->first.first,iter->first.second,mountain[iter->first.first][iter->first.second]);
    // }
    
    // 这里可以看到，all_peaks传进去，也没啥用。但我如何不传？
    // 因为我用的都是引用。用c指针重写，完全可以，但是比较麻烦。
    // 有啥好办法呢，我不知奥哎:函数重载，可选参数，都不太方便。。
    // FindPeak(mountain,NULL,peak,2);
    // FindPeak(mountain,all_peaks,peak,2);

    FindPeak(mountain,all_peaks,peak,3);

    // FindPeak(mountain,all_peaks,peak,4);
    printf("the peak location is (%d,%d), heigh is %d\n",peak.first,peak.second,mountain[peak.first][peak.second]);

    return 0;
}

void FindPeak(const vector<vector<int>>& mountain,map<pair<int,int>,int>& all_peaks, pair<int,int>& peak,int mod){
    // 方法一：暴力法，比较上下左右
    if(mod==1){
        find_peak1(mountain,all_peaks,peak);
    }else if(mod==2){
        find_peak2(mountain,peak);
    }else if(mod==3){
        find_peak3(mountain,peak);
    }
    // }else if(mod==4){
    //     find_peak4(mountain,peak);
    // }
    
}

void find_peak1(const vector<vector<int>>& mountain,map<pair<int,int>,int>& all_peaks, pair<int,int>& peak){
    // 方法一：暴力法，与上下左右比较
    // 比较得出所有峰值:all_peaks中记录所有峰值，peak中记录最后一个查到的峰值
    // 如果不需要存储所有的峰值，all_peaks传入NULL
    // 时间复杂度O(n*m)
    // 注释：每个vecotr<int>的长度相同。代码中没有用逻辑去判断。当然也可以去做，添加一个辅助的一维向量就好。
    for(int i=0; i<mountain.size();i++){
        for(int j=0; j< mountain[i].size(); j++){
            // 这个判断条件太长了，可读性比较差，这里备注下。
            //( (【左边存在且大于左边】||左边不存在) && (【右边存在且大于右边】||右边不存在) )
            // 同理，比较上下元素
            if( (((j-1)>=0 && (mountain[i][j]>=mountain[i][j-1]))||((j-1)<0)) && 
                (((j+1)<mountain[i].size() && (mountain[i][j]>=mountain[i][j+1]))||((j+1)>=mountain[i].size())) &&
                (((i-1)>=0 && (mountain[i][j]>=mountain[i-1][j]))||((i-1)<0)) &&
                (((i+1)<mountain.size() && (mountain[i][j]>=mountain[i+1][j]))||((i+1)>=mountain.size()))
                ){
                    peak.first = i;
                    peak.second = j;
                    if(&all_peaks!=nullptr)
                        all_peaks[peak] = 1;
                }
        }
    }
}

void find_peak2(const vector<vector<int>>& mountain, pair<int,int>& peak){
    // 方法二：暴力法，算出每行的最大值放入一个一维辅助数组。辅助数组中的峰值，即为一个峰值。
    // 为了保存位置信息，添加一个报错每行最大值位置的一维数组
    // 注释：每个vecotr<int>的长度相同。代码中没有用逻辑去判断。当然也可以去做，添加一个辅助的一维向量就好。
    vector<int> row_max(mountain.size(),0);
    vector<int> row_max_from_loc(row_max.size(),0);
    int tmp_loc;
    for(int i=0; i<mountain.size(); i++){
        find_vector_max(mountain[i],tmp_loc);
        row_max[i] = mountain[i][tmp_loc];
        row_max_from_loc[i]=tmp_loc;
    }
    find_vector_max(row_max,tmp_loc);//这里可以借用一维峰值的处理。我嫌麻烦，直接求个最大值。
    peak.first=tmp_loc;
    peak.second=row_max_from_loc[tmp_loc];
}


void find_peak3(const vector<vector<int>>& mountain, pair<int,int>& peak){
    find_peak3_recursive(mountain,peak,0,mountain.size());
}

void find_peak3_recursive(const vector<vector<int>>& mountain, pair<int,int>& peak,int up,int down){
    // 分治法，每次分一半
    // 二维向量按行处理比较容易。
    int tmp_loc;
    int mid = (up+down)>>1;
    find_vector_max(mountain[mid],tmp_loc);
    // 必然有解，不用担心递归没有出口
    if( ((mid-1>0)&&(mountain[mid][tmp_loc]>mountain[mid-1][tmp_loc])||(mid==0)) &&
        ((mid+1<mountain.size())&&(mountain[mid][tmp_loc]>mountain[mid+1][tmp_loc])||(mid==mountain.size()))
    ){
        peak.first=mid;
        peak.second=tmp_loc;
        return;
    }else if(mountain[mid][tmp_loc]<mountain[mid-1][tmp_loc]){
        find_peak3_recursive(mountain,peak,up,mid);
    }else{
        find_peak3_recursive(mountain,peak,mid+1,down);
    }
}


// void find_peak4(const vector<vector<int>>& mountain, pair<int,int>& peak){
//     find_peak4_recursive(mountain,peak,0,mountain[0].size()-1,0,mountain.size()-1);
// }
/**我注释掉这个代码是因为，考虑不全面：应当按照上下左右中六种情况考虑田子的走向**/
// void find_peak4_recursive(const vector<vector<int>>& mountain, pair<int,int>& peak,int left,int right,int up,int down){
//     pair<int,int> tian_max;
//     find_tian_max(mountain,tian_max,left,right,up,down);
//     int i=tian_max.first,j=tian_max.second;
//     int tmp_max = mountain[i][j];
//     // 要考虑边界条件，麻烦;从上面暴力破解的判断条件复制下
//     // 同时为了把边框包含进入，脑子转不过来弯，边界都放大一行处理
//     if( (((j-1)>=0 && (mountain[i][j]>=mountain[i][j-1]))||((j-1)<0)) && 
//         (((j+1)<mountain[i].size() && (mountain[i][j]>=mountain[i][j+1]))||((j+1)>=mountain[i].size())) &&
//         (((i-1)>=0 && (mountain[i][j]>=mountain[i-1][j]))||((i-1)<0)) &&
//         (((i+1)<mountain.size() && (mountain[i][j]>=mountain[i+1][j]))||((i+1)>=mountain.size()))
//         ){
//             peak.first=i;
//             peak.second=j;
//             return;
//     }else if((j-1)>=0 && (mountain[i][j]<mountain[i][j-1])){
//         // 小于上半部分
//         if(i < (left+right)/2 )//在左上角画田字
//             find_peak4_recursive(mountain,peak,left,(left+right)/2+1,up,(up+down)/2-1);
//         else//在右上角画田字
//             find_peak4_recursive(mountain,peak,(left+right)/2-1,right,up,(up+down)/2-1);
//     }else{
//         // 在下半部分
//         if(i < (left+right)/2 )//在左下角画田字
//             find_peak4_recursive(mountain,peak,left,(left+right)/2+1,(up+down)/2+1,down);
//         else//在右下角画田字
//             find_peak4_recursive(mountain,peak,(left+right)/2-1,right,(up+down)/2-1,down);
//     }
// }

// void find_tian_max(const vector<vector<int>>& mountain,pair<int,int>& tian_max,int left,int right,int up,int down){
//     // 这里的tian是拼音；找出田中的最大值的坐标
//     int max=INT32_MIN;
//     for(int i=left;i<=right;i++){
//         if(mountain[up][i]>max){
//             max=mountain[up][i];
//             tian_max.first=up;
//             tian_max.second=i;
//         }
//         if(mountain[down][i]>max){
//             max=mountain[down][i];
//             tian_max.first=down;
//             tian_max.second=i;
//         }  
//         if(mountain[(up+down)>>1][i]>max){
//             max=mountain[(up+down)>>1][i];
//             tian_max.first=(up+down)>>1;
//             tian_max.second=i;
//         }  
//     }
//     for(int i=up;i<=down;i++){
//         if(mountain[left][i]>max){
//             max=mountain[left][i];
//             tian_max.first=i;
//             tian_max.second=left;
//         }
//         if(mountain[right][i]>max){
//             max=mountain[right][i];
//             tian_max.first=i;
//             tian_max.second=right;
//         }  
//         if(mountain[(left+right)>>1][i]>max){
//             max=mountain[(left+right)>>1][i];
//             tian_max.first=i;
//             tian_max.second=left+right;
//         }  
//     }
// }

void find_vector_max(const vector<int>& v,int& loc){
    // 返回最大值位置
    int max = INT32_MIN;
    for(int i=0; i<v.size(); i++)
        if(v[i]>max){
            max=v[i];
            loc=i;
        }        
}



