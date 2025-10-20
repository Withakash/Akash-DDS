# Unit 3 — Linked Lists (Q36–Q55)

## Q36 — Traverse a Singly Linked List
```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val): data(val), next(nullptr) {}
};

void traverse(Node* head) {
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    traverse(head);
}
```
**Explanation:** Iterate through each node using `next`; O(n) time.

## Q37 — Search in Linked List
```cpp
#include <iostream>
using namespace std;

struct Node { int data; Node* next; Node(int val):data(val),next(nullptr){} };

bool search(Node* head, int key) {
    Node* temp = head;
    while(temp){
        if(temp->data==key) return true;
        temp = temp->next;
    }
    return false;
}

int main(){
    Node* head = new Node(5);
    head->next = new Node(10);
    cout << (search(head,10)?"Found":"Not Found") << endl;
}
```
**Explanation:** Linear search in linked list; O(n).

## Q38 — Insert at Beginning
```cpp
#include <iostream>
using namespace std;

struct Node { int data; Node* next; Node(int v):data(v),next(nullptr){} };

void insertBegin(Node*& head, int val){
    Node* n = new Node(val);
    n->next = head;
    head = n;
}

int main(){
    Node* head = nullptr;
    insertBegin(head, 10);
    insertBegin(head, 20);
    Node* temp = head;
    while(temp){ cout << temp->data << " "; temp=temp->next;}
}
```
**Explanation:** O(1) insertion at head.

## Q39 — Insert at End
```cpp
#include <iostream>
using namespace std;

struct Node { int data; Node* next; Node(int v):data(v),next(nullptr){} };

void insertEnd(Node*& head, int val){
    Node* n = new Node(val);
    if(!head){ head=n; return;}
    Node* temp=head;
    while(temp->next) temp=temp->next;
    temp->next=n;
}

int main(){
    Node* head=nullptr;
    insertEnd(head,5);
    insertEnd(head,15);
    Node* temp=head;
    while(temp){ cout<<temp->data<<" "; temp=temp->next;}
}
```
**Explanation:** Traverse to end and append; O(n).

## Q40 — Delete a Node by Value
```cpp
#include <iostream>
using namespace std;

struct Node { int data; Node* next; Node(int v):data(v),next(nullptr){} };

void deleteNode(Node*& head, int val){
    if(!head) return;
    if(head->data==val){ Node* t=head; head=head->next; delete t; return;}
    Node* temp=head;
    while(temp->next && temp->next->data!=val) temp=temp->next;
    if(temp->next){ Node* t=temp->next; temp->next=temp->next->next; delete t;}
}

int main(){
    Node* head=new Node(1);
    head->next=new Node(2);
    deleteNode(head,1);
    Node* temp=head;
    while(temp){ cout<<temp->data<<" "; temp=temp->next;}
}
```
**Explanation:** O(n) deletion by value.

## Q41 — Count Nodes in Linked List
```cpp
#include <iostream>
using namespace std;

struct Node { int data; Node* next; Node(int v):data(v),next(nullptr){} };

int countNodes(Node* head){
    int cnt=0;
    while(head){ cnt++; head=head->next;}
    return cnt;
}

int main(){
    Node* head=new Node(5);
    head->next=new Node(10);
    cout << "Node count: " << countNodes(head) << endl;
}
```
**Explanation:** Simple traversal; O(n).

## Q42 — Reverse a Linked List Iteratively
```cpp
#include <iostream>
using namespace std;

struct Node { int data; Node* next; Node(int v):data(v),next(nullptr){} };

Node* reverseIter(Node* head){
    Node *prev=nullptr, *curr=head, *next;
    while(curr){ next=curr->next; curr->next=prev; prev=curr; curr=next;}
    return prev;
}

int main(){
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head=reverseIter(head);
    Node* temp=head;
    while(temp){ cout<<temp->data<<" "; temp=temp->next;}
}
```
**Explanation:** Iterative reversal; O(n) time, O(1) space.

## Q43 — Reverse a Linked List Recursively
```cpp
#include <iostream>
using namespace std;

struct Node{ int data; Node* next; Node(int v):data(v),next(nullptr){} };

Node* reverseRec(Node* head){
    if(!head || !head->next) return head;
    Node* rest=reverseRec(head->next);
    head->next->next=head;
    head->next=nullptr;
    return rest;
}

int main(){
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head=reverseRec(head);
    Node* temp=head;
    while(temp){ cout<<temp->data<<" "; temp=temp->next;}
}
```
**Explanation:** Recursive reversal; O(n) time, O(n) stack.

## Q44 — Detect Loop in Linked List (Floyd’s Cycle)
```cpp
#include <iostream>
using namespace std;

struct Node{ int data; Node* next; Node(int v):data(v),next(nullptr){} };

bool detectLoop(Node* head){
    Node *slow=head,*fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}

int main(){
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=head; // create loop
    cout << (detectLoop(head)?"Loop detected":"No loop") << endl;
}
```
**Explanation:** Floyd’s cycle detection; O(n) time, O(1) space.

## Q45 — Merge Two Sorted Linked Lists
```cpp
#include <iostream>
using namespace std;

struct Node{ int data; Node* next; Node(int v):data(v),next(nullptr){} };

Node* mergeSorted(Node* a, Node* b){
    if(!a) return b;
    if(!b) return a;
    if(a->data<b->data){ a->next=mergeSorted(a->next,b); return a;}
    else { b->next=mergeSorted(a,b->next); return b;}
}

int main(){
    Node* a=new Node(1); a->next=new Node(3);
    Node* b=new Node(2); b->next=new Node(4);
    Node* head=mergeSorted(a,b);
    while(head){ cout<<head->data<<" "; head=head->next;}
}
```
**Explanation:** Merge step similar to merge sort; O(n+m).

## Q46 — Find Middle of Linked List
```cpp
#include <iostream>
using namespace std;

struct Node{ int data; Node* next; Node(int v):data(v),next(nullptr){} };

Node* findMiddle(Node* head){
    Node *slow=head,*fast=head;
    while(fast && fast->next){ slow=slow->next; fast=fast->next->next;}
    return slow;
}

int main(){
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    cout << "Middle: " << findMiddle(head)->data << endl;
}
```
**Explanation:** Slow-fast pointer; O(n).

## Q47 — Remove Duplicates from Sorted Linked List
```cpp
#include <iostream>
using namespace std;

struct Node{ int data; Node* next; Node(int v):data(v),next(nullptr){} };

void removeDuplicates(Node* head){
    Node* curr=head;
    while(curr && curr->next){
        if(curr->data==curr->next->data){
            Node* t=curr->next; curr->next=curr->next->next; delete t;
        }