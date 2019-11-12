#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define MIN(a, b) (a < b) ? a : b

pair<ll, ll> a[212345];

ll decide(ll h, ll n){
	ll l, r, il, ir, max, aux;
	int marcador = 1;
	l = r = a[0].f; //garante que vamos pegar todos os casos
	il = ir = aux = 0;
	max = 0;

	while(il < n){ //garante que vamos até o final
		printf("h = %lld l = %lld il = %lld r = %lld ir = %lld max = %lld aux = %lld\n", h, l, il, r, ir, max, aux);
		if(h > 0){ //Mexemos no r até h terminar
			if(a[ir].f <= r && r <= a[ir].s){
				r = a[ir].s;
				ir++;
			} else {
				h -= (a[ir].f - r);
				r = a[ir].f;
				if(marcador)
				{
					aux = MIN((r - a[il].s), (a[il+1].f - a[il].s));
					marcador = 0;
				}
				if(h < 0){
					r += h;
					h = 0;
				}
			}
		} else { //Devemos mexer no l
			if(r - l > max) max = r - l;
			l = a[il++].f;
			h += aux;
			marcador = 1;
			/*
			if(a[il].f <= l && l <= a[il].s) //Nesses casos, temos que a distância é a mesma para qualquer l nessas condições
			{
				l = a[il].s + 1; //Colocamos o l fora da região de ar
				h++; //Ganhamos uma altura
				il++; //Vamos para a próxima região com o il.
			} else {
				ll dl, dr;
				dl = a[il].f - l; dr = a[ir].f - r;
				if(dl < dr)
				{
					l = a[il].s + 1;
					il++;
					h += dl + 1;
				} else
				{
					l += dr + 1;
					h += dr + 1;
				}
				if(r <= l){ h = oh; r = l; }
			}
			*/
		}
	}

	if(r - l > max) max = r - l;
//	printf("h = %lld l = %lld il = %lld r = %lld ir = %lld max = %lld\n", h, l, il, r, ir, max);
	return max;
}

int main(){
	ll n, h;
	ll i;

	scanf("%lld %lld", &n, &h);

	for(i = 0; i < n; i++)
		scanf("%lld %lld", &(a[i].f), &(a[i].s));

	a[i].f = a[i-1].s + 2*h;
	a[i].s = a[i].f + 1;

	printf("%lld\n", decide(h, n));

	return 0;
}