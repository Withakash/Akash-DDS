**📘 DATA & DATA STRUCTURES – 50 CODING QUESTIONS (ALL UNITS)**

🧩 UNIT 1: Introduction & Complexity (Q1–Q10)

Q1. Write a program to calculate time complexity of a loop (O(n)).
Concept: Time complexity basics
```
#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cout << i << " ";
    return 0;
}
```

Q2. Write a program to demonstrate O(log n) complexity using binary search.
Concept: Asymptotic analysis

```
#include <iostream>
using namespace std;
int binarySearch(int arr[], int n, int x) {
    int l = 0, r = n - 1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(arr[mid] == x) return mid;
        else if(arr[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
int main() {
    int arr[] = {10,20,30,40,50};
    cout << binarySearch(arr,5,40);
}
```

Q3. Write a program to count the number of comparisons in linear search.
```
#include <iostream>
using namespace std;
int main() {
    int arr[] = {5,3,7,9,2}, n=5, x=9, count=0;
    for(int i=0;i<n;i++){
        count++;
        if(arr[i]==x){
            cout<<"Found after "<<count<<" comparisons";
            return 0;
        }
    }
    cout<<"Not Found";
}
```

Q4. Demonstrate O(n²) complexity using nested loops.
```
#include <iostream>
using namespace std;
int main(){
    int n; cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cout<<"*";
}
```

Q5. Write a program to compute factorial using recursion and find its time complexity.
```
#include <iostream>
using namespace std;
int fact(int n){ return (n<=1)?1:n*fact(n-1); }
int main(){ cout<<fact(5); }
```

Q6. Write a program to swap two numbers using functions (pass by reference).
```
#include <iostream>
using namespace std;
void swapNum(int &a, int &b){ int t=a; a=b; b=t; }
int main(){
    int x=10,y=20;
    swapNum(x,y);
    cout<<x<<" "<<y;
}
```

Q7. Write a program to display Big O analysis message for any algorithm (user choice).
```
#include <iostream>
using namespace std;
int main(){
    cout<<"Enter Algorithm Type (1=Linear,2=Log,3=Quad): ";
    int ch; cin>>ch;
    switch(ch){
        case 1: cout<<"O(n)"; break;
        case 2: cout<<"O(log n)"; break;
        case 3: cout<<"O(n^2)"; break;
    }
}
```

Q8. Demonstrate a recursive function with O(2ⁿ) complexity (Fibonacci).
```
#include <iostream>
using namespace std;
int fib(int n){ return (n<=1)?n:fib(n-1)+fib(n-2); }
int main(){ cout<<fib(6); }
```

Q9. Write a program to reverse a number (basic algorithm question).
```
#include <iostream>
using namespace std;
int main(){
    int n=1234,rev=0;
    while(n){ rev=rev*10+n%10; n/=10; }
    cout<<rev;
}
```

Q10. Write a program to find GCD using recursion (O(log n)).
```
#include <iostream>
using namespace std;
int gcd(int a,int b){ return (b==0)?a:gcd(b,a%b); }
int main(){ cout<<gcd(60,24); }
```
🧮 UNIT 2: Arrays, Stacks & Queues (Q11–Q20)

Q11. Program to insert an element in an array.
```
#include <iostream>
using namespace std;
int main(){
    int arr[10]={1,2,3,4,5}, n=5, pos=3, val=99;
    for(int i=n;i>=pos;i--) arr[i]=arr[i-1];
    arr[pos-1]=val; n++;
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
```

Q12. Program to delete an element from array.
```
#include <iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5}, n=5, pos=3;
    for(int i=pos-1;i<n-1;i++) arr[i]=arr[i+1];
    n--;
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
```

Q13. Implement stack using array.
```
#include <iostream>
using namespace std;
#define MAX 5
int st[MAX], top=-1;
void push(int x){ if(top<MAX-1) st[++top]=x; }
int pop(){ return (top>=0)?st[top--]:-1; }
int main(){
    push(10);push(20);cout<<pop();
}
```

Q14. Implement queue using array.
```
#include <iostream>
using namespace std;
#define MAX 5
int q[MAX],f=-1,r=-1;
void enq(int x){ if(r<MAX-1) q[++r]=x; if(f==-1)f=0; }
void deq(){ if(f<=r) f++; }
int main(){
    enq(10);enq(20);deq();
    for(int i=f;i<=r;i++) cout<<q[i]<<" ";
}
```

Q15. Implement circular queue.
```
#include <iostream>
using namespace std;
#define MAX 5
int q[MAX],f=-1,r=-1;
bool isFull(){ return (f==0 && r==MAX-1)||(r+1==f); }
bool isEmpty(){ return f==-1; }
void enq(int x){
    if(isFull()) return;
    if(f==-1) f=0;
    r=(r+1)%MAX; q[r]=x;
}
void deq(){ if(isEmpty()) return; if(f==r) f=r=-1; else f=(f+1)%MAX; }
int main(){
    enq(10);enq(20);enq(30);deq();
    for(int i=f;i<=r;i++) cout<<q[i]<<" ";
}
```

Q16. Program to reverse an array.
```
#include <iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5},n=5;
    for(int i=0;i<n/2;i++) swap(arr[i],arr[n-1-i]);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
```

Q17. Implement stack using linked list.
```
#include <iostream>
using namespace std;
struct Node{ int data; Node* next; };
Node* top=NULL;
void push(int x){
    Node* n=new Node(); n->data=x; n->next=top; top=n;
}
void pop(){ if(top){ Node* t=top; top=top->next; delete t; } }
int main(){ push(10);push(20);pop(); }
```

Q18. Implement queue using linked list.
```
#include <iostream>
using namespace std;
struct Node{ int data; Node* next; };
Node *f=NULL,*r=NULL;
void enq(int x){
    Node* n=new Node(); n->data=x; n->next=NULL;
    if(!f) f=r=n; else r->next=n, r=n;
}
void deq(){ if(f){ Node* t=f; f=f->next; delete t; } }
int main(){ enq(10);enq(20);deq(); }
```
Q19. Evaluate postfix expression using stack.
```
#include <iostream>
#include <stack>
using namespace std;
int main(){
    string exp="23*54*+";
    stack<int> s;
    for(char c:exp){
        if(isdigit(c)) s.push(c-'0');
        else{
            int b=s.top();s.pop();int a=s.top();s.pop();
            if(c=='+') s.push(a+b);
            if(c=='*') s.push(a*b);
        }
    }
    cout<<s.top();
}
```

Q20. Implement parenthesis balancing using stack.
```
#include <iostream>
#include <stack>
using namespace std;
bool balanced(string str){
    stack<char> s;
    for(char c:str){
        if(c=='(') s.push(c);
        else if(c==')'){
            if(s.empty()) return false; s.pop();
        }
    }
    return s.empty();
}
int main(){ cout<<(balanced("(())")?"Balanced":"Not"); }
```
🔍 UNIT 3: Searching Algorithms (Q21–Q30)

Q21. Implement linear search.
```
#include <iostream>
using namespace std;
int main(){
    int arr[]={5,8,3,1,2},n=5,x=3;
    for(int i=0;i<n;i++)
        if(arr[i]==x){ cout<<"Found at "<<i; return 0; }
    cout<<"Not found";
}
```

Q22. Implement binary search (iterative).
```
#include <iostream>
using namespace std;
int binary(int a[],int n,int k){
    int l=0,h=n-1;
    while(l<=h){
        int m=(l+h)/2;
        if(a[m]==k) return m;
        else if(a[m]<k) l=m+1;
        else h=m-1;
    } return -1;
}
int main(){
    int a[]={10,20,30,40,50};
    cout<<binary(a,5,30);
}
```

Q23. Implement interpolation search.
```
#include <iostream>
using namespace std;
int interp(int arr[],int n,int x){
    int low=0,high=n-1;
    while(low<=high && x>=arr[low] && x<=arr[high]){
        int pos = low + ((x-arr[low])*(high-low))/(arr[high]-arr[low]);
        if(arr[pos]==x) return pos;
        if(arr[pos]<x) low=pos+1;
        else high=pos-1;
    } return -1;
}
int main(){
    int a[]={10,20,30,40,50};
    cout<<interp(a,5,30);
}
```

Q24. Implement recursive binary search.
```
#include <iostream>
using namespace std;
int recBin(int a[],int l,int h,int x){
    if(l>h) return -1;
    int m=(l+h)/2;
    if(a[m]==x) return m;
    return (a[m]<x)?recBin(a,m+1,h,x):recBin(a,l,m-1,x);
}
int main(){
    int a[]={2,4,6,8,10};
    cout<<recBin(a,0,4,8);
}
```

Q25. Program to find number of comparisons in binary search.
```
#include <iostream>
using namespace std;
int main(){
    int a[]={1,2,3,4,5,6},n=6,x=5,c=0;
    int l=0,h=n-1;
    while(l<=h){
        int m=(l+h)/2;c++;
        if(a[m]==x) break;
        else if(a[m]<x) l=m+1;
        else h=m-1;
    }
    cout<<"Comparisons="<<c;
}
```
🔄 UNIT 4: Sorting Algorithms (Q31–Q40)

Q31. Bubble sort
```
#include <iostream>
using namespace std;
void bubble(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
    }
}
int main(){
    int a[]={5,3,4,1,2};
    bubble(a,5);
    for(int x:a) cout<<x<<" ";
}
```

Q32. Selection sort
```
#include <iostream>
using namespace std;
void sel(int a[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++)
            if(a[j]<a[min]) min=j;
        swap(a[i],a[min]);
    }
}
int main(){
    int a[]={3,1,5,2,4};
    sel(a,5);
    for(int x:a) cout<<x<<" ";
}
```

Q33. Insertion sort
```
#include <iostream>
using namespace std;
void ins(int a[],int n){
    for(int i=1;i<n;i++){
        int key=a[i],j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j]; j--;
        }
        a[j+1]=key;
    }
}
int main(){
    int a[]={9,7,5,3,1};
    ins(a,5);
    for(int x:a) cout<<x<<" ";
}
```

Q34. Quick sort (pivot = first element)
```
#include <iostream>
using namespace std;
int part(int a[],int low,int high){
    int pivot=a[low],i=low+1,j=high;
    while(true){
        while(i<=high && a[i]<=pivot) i++;
        while(a[j]>pivot) j--;
        if(i<j) swap(a[i],a[j]);
        else break;
    }
    swap(a[low],a[j]);
    return j;
}
void quick(int a[],int low,int high){
    if(low<high){
        int p=part(a,low,high);
        quick(a,low,p-1);
        quick(a,p+1,high);
    }
}
int main(){
    int a[]={8,4,7,2,6};
    quick(a,0,4);
    for(int x:a) cout<<x<<" ";
}
```

Q35. Merge sort
```
#include <iostream>
using namespace std;
void merge(int a[],int l,int m,int r){
    int n1=m-l+1,n2=r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++) L[i]=a[l+i];
    for(int j=0;j<n2;j++) R[j]=a[m+1+j];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
        a[k++]=(L[i]<=R[j])?L[i++]:R[j++];
    while(i<n1) a[k++]=L[i++];
    while(j<n2) a[k++]=R[j++];
}
void mergeSort(int a[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}
int main(){
    int a[]={6,3,9,5,2};
    mergeSort(a,0,4);
    for(int x:a) cout<<x<<" ";
}
```

Q36. Radix sort
```
#include <iostream>
#include <algorithm>
using namespace std;
int getMax(int a[],int n){
    return *max_element(a,a+n);
}
void countSort(int a[],int n,int exp){
    int out[n],count[10]={0};
    for(int i=0;i<n;i++) count[(a[i]/exp)%10]++;
    for(int i=1;i<10;i++) count[i]+=count[i-1];
    for(int i=n-1;i>=0;i--){
        out[count[(a[i]/exp)%10]-1]=a[i];
        count[(a[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++) a[i]=out[i];
}
void radixSort(int a[],int n){
    int m=getMax(a,n);
    for(int exp=1;m/exp>0;exp*=10) countSort(a,n,exp);
}
int main(){
    int a[]={170,45,75,90,802,24,2,66};
    radixSort(a,8);
    for(int x:a) cout<<x<<" ";
}
```

Q37–Q50 → UNIT 5 (Trees)
