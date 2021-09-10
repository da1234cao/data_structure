class MyQueue {
private:
    void stackMove(stack<int>& src, stack<int>& target){
        assert(target.empty());
        while(!src.empty()){
            target.push(src.top());
            src.pop();
        }
    }

    void clear(stack<int>& st){
        while(!st.empty()) st.pop();
    }

    stack<int> st1_data; // 栈1用于存储数据
    stack<int> st2_queue; // 栈2用于作为队列使用

public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        assert(st2_queue.empty());
        st1_data.push(x); // 数据放入
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        assert(st2_queue.empty());
        stackMove(st1_data,st2_queue); // 将栈1中的数据，放入栈2中，作为queue
        int result = st2_queue.top();
        st2_queue.pop(); // 弹出数据
        stackMove(st2_queue,st1_data); // 数据作为queue操作完成后，放回栈1中
        return result;
    }
    
    /** Get the front element. */
    int peek() {
        assert(st2_queue.empty());
        stackMove(st1_data,st2_queue);
        int result = st2_queue.top();
        stackMove(st2_queue,st1_data);
        return result;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st1_data.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */