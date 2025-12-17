#include<bits/stdc++.h>

using namespace std;


void singleDigits(int n){
    while(n>0){
        int lastDigit = n % 10;
        n /= 10;
        cout << lastDigit<< endl;
    }
}

void revNumber(int n){
    int revNum = 0;
    while(n>0){
        int lastDigit = n % 10;
        revNum = (revNum * 10) + lastDigit;
        n /= 10;
    }
    cout << revNum << endl;
}

void plindromicNum(int n){
    int revNum = 0;
    int dp = n;
    while(n>0){
        int lastDigit = n % 10;
        revNum = (revNum * 10) + lastDigit;
        n /= 10;
    }
    if(revNum == dp) cout << "true" ;
    else cout << "false";
}

bool isArmStrong(int n){
    int dp = n;
    int arm = 0;

    while(n>0){
        int ld = n % 10;
        arm += (ld*ld*ld);
        n /= 10;
    }
    return dp == arm ? true : false;
}

void printAllDivisors(int n){
    for(int i{1};i<=n;i++){
        if(n % i == 0)cout << i << " ";
    }
}

void printDivisors(int n,int i){
    if(i > n){ //if i is greater than n, then it will print the n, other wise it will skip it
        return;
    }
    if(n % i == 0)cout << i << " ";
    printDivisors(n,i+1);
}

vector<int> printDivisors(int n){
    vector<int> ls;
    for(int i{1};i<=sqrt(n);i++){
        if(n % i == 0) ls.push_back(i);
        if(n/i != i) ls.push_back(n/i);
    }
    sort(ls.begin(),ls.end());
    return ls;
}

void isPrime(int n){
    int count = 0;
    for(int i{1};i*i<=n;i++){
        if(n % i == 0){
            count++;
            if((n/i) != i) count++;
        }
    }
    if(count == 2){
        cout << "true";
    }
    else{
        cout << "false";
        }
}

int calculateGcd(int n1,int n2){
    int gcd = 1;
    for(int i{1};i<n1;i++){
        if(n1 % i == 0 && n2 % i == 0){
            gcd = i;
        }
    }
    return gcd;
}

//gcd the reverse order

int calculateGCD(int n1,int n2){
    int gcd = 1;
    for(int i=min(n1,n2);i>=1;i--){
        if(n1%i==0 && n2%i==0){
            gcd = i;
            break;
        }
    }
    return gcd;
}

int euclideanAlgorithm(int n1,int n2){
    int gcd = 1;
    while (n1 > 0 && n2 > 0)
    {
        if(n1 > n2) n1 = n1%n2;
        else n2 = n2 % n1;
    }
    if(n1 == 0) return gcd = n2;
    else return n1;
    
}

int main(){
    int n;
    cin>>n;

    // singleDigits(n);
    // int count = (int)log10(n) + 1;
    // cout << endl;
    // cout << count << endl;
    // cout << endl;

    // cout << "The reverse number is: ";
    // revNumber(n);
    // cout << "Plindromic Numbers:" << endl;
    // plindromicNum(n);

    // cout << boolalpha;
    // cout << "ArmStrong Number: " << isArmStrong(n) << endl;

    // cout << "Printing all the divisors of " << n << ": "<< endl;
    // printAllDivisors(n);
    // cout << endl;
    // cout << "Printing all the divisors of (using recursion) " << n << ": "<< endl;
    // printDivisors(n,1);
    // cout << endl;
    // cout << "Optimized Solution to Print Divisors" << endl;
    // for(int val : printDivisors(n)){
    //     cout << val << " ";
    // }
    // cout << endl;
    // isPrime(n) ;
    // cout << endl;

    cout  << calculateGcd(11,13) << endl;
    cout  << "GCD the reverse way: " << calculateGCD(20,40) << endl;
    cout  << "Euclidean Algorithm: " << euclideanAlgorithm(8,6) << endl;

    return 0;
}