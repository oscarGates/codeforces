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

const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;

void fillZeroes(vector<vector<ll>> matrix, int a, int b){
    for(int i = 0; i < matrix[0].size(); i++){
        matrix[a][i] = 0;
    }
    for(int i = 0; i < matrix.size(); i++){
        matrix[i][b] = 0;

    }
}

bool validate(vector<vector<ll>> matrix, int a, int b){
    for(int i = 0; i < matrix[0].size(); i++){
        if(matrix[a][i] == 1)
            return true;
    }
    for(int i = 0; i < matrix.size(); i++){
        if(matrix[i][b] == 1)
            return true;

    }
    return false;
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> matrix(n, vector<ll>(m));

    for(int i =0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    vector<vector<ll>> ans(n, vector<ll>(m , 1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
           if(matrix[i][j] == 0){
                fillZeroes(ans, i, j);
           }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
           if(matrix[i][j] == 1 && !validate(ans, i, j)){
                cout << "NO" << endl;
                return 0;
           }
        }
    }
    cout << "YES" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

	return 0;
}
