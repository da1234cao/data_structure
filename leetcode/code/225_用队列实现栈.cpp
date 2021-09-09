#include <queue>
#include <cassert>

using namespace std;

class MyStack {
private:
    queue<int> qOne;
    queue<int> qTwo;
public:
    void moveKeepOne(queue<int>& src,queue<int>& des){
        // assert(des.empty());
        int n = src.size();
        for(int i=0; i<n-1; i++){
            des.push(src.front());
            src.pop();
        }
    }

    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        qOne.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        assert(!this->empty());
        int result;
        if(qOne.empty()){ // 此时元素已全部在Q2中；Q2保留最后一个元素，其他全部转移到Q1中
            moveKeepOne(qTwo,qOne);
            result = qTwo.front();
            qTwo.pop();
        }else if(qOne.size()==1){ // 此时Q1中只有一个元素，它是最后一个push入的元素
            result = qOne.front();
            qOne.pop();
        }else{ // 多于一个元素的时候，非最后一个元素移入Q2中
            moveKeepOne(qOne,qTwo);
            result = qOne.front();
            qOne.pop();
        }

        return result;
    }
    
    /** Get the top element. */
    int top() {
        assert(!this->empty());
        int result = this->pop();
        this->push(result);
        return result;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return qOne.empty() && qTwo.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */