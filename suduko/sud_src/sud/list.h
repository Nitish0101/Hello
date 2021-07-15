#include"stdio.h"
template<class T>
class LIST
{
	class node
	{
	public:
		T a;//element at this node
		node *l;//link to next node
		node* getnode(T b)
		{
			node *t;
			t=new node;
			t->l=NULL;
			t->a=b;
			return t;
		}
		void deal();
	};
public:
	LIST();
	~LIST();
	int isempty();
	T frontel();
	void frontins(T b);
	T prel();
	void repr();
	int frontdel();
	int pos(T el);
private:
	node *f;
	node *pr;
};