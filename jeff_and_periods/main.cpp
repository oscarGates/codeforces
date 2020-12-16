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
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    map<int, vector<ll>> hmap;

    for(int i = 0; i < n; i++){
        vector<ll> v(0);
        if(hmap.count(arr[i]) == 0)
            hmap[arr[i]] = v;
        hmap[arr[i]].push_back(i);
    }
    ll k = 0;
    vector <string> vString(0);
    for( auto const& [key, val] : hmap )
    {
       if(val.size() == 1){
        string aux = to_string(key).append(" 0");
        vString.push_back(aux);
        k++;
        continue;
       }
       ll diff = val[1] - val[0];
       bool flag = true;
       for(int i = 2; i < val.size(); i++){
        if(val[i] - val[i - 1] != diff){
            flag = false;
            break;
        }
       }
       if(flag){
        string aux = to_string(key).append( " ").append( to_string(diff));
        vString.push_back(aux);
        k++;
       }

    }
    cout << k << endl;
    for(int i = 0; i < vString.size(); i++){
        cout << vString[i] << endl;
    }

	return 0;
}
