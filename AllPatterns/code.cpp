#include<bits/stdc++.h>


using namespace std;

void starSquare(int n){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << "*";
        }
        cout << endl;
    }
}

void starTriangle(int n){
    for(int i{0};i<n;i++){
        for(int j{0};j<i+1;j++){
            cout << "*";
        } cout << endl;
    }
}

void starTriangle123(int n){
    for(int i{1};i<=n;i++){
        for(int j{1};j<=i;j++){
            cout << j << " ";
        } cout << endl;
    }
}

void starTriangle11(int n){
    for(int i{1};i<=n;i++){
        for(int j{1};j<=i;j++){
            cout << i << " ";
        } cout << endl;
    }
}

void invertedPyramid(int n){
    for(int i{0};i<=n;i++){
        for(int j{1};j<=n-i;j++){
            cout <<"*";
        } cout << endl;
    }
}

void invertedNumbers(int n){
    for(int i{1};i<=n;i++){
        for(int j{1};j<=n+ 1 - i;j++){
            cout <<j << " ";
        } cout << endl;
    }
}

void diamondShape(int n){
    for(int i{0};i < n; i++){
        for(int space{0}; space < n - 1 - i; space++){
            cout << " ";
        }
        for(int k{0};k < 2*i+1;k++){
            cout << "*";
            }
        for(int space{0}; space < n - 1 - i; space++){
            cout << " ";
        }cout << endl;
    }
}

void diamondShapeInverted(int n){
    for(int i{0};i < n; i++){
        for(int space{0}; space < i; space++){
            cout << " ";
        }
        for(int k{0};k < 2*n - (2*i+1);k++){
            cout << "*";
            }
        for(int space{0}; space < i; space++){
            cout << " ";
        }cout << endl;
    }
}
    

void halfDiamondSide(int n){
    for(int i{1};i<=2*n-1;i++){
        int stars = i;
        if(i > n) stars = 2*n-i;
        for(int j=1;j<=stars;j++){
            cout << "*";
        }
        cout << endl;
    }
}

void binTriangle(int n){
    int start{0};

    for(int i{0};i<n;i++){
        if(i%2 == 0) start = 1;
        else start = 0;

        for(int j=0;j<=i;j++){
            cout << start << " ";
            start = 1 - start;
        }
        cout << endl;
    }
}

void TriangleInside(int n){
    for(int i{0};i<n;i++){

        for(int j=0;j<=i;j++){
            cout << j;
        }

        //spaces
        for(int k=0;k<=i;k++){
            cout << " ";
        }

        for(int j=i;j>=0;j++) {
            cout << j;
        }
    }
}

void rightAngledTriangle(int n){
    int num = 1;
    for(int i{0};i<n;i++){
        for(int j{0};j <= i;j++){
            cout << num << " ";
            num = num + 1;
        }cout << endl;
    }
}

void rightTriangleABC(int n){
    for(int i{0};i<n;i++){
        char ch = 'A';
        for(int j{0}; j <= i; j++){
            cout << ch ;
            ch = ch + 1;
        } cout << endl;
    }
}

void invertedRightTriangleABC(int n){
    for (int i{0};i<n;i++){
        char ch = 'A';
        for(int j{0};j<=n-i;j++){
            cout << ch ;
            ch = ch + 1;
        }
        cout << endl;
    }
}

void invertedRightTriangle(int n){
    for (int i{0};i<n;i++){
        for(char ch = 'A';ch <= 'A' + i;ch++){
            cout << ch ;
        }
        cout << endl;
    }
}


void invertedRightTriangleFullABC(int n){
    for (int i{0};i<n;i++){
        for(char ch = 'A';ch <= 'A' + (n - i);ch++){
            cout << ch ;
        }
        cout << endl;
    }
}

void ABBCCC(int n){\
    char ch = 'A';
    for(int i{0};i<n;i++){
        for(int j{0};j<=i;j++){
            cout << ch << " ";
        }
        ch = ch + 1;
        cout << endl;
    }
}

void midTriangle(int n){
    for(int i{0};i<n;i++){
        for(int j{0};j<=n-i-1;j++){
            cout << " ";
        }
        char ch = 'A';
        int breakpoint = (2*i+1)/2;
        for(int k{0};k<2*i + 1;k++){
            cout << ch << " ";
            if(k<=breakpoint) ch++;
            else ch--;
        }
        for(int l{0};l<n-i-1;l++){
            cout << " ";
        }
        cout << endl;
    }
}

void pattern18(int n){

    for(int i{0};i<n;i++){
        // char ch = 'A' + (n-i-1);
        for(char ch = 'E' - i;ch <= 'E';ch++){
            cout << ch << " ";
        }
        //for(int j{0};j<=i;j++){
        //     cout << ch << " ";
        //     ch = ch + 1;
        // }
        cout << endl;
    }
}

void pattern19(int n){
    for(int i{0};i<=n;i++){
        //stars
        for(int j{0};j<=n-i;j++){
            cout << "*" ;
        }
        //spaces
        for(int k{0};k<2*i;k++){
            cout << " ";
        }
        //stars
        for(int l{0};l<=n-i;l++){
            cout << "*";
        }
        cout << endl;
    }
    for(int i{0};i<=n;i++){
        for(int j{0};j<=i;j++){
            cout << "*";
        }
        for(int k{0};k<2*n-2*i;k++){
            cout << " ";
        }
        for(int l{0};l<=i;l++){
            cout << "*";
        }
        cout << endl;
    }
}

void pattern20(int n){
    for(int i{1};i<=n;i++){
        for(int j{1};j<=i;j++){
            cout << "*";
        }
        for(int k{1};k<=2*n-2*i;k++){
            cout << " ";
        }
        for(int l{1};l<=i;l++){
            cout << "*";
        }
        cout << endl;
    }
    for(int i{1};i<=n;i++){
        for(int j{1};j<=n-i;j++){
            cout << "*";
        }
        for(int k{1};k<=2*i;k++){
            cout << " ";
        }
        for(int l{1};l<=n-i;l++){
            cout << "*";
        }
        cout << endl;
    }
}

void pattern21(int n){
    for(int i{0};i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 || i == n-1 || j==0 || j == n-1){
                cout << "*";
            } else{
                cout << " ";
            }
        }cout << endl;
    }
}

void pattern22(int n){
    for(int i{0};i<2*n-1;i++){
        for(int j{0};j<2*n-1;j++){
            int top = i;
            int left = j;
            int right = (2*n-2)-j;
            int down = (2*n-2)-i;
            cout << (n - min(min(top,down),min(left,right))) << " ";
        }
        cout << endl;
    }
}



int main(){
    int numberOfTestCases;
    cin >> numberOfTestCases;

    for(int i{0};i<numberOfTestCases;i++){
        int n;
        cin >> n;
        pattern22(n);
        cout << endl;
    }




    return 0;
}