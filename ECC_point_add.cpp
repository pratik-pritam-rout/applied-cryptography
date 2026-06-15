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

void point_addition(int a, int b, int mod, int x1, int y1, int x2, int y2){
    int lambda = ((y2 - y1) % mod * modInverse(x2 - x1, mod)) % mod;
    if(lambda < 0) lambda += mod;
    int x3 = (lambda * lambda - x1 - x2) % mod;
    if(x3 < 0) x3 += mod;
    int y3 = (-y1 + lambda * (x1 - x3)) % mod;
    if(y3 < 0) y3 += mod;

    cout << "x3 : " << x3 << " , " << "y3 : " << y3 << endl;
}

void point_negation(int mod, int x1, int y1){
    int x3 = x1;
    int y3 = (mod - y1) % mod;

    cout << "Negation : " << endl;
    cout << "x3 : " << x3 << " ; " << "y3 : " << y3 << endl;

}

void point_doubling(int a, int b, int mod, int x1, int y1){
    int lambda = (((3 * x1 * x1 + a) % mod) * modInverse(2 * y1, mod)) % mod;
    if(lambda < 0){
        lambda += mod;
    }

    int x3 = (lambda * lambda - 2 * x1) % mod;
    if(x3 < 0) x3 += mod;
    int y3 = (-y1 + lambda * (x1 - x3)) % mod;
    if(y3 < 0) y3 += mod;
    cout << "x3 : " << x3 << " , " << "y3 : " << y3 << endl;
}

int main(){

    int a, b, mod; //curve
    cout << "a : ";
    cin >> a;

    cout << "b : ";
    cin >> b;

    cout << "mod : ";
    cin >> mod;

    int x1, y1, x2, y2;

    cout << "Enter x1 & y1: ";
    cin >> x1 >> y1;
    cout << "Enter x2 & y2 : ";
    cin >> x2 >> y2;

    // point_addition(a, b, mod, x1, y1, x2, y2);
    point_doubling(a, b, mod, x1, y1);

    return 0;
}