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

ll arrToInt(vector<ll> arr){
    ll ans = 0;
    for(int i = 0; i < arr.size(); i++){
        ans *= 10;
        ans += arr[i];
    }
    return ans;
}
ll res = 0;
ll minVal = -1;
void backtracking(vector<ll> arr, ll pos, ll fours, ll sevens, ll n){
    if(fours == 0 && sevens == 0){
        ll val = arrToInt(arr);
        if(val >= n && (minVal == -1 || val - n < minVal)){
            minVal = val -n;
            res = val;
        }
        return;
    }
    if(fours > 0){
        arr[pos] = 4;
        backtracking(arr, pos + 1, fours -1, sevens, n);
    }
    if(sevens > 0){
        arr[pos] = 7;
        backtracking(arr, pos + 1, fours, sevens - 1, n);

    }

}
int main() {
    string s;
    cin >> s;
    ll len = (s.size() % 2 == 0)? s.size(): s.size()+1;
      vector<ll> arr(len);
    ll fours = len / 2;
    for(int i = 0; i < len; i++){
        if(fours <= 0)
            arr[i] = 4;
        else
            arr[i] = 7;
        fours--;
    }
    if(stoi(s) > arrToInt(arr))
        len += 2;


    vector<ll> ans(len);
    vector<bool> isAvailable(len, true);
    backtracking(ans, 0, len / 2, len / 2, stoi(s));
    cout << res << endl;
    return 0;
}

