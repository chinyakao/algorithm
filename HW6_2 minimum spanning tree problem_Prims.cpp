#include <stdio.h>  
#include<stdlib.h>  


struct vertex {
	vertex* parent;
	int nuber;
	int color;

};

struct edge {
	int weight;
	vertex* v1;
	vertex* v2;
	int color;
};

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
			vertexs[i].parent = NULL;
			vertexs[i].color = 0;
		}
		edge *edges = new edge[e];
		for (int i = 0; i < e; i++) {//讀edge的側資  
			int v1, v2;
			scanf("%d %d", &v1, &v2);
			if (v1 < v2) {
				edges[i].v1 = &vertexs[v1];
				edges[i].v2 = &vertexs[v2];
			}
			else {
				edges[i].v2 = &vertexs[v1];
				edges[i].v1 = &vertexs[v2];
			}

			scanf("%d", &edges[i].weight);
			edges[i].color = 0;
		}

		vertex *selectVertice = &vertexs[0];
		v--;
		while (v--) {

			selectVertice->color = 2;

			for (int i = 0; i < e; i++) {
				if (edges[i].v1 == selectVertice) {
					if (edges[i].v2->color == 0)
						edges[i].v2->color = 1;
					if (edges[i].color == 0)
						edges[i].color = 1;
				}
				else if (edges[i].v2 == selectVertice) {
					if (edges[i].v1->color == 0)
						edges[i].v1->color = 1;
					if (edges[i].color == 0)
						edges[i].color = 1;
				}
				if (edges[i].v1->color == 2 && edges[i].v2->color == 2) {
					edges[i].color = 2;
				}
			}

			edge*selectEdge = NULL;

			for (int i = 0; i < e; i++) {
				if (selectEdge == NULL)
					if (edges[i].color == 1)
						selectEdge = &edges[i];
					else
						continue;
				else if (edges[i].color == 1 && edges[i].weight < selectEdge->weight) {
					selectEdge = &edges[i];
				}
			}

			if (selectEdge != NULL) {
				selectEdge->color = 2;
				if (selectEdge->v1->color == 1)
					selectVertice = selectEdge->v1;
				else
					selectVertice = selectEdge->v2;

				totalWeight += selectEdge->weight;
				if (option == 1)
					printf("%d %d\n", selectEdge->v1->nuber, selectEdge->v2->nuber);
			}
			else
				break;
		}

		printf("%d\n", totalWeight);
	}

	//system("pause");  
	return 0;
}