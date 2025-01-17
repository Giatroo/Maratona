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

queue<char> times;
int M, N;
char a, b;

int main(int argc, char const *argv[]) {
  fora(i, 16)
    times.push('A'+i);

  fora(i, 15)
  {
    cin >> M >> N;
    a = times.front();
    times.pop();
    b = times.front();
    times.pop();
    if(M > N) times.push(a);
    else times.push(b);
  }

  cout << times.front() << endl;

  return 0;
}
