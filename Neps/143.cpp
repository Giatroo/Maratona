#include <bits/stdc++.h>
typedef long long int ll;
typedef long double lld;
#define fora(i, n) for(ll i = 0; i < n; i++)
#define forai(i, n) for(ll i = 1; i <= n; i++)
#define ford(i, n) for(ll i = n-1; i >= 0; i--)
#define fordi(i, n) for(ll i = n; i >= 0; i--)
#define f first
#define s second
#define sortvector(v) sort(v.begin(), v.end())
#define sortvectorby(v, f) sort(v.begin(), v.end(), f)

using namespace std;

ll min(ll a, ll b)
{
  return (a < b) ? a : b;
}

ll max(ll a, ll b)
{
  return (a > b) ? a : b;
}

int main(int argc, char const *argv[]) {
  int a;
  int tot = 0;
  int can[6] = {100, 50, 25, 10, 5, 1};
  vector<int> out(6);
  cin >> a;

  fora(i, 6)
  {
    tot += a / can[i];
    out[i] = a / can[i];
    a %= can[i];
  }

  cout << tot << endl;
  fora(i, 6) cout << out[i] << endl;

  return 0;
}
