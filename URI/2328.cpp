#include <cstdio>
int main(){
	int n,soma=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		soma += x;
	}
	printf("%d\n",soma - n);
	return 0;
} 