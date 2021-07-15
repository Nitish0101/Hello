#include "StdAfx.h"
#include "sudokugame.h"
#include<iostream>
using namespace std;
sudokugame::sudokugame(void)
{
	int i,j;
	m=gcnew array<int^,2>(9,9);
	sol=new LIST<int**>;
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
			m[i,j]=gcnew int;
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
			*m[i,j]=0;
	Application::Run(display=gcnew Form1(this));
}

sudokugame::~sudokugame(void)
{
	clearsoln();
}

int sudokugame::mat(int i, int j,bool assign,int val)
{
	if(assign)
	{
		*m[i,j]=val;
	}
	return *m[i,j];
}
bool sudokugame::backtrack(int &i,int &j,bool rq[9][9],barrs l[9][9])
{
	l[i][j].repr();
	do{
		if(i==0&&j==0)	return 0;
		if(j==0)	i--,j=8;
		else	j--;
	}while(!rq[i][j]);
	if(j==0)	i--,j=8;
	else	j--;
	return 1;
}

int sudokugame::evaluate()
{
	clearsoln();
	bool rq[9][9];//2D array indicating corresponding elements of m that need to be evaluated
	int i,j,k//used as iterators
		,r=0//return value(number of solutions found and inserted to sol
		,li=8,lj=8//(li,lj)->indices of last position in m to be evaluated
		;
	if(!valid(0))	return 0;
	if(valid(1))	return 1;
	//evaluate rq
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			rq[i][j]=!(*m[i,j]);
		}
	}
	barrs l[9][9];//array of lists, each list containing allowable digits at corresponding position in m, as per following logic
	int *de1,*de2,*de3;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(rq[i][j]){
				//add to l[i][j] all elements from 1 through 9 not present in either row or column or grid of m[i,j]
				for(k=1;k<10;k++){
					*m[i,j]=k;
					if(validsarr(de3=row(i),0)){
						if(validsarr(de1=col(j),0)){
							if(validsarr(de2=grd(grid(i,j)),0))
								l[i][j].ins(k);
							delete[] de2;
						}
						delete[] de1;
					}
					delete[] de3;
				}
				l[i][j].calf();//make l[i][j] ready to process
				*m[i,j]=0;
			}
		}
	}
	//evaluate (li,lj)
	bool f=1;
	for(i=8;i>=0;i--){
		for(j=8;j>=0;j--){
			if(rq[i][j]){
				li=i;
				lj=j;
				f=0;
				break;
			}
		}
		if(!f)	break;
	}
	//evaluate
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(rq[i][j]){
				do{
					*m[i,j]=l[i][j].prel();//make next guess for m[i,j]
					if(!(*m[i,j])){//if no guess left, then backtrack
						if(!backtrack(i,j,rq,l))	return r;
						break;
					}
					//check to see if the last guess made leaves m in a valid state
					if(validsarr(de3=row(i),0)){
						if(validsarr(de1=col(j),0)){
							if(validsarr(de2=grd(grid(i,j)),0)){
								delete[] de3;
								delete[] de1;
								delete[] de2;
								break;//last guess made leaves m in valid state
							}
							delete[] de2;
						}
						delete[] de1;
					}
					delete[] de3;
				}while(1);
				if(i==li&&j==lj){//if position just filled was last one to be filled to give a solution
					if(addtosoln()){//add present state of m to sol;if succesful in doing so
						r++;
						if(r==LIMIT)	return LIMIT;
						if(!backtrack(i,j,rq,l))	return r;
					}
					else
						return -1;//indicate error(though more solutions exist then present in sol, and though number of solutions in sol is less than LIMIT,we could'nt add to sol,probably due to memory shortage)
				}
			}
		}
	}
	return r;
}
int* sudokugame::row(int n)
{
	int *r;
	r=new int[9];
	for(int i=0;i<9;i++)
		r[i]=*m[n,i];
	return r;
}
int* sudokugame::col(int n)
{
	int *r;
	r=new int[9];
	for(int i=0;i<9;i++)
		r[i]=*m[i,n];
	return r;
}
int* sudokugame::grd(int n)
{
	int *r;
	r=new int[9];
	int radd=3*(n/3),cadd=3*(n%3);
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			r[3*i+j]=Convert::ToInt32(m[radd+i,cadd+j]);
	return r;
}
int sudokugame::validsarr(int arr[9],bool comp)
{
	int r[10]={0},f=1,f1=1,i;
	for(i=0;i<9;i++)
		r[arr[i]]++;
	for(i=1;i<10;i++)
		if(r[i]!=1)
		{
			f=0;
			if(r[i]>1)
				f1=0;
		}
	if(comp)	return f;
	return f1;
}
int sudokugame::valid(bool comp)
{
	int *a;
	for(int i=0;i<9;i++)
	{
		if(!validsarr(a=row(i),comp))
		{
			delete[]a;
			return 0;
		}
		delete[] a;
		if(!validsarr(a=col(i),comp))
		{
			delete[]a;
			return 0;
		}
		delete[] a;
		if(!validsarr(a=grd(i),comp))
		{
			delete[]a ;
			return 0;
		}
		delete[] a;
	}
	return 1;
}
int sudokugame::grid(int i, int j)
{
	return (i/3)*3+j/3;
}
int sudokugame::addtosoln()
{
	int **s,i,j;
	try
	{
		s=new int*[9];
		for(i=0;i<9;i++)
			s[i]=new int[9];
	}
	catch(...)
	{
		return 0;
	}
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
			s[i][j]=*m[i,j];
	sol->frontins(s);
	return 1;
}
int sudokugame::prsoln()
{
	int **p=sol->prel();
	if(!p)
	{
		sol->repr();
		p=sol->prel();
	}
	int i,j;
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
			try
			{
				*m[i,j]=p[i][j];
			}
			catch(...)
			{
			}
	return sol->pos(p);
}
void sudokugame::clearsoln()
{
	int **d,i;
	while(!sol->isempty())
	{
		d=sol->frontel();
		for(i=0;i<9;i++)
		{
			delete[] d[i];
		}
		delete[] d;
		sol->frontdel();
	}
}