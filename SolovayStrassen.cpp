#include<iostream>
using namespace std;

int jacobi(int a, int n){
    if(n <= 0 || n % 2 == 0){
        return 0;
    }

    a = a % n;
    int result = 1;
    
    while(a != 0){

        while(a % 2 == 0){
            a = a / 2;
            int r = n % 8;
            if(r == 3 || r == 5){
                result = -result;
            }
        }

        int temp = a;
        a = n;
        n = temp;

        if(a % 4 == 3 && n % 4 == 3){
            result = -result;
        }

        a = a % n;
    }

    if(n == 1){
        return result;
    }
    else{
        return 0;
    }
}

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

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

int main(){

    int n, a;
    cout << "Enter number : ";
    cin >> n;

    cout << "Enter a : ";
    cin >> a;

    int g = gcd(a, n);

    if(g > 1){
        cout << "Composite" << endl;
        return 0;
    }


    int x = fastExpo(a, (n - 1)/2 , n);

    int y = jacobi(a, n);
    if(y < 0){
        y = n - 1;
    }

    if(x % n == y % n){
        cout << "Probably Prime" << endl;
    }
    else{
        cout << "Composite" << endl;
    }

    return 0;
}