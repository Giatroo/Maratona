#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

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

const int MAX = 112345;

int n;
bool vis[MAX];
vii a;
int num, maxi;
int h;

int main() {
	cin >> n;
	vis[0] = vis[n+1] = true;
	frr (i, n) {
		vis[i] = false;
		cin >> h;
		a.pb(mk(h, i));
	}

	num = maxi = 1;
	sort(a.begin(), a.end());
	fr (i, n) {
		if (!vis[a[i].s - 1] && !vis[a[i].s + 1]) num++;
		if (vis[a[i].s - 1] && vis[a[i].s + 1]) num--;
		if (a[i].f != a[i+1].f || i == n-1) maxi = max(maxi, num);
		vis[a[i].s] = true;
	}

	cout1e(maxi+1);

	return 0;
}