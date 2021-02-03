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
ll maxVal = -1;
void recursive(ll mat[6][6], vector<bool> isAv, vector<ll> arr){
    if(arr.size() == 5){
        ll maxCurr = mat[arr[0]][arr[1]] + 2*mat[arr[2]][arr[3]] +
        mat[arr[1]][arr[0]] + 2*mat[arr[3]][arr[2]] +
        mat[arr[1]][arr[2]] + 2*mat[arr[3]][arr[4]] +
        mat[arr[2]][arr[1]] + 2*mat[arr[4]][arr[3]];

        if(maxCurr > maxVal)
            maxVal = maxCurr;
        return;

    }
    for(int i = 1; i <= 5; i++){
        if(isAv[i]){
            isAv[i] = false;
            arr.push_back(i);
            recursive(mat, isAv, arr);
            arr.pop_back();
            isAv[i] = true;
        }
    }

}

int main() {
    ll mat[6][6];
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 5; j++){
            cin >> mat[i][j];
        }
    }

    vector<bool> isAv(6, true);
    vector<ll> ans(0);
    recursive(mat, isAv, ans);
    cout << maxVal << endl;
	return 0;
}
