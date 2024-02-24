//君の手を握ってしまったら
//孤独を知らないこの街には
//もう二度と帰ってくることはできないのでしょう
//君が手を差し伸べた 光で影が生まれる
//歌って聞かせて この話の続き
//連れて行って見たことない星まで
//さユリ - 花の塔
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <bitset>
#include <climits>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <cstring>
#include <fstream>
using namespace std;
typedef long long ll;
#define int ll
#define starburst ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define maxn 200005
#define mod 1000000007

void solve(){
    int n; cin >> n; 
    vector<int> a(n + 1, 0), p(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        p[i] = a[i] + p[i - 1];
    }
    vector<int> L(n + 1), R(n + 1), ans(n + 1), L2(n + 1, 0), R2(n + 1, 0);
    L2[1] = 1e18;
    R2[n] = 1e18; 
    for(int i = 1, simple = 1; i <= n; ++i){
        if(a[i] != a[i - 1] && i > 1){
            L2[i] = 1;
        }else if(i > 1){
            L2[i] = L2[i - 1] + 1;
        }
        if(i > 1 && a[i - 1] > a[i]){
            L[i] = 1;
        }else if(simple || p[i - 1] <= a[i]) L[i] = 1e18;
        else {
            int l = 1, r = i - 1;
            while(l != r){
                int mid = (l + r) / 2 + 1;
                if(p[i - 1] - p[mid - 1] <= a[i]) r = mid - 1;
                else l = mid;
            }
            L[i] = max(L2[i - 1] + 1, i - l);
        }
        simple &= (a[i] == a[1]);
    }
    for(int i = n, simple = 1; i >= 1; --i){
        if(a[i] != a[i + 1] && i < n){
            R2[i] = 1;
        }else if(i < n){
            R2[i] = R2[i + 1] + 1;
        }
        if(i < n && a[i + 1] > a[i]){
            R[i] = 1;
        }else if(simple || p[n] - p[i] <= a[i]) R[i] = 1e18;
        else {
            int l = i + 1, r = n;
            while(l != r){
                int mid = (l + r) / 2;
                if(p[mid] - p[i] <= a[i]) l = mid + 1;
                else r = mid;
            }
            R[i] = max(R2[i + 1] + 1, r - i);
        }
        simple &= (a[i] == a[n]);
    }
    for(int i = 1; i <= n; ++i) ans[i] = min(L[i], R[i]);
    for(int i = 1; i <= n; ++i){
        cout << (ans[i] == 1e18 ? -1 : ans[i]) << ' ';
    }
    cout << '\n';
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
