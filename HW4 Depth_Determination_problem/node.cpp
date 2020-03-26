#include "node.h"
#include<algorithm>



node::~node()
{
}



node::node()
{
	number = -1;
	depth = -1;
	parent = 0;
}

node::node(int n)
{
	number = n;
	depth = 0;
	parent = new node();
}

node::node(const node & obj)
{
	number = obj.number;
	depth = obj.depth;
	for (int i = 0; i < obj.child.size(); i++) {
		child.push_back(obj.child[i]);
	}
	parent = obj.parent;
}

//node::node(int n, node c)
//{
//	number = n;
//	depth = 1;
//}

//node& node::Find(int n)
//{
	//for (int i = 0; i < child.size(); i++) {
	//	if (child[i].number == n) {
	//		return child[i];
	//	}
	//}

	//for (int i = 0; i < child.size(); i++) {
	//	for (int j = 0; j < child[i].child.size(); j++) {
	//		
	//		if (child[i].child[j].Find(n).number!=0) {
	//			child[i].child.erase(child[i].child.begin() + j);
	//			return child[i].child[j];
	//		}
	//	}
	//}

	//node empty = node();
	//return empty;
//}


void node::SetParent (node* p)
{
	(*this).parent = p;

	depth = p->getDepth() + 1;

	for (int i = 0; i < child.size(); i++) {
		child[i]->SetParent(this);
	}
}

void node::addChild(node* c)
{
	child.push_back(c);
}

int node::getDepth()
{
	return depth;
}

int node::getNumber()
{
	return number;
}
