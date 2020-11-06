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

    cout<<"开始，构造二叉搜索树!!"<<endl;
    for(int i=0; i<v.size(); i++){
        bst.insert(v[i]);
    }

    cout<<"先序遍历二叉搜索树：";
    bst.preOrder();
    cout<<endl;
    cout<<"中序遍历二叉搜索树：";
    bst.inOrder();
    cout<<endl;
    cout<<"后序遍历二叉搜索树：";
    bst.postOrder();
    cout<<endl;

    cout<<"二叉搜索树查找：";
    if(bst.search(8)!=nullptr){
        cout<<"查找到元素"<<endl;
    }else{
        cout<<"未查找到元素"<<endl;
    }
    cout<<"二叉搜索树查找：";
    if(bst.iterativeSearch(8)!=nullptr){
        cout<<"递归查找到元素"<<endl;
    }else{
        cout<<"递归未查找到元素"<<endl;
    }

    cout<<"二叉搜索树最小值：";
    cout<<bst.minnum()<<endl;
    cout<<"二叉搜索树最大值：";
    cout<<bst.maxnum()<<endl;
    
    cout<<"二叉树元素前驱查找:";
    BSTreeNode<int>* pre = bst.predecessor( (bst.search(4)) );
    if(pre!=nullptr)
        cout<<pre->key<<endl;
    else
        cout<<"没有前驱"<<endl;

    cout<<"二叉树元素后继查找:";
    BSTreeNode<int>* suc = bst.successor( (bst.search(4)) );
    if(suc!=nullptr)
        cout<<suc->key<<endl;
    else
        cout<<"没有后继"<<endl;

    bst.destroy();
    cout<<"结束，销毁二叉搜索树!!"<<endl;
    return 0;
}