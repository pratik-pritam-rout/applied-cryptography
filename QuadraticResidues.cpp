#include <iostream>
#include<set>
using namespace std;
int main() {
    int m;
    cout << "Enter modulo : ";
    cin >> m;
    
    set<int> residues;
    
    
    for(int i = 0; i < m; i++){
        int res = (i * i ) % m;
        residues.insert(res);
    }
    
    cout << "Quadractic residues are : " << endl;
    
    for(int r : residues){
        cout << r << endl;
    }
    return 0;
}