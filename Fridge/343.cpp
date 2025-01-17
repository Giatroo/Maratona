#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define fr(i, n) for (ll i = 0; i < n; i++)
#define frr(i, n) for (ll i = 1; i <= n; i++)
#define frd(i, n) for (ll i = n; i >= 0; i--)
#define forita(it, c) for(auto it = c.begin(); it != c.end(); it++)

#define sortvector(v) sort(v.begin(), v.end())
#define sortvectorby(v, f) sort(v.begin(), v.end(), f)

#define pb push_back
#define mk make_pair
#define f first
#define s second

#define cout1e(a) cout << (a) << endl
#define cout2e(a, b) cout << (a) << " " << (b) << endl
#define cout3e(a, b, c) cout << (a) << " " << (b) << " " << (c) << endl
#define cout4e(a, b, c, d) cout << (a) << " " << (b) << " " << (c) << " " << (d) << endl
#define debug(x) cout << #x << " = " << x << endl
#define get1(a) cin >> (a)
#define get2(a, b) cin >> (a) >> (b)
#define get3(a, b, c) cin >> (a) >> (b) >> (c)
#define get4(a, b, c, d) cin >> (a) >> (b) >> (c) >> (d)

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;
const ll M = 1000000007;
// ===================================================== //

const int N = 1123;
pll box[N];
ll n;
ll memo[N][N];

bool cmp(pll a, pll b) {
	return a.f + a.s < b.f + b.s;
}

ll res(ll i, ll tam) {
	if (tam == 0) return memo[i][tam] = INF;
	if (i == 0) {
		if (tam == 1) return memo[i][tam] = box[0].s;
		else return memo[i][tam] = -1;
	}
	
	if (memo[i][tam] != -2) return memo[i][tam];
	
	ll ans = res(i-1, tam);
  ll rp = res(i-1, tam-1);
	
	if (rp >= box[i].f) ans = max(ans, min(rp-box[i].f, box[i].s));
	return memo[i][tam] = ans;
}

int main(int argc, char const *argv[]) { fastio;
	cin >> n;
	fr (i, n) {
		cin >> box[i].f >> box[i].s;
		box[i].s -= box[i].f; 
	}
	
	sort(box, box+n, cmp);
	// fr (i, n) cout2e(box[i].f, box[i].s);
	
	fr (i, n+2) fr (j, n+2) memo[i][j] = -2; // not listed

	int i = 0;
	while (i < n && res(n-1, i) != -1) {
		i++;
	}
	cout1e(i);

  return 0;
}
