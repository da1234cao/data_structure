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
    const vector<int> tmpVec = {7,1,7,2,3,5,7,7}; int val = 7;

    ListNode* head = nullptr; // 链表头节点,存储数据
    ListNode* it = head;

    // 初始化一个链表
    if(tmpVec.empty()){
        goto test;
    }

    if(tmpVec.size() >= 1){
        head = new ListNode();
        it = head;
        head->val = tmpVec[0]; // 单独给头结点赋值
        for(int i=1; i<tmpVec.size(); i++){
            ListNode* node = new ListNode(tmpVec[i]); // 在堆中申请空间
            it->next = node;
            it = it->next;
        }
        goto test;
    }

test:

    // 测试代码
    Solution s;
    head = s.removeElements(head,val); // 头结点可能被删除了，这里得到头结点指针

    // 遍历链表
    it = head;
    for(it; it!=nullptr; it=it->next)
        cout<<it->val<<" ";
    cout<<endl;

    // 释放链表
    it = head; ListNode* nextIt;
    for(; it!=nullptr;){
        nextIt = it->next; // 站在下一个位置，等待干完清除工作后回来
        delete it;
        it = nextIt;
    }
}