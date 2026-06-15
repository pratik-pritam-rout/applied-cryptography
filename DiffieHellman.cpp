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

int main(){
    int q; //prime no
    cout << "Enter a prime number q : " << endl;
    cin >> q;

    int a; //primitive root --> alpha 
    cout << "Enter a primitive root of the number q : " << endl;
    cin >> a;

    int priv_key_A, priv_key_B;
    cout << "Enter private key of A : ";
    cin >> priv_key_A; 
    cout << "Enter private key of B : ";
    cin >> priv_key_B;

    //public key of A = a^private_keyA mod q
    int pub_key_A = fastExpo(a, priv_key_A, q);
    int pub_key_B = fastExpo(a, priv_key_B, q);

    //shared secret key
    int kA = fastExpo(pub_key_B, priv_key_A, q);
    int kB = fastExpo(pub_key_A, priv_key_B, q);

    cout << "Shared secret of A : " << kA << endl;
    cout << "Shared secret of B : " << kB << endl;
    return 0;
}