#pragma once
#include <vector>

using namespace std;

class node {
public:
	node();
	node(int);
	node(const node&obj);
	//node(int,node);
	//node& Find(int n);
	void SetParent(node*);
	void addChild(node*);
	int getDepth();
	int getNumber();
	~node();
	vector<node*>child;
	node* parent;
private:

	int number;
	int depth;
	
	
};
