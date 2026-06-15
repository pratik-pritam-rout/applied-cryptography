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

bool isPrime(long long n){ //miller-rabin test
    //step 1 : n - 1 = 2^k * m
    long long d = n - 1;
    long long k = 0;
    while(d % 2 == 0){
        d = d / 2; 
        k++;
    }

    //step 2 : choose a = 2   1 < a < n
    long long a = 2;

    // step 3 : b = 2^d mod n
    long long x = fastExpo(a, d, n);

    if(x == 1 || x == n - 1){
        return true;
    }

    //step 4 : repeated squaring
    for(int i = 1; i < k; i++){
        x = (x * x) % n;
        if(x == n - 1){
            return true;
        }
    }

    return false;
}

int main(){
    long long n;
    cout << "Enter number : " << endl;
    cin >> n;

    if(isPrime(n)){
        cout << "Probably Prime" << endl;
    }
    else{
        cout << "Not a prime. Composite Number" << endl;
    }
    return 0;
}