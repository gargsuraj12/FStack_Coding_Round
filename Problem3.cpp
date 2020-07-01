#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

ll countWays(vector<int> &A, vector<int> &B, vector<int> &C, int n){
    ll ways = 0, lc, rc;
    sort(A.begin(), A.end());
    sort(C.begin(), C.end());

    for(int i=0; i<n; i++){
        lc = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
        rc = C.end() - upper_bound(C.begin(), C.end(), B[i]);
        ways += (lc*rc);
    }
    return ways;
}

int main(){
    int n;
    cin>>n;
    vector<int> A(n), B(n), C(n);
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    for(int i=0; i<n; i++){
        cin>>B[i];
    }
    for(int i=0; i<n; i++){
        cin>>C[i];
    }
    cout<<countWays(A, B, C, n)<<endl;
    return 0;
}