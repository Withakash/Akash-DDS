# Unit 2 — Arrays, Stack & Queue (Q11–Q25)

### 📚 Overview
This section contains problems Q11–Q25 focused on **arrays, stacks, and queues**. Each question includes a short problem statement, the full C++ code wrapped with triple backticks (```), and a concise explanation — ready for direct copy into your GitHub `.md` file.

---

### Q11 — Insert element into array (shift right)
**Problem:** Insert an element at position `pos` (1-based) by shifting elements to the right.

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[20] = {1,2,3,4,5};
    int n = 5, pos = 3, val = 99;
    for (int i = n; i >= pos; --i) arr[i] = arr[i-1];
    arr[pos-1] = val; ++n;
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
```

**Explanation:** Shift elements from the end to `pos` rightwards, place `val` at `pos-1`. Time: **O(n)**.

---

### Q12 — Delete element from array (shift left)
**Problem:** Delete element at position `pos` (1-based) by shifting elements left.

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,2,3,4,5};
    int n = 5, pos = 2;
    for (int i = pos-1; i < n-1; ++i) arr[i] = arr[i+1];
    --n;
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
```

**Explanation:** Overwrite the element at `pos-1` with the next element repeatedly. Time: **O(n)**.

---

### Q13 — Reverse an array in-place
**Problem:** Reverse an array using two-pointer swaps.

```cpp
#include <iostream>
using namespace std;

int main() {
    int a[] = {1,2,3,4,5};
    int n = 5;
    for (int i = 0; i < n/2; ++i) swap(a[i], a[n-1-i]);
    for (int x: a) cout << x << " ";
    cout << endl;
    return 0;
}
```

**Explanation:** Swap symmetric elements until the middle. Time: **O(n)**, Space: **O(1)**.

---

### Q14 — Find maximum element
**Problem:** Find the maximum element in an array.

```cpp
#include <iostream>
using namespace std;

int main() {
    int a[] = {10,50,20,5,60};
    int n = 5, mx = a[0];
    for (int i = 1; i < n; ++i) if (a[i] > mx) mx = a[i];
    cout << "Max = " << mx << endl;
    return 0;
}
```

**Explanation:** Single-pass scan keeping the current maximum. Time: **O(n)**.

---

### Q15 — Stack (array implementation)
**Problem:** Implement a simple stack using a fixed-size array.

```cpp
#include <iostream>
using namespace std;

struct Stack {
    int st[100];
    int top = -1;
    void push(int x) { if (top < 99) st[++top] = x; }
    int pop() { return (top >= 0) ? st[top--] : -1; }
    int peek() { return (top >= 0) ? st[top] : -1; }
};

int main() {
    Stack s;
    s.push(10); s.push(20);
    cout << s.pop() << endl; // 20
    cout << s.peek() << endl; // 10
    return 0;
}
```

**Explanation:** Constant-time push/pop/peek. Space limited by array size. Time: **O(1)** per operation.

---

### Q16 — Queue (array implementation, simple)
**Problem:** Simple queue using front and rear indices (no reuse of freed space).

```cpp
#include <iostream>
using namespace std;

struct Queue {
    int q[100];
    int f = 0, r = -1;
    void enqueue(int x) { q[++r] = x; }
    int dequeue() { return (f <= r) ? q[f++] : -1; }
};

int main() {
    Queue qq;
    qq.enqueue(10); qq.enqueue(20);
    cout << qq.dequeue() << endl; // 10
    return 0;
}
```

**Explanation:** Simple fixed-array queue; does not wrap around — may waste space. Operations: **O(1)**.

---

### Q17 — Circular Queue (array)
**Problem:** Fixed-size circular queue using modulo arithmetic.

```cpp
#include <iostream>
using namespace std;

struct CQueue {
    int q[5], f = -1, r = -1;
    bool isFull() { return ((r+1)%5 == f); }
    bool isEmpty() { return f == -1; }
    void enqueue(int x) {
        if (isFull()) return;
        if (isEmpty()) f = 0;
        r = (r + 1) % 5; q[r] = x;
    }
    int dequeue() {
        if (isEmpty()) return -1;
        int v = q[f];
        if (f == r) f = r = -1;
        else f = (f + 1) % 5;
        return v;
    }
};

int main() {
    CQueue cq;
    cq.enqueue(1); cq.enqueue(2); cq.enqueue(3);
    cout << cq.dequeue() << endl; // 1
    return 0;
}
```

**Explanation:** Reuses freed slots, avoiding wasted space. Operations: **O(1)**.

---

### Q18 — Stack via Linked List
**Problem:** Implement a stack using a singly linked list for dynamic size.

```cpp
#include <iostream>
using namespace std;

struct Node { int data; Node *next; Node(int v):data(v),next(nullptr){} };
struct StackLL {
    Node *top = nullptr;
    void push(int x) { Node* n = new Node(x); n->next = top; top = n; }
    int pop() { if(!top) return -1; Node* t = top; int v = t->data; top = top->next; delete t; return v; }
};

int main() {
    StackLL s; s.push(10); s.push(20);
    cout << s.pop() << endl; // 20
    return 0;
}
```

**Explanation:** Dynamic stack; push/pop at head for **O(1)** operations. Remember to free memory.

---

### Q19 — Queue via Linked List
**Problem:** Implement a queue using singly linked list with front and rear pointers.

```cpp
#include <iostream>
using namespace std;

struct Node { int data; Node* next; Node(int v):data(v),next(nullptr){} };
struct QueueLL {
    Node *front = nullptr, *rear = nullptr;
    void enqueue(int x) {
        Node* n = new Node(x);
        if (!rear) front = rear = n;
        else rear->next = n, rear = n;
    }
    int dequeue() {
        if (!front) return -1;
        Node* t = front; int v = t->data; front = front->next;
        if (!front) rear = nullptr;
        delete t; return v;
    }
};

int main() {
    QueueLL q; q.enqueue(5); q.enqueue(6);
    cout << q.dequeue() << endl; // 5
    return 0;
}
```

**Explanation:** Maintain both `front` and `rear` to achieve amortized **O(1)** enqueue and dequeue. Be careful with empty queue cleanup.

---

### Q20 — Reverse a Stack (recursively)
**Problem:** Reverse a stack using recursion and an `insertBottom` helper.

```cpp
#include <iostream>
#include <stack>
using namespace std;

void insertBottom(stack<int>& s, int x) {
    if (s.empty()) { s.push(x); return; }
    int t = s.top(); s.pop();
    insertBottom(s, x);
    s.push(t);
}
void reverseStack(stack<int>& s) {
    if (s.empty()) return;
    int x = s.top(); s.pop();
    reverseStack(s);
    insertBottom(s, x);
}

int main() {
    stack<int> s; s.push(1); s.push(2); s.push(3);
    reverseStack(s);
    while (!s.empty()) { cout << s.top() << " "; s.pop(); } // prints 1 2 3
    cout << endl;
    return 0;
}
```

**Explanation:** `reverseStack` pops all elements recursively; `insertBottom` places each popped element at bottom, reversing order. Complexity: **O(n²)** due to repeated insertBottom operations.

---

### Q21 — Evaluate Postfix Expression
**Problem:** Evaluate a postfix expression with single-digit operands using a stack.

```cpp
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evalPostfix(const string& s) {
    stack<int> st;
    for (char c: s) {
        if (isdigit(c)) st.push(c - '0');
        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if (c == '+') st.push(a + b);
            else if (c == '-') st.push(a - b);
            else if (c == '*') st.push(a * b);
            else if (c == '/') st.push(a / b);
        }
    }
    return st.top();
}

int main() {
    cout << evalPostfix("23*54*+") << endl; // example
    return 0;
}
```

**Explanation:** Use stack to push operands; on operator, pop two operands, compute, push result. Time: **O(n)**.

---

### Q22 — Parentheses Balancing
**Problem:** Check if parentheses in a string are balanced using a stack.

```cpp
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(const string& s) {
    stack<char> st;
    for (char c: s) {
        if (c == '(') st.push(c);
        else if (c == ')') {
            if (st.empty()) return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    cout << (isBalanced("(())") ? "Balanced" : "Not Balanced") << endl;
}
```

**Explanation:** Push '(' and pop when seeing ')'. If stack empty when popping or stack non-empty at end → not balanced. Time: **O(n)**.

---

### Q23 — Peek / Top of Stack (using std::stack)
**Problem:** Demonstrate peek/top operation on a stack.

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    cout << "Top = " << s.top() << endl;
    s.pop();
    cout << "Top after pop = " << s.top() << endl;
    return 0;
}
```

**Explanation:** `top()` returns the top element without removing it. `pop()` removes it. Both are **O(1)**.

---

### Q24 — Deque (double-ended queue) basics
**Problem:** Demonstrate basic `deque` operations (push/pop at both ends).

```cpp
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;
    dq.push_back(1);
    dq.push_front(2);
    cout << dq.front() << " " << dq.back() << endl;
    dq.pop_front();
    dq.pop_back();
    cout << "Size = " << dq.size() << endl;
    return 0;
}
```

**Explanation:** `deque` supports O(1) average push/pop at both ends. Useful for sliding window problems.

---

### Q25 — Implement Stack using Two Queues (brief)
**Problem:** Use two queues to simulate stack `push` and `pop`.

```cpp
#include <iostream>
#include <queue>
using namespace std;

struct StackUsingQueues {
    queue<int> q1, q2;
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) { q2.push(q1.front()); q1.pop(); }
        swap(q1, q2);
    }
    int pop() {
        if (q1.empty()) return -1;
        int v = q1.front(); q1.pop(); return v;
    }
    int top() { return q1.empty() ? -1 : q1.front(); }
    bool empty() { return q1.empty(); }
};

int main() {
    StackUsingQueues s;
    s.push(10); s.push(20); s.push(30);
    cout << s.pop() << endl; // 30
    cout << s.top() << endl; // 20
    return 0;
}
```

**Explanation:** `push` is made costly: new element enqueued to `q2`, then all `q1` moved to `q2` and queues swapped — ensures LIFO order in `q1`. `pop` is O(1). Amortized complexities depend on chosen approach.

