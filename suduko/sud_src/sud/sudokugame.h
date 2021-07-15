#pragma once
#include"list.cpp"
#include"form1.h"
using namespace sudoku;
#include"barrs.h"
ref class sudokugame
{
	array<int^,2>^m;
	LIST<int**> *sol;//list of solutions	
	sudoku::Form1 ^display;
	int* row(int n);//give nth row
	int* col(int n);//give nth column
	int* grd(int n);//give nth grid
	int addtosoln();//add present value of m to sol
	int validsarr(int arr[9],bool comp);//check if arr is a valid sudoku array(row/col/grid);if comp=0,check is done on a partially filled array
	int valid(bool comp);//check if present state of m is a valid as per sudoku rules;if comp=0,check if done to verify partially filled m
	int grid(int i,int j);//give grid number of element in ith row and jth column
	void clearsoln();//clear sol,i.e. make sol a empty list
public:
	int prsoln();//process an element in the list sol
	sudokugame(void);
	~sudokugame(void);
	int evaluate();//solve the puzzle in m;put solutions in list sol; return val=number of solutions found(max=LIMIT);m comtains last solution found on return
	bool backtrack(int &i,int &j,bool rq[9][9],barrs l[9][9]);
	int mat(int i,int j,bool assign,int val);//operate on m[i][j];if assign=0,returm m[i][j];else assign val to it
};