#include<iostream>
using namespace std;

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

int modInverse(int e, int phi){
    for(int d = 1; d < phi; d++){
        if((d * e) % phi == 1){
            return d;
        }
    }
    return -1;
}

int fastExpo(int a, int b, int n){
    int ans = 1;
    a = a % n;
    while(b > 0){
        if(b % 2 == 1){ //odd
            ans = (ans * a) % n;
            b--;
        }
        else{
            b = b / 2;
            a = (a * a) % n;
        }
    }
    return ans;
}

int main(){
    int p = 3;
    int q = 11;
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e;
    for(int i = 2; i < phi; i++){
        if(gcd(phi, i) == 1){
            e = i;
            break;
        }
    }

    int d = modInverse(e, phi);

    //public key {e, n} 
    //private key {d, n}

    //encryption 
    int pt = 7;
    cout << "plaintext : " << pt << endl;
    int ct = fastExpo(pt, e, n);
    cout << "Ciphertext : " << ct << endl;

    //decryption 
    int dec = fastExpo(ct, d, n);
    cout << "Decrypted text : " << dec << endl;


    return 0;
}