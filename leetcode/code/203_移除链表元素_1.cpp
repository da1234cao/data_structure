#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 题目要求的链表，表头包含数据，没关系，传递head->next进来就好

        // 寻找第一个非val节点
        while(head!=nullptr && head->val==val){
            ListNode* nextHead = head->next;
            delete head;
            head = nextHead;
        }

         // 如果是空链表,直接返回
        if(head == nullptr)
            return head;
        
        // 头节点已经是非val了。删除非头结点的其他val
        ListNode* it=head->next; ListNode* beforeIt=head; ListNode* nextIt;
        while(it!=nullptr){
            nextIt = it->next;
            if(it->val == val){
                delete it;
                beforeIt->next = nextIt; // 删除节点会断裂链表，这里给续上;并且beforeIt不需要移动
                it = nextIt;
            }else{
                beforeIt = beforeIt->next;
                it = nextIt;
            }   
        }
        return head;
    }
};


int main(void){
    vector<int> tmpVec = {7,1,7,2,3,5,7,7}; int val = 7;

    ListNode head; // 链表头节点，不存储数据

    ListNode* it = &head;

    // // 初始化一个链表
    //// 最开始敲代码的时候，我是这么写的，但是程序会陷入死循环。我调试的时候，发现it指针不动。
    //// 问题在于，创建node这一局部变量。当再次循环到它时候，使用新的num值，替换原来对象中的值。但仍然是同一个对象，只是里面的值变了而已。这导致next指向了自己。
    //// 根本原因是不是：node在栈中创建之后，循环时变量不会重复分配？？
    // for( auto num : tmpVec){
    //     ListNode node(num);
    //     it->next = &node;
    //     it = it->next;
    // }

    // 初始化一个链表
    for( auto num : tmpVec){
        ListNode* node = new ListNode(num); // 在堆中申请空间
        it->next = node;
        it = it->next;
    }

    // 测试代码
    Solution s;
    it = s.removeElements(head.next,val);
    head.next = it; // removeElements里面察觉不到外面的head，需要给续上

    // 遍历链表
    it = &head;
    for(it; it->next!=nullptr; it=it->next)
        cout<<it->next->val<<" ";
    cout<<endl;

    // 释放链表
    it = &head; it = it->next;  ListNode* nextIt;
    for(; it!=nullptr;){
        nextIt = it->next; // 站在下一个位置，等待干完清除工作后回来
        delete it;
        it = nextIt;
    }
}