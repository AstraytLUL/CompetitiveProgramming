#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
using namespace std;
#define pii pair<int, int>
#define ff first
#define ss second
#define io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

#define nl '\n'
#define rep(i,a,b) for(int i=(int)a; i<(int)b; i++)

#define all(x) (x).begin(), (x).end()
#define dbg(x) if(0) ;
// #define dbg(x) cerr << "?" << #x << " : " << x << endl;
#define int long long
// #define Int __int128_t
#define V vector


const int B = 30;

int cdiv(int a,int b){
    return (a-1)/b+1;
}

void solve(){

    int n;
    cin >> n;
    V<int> cnt(B);
    
    rep(i,0,n){
        int x;
        cin >> x;

        rep(j,0,B) if(x&1<<j){
            cnt[j]++;
        }
    }

    while(1){
        bool decreasing = 1;
        rep(i,1,B){
            decreasing &= cnt[i-1] >= cnt[i];
        }
        if(decreasing) break;

        rep(i,1,B) if(cnt[i-1] < cnt[i]){
            int mov = cdiv(cnt[i]-cnt[i-1], 3);
            cnt[i] -= mov;
            cnt[i-1] += 2*mov;
        }
    }

    int ans = cnt[0];
    cout << ans << nl;
}

signed main(){
    io
    int t = 1; cin >> t;
    while(t--) solve();
}