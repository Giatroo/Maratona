#include <bits/stdc++.h>
typedef long long int ll;
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
  int a, b;
  cin >> a >> b;
  if(a*b == 0) cout << "eixos\n";
  else if(a > 0 && b > 0) cout << "Q1\n";
  else if(a > 0 && b < 0) cout << "Q4\n";
  else if(a < 0 && b > 0) cout << "Q2\n";
  else if(a < 0 && b < 0) cout << "Q3\n";
  return 0;
}
