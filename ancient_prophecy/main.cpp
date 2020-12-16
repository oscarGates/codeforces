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
ll my[13] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


string isCorrect(string s, ll pos, ll number, bool isNotDig){
    string ans = "";
    if(isNotDig){
        return (s[pos] == '-')? "-": ans;
    }
    for(int i = pos; i < pos+number; i++){
         if(s[i] - '0' >= 0 && s[i]- '0' <= 9){
            ans.pb(s[i]);
        }
    }

    return ans;
}
bool validateDate(ll d, ll m, ll y){
    if(y > 2015 || y < 2013)
        return false;

    if(m < 1 || m > 12)
        return false;

    if(d < 1 || d > 31)
        return false;

    if(my[m] < d)
        return false;
    return true;
}

int main() {
    string s;
    cin >> s;

    map<string, ll> umap;

    for(int i = 0; i < s.size() - 10; i++){

        string d, m, y, g1, g2;

        string aux = "";
        d = ( isCorrect(s, i, 2, false));
        g1 = ( isCorrect(s, i+2, 1, true));
        m = ( isCorrect(s, i+3, 2, false));
        g2 = ( isCorrect(s, i+5, 1, true));
        y = ( isCorrect(s, i+6, 4, false));
        aux+=d;aux+=g1; aux+=m; aux+=g2; aux+=y;
       if(aux.size() == 10 && validateDate(stoi(d), stoi(m), stoi(y))){
            umap[aux]++;
       }
    }
    string ans;
    ll maxVal = 0;
    for( auto const& [key, val] : umap )
    {
        if(val > maxVal){
            maxVal = val;
            ans = key;
        }
    }
    cout << ans << endl;

	return 0;
}
