#include<iostream>
using namespace std;

int modInverse(int e, int phi){
    for(int d = 1; d < phi; d++){
        if((d * e) % phi == 1){
            return d;
        }
    }
    return -1;
}

int main(){
    int e = 7;
    int phi = 40;
    cout << modInverse(e, phi) << endl;;
    return 0;
}