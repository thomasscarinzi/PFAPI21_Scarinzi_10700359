#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define MAX 15

	
typedef struct{
	int number;
	int index;
	} pair;

int minimo(int dist[], bool set[], int V)
{
    int min = INT_MAX; 
    int min_index=INT_MAX;
 
    for (int v=0; v<V; v++){
        if (set[v]==false && dist[v]<=min){
            min=dist[v]; 
            min_index=v;
        }    
	}
    return min_index;
}

long int dijkstra(int V, int grafo[V][V], int nodo)
{
	long int sum=0;		//var per la somma utilizzata per topk
    int dist[V]; 	// array di distanza minima da src a nodo i
    int u;
    bool visitato[V]; 	// vero se l'esplorazione di i è terminata
 
    for (int i=0; i<V; i++){
        dist[i]=INT_MAX; 
        visitato[i]=false;
	}
		dist[nodo]=0;
 
    for (int count=0; count<V; count++) {
        u=minimo(dist, visitato, V);
 
        visitato[u]=true;
 
        for (int v=0; v<V; v++)
            if (!visitato[v] && grafo[u][v] && dist[u] != INT_MAX
                && dist[u] + grafo[u][v] < dist[v]){
				if(dist[v]==INT_MAX){
					sum=sum+dist[u]+grafo[u][v];
					//printf("%d", sum);
				}
				else{
					sum=sum+dist[u]+grafo[u][v]-dist[v];
					}
				dist[v] = dist[u] + grafo[u][v];
            }
    }
	return sum;
   
}

int getGrafo(int d){
	int sum=0;
	int i, j, tmp;
	int grafo[d][d];
	char c;
	c=getchar_unlocked();
	for (i=0; i<d; i++){
		for(j=0; j<d; j++){
			tmp = 0; 
			while(c != ',' && c != 0 && c != 10){
				
				tmp = tmp*10+(c - '0');
				grafo[i][j] = tmp;
				
				c=getchar_unlocked();
			}
			if(i!=d-1 || j!=d-1)
				c=getchar_unlocked();
			
		}
	}
	sum=dijkstra(d, grafo, 0);
	
	return sum;
	}

void maxHeapify(pair * classifica, int i, int* hs){
	int max;
	pair temp;
	//printf("HS=%d\n", *hs);
	//printf("I=%d\n", i);
	int l=2*i+1;
	//printf("L=%d\n", l);
	int r=2*i+2;
	//printf("R=%d\n", r);
	//printf("%d - %d - %d\n", classifica[l].number, classifica[i].number, classifica[r].number);
	if(l<*hs && (classifica[l].number>classifica[i].number || 
		(classifica[l].number==classifica[i].number && classifica[l].index>classifica[i].index)))
		max=l;
	else
		max=i;
	if(r<*hs && (classifica[r].number>classifica[max].number || 
		(classifica[r].number==classifica[max].number && classifica[r].index>classifica[max].index)))
		max=r;
	if(max!=i){
		//printf("PRE: %d - %d\n", classifica[i].number, classifica[max].number);
		temp=classifica[i];
		classifica[i]=classifica[max];
		classifica[max]=temp;
		/*printf("POST: %d - %d\n", classifica[i].number, classifica[max].number);
		for(int l=0; l<10; l++)
			printf("%d ", classifica[l].number);
		printf("\n");*/
		maxHeapify(classifica, max, hs);
		}
	}



int main(){
	char stringa[MAX];

	int d, k;
	long int sum=-1;
	//stringa=NULL;
	
	//long long int maxK=-1;
	
	if(scanf("%d", &d)>0){}
	if(scanf("%d", &k)>0){}
	
	int i;
	//int j;
         
    pair classifica[k];
    for(int i=0; i<k; i++){
		classifica[i].number=-1;
		classifica[i].index=-1;
	}

	//fscanf(fp, "%c", &var);
	//fscanf(fp, "%c", &var);
	int index=0;
		
	//printf("%c", var);
	while (fgets(stringa, MAX, stdin)!=NULL){
		//printf("%s", stringa);
	//while ((var=fgetc(stdin))!=EOF){
		if(stringa[0]=='A'){
		//pend=malloc((2*d+1)*sizeof(char));
		//free(stringa);	
		sum = getGrafo(d);
			//printf("%d\n", sum);
			if(index<k-1){
				classifica[index].number=sum;
				classifica[index].index=index;
				//qsort(&classifica, sizeof(classifica) / sizeof(pair), sizeof(pair), (int (*) (const void *, const void *)) &comp);
				//order(classifica, k);			
				/*for(i=0; i<k; i++)
					printf("%d ", classifica[i].number);
				printf("\n");*/
				}
			else if(index==k-1){
				classifica[index].number=sum;
				classifica[index].index=index;
				for(i=(k-1)/2; i>=0; i--)
					maxHeapify(classifica, i, &k);
				//order(classifica, k);		
				/*printf("PRIMA\n");
				for(i=0; i<k; i++)
					printf("%d ", classifica[i].number);
				printf("\n");*/
				//heapSort(classifica, k);
				/*printf("DOPO\n");
				for(i=0; i<k; i++)
					printf("%d ", classifica[i].number);
				printf("\n");*/
				}
			else if(classifica[0].number>sum){
				classifica[0].number=sum;
				classifica[0].index=index;
				//order(classifica, k);			
				/*printf("PRIMA\n");
				for(i=0; i<k; i++)
					printf("%d ", classifica[i].number);
				printf("\n");*/
				//heapSort(classifica, k);
				maxHeapify(classifica, 0, &k);
				/*printf("DOPO\n");
				for(i=0; i<k; i++)
					printf("%d ", classifica[i].number);
				printf("\n");*/
				}
			
			index=index+1;
			//stringa=malloc(sizeof(char)*MAX);
		}
		
		else if(stringa[0]=='T'){
			if(classifica[0].index!=-1){
				printf("%d", classifica[0].index);
				for (int i=1; i<k; i++) {
					if(classifica[i].index!=-1){
						printf(" %d", classifica[i].index);
					}
				}
			}
			printf("\n");
			//scanf("%c", stringa);
			//printf("%c", stringa[0]);
		}
			
	} 
				//fscanf(fp, "%c", &var);
				/*printf("\n%c\n", var);
				fscanf(fp, "%c", &var);
				printf("\n%c\n", var);*/
			
	//free(classifica);
	return 0;	 
	
}
