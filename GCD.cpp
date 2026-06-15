#include<iostream>
using namespace std;

int gcd(int a, int b){
    while(b != 0){
        int rem = a % b;
        int temp = b;
        b = rem;
        a = temp;
    }
    return a;
    
}

int gcd2(int a, int b){
    if(b == 0){
        return a;
    }

    return gcd2(b, a % b);
}

int main(){
    int a = 18;
    int b = 12;
    cout << gcd2(a, b) << endl;

    return 0;
}