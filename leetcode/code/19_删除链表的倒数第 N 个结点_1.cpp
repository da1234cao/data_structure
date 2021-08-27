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
        ListNode *result=nullptr;

        // 遍历得到总长度
        int len = 0;
        ListNode *it = head;
        while(it != nullptr){
            len++;
            it=it->next;
        }

        // 第n个节点的顺序下标=总长度-倒数第n个节点
        int index = len-n;
        if(index >=0){
            ListNode *dummyHead = new ListNode(0,head);// 添加一个伪头部，便于删除
            ListNode *prevIt = dummyHead;
            it = head;
            for(int i = 0; i<index; i++){ // 遍历到待删除节点位置
                prevIt = it;
                it = it->next;
            }
            prevIt->next = it->next;
            delete it;

            result =  dummyHead->next;
            delete dummyHead;
        }else{ // 不再删除范围内
            result =  head;
        }

        return result;
    }
};