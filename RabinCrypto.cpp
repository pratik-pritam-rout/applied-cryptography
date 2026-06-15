#include<iostream>
using namespace std;

long long fastExpo(long long a, long long n, long long mod){
    long long ans = 1;
    a = a % mod;
    while(n > 0){
        if(n % 2 == 1){
            ans = (ans * a) % mod;
            n--;
        }
        else{
            n = n / 2;
            a = (a * a) % mod;
        }
    }
    return ans;
}

int modInv(int a, int m){
    for(int i = 1; i < m; i++){
        if((a * i) % m == 1){
            return i;
        }
    }
    return 0;
}

int crt(int a1, int m1, int a2, int m2){
    int M = m1 * m2;
    int M1 = M / m1;
    int M2 = M / m2;
    int M1_inv = modInv(M1, m1);
    int M2_inv = modInv(M2, m2);

    int x = (a1*M1*M1_inv + a2*M2*M2_inv) % M;
    if(x < 0){
        x += M;
    }
    return x;
}

int main(){
    long long p, q;
    cout << "Enter two large prime numbers : ";
    cin >> p >> q;

    int n = p * q; //public key
    //private key {q, n}

    //encryption
    int pt;
    cout << "Enter message : ";
    cin >> pt; 
    int c = fastExpo(pt, 2, n);
    cout << "Ciphertext : " << c << endl;

    //decryption
    int mp = fastExpo(c, (p + 1) / 4, p);
    int mq = fastExpo(c, (q + 1) / 4, q);

    //four points (+-mp, +-mq)
    //(+mp, +mq) (+mp, -mq) (-mp, +mq) (-mp, -mq)
    //crt(a1, m1, a2, m2)
    int ans1 = crt(mp, p,  mq, q);
    int ans2 = crt(mp, p, q - (mq % q), q);
    int ans3 = crt(p - (mp % p), p, +mq, q);
    int ans4 = crt(p - (mp % p), p, q - (mq % q), q);

    cout << "Decrypted values : " << ans1 << " , " << ans2 << " , " << ans3 << " , " << ans4 << endl;


    return 0;
}