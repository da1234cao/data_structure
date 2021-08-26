
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 链表节点之间两两交换

        if(head==nullptr || head->next==nullptr) // 空链表，或链表只包含一个元素，直接返回
            return head;
        
        ListNode *it=head, *itNext, *itNextNext;
        ListNode *result = it->next; // 如果节点个数大于等于2，第二个节点为新的头结点
        while(it != nullptr){
            itNext = it->next; // 当it不为null的时候，itNext才有可能存在，即使itNext为null
            if(itNext != nullptr){
                itNextNext = itNext->next; // 站在下一个待两两交换的位置
                it->next = itNextNext; // 链表交换节点
                itNext->next = it;
                it = itNextNext; // 前往下一个位置
            }else{ // 待交换的第二个节点为空，此次两两交换只存在一个节点时，不动它
                ;
            }
        }

        return result; 
    }
};