#include <limits.h> 
#include <stdio.h> 
#define V 9
#include<iostream>
int minDistancia(int dist[], bool A[]) 
{ 
	int min = INT_MAX, min_indice; 

	for (int v = 0; v < V; v++) 
		if (A[v] == false && dist[v] <= min) 
			min = dist[v], min_indice = v; 

	return min_indice; 
} 

void Solucion(int dist[]) 
{ 
	printf("Vertice  \t\t Distancia desde  el origen\n"); 
	for (int i = 0; i < V; i++) 
		printf("%d \t\t %d\n", i, dist[i]); 
} 

void dijkstra(int graph[V][V], int src) 
{ 
	int dist[V]; 
	bool A[V]; 
	for (int i = 0; i < V; i++) 
		dist[i] = INT_MAX, A[i] = false; 
	dist[src] = 0; 
	for (int count = 0; count < V - 1; count++) {  
		int u = minDistancia(dist, A); 
		A[u] = true; 
		for (int v = 0; v < V; v++) 
			if (!A[v] && graph[u][v] && dist[u] != INT_MAX 
				&& dist[u] + graph[u][v] < dist[v]) 
				dist[v] = dist[u] + graph[u][v]; 
	} 
	Solucion(dist); 
} 
int main() 
{ 
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
	dijkstra(graph, 0); 
		return 0; 
} 

