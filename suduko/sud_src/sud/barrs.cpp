#include "StdAfx.h"
#include "barrs.h"
#include"stdio.h"
barrs::barrs(void)
{
	p=NULL;
	for(int i=0;i<9;i++)
		arr[i]=false;//make the list empty
}

barrs::~barrs(void)
{
}
void barrs::ins(int a)
{
	arr[a-1]=true;
}
void barrs::calf()
{
	for(int i=0;i<9;i++)
		if(arr[i])
		{
			f=arr+i;
			break;
		}
	p=f;
}
int barrs::prel()
{
	int i,j;
	if(p==NULL)	return 0;
	i=p-arr+1;
	p=NULL;
	for(j=i;j<9;j++)
		if(arr[j]==true)
		{
			p=arr+j;
			break;
		}
	return i;
}
void barrs::repr()
{
	p=f;
}