// sudoku.cpp : main project file.

#include "stdafx.h"
#include"sudokugame.h"
#include"form1.h"
using namespace sudoku;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	//Application::Run(gcnew Form1(2));
	sudokugame s;
	return 0;
}
