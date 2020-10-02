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


int main() {
    ll length = 10000001;
    vector<bool> sieve(length, true);
    vector<ll> vect(0);
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i= 2; i < length; i++){
        int aux = 2;

        if(!sieve[i])
            continue;


        vect.insert(vect.end(), i);

        while( aux * i < length){
            sieve[aux * i] = false;
            aux++;
        }
    }
    for(int x = 0; x < n; x++){
        int i= 0, j = vect.size() - 1;
        bool flag = false;
        while(i < j){
            ll mid = i + (j - i) / 2;
            ll val = vect[mid] * vect[mid];
            if(val == arr[x]){
                flag = true;
                break;
            } else if( val < arr[x]){
                i = mid + 1;
            } else {
                j = mid;
            }
        }

        if(flag){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
	return 0;
}
