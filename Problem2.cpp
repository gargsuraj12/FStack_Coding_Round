#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll calcTime(vector<int> &A, int &n){
    if(n == 0) return 0;
    ll sum = accumulate(A.begin(), A.end(), 0);
    ld avg_d = (ld)sum/n;
    ll avg = sum/n;
    // cout<<avg_d<<" "<<(ld)avg<<endl;
    if(avg_d != (ld)avg)
        return -1;
    ll res = 0;
    for(auto x : A){
        res += abs(avg-x);
    }
    return res;
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
        cout<<calcTime(A, n)<<endl;
    }
    return 0;
}