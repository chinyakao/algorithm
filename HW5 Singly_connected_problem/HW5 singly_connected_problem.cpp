#include<stdlib.h>
#include<stdio.h>

bool ans = true;

struct node {
	int color;
	node *parent;
	node **adjacent;
	int adjacent_cnt;
}; 


void DFS(node *nodes, node* v) {
	//cnt++;
	v->color = 1;
	for (int i = 0; i < v->adjacent_cnt; i++) {
		if (v->adjacent[i]->color == 0) {
			v->adjacent[i]->parent = v;
			DFS(nodes, v->adjacent[i]);
		}
		else if (v->adjacent[i]->color==2) {
			ans = false;
			return;
		}
	}
	v->color = 2;
	//cnt++;
}


int main() {


	int n;
	scanf("%d", &n);

	int m = 1;
	while (m<=n) {
		ans = true;
		int v;
		scanf("%d", &v);
		node *nodes = new node[v];

		for (int i = 0; i < v; i++) {
			nodes[i].adjacent_cnt = 0;
			nodes[i].color = 0;
			nodes[i].parent = NULL;
			nodes[i].adjacent = new node*[50];
		}

		int e;
		scanf("%d", &e);

		for (int i = 0; i < e; i++) {
			int from;
			int to;
			scanf("%d", &from);
			scanf("%d", &to);
			nodes[from].adjacent[nodes[from].adjacent_cnt] = &nodes[to];
			nodes[from].adjacent_cnt++;
		}
		//cnt = 0;

		for (int i = 0; i < v && ans; i++) {
			for (int j = 0; j < v; j++) {
				nodes[j].color = 0;
				nodes[j].parent = NULL;
			}
			DFS(nodes, &nodes[i]);
		}

		if(ans)
			printf("%d YES\n", m);
		else
			printf("%d NO\n", m);

		m++;
	}


	//system("pause");
	return 0;
}
