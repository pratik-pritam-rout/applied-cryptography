#include<iostream>
using namespace std;

int modInv(int b, int a){
    int original_a = a;
    int q;
    int r;
    int t1 = 0;
    int t2 = 1;
    int t;
    while(b != 0){
        r = a % b;
        q = a / b;
        t = t1 - t2 * q;

        a = b;
        b = r;
        t1 = t2;
        t2 = t;
    }

    if(t1 < 0){
        t1 += original_a;
    }
    return t1;
}

int main(){
    int a = 11;
    int m = 13;
    cout << "modInv : " << modInv(a, m) << endl;
    return 0;
}