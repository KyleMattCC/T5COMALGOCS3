#include<stdio.h>
#include<math.h>

int gcd(int x, int y){
	int z;
	while(y != 0){
		z = y;
		y = x%y;
		x = z;
	}
	return x;
}

int main(){
	int n, set[50], i, j;
	double pi, nofacctr, pairs;

	scanf("%d",&n);
	while(n){
		nofacctr = 0;
		pairs = 0;
		for(i=0; i<n; i++)
			scanf("%d", &set[i]);

		for(i=0; i<n-1; i++){
			for(j=i+1; j<n; j++){
				pairs++;
				if(gcd(set[i], set[j]) == 1)
					nofacctr++;
			}
		}

		if(nofacctr == 0)
			printf("No estimate for this data set.\n");
		else{
			pi = sqrt((pairs*6)/nofacctr);
			printf("%lf\n", pi);
		}
		scanf("%d",&n);
	}
	return 0;
}
