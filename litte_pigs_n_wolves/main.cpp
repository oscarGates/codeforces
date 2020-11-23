#include <bits/stdc++.h>
using namespace std;
#define mp             make_pair
#define pb             push_back
#define fi             first
#define se             second
#define sz(x)          (int)((x).size())
#define fill(x, y)     memset(x, y, sizeof(y))
#define all(x)         (x).begin(), (x).end()
#define sci(x)         int x;       scanf("%d", &x);
#define scii(x, y)     int x, y;    scanf("%d %d", &x, &y);
#define sciii(x, y, z) int x, y, z; scanf("%d %d %d", &x, &y, &z);
#define TC(x)          sci(x); while(x --)
#define eprintf(...)   fprintf(stderr, __VA_ARGS__)
#define debug(x)       { cerr << #x << " = " << x << endl; }
#define rep(i, x, y)   for (__typeof(x) i = x; i <= y; i ++)
#define repi(i, x, y)  for (__typeof(x) i = x; i >= y; i --)
#define fore(itr, x)   for (__typeof(x.begin()) itr = x.begin(); itr != x.end(); itr ++)
#define forei(itr, x)  for (__typeof(x.end()) itr = x.end() - 1; itr != x.begin() - 1; itr --)
typedef long long      ll;
typedef pair<int, int> ii;
typedef pair<ii, int>  iii;
typedef vector<int>    vi;
typedef vector<ii>     vii;
typedef vector<iii>    viii;
const   int            inf = 0;
const   double         eps = 0;
const   int            ms  = 0;
const   int            md  = 0;
//     vector<vector<int> > vec( n , vector<int> (m));
const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;
bool hasPig(vector<vector<char>> mat, int i, int j, int n, int m){
    if(i + 1 < n && mat[i+1][j] == 'P')
        return true;
    if(i - 1 >= 0 && mat[i-1][j] == 'P')
        return true;
    if(j + 1 < m && mat[i][j + 1] == 'P')
        return true;
    if(j - 1 >= 0 && mat[i][j - 1] == 'P')
        return true;
    return false;
}

int main() {
    ll n, m;
    cin >> n >> m;

    vector<vector<char>> mat(n, vector<char> (m));
    for(int i = 0; i < n; i++){

        string aux;
        cin >> aux;
        for(int j = 0; j < m; j++){
            mat[i][j] = aux[j];
        }
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == 'W'){
                if(hasPig(mat, i, j, n, m)){
                   ans++;
                }

            }
        }
    }
    cout << ans << endl;

	return 0;
}
