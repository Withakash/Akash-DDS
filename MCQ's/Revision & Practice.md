# 🧮 C++ Practical Programs

---
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






