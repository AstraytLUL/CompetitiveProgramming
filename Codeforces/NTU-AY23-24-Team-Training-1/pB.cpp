#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define pii pair<int, int>
#define ff first
#define ss second
#define io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define nl '\n'
#define rep(i,a,b) for(int i=(int)a; i<(int)b; i++)

const int N = 1e5+5;
const int A = 205;

int n;
int a[N];

int prv[N];
int dp[N][A];

signed main(){
    io

    cin >> n;
    
    rep(i,1,n+1){
        cin >> a[i];

        rep(x,0,A){
            dp[i][x] = dp[i-1][x];
            
            if(x-a[i]>=0 && prv[x-a[i]]){
                int j = prv[x-a[i]];
                dp[i][x] = max(dp[i][x], dp[j-1][x]+2);
            }
        }

        prv[a[i]] = i;
    }


    int ans = 0;
    rep(x,0,A){
        ans = max(ans, dp[n][x]);
    }
    cout << ans << nl;
}