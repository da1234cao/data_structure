/**
 * 自行写二叉树类
 * 简单起见，头文件中使用using namespace std;
*/
#ifndef MY_BSTREE_H
#define MY_BSTREE_H

#include <iostream>
using namespace std;

template<class T>
class BSTreeNode{
public:
    T key;
    BSTreeNode* left;
    BSTreeNode* right;
    BSTreeNode* parent;
    // 这里类放在public里面
    BSTreeNode(T key,BSTreeNode* left,BSTreeNode* right,BSTreeNode* parent):
    key(key),left(left),right(right),parent(parent){} 
};

template<class T>
class BSTree{
private:
    BSTreeNode<T>* tree=nullptr;
    void insert(BSTreeNode<T>* inode,BSTreeNode<T>* &tree);
    void destroy(BSTreeNode<T>* &tree);
    void preOrder(BSTreeNode<T>* tree);
    void inOrder(BSTreeNode<T>* tree);
    void postOrder(BSTreeNode<T>* tree);
public:
    BSTree(){}
    ~BSTree(){}
    void insert(T key);
    void destroy();
    void preOrder();
    void inOrder();
    void postOrder();
};

// 插入树节点
template<class T>
void BSTree<T>::insert(BSTreeNode<T>* inode,BSTreeNode<T>* &tree){
    if(tree==nullptr){
        tree = inode;
        return;
    }

    BSTreeNode<T>* x = tree;
    BSTreeNode<T>* y = nullptr;
    while(x!=nullptr){
        y=x; // 因为待插入的节点，不知道其父母在哪
        if(inode->key == x->key)
            return; // 重复值，不插入
        else if(inode->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    if(inode->key < y->key){
        y->left = inode;
        inode->parent = y;
    }else{
        y->right = inode;
        inode->parent = y;
    }

}

template<class T>
void BSTree<T>::insert(T key){
    BSTreeNode<T>* inode = new BSTreeNode<T>(key,nullptr,nullptr,nullptr);
    if(inode == nullptr){
        cout<<"开辟空间失败";
        exit(0);
    }
    insert(inode,tree);
}


// 销毁树
template<class T>
void BSTree<T>::destroy(BSTreeNode<T>* &tree){
    if(tree==nullptr)
        return;//递归出口
    if(tree->left!=nullptr)
        destroy(tree->left);
    if(tree->right!=nullptr)
        destroy(tree->right);
    delete tree;
    tree=nullptr;
}

template<class T>
void BSTree<T>::destroy(){
    destroy(tree);
}


// 先序遍历二叉树:根左右
template<class T>
void BSTree<T>::preOrder(BSTreeNode<T>* tree){
    if(tree==nullptr)
        return;
    cout<<tree->key<<" ";
    if(tree->left!=nullptr)
        preOrder(tree->left);
    if(tree->right!=nullptr)
        preOrder(tree->right);
}

template<class T>
void BSTree<T>::preOrder(){
    preOrder(tree);
}

// 中序遍历二叉树:左根右
template<class T>
void BSTree<T>::inOrder(BSTreeNode<T>* tree){
    if(tree==nullptr)
        return;
    if(tree->left!=nullptr)
        inOrder(tree->left);
    cout<<tree->key<<" ";
    if(tree->right!=nullptr)
        inOrder(tree->right);
}

template<class T>
void BSTree<T>::inOrder(){
    inOrder(tree);
}

// 后序遍历二叉树：左右根
template<class T>
void BSTree<T>::postOrder(BSTreeNode<T>* tree){
    if(tree==nullptr)
        return;
    if(tree->left!=nullptr)
        postOrder(tree->left);
    if(tree->right!=nullptr)
        postOrder(tree->right);
    cout<<tree->key<<" ";
}

template<class T>
void BSTree<T>::postOrder(){
    postOrder(tree);
}

#endif