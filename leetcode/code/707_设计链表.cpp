#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class MyLinkedList {
public:
    /** 定义节点*/
    struct LinkNode{
        int val;
        LinkNode* next;
        LinkNode* prev;
        LinkNode() : val(0), next(nullptr),prev(nullptr) {}
        LinkNode(int x) : val(x), next(nullptr),prev(nullptr) {}
    };

    /** Initialize your data structure here. */
    MyLinkedList() {
        head = new LinkNode();
        head->next = head;
        head->prev = head;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        LinkNode* it = head->next;
        int i=0;
        for(; it!=head && i<index; it=it->next,i++){
            ;
        }
        if(it != head && i==index)
            return it->val;
        else
            return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        LinkNode* addNode = new LinkNode(val);
        LinkNode* headNext = head->next;
        
        head->next = addNode;
        addNode->prev = head;
        addNode->next = headNext;
        headNext->prev = addNode;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        // 我让数据结构为双链表的好处来了。插入尾部的时候，等效与插在head之前
        LinkNode* addNode = new LinkNode(val);
        LinkNode* headPrev = head->prev;
        
        head->prev = addNode;
        addNode->next = head;
        addNode->prev = headPrev;
        headPrev->next = addNode;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        LinkNode* it = head->next;
        int i=0;
        while(it!=head && i<index){
            it = it->next;
            i++;
        }
        if(it!=head && i==index){// 插入在链表内
            LinkNode* addNode = new LinkNode(val);
            LinkNode* itPrev = it->prev;

            itPrev->next = addNode;
            addNode->next = it;
            it->prev = addNode;
            addNode->prev = itPrev;
            return;
        }
        if(it==head && i==index){ // 插在尾部
            this->addAtTail(val);
            return;
        }
        // 超出范围了，咱不干了
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        LinkNode* it = head->next;
        int i=0;
        while(it!=head && i<index){
            it = it->next;
            i++;
        }
        if(it!=head && i==index){ // 在链表范围内
            LinkNode* itPre = it->prev;
            LinkNode* itNext = it->next;

            itPre->next = itNext;
            itNext->prev = itPre;
            delete it;
        }
        // 超出范围
    }

private:
    LinkNode* head; // 头节点不存储元素
    // 不添加size属性了，也不用head的val来存储，避免引入复杂度
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main(void){

    MyLinkedList* linkedList = new MyLinkedList();
    linkedList->addAtHead(1);
    linkedList->addAtTail(3);
    linkedList->addAtIndex(1,2);//链表变为1-> 2-> 3
    for(int i=0; i<3; i++)
        cout<<linkedList->get(i)<<" ";            
    linkedList->deleteAtIndex(1);  //现在链表是1-> 3
    cout<<linkedList->get(1)<<" ";            //返回3
}