#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 原空间翻转

        if(head==nullptr || head->next==nullptr) // 如果为空，或者只有一个元素，直接翻转
            return head;
        
        ListNode *it = head, *itNext = head->next, *itNextNext;
        it->next = nullptr;
        while(itNext!=nullptr){
            itNextNext = itNext->next; // 站在后方，等待前面的指针过来
            itNext->next = it; // 指针翻转
            it = itNext; // 指针向前移动
            itNext = itNextNext;
        }

        return it;
    }
};