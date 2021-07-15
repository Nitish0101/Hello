#pragma once
ref class sudokugame;
ref class num;
namespace sudoku {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(sudokugame ^p);
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1();
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	public: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;

	private: System::Windows::Forms::Button^  submit;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  clearall;
	private: System::Windows::Forms::Button^  modifyinp;
	private: System::Windows::Forms::Button^  next;
	private: System::Windows::Forms::Label^  label2;

			 sudokugame ^game;
			 array<num^,2> ^numbers;
			 const System::Drawing::Color^ numcs;
			 const System::Drawing::Color^ numcp;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->submit = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->clearall = (gcnew System::Windows::Forms::Button());
			this->modifyinp = (gcnew System::Windows::Forms::Button());
			this->next = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->AutoSize = true;
			this->tableLayoutPanel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->tableLayoutPanel1->BackColor = System::Drawing::SystemColors::Control;
			this->tableLayoutPanel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tableLayoutPanel1.BackgroundImage")));
			this->tableLayoutPanel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->tableLayoutPanel1->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::OutsetDouble;
			this->tableLayoutPanel1->ColumnCount = 9;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tableLayoutPanel1->GrowStyle = System::Windows::Forms::TableLayoutPanelGrowStyle::FixedSize;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 9;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->Size = System::Drawing::Size(30, 30);
			this->tableLayoutPanel1->TabIndex = 0;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::tableLayoutPanel1_Paint);
			// 
			// submit
			// 
			this->submit->Location = System::Drawing::Point(611, 467);
			this->submit->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->submit->Name = L"submit";
			this->submit->Size = System::Drawing::Size(112, 35);
			this->submit->TabIndex = 1;
			this->submit->Text = L"Submit";
			this->submit->UseVisualStyleBackColor = true;
			this->submit->Click += gcnew System::EventHandler(this, &Form1::submit_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->label1->Location = System::Drawing::Point(0, 507);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(188, 25);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Number of Solutions";
			// 
			// clearall
			// 
			this->clearall->Location = System::Drawing::Point(491, 467);
			this->clearall->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->clearall->Name = L"clearall";
			this->clearall->Size = System::Drawing::Size(112, 35);
			this->clearall->TabIndex = 3;
			this->clearall->Text = L"Clear All";
			this->clearall->UseVisualStyleBackColor = true;
			this->clearall->Click += gcnew System::EventHandler(this, &Form1::clearall_Click);
			// 
			// modifyinp
			// 
			this->modifyinp->Location = System::Drawing::Point(491, 388);
			this->modifyinp->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->modifyinp->Name = L"modifyinp";
			this->modifyinp->Size = System::Drawing::Size(112, 69);
			this->modifyinp->TabIndex = 4;
			this->modifyinp->Text = L"Modify input";
			this->modifyinp->UseVisualStyleBackColor = true;
			this->modifyinp->Visible = false;
			this->modifyinp->Click += gcnew System::EventHandler(this, &Form1::modifyinp_Click);
			// 
			// next
			// 
			this->next->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"next.BackgroundImage")));
			this->next->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->next->Location = System::Drawing::Point(610, 388);
			this->next->Name = L"next";
			this->next->Size = System::Drawing::Size(113, 69);
			this->next->TabIndex = 5;
			this->next->Text = L"Next solution";
			this->next->UseVisualStyleBackColor = true;
			this->next->Visible = false;
			this->next->Click += gcnew System::EventHandler(this, &Form1::next_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Dock = System::Windows::Forms::DockStyle::Right;
			this->label2->Location = System::Drawing::Point(618, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(118, 25);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Solution No.";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(736, 532);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->next);
			this->Controls->Add(this->modifyinp);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->clearall);
			this->Controls->Add(this->submit);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: System::Void tableLayoutPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e);
private:
	System::Void numbers_changed(System::Object^  sender,System::EventArgs^e);
private: System::Void submit_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void clearall_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void modifyinp_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void next_Click(System::Object^  sender, System::EventArgs^  e);		 
};
}