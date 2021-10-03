struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummyHead = new ListNode(0,head); // 添加一个哑节点
        ListNode *slowIt=dummyHead, *fastIt=head;
        ListNode *result;

        // 让快指针超前慢指针n+1步。(初始化的时候已超前一步，多合法的超前一步，不用保存倒数第n个元素的前指针)
        for(int i=0; i<n; i++)
            if(fastIt!=nullptr)
                fastIt = fastIt->next;
            else
                return head; //这个n超过链表长度，非法
        
        // 一起向前走，当快指针为空时，慢指针举例快指针n+1个距离，即倒数第n个元素的前一个元素
        while(fastIt!=nullptr){
            fastIt = fastIt->next;
            slowIt = slowIt->next;
        }

        // 删除倒数第n个元素
        ListNode *it = slowIt->next; // 待删除元素
        slowIt->next = it->next;
        delete it;

        // 删除伪头结点
        result = dummyHead->next;
        delete dummyHead;

        return result;
    }
};