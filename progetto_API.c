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

long int dijkstra(int V, int** grafo, int nodo)
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

void order(pair * classifica, int k) {
	pair temp;
	int i, j;

	for (i = 1; i < k; i++){
		for (j = 0; j < k-i; j++) {
			if (classifica[j].number>classifica[j + 1].number || 
					(classifica[j].number==classifica[j + 1].number && classifica[j].index>classifica[j + 1].index)) {
				temp = classifica[j];
				classifica[j] = classifica[j + 1];
				classifica[j + 1] = temp;
			}
		}
	}
}



int main(){
	char* stringa=malloc(sizeof(char)*MAX);
//	char * mat;
	char c;


	int d, k, tmp;
	long int sum=-1;
	//stringa=NULL;
	
	//long long int maxK=-1;
	
	if(scanf("%d", &d)>0){}
	if(scanf("%d", &k)>0){}
	
	int i;
	int j;
	
	/*if (scanf("%d", &d)==1 && scanf("%d", &k)==1)
		printf("OK");*/
	
	/*int **grafo = (int **)malloc(d * sizeof(int *));
    for (i=0; i<d; i++)
         grafo[i] = (int *)malloc(d * sizeof(int));*/
         
    pair *classifica=malloc(sizeof(pair)*k);
    for(int i=0; i<k; i++){
		classifica[i].number=-1;
		classifica[i].index=-1;
	}

	//fscanf(fp, "%c", &var);
	//fscanf(fp, "%c", &var);
	int index=0;
		
	//printf("%c", var);
	while (fgets(stringa, MAX, stdin)!=NULL){
		printf("BRUH1\n");
		printf("%s", stringa);
	//while ((var=fgetc(stdin))!=EOF){
		if(stringa[0]=='A'){
		printf("BRUH\n");	
		//pend=malloc((2*d+1)*sizeof(char));
		//free(stringa);	
		int **grafo = (int **)malloc(d * sizeof(int *));
		//for (i=0; i<d; i++)	
		printf("OK MAN\n");
		for (i=0; i<d; i++){
			printf("Qui ci arrivo\n");
			grafo[i] = (int *)malloc(d * sizeof(int));
			
			//mat=malloc((20*d+1)*sizeof(char));
			//if(fgets(mat, 20*d+1, stdin)){}
			//printf("%s\n", mat);
			c=getchar_unlocked();
			printf("%c\n", c);
			//int l=0;
			j=0;
			while(c != 0 && c != 10){
				

				tmp = 0; 
				while(c != ',' && c != 0 && c != 10){
					
					tmp = tmp*10+(c - '0');
					grafo[i][j] = tmp;
					
					c=getchar_unlocked();
					//printf("%c", c);	
				}
		/*for (j=0; j<d; j++){
				
				}*/
				//printf("%d", grafo[i][j]);
				c=getchar_unlocked();
				printf("%c\n", c);
				j++;
			}
				//printf("\n");
			
			//free(mat);
		}
			//if(scanf("%c", stringa)>0){}
			/*for (i=0; i<d; i++){
				//free(stringa);
				grafo[i] = (long int *)malloc(d * sizeof(long int));				
				if(fgets(stringa, 2*d+1, stdin)){}
				grafo[i][0]=strtol(stringa, &pend, 10);
				for(j=1; j<d; j++){
					//grafo[i][j]=strtol(stringa, &pend, 10);
					//stringa=pend;
					grafo[i][j]=strtol(pend, &pend, 10);*/
					//stringa=pend;
					
			
			//free(pend);

			//printf("%f\n", time_spent);
			
			
			
			sum=dijkstra(d, grafo, 0);
			free(grafo);
			//printf("%d\n", sum);
			if(index<k-1){
				classifica[index].number=sum;
				classifica[index].index=index;
				//qsort(&classifica, sizeof(classifica) / sizeof(pair), sizeof(pair), (int (*) (const void *, const void *)) &comp);
				//order(classifica, k);
				}
			else if(index==k-1){
				classifica[index].number=sum;
				classifica[index].index=index;
				order(classifica, k);
				}
			else if(classifica[k-1].number>sum){
				classifica[k-1].number=sum;
				classifica[k-1].index=index;
				order(classifica, k);
				}
			
			index=index+1;
			//stringa=malloc(sizeof(char)*MAX);
		}
		
		else if(stringa[0]=='T'){
			printf("BRUHTOP\n");
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
			
	free(classifica);
	return 0;	 
	
}
