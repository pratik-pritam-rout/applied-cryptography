#include <iostream>
using namespace std;

int jacobi(int a, int n){
    if(n <= 0 || n % 2 == 0){
        return 0; //invalid case
    }
    
    a = a % n;
    int result = 1;
    
    while(a != 0){
        
        //step 1 : handle factor of 2
        while(a % 2 == 0){
            a = a / 2;
            int r = n % 8;
            if(r == 3 || r == 5){
                result = -result;
            }
        }

        //step 2 : swap (quadratic reciprocity)
        int temp = a;
        a = n;
        n = temp;

        //step 3 : sign change if both = 3 mod 4
        if(a % 4 == 3 && n % 4 == 3){
            result = -result;
        }

        //step 4 : reduce
        a = a % n;
        
    }

    //step 5 : final result
    if(n == 1){
        return result;
    }
    else{
        return 0;
    }
}

int main() {
    int a, n;
    cout << "Enter a : ";
    cin >> a;
    cout << "Enter n : ";
    cin >> n;
    int ans = jacobi(a, n);
    cout << "Jacobi : " << ans << endl;
    return 0;
}