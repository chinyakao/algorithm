#include <stdio.h>
#include<stdlib.h>


struct vertex {
	vertex* root;
	int nuber;
};

struct edge{
	int weight;
	vertex* v1;
	vertex* v2;
	bool used;
};

vertex* findSet(vertex *v) {
	while (v->root != NULL) {
		v = v->root;
	}
	return v;
}

int comp(const void *a, const void *b){
	return (*(edge *)a).weight > (*(edge *)b).weight ? 1 : -1;
}

int main() {

	int n;
	scanf("%d", &n);

	while (n--) {
		int totalWeight = 0;
		int v, e, option;
		scanf("%d %d %d", &v, &e, &option);

		vertex *vertexs = new vertex[v];
		for (int i = 0; i < v; i++) {//初始化
			vertexs[i].nuber = i;
			vertexs[i].root = NULL;
		}

		edge *edges = new edge[e];
		for (int i = 0; i < e; i++) {//讀edge的側資
			int v1, v2;
			scanf("%d %d", &v1, &v2);
			edges[i].v1 = &vertexs[v1];
			edges[i].v2 = &vertexs[v2];
			scanf("%d", &edges[i].weight);
			edges[i].used = false;
		}
		qsort(edges, e, sizeof(edge), comp);//依照weight做排序

		for (int i = 0; i < e; i++) {
			vertex *root1 = edges[i].v1;
			vertex * root2= edges[i].v2;
			while (root1->root != NULL) {
				root1 = root1->root;
			}
			while (root2->root != NULL) {
				root2 = root2->root;
			}

			if (root1 != root2) {
				root2->root = root1;
				edges[i].used = true;
			}
		}

		for (int i = 0; i < v; i++) {//Kruskal's algorithm
			if (edges[i].used) {
				if (option == 1) {
					if(edges[i].v1->nuber<= edges[i].v2->nuber)
						printf("%d %d\n", edges[i].v1->nuber, edges[i].v2->nuber);
					else
						printf("%d %d\n", edges[i].v2->nuber, edges[i].v1->nuber);
				}
				totalWeight += edges[i].weight;
			}
		}
		printf("%d\n", totalWeight);
	}


	//system("pause");
	return 0;
}