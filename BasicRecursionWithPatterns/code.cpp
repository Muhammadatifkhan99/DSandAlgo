#include<bits/stdc++.h>

using namespace std;


void printNtimes(int i,int n){
    if(i == n){
        return;
    }
    cout << "Atif" << endl;
    printNtimes(i+1,n);
}

//print numbers from 1-N

void print1N(int i,int n){
    if(i == n){
        return;
    }
    cout << i << " ";
    print1N(i+1,n);
}

//print numbers from N-1

void printN1(int n){
    if(n <= 0){
        return;
    }
    cout << n << " ";
    printN1(n-1);
}
//printing from 1 to n using backtracking

void print1n(int n){
    if(n <= 0){
        return;
    }
    print1n(n-1);
    cout << n << " ";
}

void printn1(int i,int n){
    if(i > n){
        return;
    }
    printn1(i+1,n);
    cout << i << " ";
}

///parameterized recursion
//sum of n numbers

void sumofN(int i,int sum){
    if(i <= 0){
        cout << sum << endl;
        return;
    }
    sumofN(i-1,sum+i);
}

//funtional recursion

int sumN(int n){
    if(n < 0){
        return 0;
    }
    return n+sumN(n-1);
}

///functional recursion on factorial of n 

long fact(int n){
    if (n == 1){
        return 1;
    }
    return n * fact(n-1);
}

//using functional recursion to reverse an array 

void reverseArray(vector<int> &arr,int start, int end){
    if(start >= end) return;

    swap(arr[start],arr[end]);
    reverseArray(arr,start+1,end-1);
}

//reversing array using single pointer variable
void reverseArray1(vector<int> &arr,int i,int n){
    if(i >= n/2) return;
    swap(arr[i],arr[n-1-i]);
    reverseArray1(arr,i+1,n);
}

bool palindromicString(string s,int i,int n){
    if(i >= n/2) return true;
    if(s[i] != s[n-1-i]) return false;
    return palindromicString(s,i+1,n);
}

//finding the nth fibonacci number using recursion 

int fibonacci(int n){
    if(n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

///fibonacci using looops

int fibonacciloop(int n){
    int a = 0;
    int b = 1;
    int fib = 0;
    for(int i=2;i<n;i++){
        fib = a + b;
        a = b;
        b = fib;
    }
    return fib;
}

int main(){
    int n;
    cin>>n;

    cout << fibonacci(n);
    cout << endl;
    cout << fibonacciloop(4);
    // cout << "Plindromic String: " << endl;
    // cout << boolalpha;
    // cout << palindromicString("racecar",0,7);



    // vector<int> arr = {1,2,3,4,5};
    // int start = 0;
    // int end = arr.size() - 1;
    // cout << "Array before reversing: ";
    // for(auto v:arr){
    //     cout << v << " ";
    // }
    // cout << endl;
    // reverseArray1(arr,0,5);
    // cout << "Array  after reversing: ";
    // for(auto v: arr){
    //     cout << v << " ";
    // }

    // cout << fact(n);

    return 0;
}