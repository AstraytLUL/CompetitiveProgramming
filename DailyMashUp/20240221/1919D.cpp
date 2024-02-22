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

    int cnt = 0;
    vector<int> a(n + 1), L(n + 1, 0), R(n + 1, 0), del(n + 1, 0);
    vector<pii> ord;

    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        L[i] = i - 1;
        R[i] = i + 1;
        ord.pb(mp(a[i], i));
        if(a[i] == 0) cnt++;
    }

    if(cnt != 1) {
        cout << "No\n";
        return;
    }
    
    L[1] = -1;
    R[n] = -1;
    bool ans = 1;

    sort(ord.begin(), ord.end());

    while(ord.size() > 1){
        pii t = ord.back();
        ord.pop_back();
        int val = t.ff, pos = t.ss;
        if(del[pos] == 1) continue;
        int l = L[pos], r = R[pos];
        bool remove = 0;
        if(l != -1 && (a[l] == val - 1 || a[l] == val)) remove = 1;
        if(r != -1 && (a[r] == val - 1 || a[r] == val)) remove = 1;
        
        if(remove){
            del[pos] = 1;
            if(l != -1) R[l] = r;
            if(r != -1) L[r] = l;
        }else{
            ans = 0;
            break;
        }
    }

    cout << (ans ? "Yes\n" : "No\n");
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
