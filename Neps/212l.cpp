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
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) > (b) ? (a) : (b)
#define INF INT_MAX

using namespace std;

ll n, m;
ll s, t, b;
vector<pll> adj[1123];
ll dist[1123];

void dijkstra(ll S) {
  set<pll> f;
  fora(i, n+2) dist[i] = INF;
  f.insert(mk(0, S));

  while (!f.empty()) {
    pll aux = *f.begin(); f.erase(f.begin());

    if (dist[aux.s] == INF) {
      // cout << "Olhando " << aux.s << endl;
      dist[aux.s] = aux.f;

      forita (it, adj[aux.s])
        if (dist[it->f] > dist[aux.s] + it->s)
          f.insert(mk(dist[aux.s] + it->s, it->f));
    }
  }
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get2(n, m);
  n += 2;
  fora(i, m) {
    get3(s, t, b);
    adj[s].pb(mk(t, b));
    adj[t].pb(mk(s, b));
  }

  dijkstra(0);
  cout << dist[n-1] << endl;


  return 0;
}
