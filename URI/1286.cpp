#include <bits/stdc++.h>
typedef long long int ll;
typedef long double lld;
#define fora(i, n) for (ll i = 0; i < n; i++)
#define forai(i, n) for (ll i = 1; i <= n; i++)
#define ford(i, n) for (ll i = n-1; i >= 0; i--)
#define fordi(i, n) for (ll i = n; i >= 0; i--)
#define forita(it, c) for(auto it = c.begin(); it != c.end(); it++)
#define foritd(it, c) for(auto it = c.rbegin(); it != c.rend(); it++)
#define f first
#define s second
#define sortvector(v) sort(v.begin(), v.end())
#define sortvectorby(v, f) sort(v.begin(), v.end(), f)
#define pb push_back
#define mk make_pair
#define pll pair<ll, ll>
#define cout1(a) cout << (a)
#define cout2(a, b) cout << (a) << " " << (b)
#define cout3(a, b, c) cout << (a) << " " << (b) << " " << (c)
#define cout1e(a) cout1(a) << endl
#define cout2e(a, b) cout2(a, b) << endl
#define cout3e(a, b, c) cout3(a, b, c) << endl
#define get1(a) cin >> (a)
#define get2(a, b) cin >> (a) >> (b)
#define get3(a, b, c) cin >> (a) >> (b) >> (c)
#define get4(a, b, c, d) cin >> (a) >> (b) >> (c) >> (d)
#define INF LLONG_MAX
#define M 1000000007

using namespace std;

ll n, p;
ll t, a;
ll dp[21][31];

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  while (n != 0) {
    cin >> p;

    cin >> t >> a;
    fora (i, p+1) dp[0][i] = -1;
    dp[0][a] = t;

    forai (i, n-1) {
      cin >> t >> a;
      forai (j, p) {
        dp[i][j] = max((ll)-1, dp[i-1][j]);
        if (j - a > 0 && dp[i-1][j-a] != -1)
          dp[i][j] = max(dp[i][j], dp[i-1][j-a] + t);
      }
      dp[i][a] = max(dp[i][a], t);
    }

    // fora (i, n) {
    //   forai (j, p) cout1(dp[i][j]) << " ";
    //   cout << endl;
    // }
    // cout << endl;

    ll maxi = 0;
    forai (i, p) maxi = max(maxi, dp[n-1][i]);
    cout2e(maxi, "min.");
    cin >> n;
  }

  return 0;
}