#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main(){
	int n, m;
	int heads[20000];
	int knights[20000];
	int i;
	int j;
	int ctr;
	int cost;
	
	scanf("%d %d", &n, &m);

	while(n != 0 && m != 0){
		ctr = 0;
		cost = 0;

		for(i=0; i<n; i++)
			scanf("%d", &heads[i]);
		for(i=0; i<m; i++)
			scanf("%d", &knights[i]);

		if(n > m)
			printf("Loowater is doomed!\n");
		else{
			qsort(heads, n, sizeof(int), compare);
			qsort(knights, m, sizeof(int), compare);

			while(heads[0] > knights[ctr])
				ctr++;

			if(n > m-ctr)
				printf("Loowater is doomed!\n");
			else{
				j = ctr;
				i = 0;
				while(i < n && j < m){
					if(heads[i] > knights[j])
						j++;
					else{
						cost += knights[j];
						j++;
						i++;
					}
				}
				if(i == n)
					printf("%d\n", cost);
				else
					printf("Loowater is doomed!\n");
			}
		}
		scanf("%d %d", &n, &m);
	}
	return 0;
}
