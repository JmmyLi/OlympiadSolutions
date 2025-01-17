// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1033
#include <iostream>
#define endl '\n'
#define A11 first
#define A12 second.first
#define A21 second.second.first
#define A22 second.second.second
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<ll, pair<ll, pair<ll,ll> > > iiii;
const iiii identidade = MP(1,MP(0,MP(0,1)));
const iiii base = MP(1,MP(1,MP(1,0)));
ll MODULO,N,TC;
iiii multiplicar(iiii matriza,iiii matrizb){
	ll a11 = matriza.A11, a12 = matriza.A12, a21 = matriza.A21, a22 = matriza.A22;
	ll b11 = matrizb.A11, b12 = matrizb.A12, b21 = matrizb.A21, b22 = matrizb.A22;
	ll c11 = ( ( ( a11 * b11 ) % MODULO ) + ( ( a12 * b21 ) % MODULO ) );
	ll c12 = ( ( ( a11 * b12 ) % MODULO ) + ( ( a12 * b22 ) % MODULO ) );
	ll c21 = ( ( ( a21 * b11 ) % MODULO ) + ( ( a22 * b21 ) % MODULO ) );
	ll c22 = ( ( ( a21 * b12 ) % MODULO ) + ( ( a22 * b22 ) % MODULO ) );
	return MP(c11,MP(c12,MP(c21,c22)));
}
iiii func(ll expo){
	if (expo == 0) return identidade;
	if (expo == 1) return base;
	if (expo % 2 == 1){
		return multiplicar(base,func(expo-1));
	}
	iiii atual = func(expo/2);
	return multiplicar(atual,atual);
}
int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	while(cin >> N >> MODULO && (N || MODULO)){
		TC++;
		iiii answer = func(N);
		ll exhibit = (2*answer.A11 - 1 + MODULO) % MODULO;
		cout << "Case " << TC << ": " << N << " " << MODULO << " " << exhibit << endl;
	}
	return 0;
} 
