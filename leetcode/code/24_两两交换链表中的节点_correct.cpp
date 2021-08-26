#include <iostream>
#include <vector>

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
    ListNode* swapPairs(ListNode* head) {
        // 链表节点之间两两交换

        if(head==nullptr || head->next==nullptr) // 空链表，或链表只包含一个元素，直接返回
            return head;
        
        // 变量名含义：当前交换组的第一、第二元素；前一组的交换后的第二个元素，后一组交换前的第一个元素
        ListNode *groupOne=head, *groupTwo=nullptr; 
        ListNode *prevGroupTwo=nullptr, *nextGroupOne=nullptr;

        ListNode *result = head->next; // 如果节点个数大于等于2，第二个节点为新的头结点
        while(groupOne != nullptr){
            groupTwo = groupOne->next; 
            if(groupTwo != nullptr){
                nextGroupOne = groupTwo->next; // 站在下一个待两两交换的位置
                groupOne->next = nextGroupOne; // 链表交换节点
                groupTwo->next = groupOne; // 链表交换节点
                if(prevGroupTwo != nullptr)
                    prevGroupTwo->next = groupTwo; // 修正前一组的指针指向
                prevGroupTwo = groupOne; // 前往下一个位置.因为当前组的第一个位置，已经被交换到第二个位置(作为前一组的第二个位置)。
                groupOne = nextGroupOne; // 前往下一个位置
            }else{ // 待交换的第二个节点为空，此次两两交换只存在一个节点时，不动它
                break;
            }
        }

        return result; 
    }
};

int main(void){
    vector<int> tmpVec = {1,2,3};

    ListNode* head = nullptr; // 链表头节点,存储数据
    ListNode* it = head;
    if(tmpVec.size() >= 1){
        head = new ListNode();
        it = head;
        head->val = tmpVec[0]; // 单独给头结点赋值
        for(int i=1; i<tmpVec.size(); i++){
            ListNode* node = new ListNode(tmpVec[i]); // 在堆中申请空间
            it->next = node;
            it = it->next;
        }
    } 

    for(it=head; it!=nullptr; it=it->next)
        cout<<it->val<<" ";
    cout<<endl; 

    Solution s;
    head = s.swapPairs(head);

    for(it=head; it!=nullptr; it=it->next)
        cout<<it->val<<" ";
    cout<<endl;   

}
