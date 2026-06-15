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

int legendre(int a, int n){
    int temp = fastExpo(a, (n - 1) / 2, n);
    if(temp == 1){
        return 1;
    }
    else{
        return -1;
    }
    return 0;
}

int main(){
    int a, n;
    cout << "Enter a, n : ";
    cin >> a >> n;
    cout << "Legendre : " << legendre(a, n) << endl;
    return 0;
}