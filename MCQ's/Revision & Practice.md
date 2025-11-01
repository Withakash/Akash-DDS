# 🧮 C++ Practical Programs

---

# 🎯 Section – A : Coding / Practical Questions 



**Q1. Write a program to find the Factorial of a number using recursion.**

**Sample Input:**
5

**Expected Output:**
120

```cpp
#include <iostream>
using namespace std;

int fact(int n){
    if(n == 0)
        return 1;
    else
        return n * fact(n - 1);
}

int main(){
    int n;
    cout << "Enter number: ";
    cin >> n;
    cout << "Factorial = " << fact(n);
    return 0;
}
```

**Q2. Write a program to display the Fibonacci Series up to n terms.**

**Sample Input:**
5

**Expected Output:**
0 1 1 2 3

```cpp
#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter number of terms: ";
    cin >> n;
    int a = 0, b = 1, c;
    cout << a << " " << b << " ";
    for(int i = 2; i < n; i++){
        c = a + b;
        cout << c << " ";
        a = b;
        b = c;
    }
    return 0;
}
```
**Q3. Write a program to find GCD (Greatest Common Divisor) of two numbers using recursion.**

**Sample Input:**
12 18

**Expected Output:**
GCD = 6

```cpp
#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int main(){
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "GCD = " << gcd(a, b);
    return 0;
}
```

**Q4. Write a program for Linear Search to find an element in an array.**

**Sample Input:**
5
10 20 30 40 50
30

**Expected Output:**
Element found at position 3

```cpp
#include <iostream>
using namespace std;

int main(){
    int n, key;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[50];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter element to search: ";
    cin >> key;

    int pos = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] == key){
            pos = i + 1;
            break;
        }
    }
    if(pos == -1)
        cout << "Element not found.";
    else
        cout << "Element found at position " << pos;
    return 0;
}
```
**Q5. Write a program to perform Binary Search on a sorted array.**

**Sample Input:**
5
10 20 30 40 50
40

**Expected Output:**
Element found at position 4

```cpp
#include <iostream>
using namespace std;

int main(){
    int n, key;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[50];
    cout << "Enter sorted elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter element to search: ";
    cin >> key;

    int low = 0, high = n - 1, mid, pos = -1;
    while(low <= high){
        mid = (low + high) / 2;
        if(arr[mid] == key){
            pos = mid + 1;
            break;
        }
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if(pos == -1)
        cout << "Element not found.";
    else
        cout << "Element found at position " << pos;
    return 0;
}
```

**Q6. Write a program to push and pop elements from a stack using arrays.**

**Sample Input:**
Push 10

Push 20

Pop

Display

**Expected Output:**
Stack Elements: 10

```cpp
#include <iostream>
using namespace std;

#define SIZE 5
int stack[SIZE], top = -1;

void push(int val){
    if(top == SIZE - 1)
        cout << "Stack Overflow\n";
    else
        stack[++top] = val;
}

void pop(){
    if(top == -1)
        cout << "Stack Underflow\n";
    else
        top--;
}

void display(){
    if(top == -1)
        cout << "Stack is empty\n";
    else{
        cout << "Stack Elements: ";
        for(int i = 0; i <= top; i++)
            cout << stack[i] << " ";
        cout << endl;
    }
}

int main(){
    push(10);
    push(20);
    pop();
    display();
    return 0;
}

```
**Q7. Write a program to implement Queue operations using arrays.**

**Sample Input:**
Enqueue 10
Enqueue 20
Dequeue
Display

**Expected Output:**
Queue Elements: 20

```cpp
#include <iostream>
using namespace std;

#define SIZE 5
int queueArr[SIZE], front = -1, rear = -1;

void enqueue(int val){
    if(rear == SIZE - 1)
        cout << "Queue Overflow\n";
    else{
        if(front == -1) front = 0;
        queueArr[++rear] = val;
    }
}

void dequeue(){
    if(front == -1 || front > rear)
        cout << "Queue Underflow\n";
    else
        front++;
}

void display(){
    if(front == -1 || front > rear)
        cout << "Queue is empty\n";
    else{
        cout << "Queue Elements: ";
        for(int i = front; i <= rear; i++)
            cout << queueArr[i] << " ";
        cout << endl;
    }
}

int main(){
    enqueue(10);
    enqueue(20);
    dequeue();
    display();
    return 0;
}
```

**Q8. Write a program to evaluate a postfix expression using stack.**

**Sample Input:**
2354+9-

**Expected Output:**
17

```cpp
#include <iostream>
#include <cstring>
using namespace std;

#define SIZE 20
int stackArr[SIZE];
int top = -1;

void push(int val){ stackArr[++top] = val; }
int pop(){ return stackArr[top--]; }

int main(){
    char exp[SIZE];
    cout << "Enter Postfix Expression: ";
    cin >> exp;
    int n = strlen(exp);

    for(int i = 0; i < n; i++){
        char c = exp[i];
        if(isdigit(c))
            push(c - '0');
        else{
            int b = pop();
            int a = pop();
            switch(c){
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }
    cout << "Result = " << pop();
    return 0;
}
```

**Q9. Write a program for Tower of Hanoi using recursion.**

**Sample Input:**
3

**Expected Output:**

Move disk 1 from A to C  
Move disk 2 from A to B  
Move disk 1 from C to B  
Move disk 3 from A to C  
Move disk 1 from B to A  
Move disk 2 from B to C  
Move disk 1 from A to C

```cpp

#include <iostream>
using namespace std;

void tower(int n, char from, char aux, char to){
    if(n == 1){
        cout << "Move disk 1 from " << from << " to " << to << endl;
        return;
    }
    tower(n-1, from, to, aux);
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    tower(n-1, aux, from, to);
}

int main(){
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    tower(n, 'A', 'B', 'C');
    return 0;
}

```

**Q10. Write a program for Bubble Sort in ascending order.**

**Sample Input:**
5
5 2 8 1 3

**Expected Output:**
1 2 3 5 8

```cpp
#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter size: ";
    cin >> n;
    int arr[50];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    cout << "Sorted elements: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
```

**Q11. Write a program for Insertion Sort.**

**Sample Input:**
5
9 5 1 4 3

**Expected Output:**
1 3 4 5 9

```cpp

#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter size: ";
    cin >> n;
    int arr[50];
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    cout << "Sorted elements: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}

Q12. Write a program for Selection Sort.

Sample Input:
5
64 25 12 22 11

Expected Output:
11 12 22 25 64

#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter size: ";
    cin >> n;
    int arr[50];
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = 0; i < n-1; i++){
        int minIndex = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    cout << "Sorted elements: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
```






# 🎯 Section B — Objective / Fill-in-the-Blanks / Output-Based Questions

---

### 🧩 Multiple Choice Questions (MCQs)

1. A data structure is a way of organizing **_____** in a computer so it can be used efficiently.  
   - A. Code  B. Memory  C. **Data**  D. Function  

2. The complexity of **linear search** is _____  
   - A. O(1)  B. O(log n)  C. **O(n)**  D. O(n²)

3. In recursion, a function **_____** itself until a base condition is met.  
   - A. Repeats  B. **Calls**  C. Copies  D. Stops  

4. Stack follows which principle?  
   - A. FIFO  B. **LIFO**  C. FILO  D. None  

5. In a queue, insertion is done at _____ and deletion at _____.  
   - A. Front, Rear  B. **Rear, Front**  C. Both Rear  D. Both Front  

6. Which of the following is **not** a linear data structure?  
   - A. Array  B. Stack  C. Queue  D. **Tree**

7. Which search technique requires **sorted data**?  
   - A. Linear  B. **Binary Search**  C. Hashing  D. All  

8. The worst-case complexity of **bubble sort** is _____  
   - A. **O(n²)**  B. O(n log n)  C. O(n)  D. O(1)

9. In a stack, overflow occurs when _____  
   - **Top == size – 1**

10. In queue operations, removing an element is called **Dequeue**.

11. A linked list node contains _____ and _____.  
    - **Data**, **Pointer to Next Node**

12. The search operation in a linked list takes _____ time in the worst case.  
    - **O(n)**  

13. Which sorting algorithm is **stable**?  
    - A. Selection  B. **Insertion**  C. Quick  D. Heap  

14. A stack is useful for **Undo** operations in text editors.  

15. Traversing a binary search tree in **In-order** results in **sorted data**.

16. The postfix form of (A + B) * (C – D) is **AB+CD-\***  

17. Which structure uses both FIFO and LIFO principles?  
    - **Deque**

18. The auxiliary space of merge sort = **O(n)**  

19. In an array, index starts from **0**.  

20. Recursion ends when the **base condition** is true.  

---

### ✍️ Fill in the Blanks

21. The queue used in **BFS** is a **Queue (FIFO)**.  
22. In selection sort, the smallest element is placed at the **first position**.  
23. Merge sort uses the **Divide and Conquer** technique.  
24. Stack is used for **expression evaluation and syntax parsing**.  
25. In a binary tree, the maximum number of nodes on level L = **2ᴸ**.  
26. The best-case complexity of insertion sort = **O(n)**.  
27. Stack used in function calls is called **Call Stack**.  
28. A circular queue helps reduce **memory wastage**.  
29. For a queue implemented using an array, if `front == rear == –1`, queue is **Empty**.  
30. Stack is used to convert **infix to postfix** expressions.  

---

### 💻 Output-Based Questions

31. Predict the output:  
    ```cpp
    int a=5,b=2;
    while(a-- > b++){}
    cout << a << " " << b;
    ```
    ✅ **Output:** `1 3`

32. If n = 4, how many times does the inner loop run in bubble sort?  **6**

33. In recursion, each call is pushed onto the **Stack**.  

34. Output of the following:  
    ```cpp
    int x=5;
    cout << x++ + ++x;
    ```
    ✅ **Output:** `12`

35. For an array base address 100 (int = 4 bytes), address of arr[3] = **112**.  

36. Output:  
    ```cpp
    int a=3,b=4;
    cout << (a & b) << " " << (a | b);
    ```
    ✅ **Output:** `0 7`

37. In a queue where rear = 4 and front = 2, number of elements = **3**.  

38. Output:  
    ```cpp
    cout << (10/4*2);
    ```
    ✅ **Output:** `4`

39. Output:  
    ```cpp
    for(int i=1;i<=5;i++)
      for(int j=1;j<=i;j++);
    cout << i;
    ```
    ✅ **Output:** `6`

40. Output of `cout << 5/2.0;` = **2.5**

---

### 🧾 Answer Highlights (Quick Key)

| # | Answer | Concept |
|:--:|:--|:--|
| 1 | Data | Defines what is organized. |
| 2 | O(n) | Linear search scans all elements. |
| 4 | LIFO | Stack behavior. |
| 5 | Rear/Front | Queue in/out ends. |
| 6 | Tree | Non-linear DS. |
| 8 | O(n²) | Nested loops in bubble sort. |
| 13 | Insertion Sort | Stable algorithm. |
| 15 | In-order → sorted | BST property. |
| 16 | AB+CD-\* | Postfix conversion. |
| 21 | Queue | Used in BFS. |
| 23 | Divide & Conquer | Merge sort method. |
| 28 | Reduces wastage | Circular queue advantage. |
| 31 | 1 3 | Loop trace question. |
| 34 | 12 | Increment operators. |
| 36 | 0 7 | Bitwise AND/OR logic. |
| 39 | 6 | Loop scope trick. |
| 40 | 2.5 | Floating division. |

---




