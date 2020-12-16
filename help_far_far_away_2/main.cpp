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
    string s;
    cin >> s;
    string decimal = "00";
    bool flag = false;
    if(s[0] == '-'){
        flag = true;
        s = s.substr(1, s.size() - 1);
    }

    istringstream iss(s);
    vector<string> tokens;
    string token;
    while (getline(iss, token, '.')) {
        if (!token.empty())
            tokens.push_back(token);
    }
    if(tokens.size() == 2){
        int l =  tokens[1].length();
        for(int i = 0; i < min(2, l); i++){
            decimal[i] = tokens[1][i];
        }
    }
    string num;
    int sum = 0;
    string chunk = "";
    stack<string> s1;
    for(int i = tokens[0].size() - 1; i >= 0;i--){
        chunk.insert(0, 1, tokens[0][i]);
        sum++;
        if(sum == 3 || i == 0){
            s1.push(chunk);
            sum = 0;
            chunk = "";
        }
    }

    while(!s1.empty()){
        num.append(s1.top());
        s1.pop();
        if(s1.empty())
            continue;
        num.append(",");
    }
    if(flag)
        cout << "("<< "$"<< num << "." << decimal<< ")";

    else
        cout << "$"<< num << "." << decimal;

	return 0;
}
