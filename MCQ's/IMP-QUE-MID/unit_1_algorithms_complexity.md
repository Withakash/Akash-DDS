# Unit 1 — Algorithms & Complexity (Q1–Q10)

## Q1 — Factorial (Recursive)
```cpp
#include <iostream>
using namespace std;

long long fact(int n) {
    if (n <= 1) return 1LL;
    return n * fact(n - 1);
}

int main() {
    int n = 5; // sample input
    cout << "5! = " << fact(n) << endl;
    return 0;
}
```
**Explanation:** Classic recursion. Time Complexity: O(n), Space Complexity: O(n) (call stack).

## Q2 — Fibonacci Series (Iterative)
```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 10;
    int a = 0, b = 1;
    cout << "Fibonacci Series: ";
    for (int i = 0; i < n; ++i) {
        cout << a << (i+1==n ? '\n' : ' ');
        int c = a + b;
        a = b; b = c;
    }
    return 0;
}
```
**Explanation:** Iterative approach, O(n) time, O(1) space.

## Q3 — Count Operations in Loop
```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 100;
    long long count = 0;
    for (int i = 0; i < n; ++i) count++;
    cout << "Operations Count: " << count << endl;
    return 0;
}
```
**Explanation:** Demonstrates linear complexity O(n).

## Q4 — Nested Loops (O(n²))
```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 50;
    long long cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            ++cnt;
    cout << "Total Operations: " << cnt << endl;
    return 0;
}
```
**Explanation:** Two nested loops → O(n²).

## Q5 — GCD (Euclidean Algorithm, Recursive)
```cpp
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

int main() {
    cout << "GCD of 60 and 24 = " << gcd(60, 24) << endl;
    return 0;
}
```
**Explanation:** Time Complexity ~ O(log min(a,b)).

## Q6 — Swap Two Numbers (Pass by Reference)
```cpp
#include <iostream>
using namespace std;

void swapNum(int &x, int &y) {
    int t = x; x = y; y = t;
}

int main() {
    int a = 10, b = 20;
    swapNum(a, b);
    cout << "a = " << a << ", b = " << b << endl;
    return 0;
}
```
**Explanation:** Swaps two numbers without returning; O(1) time.

## Q7 — Reverse a Number
```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 12345;
    int rev = 0;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    cout << "Reversed Number: " << rev << endl;
    return 0;
}
```
**Explanation:** Extracts digits using modulo/division; O(log n) time.

## Q8 — Prime Check (Sqrt Method)
```cpp
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * 1LL * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}

int main() {
    cout << "13 is " << (isPrime(13) ? "Prime" : "Not Prime") << endl;
}
```
**Explanation:** Checks primes efficiently using O(√n) time.

## Q9 — Power (Recursive)
```cpp
#include <iostream>
using namespace std;

long long power(long long x, int y) {
    if (y == 0) return 1;
    return x * power(x, y - 1);
}

int main() {
    cout << "2^5 = " << power(2, 5) << endl;
}
```
**Explanation:** Simple recursion; can be optimized with exponentiation by squaring.

## Q10 — Sum of Digits (Recursive)
```cpp
#include <iostream>
using namespace std;

int sumDigits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumDigits(n / 10);
}

int main() {
    cout << "Sum of digits of 1234 = " << sumDigits(1234) << endl;
}
```
**Explanation:** Recursive sum of digits; O(log n) recursion depth.

