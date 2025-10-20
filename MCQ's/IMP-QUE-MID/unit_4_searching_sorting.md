# Unit 4 — Searching & Sorting (Q56–Q80)

## Q56 — Interpolation Search (Advanced)
```cpp
#include <iostream>
using namespace std;

int interpolationSearch(int a[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high && x >= a[low] && x <= a[high]) {
        if (a[low] == a[high]) {
            return (a[low] == x) ? low : -1;
        }
        int pos = low + (double)(high - low) * (x - a[low]) / (a[high] - a[low]);
        if (a[pos] == x) return pos;
        if (a[pos] < x) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

int main() {
    int a[] = {10,20,30,40,50,60};
    cout << "Index of 40: " << interpolationSearch(a,6,40) << endl;
}
```
**Explanation:** Best for uniformly distributed arrays; average O(log log n).

## Q57 — Bubble Sort (Standard)
```cpp
#include <iostream>
using namespace std;

void bubbleSort(int a[], int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
        }
    }
}

int main(){
    int a[]={5,1,4,2,8};
    bubbleSort(a,5);
    for(int x:a) cout<<x<<" ";
}
```
**Explanation:** O(n^2); stable sort.

## Q58 — Bubble Sort Optimized
```cpp
#include <iostream>
using namespace std;

void bubbleSortOptimized(int a[], int n){
    for(int i=0;i<n-1;i++){
        bool swapped=false;
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){swap(a[j],a[j+1]);swapped=true;}
        }
        if(!swapped) break;
    }
}

int main(){
    int a[]={5,1,4,2,8};
    bubbleSortOptimized(a,5);
    for(int x:a) cout<<x<<" ";
}
```
**Explanation:** Early exit if already sorted; best O(n).

## Q59 — Selection Sort
```cpp
#include <iostream>
using namespace std;

void selectionSort(int a[], int n){
    for(int i=0;i<n-1;i++){
        int minIdx=i;
        for(int j=i+1;j<n;j++) if(a[j]<a[minIdx]) minIdx=j;
        swap(a[i],a[minIdx]);
    }
}

int main(){
    int a[]={3,1,5,2,4};
    selectionSort(a,5);
    for(int x:a) cout<<x<<" ";
}
```
**Explanation:** Always O(n^2); not stable.

## Q60 — Insertion Sort
```cpp
#include <iostream>
using namespace std;

void insertionSort(int a[], int n){
    for(int i=1;i<n;i++){
        int key=a[i], j=i-1;
        while(j>=0 && a[j]>key){ a[j+1]=a[j]; j--; }
        a[j+1]=key;
    }
}

int main(){
    int a[]={9,7,5,3,1};
    insertionSort(a,5);
    for(int x:a) cout<<x<<" ";
}
```
**Explanation:** O(n) best-case, O(n^2) worst-case; stable.

## Q61 — Quick Sort (Pivot = Last Element)
```cpp
#include <iostream>
using namespace std;

int partition(int a[], int low, int high){
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(a[j]<=pivot){ i++; swap(a[i],a[j]); }
    }
    swap(a[i+1],a[high]);
    return i+1;
}

void quickSort(int a[], int low, int high){
    if(low<high){
        int p=partition(a,low,high);
        quickSort(a,low,p-1);
        quickSort(a,p+1,high);
    }
}

int main(){
    int a[]={8,4,7,2,6};
    quickSort(a,0,4);
    for(int x:a) cout<<x<<" ";
}
```
**Explanation:** Average O(n log n), worst O(n^2).

## Q62 — Merge Sort
```cpp
#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r){
    int n1=m-l+1,n2=r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++) L[i]=a[l+i];
    for(int i=0;i<n2;i++) R[i]=a[m+1+i];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2) a[k++]=(L[i]<=R[j])?L[i++]:R[j++];
    while(i<n1) a[k++]=L[i++];
    while(j<n2) a[k++]=R[j++];
}

void mergeSort(int a[], int l, int r){
    if(l<r){
        int m=l+(r-l)/2;
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
**Explanation:** Stable, O(n log n), needs O(n) extra space.

## Q63 — Counting Sort
```cpp
#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int>& a){
    int mx=*max_element(a.begin(),a.end());
    vector<int> cnt(mx+1,0);
    for(int x:a) cnt[x]++;
    int idx=0;
    for(int i=0;i<=mx;i++) while(cnt[i]--) a[idx++]=i;
}

int main(){
    vector<int> a={4,2,2,8,3,3,1};
    countingSort(a);
    for(int x:a) cout<<x<<" ";
}
```
**Explanation:** O(n+k), stable.

## Q64 — Radix Sort
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMax(vector<int>& a){ return *max_element(a.begin(),a.end()); }

void countSort(vector<int>& a,int exp){
    int n=a.size();
    vector<int> out(n),cnt(10,0);
    for(int i=0;i<n;i++) cnt[(a[i]/exp)%10]++;
    for(int i=1;i<10;i++) cnt[i]+=cnt[i-1];
    for(int i=n-1;i>=0;i--) out[--cnt[(a[i]/exp)%10]]=a[i];
    a=out;
}

void radixSort(vector<int>& a){
    int m=getMax(a);
    for(int exp=1;m/exp>0;exp*=10) countSort(a,exp);
}

int main(){
    vector<int> a={170,45,75,90,802,24,2,66};
    radixSort(a);
    for(int x:a) cout<<x<<" ";
}
```
**Explanation:** O(d*(n+k)), stable; d = max digits.

## Q65 — Sort Strings Alphabetically
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<string> v={"Ravi","Amit","Neha","Deep"};
    sort(v.begin(),v.end());