#include <set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // if(head==nullptr || head->next==nullptr)
        if(head==nullptr) // 空链表直接返回
            return nullptr;

        set<ListNode*> listLop;
        ListNode *it = head;
        while(it != nullptr){
            if(listLop.find(it)==listLop.end())
                listLop.insert(it);
            else
                return it;
            it = it->next;
        }

        return nullptr;
    }
};