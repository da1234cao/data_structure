class MyQueue {
private:
    stack<int> stIn; // 栈1用于输入
    stack<int> stOut; // 栈2用于输出

public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stIn.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        assert(!this->empty());
        int result;
        if(!stOut.empty()){
            result = stOut.top();
            stOut.pop();
        }else{
            while(!stIn.empty()){
                stOut.push(stIn.top());
                stIn.pop();
            }
            result = stOut.top();
            stOut.pop();
        }
        return result;
    }
    
    /** Get the front element. */
    int peek() {
        assert(!this->empty());
        int result =  this->pop();
        stOut.push(result);
        return result;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};