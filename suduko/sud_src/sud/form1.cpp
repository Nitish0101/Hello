#include"stdafx.h"
#include"Form1.h"
using namespace sudoku;
#include<iostream>
using namespace std;
#include"sudokugame.h"
#include"num.h"
System::Void Form1::numbers_changed(System::Object ^sender, System::EventArgs ^e)
{
	game->mat(((num^)sender)->i,((num^)sender)->j,1,((num^)sender)->SelectedIndex);
}
System::Void Form1::tableLayoutPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
{
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
		{
			try
			{
				numbers[i,j]->SelectedIndex=game->mat(i,j,0,0);
			}
			catch(...)
			{
				cerr<<"Error:"<<__LINE__;
				numbers[i,j]->SelectedIndex=0;
			}
		}
}
System::Void Form1::submit_Click(System::Object^  sender, System::EventArgs^  e)
{
	 label1->Text="";
	 label2->Text="";
	 int f=game->evaluate(),i,j;
	 if(f==0)
	 {
		 label1->Text="No solution";
		 return;
	 }
	 if(f==LIMIT||f==-1)
	 {
		 label1->Text="Too many solutions";
	 }
	 else
	 {
		 label1->Text="No. of solutions="+System::Convert::ToString(f);
	 }
	 for(i=0;i<9;i++)
		 for(j=0;j<9;j++)
		 {
			 if(numbers[i,j]->SelectedIndex!=0)
				 numbers[i,j]->ForeColor=*numcp;
		 }
	 System::Windows::Forms::PaintEventArgs^ ar;
	 submit->Enabled=false;
	 modifyinp->Visible=true;
	 next->Visible=true;
	 game->prsoln();
	 label2->Text="Solution No.1";
	 tableLayoutPanel1_Paint(tableLayoutPanel1,ar);
 }
System::Void Form1::clearall_Click(System::Object^  sender, System::EventArgs^  e)
{
	 int i,j;
	 label1->Text="";
	 label2->Text="";
	 for(i=0;i<9;i++)
		 for(j=0;j<9;j++)
			 numbers[i,j]->SelectedIndex=0,
			 numbers[i,j]->ForeColor=*numcs;
	 submit->Enabled=true;
	 modifyinp->Visible=false;
	 next->Visible=false;
}
System::Void Form1::modifyinp_Click(System::Object^  sender, System::EventArgs^  e)
{
	 int i,j;
	 for(i=0;i<9;i++)
		 for(j=0;j<9;j++)
			 if(numbers[i,j]->ForeColor==*numcp)
				 numbers[i,j]->ForeColor=*numcs;
			 else
				 numbers[i,j]->SelectedIndex=0;
	 submit->Enabled=true;
	 modifyinp->Visible=false;
	 next->Visible=false;
	 label1->Text="",label2->Text="";
}
System::Void Form1::next_Click(System::Object^  sender, System::EventArgs^  e)
{
	int d=game->prsoln();
	System::Windows::Forms::PaintEventArgs^ ar;
	tableLayoutPanel1_Paint(tableLayoutPanel1,ar);
	label2->Text="Solution No."+Convert::ToString(d);
}
Form1::Form1(sudokugame ^p):game(p),numcp(System::Drawing::Color::Red),numcs(Drawing::Color::Blue)
{
	InitializeComponent();
	//
	//TODO: Add the constructor code here
	//
	numbers=gcnew array<num^,2>(9,9);
	label1->Text="",label2->Text="";
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
		{
			numbers[i,j]=gcnew num;
			tableLayoutPanel1->Controls->Add(numbers[i,j],j,i);
			numbers[i,j]->ForeColor=*numcs;
			numbers[i,j]->i=i,numbers[i,j]->j=j;
			numbers[i,j]->SelectedItemChanged+=gcnew System::EventHandler(this,&Form1::numbers_changed);
		}
}

Form1::~Form1()
{
	if (components)
	{
		delete components;
	}
}
