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


int main() {
    ll  n, m;
    cin >> n >>m;
    ll grid[m][3];

    for(int i = 0; i < m; i++)
        for(int j = 0; j < 3; j++)
            cin >> grid[i][j];

    vector<ll> dancers(n+1, -1);
    for(int i = 0; i < m; i++){
        vector<bool> available(4, true);

        for(int j = 0; j < 3; j++){
            if(dancers[grid[i][j]] != -1){
                available[dancers[grid[i][j]]] = false;
            }
        }

        for(int j = 0; j < 3; j++){
            if(dancers[grid[i][j]] == -1){
                for(int k = 1; k <= 3; k++){
                    if(available[k]){
                        available[k] = false;
                        dancers[grid[i][j]] = k;
                        break;
                    }
                }
            }
        }
    }
    for(int i = 1; i < dancers.size(); i++){
        cout << dancers[i]<< " " ;
    }
    cout << endl;
	return 0;
}
