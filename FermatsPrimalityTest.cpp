#include <iostream>
using namespace std;

int fastExpo(int a, int n, int m){
    int ans = 1;
    a = a % m;
    while(n > 0){
        if(n % 2 == 1){
            ans = (ans * a) % m;
            n--;
        }
        else{
            n = n / 2;
            a = (a * a) % m;
        }
    }
    return ans;
}

bool fermatTest(int p){
    for(int a = 1; a < p; a++){
        int temp = fastExpo(a, p - 1, p);
        if(temp != 1){
            return false;
        }
    }
    return true;
}

int main() {
    cout << "Fermats Primality test : " << endl;
    int n;
    cout << "Enter number : ";
    cin >> n;
    if(fermatTest(n)){
        cout << "Number is probably prime" << endl;
    }
    else{
        cout << "Number is composite";
    }
    return 0;
}