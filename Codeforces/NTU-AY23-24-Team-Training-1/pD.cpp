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

#define all(x) (x).begin(), (x).end()
#define dbg(x) if(0) ;
// #define dbg(x) if(0) cerr << "?" << #x << " : " << x << endl;
#define int __int128_t
#define V vector
#define bitcnt __builtin_popcountll

void solve();
signed main(){
    signed tc;
    cin >> tc;
    while(tc--) solve();
}

int To_int(string s){
    int ret = 0;
    for(char c : s){
        ret = 10*ret + c-'0';
    }
    return ret;
}
string To_string(int x){
    string ret;
    while(x){
        ret += ('0'+x%10);
        x /= 10;
    }
    reverse(all(ret));
    return ret;
}

void solve(){

    string sa, sb;
    cin >> sa >> sb;


    int a = To_int(sa);
    int b = To_int(sb);
    int ansa = a, ansb = b;

    int n = sa.size();
    rep(msk,1,1<<n){
        V<int> cnt(10);
        
        int x = 0;
        rep(i,0,n){
            if(msk&1<<i){
                x = 10*x + sa[i]-'0';
            }
            else{
                cnt[sa[i]-'0']++;
            }
        }
        if(x==0) continue;

        int y = b*x/a;
        bool ok = 1;

        ok &= a*y==b*x;

        string sy = To_string(y);
        int tar = sb.size() - sa.size() + bitcnt((signed)msk);
        if(sy.size() > tar) continue;
        sy = string(tar-sy.size(), '0') + sy;

        int j = 0;
        for(char c : sb){
            if(j<(int)sy.size() && sy[j]==c){
                j++;
            }
            else{
                cnt[c-'0']--;
            }
        }

        ok &= j==sy.size();
        rep(c,0,10){
            ok &= cnt[c]==0;
        }

        if(ok && x<ansa){
            ansa = x;
            ansb = y;
        }

    }

    cout << To_string(ansa) << " " << To_string(ansb) << nl;

}