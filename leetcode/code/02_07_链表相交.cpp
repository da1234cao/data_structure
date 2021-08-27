#include <map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr || headB==nullptr) // 如果存在空链表，直接返回
            return nullptr;

        // 键值对为链表节点地址和节点在所在链表的位置信息
        // 当存在相同的链表节点时，则相交
        map<ListNode*,int> listIntersect; 

        int len = 1;
        ListNode* it = headA;
        while(it != nullptr){ // 将第一条链表的节点地址信息放入map
            listIntersect[it] = len;
            it=it->next;
            len++;
        }

        len = 1;
        it = headB;
        while(it != nullptr){
            if(listIntersect.find(it)!=listIntersect.end()){ // 找见相同的节点
                return it;
            }else{
                listIntersect[it] = len;
                it=it->next;
                len++;
            }
        }

        return nullptr; //没有交点
    }
};