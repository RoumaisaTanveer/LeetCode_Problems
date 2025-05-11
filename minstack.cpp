 #include <bits/stdc++.h>
using namespace std;
class MinStack {
     private:
    stack<int> mainStack;
    stack<int> minStack;
public:
    MinStack() {
        
    }

    // Pushes the value onto the stack
    void push(int val) {
        mainStack.push(val);
        
        // Push to minStack: either val or the current minimum, whichever is smaller
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        } else {
            minStack.push(minStack.top());
        }
    }

    // Removes the element from the top of the stack
    void pop() {
        mainStack.pop();
        minStack.pop();
    }

    // Returns the element at the top of the stack
    int top() {
        return mainStack.top();
    }

    // Retrieves the minimum element in the stack
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main() {
    return 0;
}