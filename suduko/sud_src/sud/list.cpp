#pragma once
#include "stdafx.h"
#include"list.h"
template<class T>
LIST<T>::LIST()
{
	f=pr=NULL;
}
template<class T>
LIST<T>::~LIST()
{
	if(f!=NULL)
		f->deal();
}
template<class T>
inline int LIST<T>::isempty()
{
	if(f==NULL)
		return 1;
	return 0;
}
template<class T>
void LIST<T>::frontins(T b)
{
	node *t=NULL;
	if(f==NULL)
	{
		f=pr=t->getnode(b);
		return;
	}
	t=t->getnode(b);
	t->l=f;
	f=t;
	pr=f;
}
template<class T>
T LIST<T>::prel()
{
	T r;
	if(pr==NULL)	r=0;
	else
	{
		r=pr->a;
		pr=pr->l;
	}
	return r;
}
template<class T>
inline void LIST<T>::repr()
{
	pr=f;
}
template<class T>
int LIST<T>::frontdel()
{
	if(f==NULL)
		return -1;
	node *t;
	t=f;
	f=f->l;
	pr=f;
	delete t;
	return 1;
}
template<class T>
int LIST<T>::pos(T el)
{
	int r=0;
	for(node*t=f;t!=NULL;t=t->l,r++)
		if(t->a==el)
		{
			r++;
			break;
		}
	return r;
}
template<class T>
void LIST<T>::node::deal()
{
	if(l!=NULL)	l->deal();
	delete this;
}
template<class T>
inline T LIST<T>::frontel()
{
	return f->a;
}