/**
 * 自行写二叉树类
 * 简单起见，头文件中使用using namespace std;
 * 来源地址：https://www.cnblogs.com/skywang12345/p/3576373.html
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
    BSTreeNode<T>* search(BSTreeNode<T>* tree,T key);
    BSTreeNode<T>* iterativeSearch(BSTreeNode<T>* tree,T key);
    BSTreeNode<T>* minnum(BSTreeNode<T>* tree);
    BSTreeNode<T>* maxnum(BSTreeNode<T>* tree);

public:
    BSTree(){}
    ~BSTree(){}
    void insert(T key); //插入
    void destroy(); // 销毁
    void preOrder(); // 先序遍历
    void inOrder(); // 中序遍历
    void postOrder(); // 后序遍历
    BSTreeNode<T>* search(T key); // 查找
    BSTreeNode<T>* iterativeSearch(T key); // 递归查找
    T minnum(); // 最小值
    T maxnum(); // 最大值

    // public中的函数，将private中的函数封装一次有什么好处?
    // 好处在于：树是由树构成的，部分连续子集仍然是树
    // 稍微有点麻烦的是下面三个：前驱节点，后继结点，删除

    // 找结点(x)的后继结点。即，查找"二叉树中数据值大于该结点"的"最小结点"。
    BSTreeNode<T>* successor(BSTreeNode<T> *x);
    // 找结点(x)的前驱结点。即，查找"二叉树中数据值小于该结点"的"最大结点"。
    BSTreeNode<T>* predecessor(BSTreeNode<T> *x);
    // 删除结点(key为节点键值)
    BSTreeNode<T>* remove(BSTreeNode<T>* tree,T key);

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


// 二叉搜索树树查找
template<class T>
BSTreeNode<T>* BSTree<T>::search(BSTreeNode<T>* tree,T key){
    BSTreeNode<T>* x=tree;
    while(x!=nullptr && x->key!=key){
        if(key < x->key)
            x=x->left;
        else
            x=x->right;
    }
    return x;
}

template<class T>
BSTreeNode<T>* BSTree<T>::search(T key){
    return search(tree,key);
}

// 二叉搜索树树递归查找
template<class T>
BSTreeNode<T>* BSTree<T>::iterativeSearch(BSTreeNode<T>* tree,T key){
    if(tree==nullptr || tree->key == key)
        return tree;
    if(key < tree->key)
        return iterativeSearch(tree->left,key);
    else
        return iterativeSearch(tree->right,key);
}

template<class T>
BSTreeNode<T>* BSTree<T>::iterativeSearch(T key){
    iterativeSearch(tree,key);
}

template<class T>
BSTreeNode<T>* BSTree<T>::minnum(BSTreeNode<T>* tree){
    BSTreeNode<T>* x=tree;
    while(x->left != nullptr)
        x=x->left;
    return x;
}

template<class T>
T BSTree<T>::minnum(){
    BSTreeNode<T>* x=minnum(tree);
    return x->key;
}

template<class T>
BSTreeNode<T>* BSTree<T>::maxnum(BSTreeNode<T>* tree){
    BSTreeNode<T>* x=tree;
    while(x->right != nullptr)
        x=x->right;
    return x;
}

template<class T>
T BSTree<T>::maxnum(){
    BSTreeNode<T>* x=maxnum(tree);
    return x->key;
}

/**
 * 前驱节点:
 * 若一个节点有左子树，那么该节点的前驱节点是其左子树中val值最大的节点（也就是左子树中所谓的rightMostNode）
 * 若一个节点没有左子树，那么判断该节点和其父节点的关系
 *  2.1 若该节点是其父节点的右边孩子，那么该节点的前驱结点即为其父节点。
 *  2.2 找到>这种形状。该节点的父节 是 该节点的祖父节点的右孩子；不是的继续上找，找到>形状
 *  2.3 合并：2.1和2.2合并，同是找到左上形状(\)的节点
*/
template<class T>
BSTreeNode<T>* BSTree<T>::predecessor(BSTreeNode<T>* x){
    if(x==nullptr)
        return nullptr;

    if(x->left!=nullptr)
        return maxnum(x->left);

    BSTreeNode<T>* p = x->parent;
    // 按照2.3思路:当跳出循环的时候，找到(\)||没找到nullptr
    while(p!=nullptr && x==p->left){
        x=p;
        p=p->parent;
    }
    return p;
}


/**
 * 后继节点
 * 1.有右子树，右子树中的最小值
 * 2.没有右子树，向上找到"/"形状
*/
template<class T>
BSTreeNode<T>* BSTree<T>::successor(BSTreeNode<T>* x){
    if(x==nullptr)
        return nullptr;
    if(x->right!=nullptr)
        return minnum(x->right);
    BSTreeNode<T>* p = x->parent;
    while((p!=nullptr) && (x==p->right)){
        x=p;
        p=p->parent;
    }
    return p;
}

/**
 * 如果是叶子节点，直接删除
 * 如果只有左孩子或者只有右孩子，删除节点后，剩下的拼接
 * 如果有左右孩子。删除节点的前驱[后继]，用前驱[后继]代替原位置，删除前驱[后继]。迭代执行。
*/
template<class T>
BSTreeNode<T>* BSTree<T>::remove(BSTreeNode<T>* tree,T key){
    // 查找该节点的位置
    BSTreeNode<T>* inode = search(T);
    if(inode==nullptr)
        return nullptr;

    if(inode->left==nullptr && inode->right==nullptr){
        delete(inode);
        inode=nullptr;
        return nullptr;
    }

    if(inode->left==nullptr && inode->right!=nullptr){
        
    }

}

#endif