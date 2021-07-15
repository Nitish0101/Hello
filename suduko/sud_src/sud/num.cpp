#include"stdafx.h"
#include"num.h"
num::num()
{
	BackColor=System::Drawing::Color::Azure;
	Dock=System::Windows::Forms::DockStyle::Fill;
	AutoSize = true;
	Wrap=true;
	ReadOnly=true;
	Items->Add(" ");
	for(int k=1;k<10;k++)
		Items->Add(k);
	SelectedIndex=0;
}