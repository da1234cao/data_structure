/**
 * 测试my_BSTree.h头文件
*/

#include <iostream>
#include <vector>
#include "my_BSTree.h"

using namespace std;

int main(void){
    vector<int> v = {2,5,8,4,7,1}; 
    BSTree<int> bst;

    cout<<"构造二叉树!!"<<endl;
    for(int i=0; i<v.size(); i++){
        bst.insert(v[i]);
    }

    cout<<"先序遍历二叉树：";
    bst.preOrder();
    cout<<endl;
    cout<<"中序遍历二叉树：";
    bst.inOrder();
    cout<<endl;
    cout<<"后序遍历二叉树：";
    bst.postOrder();
    cout<<endl;

    return 0;
}