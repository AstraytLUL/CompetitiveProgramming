#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define pii pair<int, int>
#define ff first
#define ss second
#define io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int M[1005][1005];

signed main(){
    io
    int n, m; cin >> n >> m;
    vector<int> R(n, 1e6 + 1), C(m, 1e6 + 1);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> M[i][j];
            R[i] = min(R[i], M[i][j]);
            C[j] = min(C[j], M[i][j]);
        }
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int mn = min(R[i], C[j]);
            if(mn == M[i][j]){
                ans++;
            }
        }
    }
    cout << ans << '\n';
}