#include <iostream>
using namespace std;

// Fast modular exponentiation
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        exp = exp / 2;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    long long p = 23;   // prime
    long long g = 5;    // generator

    // Private keys
    long long a = 6;  // Alice
    long long b = 15; // Bob
    long long e = 13; // Eve (attacker)

    // Public keys
    long long A = power(g, a, p); // Alice sends
    long long B = power(g, b, p); // Bob sends

    cout << "Original Public Keys:\n";
    cout << "Alice sends: " << A << endl;
    cout << "Bob sends: " << B << endl;

    // Eve intercepts and replaces keys
    long long E1 = power(g, e, p);
    long long E2 = power(g, e, p);

    cout << "\nEve intercepts and sends fake keys!\n";

    // Alice computes shared key with Eve (thinking it's Bob)
    long long key_Alice = power(E1, a, p);

    // Bob computes shared key with Eve (thinking it's Alice)
    long long key_Bob = power(E2, b, p);

    // Eve computes both keys
    long long key_Eve_Alice = power(A, e, p);
    long long key_Eve_Bob = power(B, e, p);

    cout << "\nShared Keys:\n";
    cout << "Alice's key (with Eve): " << key_Alice << endl;
    cout << "Bob's key (with Eve): " << key_Bob << endl;

    cout << "\nEve's keys:\n";
    cout << "With Alice: " << key_Eve_Alice << endl;
    cout << "With Bob: " << key_Eve_Bob << endl;

    return 0;
}