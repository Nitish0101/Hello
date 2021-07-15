#pragma once
class barrs//a class similar to the list class, but suitable for requirement of evaluation of a digit of a sudoku puzzle
{
	bool arr[9]//arr[i] is true if i+1 is present in the list
		,*p//points to the element being processed
		,*f//points to front of the list
		;
public:
	barrs(void);
	~barrs(void);
	void ins(int a);//insert an element to the list
	int prel();//process element
	void repr();//reposition p
	void calf();//calculate the front of the list,f, and make p equal to it
};
