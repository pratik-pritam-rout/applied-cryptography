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

bool point_validation(int a, int b, int mod, int x1, int y1){
    int rhs = (x1 * x1 * x1 + a * x1 + b) % mod;
    int lhs = (y1 * y1) % mod;
    if(rhs == lhs){
        return true;
    }
    return false;
}

int main(){

    int a, b, mod;
    cout << "a : ";
    cin >> a;

    cout << "b : ";
    cin >> b;

    cout << "mod : ";
    cin >> mod;

    //generate all points
    for(int x = 0; x < mod; x++){
        int rhs = (x * x * x + a * x + b) % mod ;
        for(int y = 0; y < mod; y++){
            int lhs = (y * y) % mod;
            if(lhs == rhs){
                cout << "x : " << x << " , ";
                cout << "y : " << y << endl;
            }
        }
    }

    //point validation 
    int x1, y1;

    cout << "Enter x1 : ";
    cin >> x1;
    cout << "Enter y1 : ";
    cin >> y1;

    cout << "Point lies on the curve : " << point_validation(a, b, mod, x1, y1) << endl;

    return 0;
}