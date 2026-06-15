#include<iostream>
using namespace std;

int fastExpo(int a, int b, int n){
    int ans = 1;
    a = a % n;
    while(b > 0){
        if(b % 2 == 1){ //odd number
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

int modInverse(int a, int m){
    for(int i = 1; i < m; i++){
        if((a * i) % m == 1){
            return i;
        }
    }
    return -1;
}

int main(){
    int p;
    cout << "Enter a prime number : ";
    cin >> p;

    int d;
    cout << "Enter a private key/decryption key : ";
    cin >> d;

    int e1;
    cout << "Enter e1 : ";
    cin >> e1;

    // e2 = e1 ^ d mod p
    int e2 = fastExpo(e1, d, p);
    cout << "e2 : " << e2 << endl;

    //public key {e1, e2, p}

    //encryption 
    //select random integer R
    int r;
    cout << "Enter r : ";
    cin >> r;

    int pt;
    cout << "Enter message : ";
    cin >> pt; 
    int c1 = fastExpo(e1, r, p);
    int c2 = ((pt % p) * fastExpo(e2, r, p)) % p;

    cout << "c1 : " << c1 << endl;
    cout << "c2 : " << c2 << endl;
    
    // decryption
    int temp = fastExpo(c1, d, p);
    int temp_inv = modInverse(temp, p);

    int dec = (c2 * temp_inv) % p;
    cout << "Decrypted message : " << dec << endl;
    return 0;
}