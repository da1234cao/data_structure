#include <iostream>
#include <stack>

using namespace std;

class CQueue {
private:
    stack<int> ist;
    stack<int> ost;

public:
    CQueue() {
        
    }
    
    void appendTail(int value) {
        ist.push(value);
    }
    
    int deleteHead() {
        // 如果两个栈均为空，模拟的队列中没有元素，返回-1(题目的奇怪要求。队列中的元素也可能是-1呀)
        if(ist.empty() && ost.empty())
            return -1;
        
        // 从输出栈中弹出
        if(!ost.empty()){
            int val = ost.top();
            ost.pop();
            return val;
        }

        // 当输出栈为空，将输入栈全部弹出到输出栈
        while(!ist.empty()){
            int val = ist.top();
            ist.pop();
            ost.push(val);
        }
        int val = ost.top();
        ost.pop();
        return val;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */