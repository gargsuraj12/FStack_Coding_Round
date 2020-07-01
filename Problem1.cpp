#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll collectRoses(vector<int> &A, int &n){
    if(A.empty()) return 0;
    if(n == 1) return A[0];
    if(n == 2) return max(A[0], A[1]);
    if(n == 3) return max(A[0]+A[2], A[1]);
    
    vector<ll> dp(n);
    dp[0] = A[0]; dp[1] = A[1]; dp[2] = dp[0]+A[2];
    for(int i=3; i<n; i++){
        dp[i] = (ll)A[i] + max(dp[i-2], dp[i-3]);
    }
    return max(dp[n-1], dp[n-2]);
}

int main(){
    int tc, n;
    vector<int> A;
    cin>>tc;
    while(tc--){
        cin>>n;
        A.resize(n);
        for(int i=0; i<n; i++){
            cin>>A[i];
        }
        cout<<collectRoses(A, n)<<endl;
    }
    return 0;
}