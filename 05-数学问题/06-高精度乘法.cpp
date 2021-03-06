#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define NEXTLINE cout << endl;

// C = A * b, A >= 0, b >= 0
vector<int> mul(vector<int> &A, int b) {
    vector<int> C;
    for (int i = 0, t = 0; i < A.size() || t; ++i) {
        if (i < A.size()) 
            t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }

    while (C.size() > 1 && C.back() == 0) 
        C.pop_back();
    return C;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string n1;
    int b;
    cin >> n1 >> b;
    vector<int> A;

    for (int i = n1.length() - 1; i >= 0; --i)
        A.push_back(n1[i] - '0');

    auto C = mul(A, b);
    for (int i = C.size() - 1; i >= 0; --i)
        cout << C[i];
    NEXTLINE; 
    return 0;
}
