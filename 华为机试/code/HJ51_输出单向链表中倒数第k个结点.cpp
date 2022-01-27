#include <iostream>

using namespace std;

struct ListNode {
    int m_nKey;
    ListNode* m_pNext;
};

int main(void){
    int tmp;
    while(cin>>tmp){
        const int N = tmp;
        ListNode* head = new ListNode();

        ListNode* cur = head;
        for(int i=0; i<N; i++){
            int num;
            cin>>num;
            ListNode* node = new ListNode();
            node->m_nKey = num;
            cur->m_pNext = node;
            cur = node;
        }

        // 检查创建的链表是否正确
        // cur = head->m_pNext;
        // while(cur!=nullptr){
        //     cout<<cur->m_nKey<<" ";
        //     cur = cur->m_pNext;
        // }

        // 双指针。快指针先行k步
        ListNode* slow = head;
        ListNode* fast = head;
        int k;
        cin>>k;
        if(k == 0){
            cout<<0<<endl;
            continue;
        }
        while(k>0){
            k--;
            fast = fast->m_pNext;
        }

        while(fast != nullptr){
            fast = fast->m_pNext;
            slow = slow->m_pNext;
        }
        cout<<slow->m_nKey<<endl;
    }
    return 0;

}