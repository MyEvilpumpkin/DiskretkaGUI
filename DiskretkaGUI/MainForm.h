#pragma once
#include <msclr/marshal_cppstd.h>
#include "P.h"
#include "Exceptions.h"
#include "ModuleDescriptionForm.h"

namespace DiskretkaGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}




	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::ComboBox^ comboBox1;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::StatusStrip^ statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ истори€¬ычисленийToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ показать»сторию¬ычисленийToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ сохранить»сторию¬ычислений¬‘айлToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ параметрыToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ справкаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ описаниећодулейToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ оѕрограммеToolStripMenuItem;



	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->истори€¬ычисленийToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->показать»сторию¬ычисленийToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->сохранить»сторию¬ычислений¬‘айлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->параметрыToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->справкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->описаниећодулейToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->оѕрограммеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableLayoutPanel1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox3
			// 
			this->textBox3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(280, 35);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->tableLayoutPanel1->SetRowSpan(this->textBox3, 4);
			this->textBox3->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox3->Size = System::Drawing::Size(271, 232);
			this->textBox3->TabIndex = 4;
			this->textBox3->Text = L"¬ыберите модуль\r\n\r\nѕодробные описани€ модулей наход€тс€ в справке (дл€ вызова спр"
				L"авки нажмите F1)";
			// 
			// textBox2
			// 
			this->textBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(3, 154);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox2->Size = System::Drawing::Size(271, 81);
			this->textBox2->TabIndex = 2;
			this->textBox2->Visible = false;
			this->textBox2->Click += gcnew System::EventHandler(this, &MainForm::TextBox2_Click);
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MainForm::TextBox2_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(3, 67);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(271, 81);
			this->textBox1->TabIndex = 1;
			this->textBox1->Visible = false;
			this->textBox1->Click += gcnew System::EventHandler(this, &MainForm::TextBox1_Click);
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MainForm::TextBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(3, 241);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(271, 26);
			this->button1->TabIndex = 3;
			this->button1->Text = L"¬ычислить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::Button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(45) {
				L"N-1 - COM_NN_D", L"N-2 - NZER_N_B", L"N-3 - ADD_1N_N",
					L"N-4 - ADD_NN_N", L"N-5 - SUB_NN_N", L"N-6 - MUL_ND_N", L"N-7 - MUL_Nk_N", L"N-8 - MUL_NN_N", L"N-9 - SUB_NDN_N", L"N-10 - DIV_NN_Dk",
					L"N-11 - DIV_NN_N", L"N-12 - MOD_NN_N", L"N-13 - GCF_NN_N", L"N-14 - LCM_NN_N", L"Z-1 - ABS_Z_N", L"Z-2 - POZ_Z_D", L"Z-3 - MUL_ZM_Z",
					L"Z-4 - TRANS_N_Z", L"Z-5 - TRANS_Z_N", L"Z-6 - ADD_ZZ_Z", L"Z-7 - SUB_ZZ_Z", L"Z-8 - MUL_ZZ_Z", L"Z-9 - DIV_ZN_Z", L"Z-10 - MOD_ZN_Z",
					L"Q-1 - RED_Q_Q", L"Q-2 - INT_Q_B", L"Q-3 - TRANS_Z_Q", L"Q-4 - TRANS_Q_Z", L"Q-5 - ADD_QQ_Q", L"Q-6 - SUB_QQ_Q", L"Q-7 - MUL_QQ_Q",
					L"Q-8 - DIV_QQ_Q", L"P-1 - ADD_PP_P", L"P-2 - SUB_PP_P", L"P-3 - MUL_PQ_P", L"P-4 - MUL_Pxk_P", L"P-5 - LED_P_Q", L"P-6 - DEG_P_N",
					L"P-7 - FAC_P_Q", L"P-8 - MUL_PP_P", L"P-9 - DIV_PP_P", L"P-10 - MOD_PP_P", L"P-11 - GCF_PP_P", L"P-12 - DER_P_P", L"P-13 - NMR_P_P"
			});
			this->comboBox1->Location = System::Drawing::Point(3, 35);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(271, 26);
			this->comboBox1->TabIndex = 0;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::ComboBox1_SelectedIndexChanged);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->button1, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->textBox2, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->textBox1, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->comboBox1, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->textBox3, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->label2, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->statusStrip1, 0, 5);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 24);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 6;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 32)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 32)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 32)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 26)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(554, 297);
			this->tableLayoutPanel1->TabIndex = 8;
			// 
			// label2
			// 
			this->label2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(280, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(271, 32);
			this->label2->TabIndex = 8;
			this->label2->Text = L"¬ывод";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label1
			// 
			this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(3, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(271, 32);
			this->label1->TabIndex = 9;
			this->label1->Text = L"¬вод";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// statusStrip1
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->statusStrip1, 2);
			this->statusStrip1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripStatusLabel1 });
			this->statusStrip1->Location = System::Drawing::Point(0, 270);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(554, 27);
			this->statusStrip1->TabIndex = 10;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->AutoSize = false;
			this->toolStripStatusLabel1->BackColor = System::Drawing::SystemColors::Control;
			this->toolStripStatusLabel1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripStatusLabel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Italic,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(539, 22);
			this->toolStripStatusLabel1->Spring = true;
			this->toolStripStatusLabel1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->истори€¬ычисленийToolStripMenuItem,
					this->параметрыToolStripMenuItem, this->справкаToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(0, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(554, 24);
			this->menuStrip1->TabIndex = 9;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// истори€¬ычисленийToolStripMenuItem
			// 
			this->истори€¬ычисленийToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->показать»сторию¬ычисленийToolStripMenuItem,
					this->сохранить»сторию¬ычислений¬‘айлToolStripMenuItem
			});
			this->истори€¬ычисленийToolStripMenuItem->Enabled = false;
			this->истори€¬ычисленийToolStripMenuItem->Name = L"истори€¬ычисленийToolStripMenuItem";
			this->истори€¬ычисленийToolStripMenuItem->Size = System::Drawing::Size(138, 20);
			this->истори€¬ычисленийToolStripMenuItem->Text = L"»стори€ вычислений";
			// 
			// показать»сторию¬ычисленийToolStripMenuItem
			// 
			this->показать»сторию¬ычисленийToolStripMenuItem->Name = L"показать»сторию¬ычисленийToolStripMenuItem";
			this->показать»сторию¬ычисленийToolStripMenuItem->Size = System::Drawing::Size(297, 22);
			this->показать»сторию¬ычисленийToolStripMenuItem->Text = L"ѕоказать историю вычислений";
			// 
			// сохранить»сторию¬ычислений¬‘айлToolStripMenuItem
			// 
			this->сохранить»сторию¬ычислений¬‘айлToolStripMenuItem->Name = L"сохранить»сторию¬ычислений¬‘айлToolStripMenuItem";
			this->сохранить»сторию¬ычислений¬‘айлToolStripMenuItem->Size = System::Drawing::Size(297, 22);
			this->сохранить»сторию¬ычислений¬‘айлToolStripMenuItem->Text = L"—охранить историю вычислений в файл";
			// 
			// параметрыToolStripMenuItem
			// 
			this->параметрыToolStripMenuItem->Name = L"параметрыToolStripMenuItem";
			this->параметрыToolStripMenuItem->Size = System::Drawing::Size(83, 20);
			this->параметрыToolStripMenuItem->Text = L"ѕараметры";
			// 
			// справкаToolStripMenuItem
			// 
			this->справкаToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->описаниећодулейToolStripMenuItem,
					this->оѕрограммеToolStripMenuItem
			});
			this->справкаToolStripMenuItem->Name = L"справкаToolStripMenuItem";
			this->справкаToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->справкаToolStripMenuItem->Text = L"—правка";
			// 
			// описаниећодулейToolStripMenuItem
			// 
			this->описаниећодулейToolStripMenuItem->Name = L"описаниећодулейToolStripMenuItem";
			this->описаниећодулейToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->описаниећодулейToolStripMenuItem->Text = L"ќписание модулей";
			this->описаниећодулейToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::ќписаниећодулейToolStripMenuItem_Click);
			// 
			// оѕрограммеToolStripMenuItem
			// 
			this->оѕрограммеToolStripMenuItem->Name = L"оѕрограммеToolStripMenuItem";
			this->оѕрограммеToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->оѕрограммеToolStripMenuItem->Text = L"ќ программе";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(554, 321);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->menuStrip1);
			this->HelpButton = true;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MinimumSize = System::Drawing::Size(570, 360);
			this->Name = L"MainForm";
			this->Text = L"—истема компьютерной алгебры";
			this->HelpButtonClicked += gcnew System::ComponentModel::CancelEventHandler(this, &MainForm::MyForm_HelpButtonClicked);
			this->HelpRequested += gcnew System::Windows::Forms::HelpEventHandler(this, &MainForm::MainForm_HelpRequested);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: void SetFields(String^ field1, String^ field2) {
			this->textBox1->Visible = true;
			this->textBox1->Text = field1;
			if (field2 == "EMPTY")
				this->textBox2->Visible = false;
			else {
				this->textBox2->Visible = true;
				this->textBox2->Text = field2;
			}
		}

private: System::Void ComboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	String^ str = "EMPTY";
	String^ str0 = "¬ведите число";
	String^ str1 = "¬ведите натуральное число";
	String^ str2 = "¬ведите целое число";
	String^ str3 = "¬ведите рациональное число";
	String^ str4 = "¬ведите многочлен";
	this->textBox1->ForeColor = System::Drawing::SystemColors::WindowText;
	this->textBox2->ForeColor = System::Drawing::SystemColors::WindowText;
	this->textBox3->Text = "";
	this->toolStripStatusLabel1->Text = "";
	this->toolStripStatusLabel1->BackColor = System::Drawing::SystemColors::Control;
	switch (this->comboBox1->SelectedIndex) {
	case 0:
		SetFields(str1, str1);
		break;
	case 1:
		SetFields(str1, str);
		break;
	case 2:
		SetFields(str1, str);
		break;
	case 3:
		SetFields(str1, str1);
		break;
	case 4:
		SetFields(str1, str1);
		break;
	case 5:
		SetFields(str1, str0);
		break;
	case 6:
		SetFields(str1, str0);
		break;
	case 7:
		SetFields(str1, str1);
		break;
	case 8:
		SetFields(str1, str1);
		break;
	case 9:
		SetFields(str1, str1);
		break;
	case 10:
		SetFields(str1, str1);
		break;
	case 11:
		SetFields(str1, str1);
		break;
	case 12:
		SetFields(str1, str1);
		break;
	case 13:
		SetFields(str1, str1);
		break;
	case 14:
		SetFields(str2, str);
		break;
	case 15:
		SetFields(str2, str);
		break;
	case 16:
		SetFields(str2, str);
		break;
	case 17:
		SetFields(str1, str);
		break;
	case 18:
		SetFields(str2, str);
		break;
	case 19:
		SetFields(str2, str2);
		break;
	case 20:
		SetFields(str2, str2);
		break;
	case 21:
		SetFields(str2, str2);
		break;
	case 22:
		SetFields(str2, str1);
		break;
	case 23:
		SetFields(str2, str1);
		break;
	case 24:
		SetFields(str3, str);
		break;
	case 25:
		SetFields(str3, str);
		break;
	case 26:
		SetFields(str2, str);
		break;
	case 27:
		SetFields(str3, str);
		break;
	case 28:
		SetFields(str3, str3);
		break;
	case 29:
		SetFields(str3, str3);
		break;
	case 30:
		SetFields(str3, str3);
		break;
	case 31:
		SetFields(str3, str3);
		break;
	case 32:
		SetFields(str4, str4);
		break;
	case 33:
		SetFields(str4, str4);
		break;
	case 34:
		SetFields(str4, str3);
		break;
	case 35:
		SetFields(str4, str0);
		break;
	case 36:
		SetFields(str4, str);
		break;
	case 37:
		SetFields(str4, str);
		break;
	case 38:
		SetFields(str4, str);
		break;
	case 39:
		SetFields(str4, str4);
		break;
	case 40:
		SetFields(str4, str4);
		break;
	case 41:
		SetFields(str4, str4);
		break;
	case 42:
		SetFields(str4, str4);
		break;
	case 43:
		SetFields(str4, str);
		break;
	case 44:
		SetFields(str4, str);
		break;
	}
}

private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		this->textBox3->Text = "";
		this->toolStripStatusLabel1->Text = "¬ычисление...";
		this->toolStripStatusLabel1->BackColor = System::Drawing::SystemColors::Control;
		switch (this->comboBox1->SelectedIndex) {
			case 0:
			{
				N n1, n2;
				int result;
				bool initializationIsCorrect = true;
				try {
					n1 = N(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				try {
					n2 = N(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
				}
				catch (IncorrectString) {
					this->textBox2->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = COM_NN_D(n1, n2);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = result.ToString();
			}
			break;
			case 1:
			{
				N n;
				bool result;
				bool initializationIsCorrect = true;
				try {
					n = N(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = NZER_N_B(n);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = result.ToString();
			}
			break;
			case 2:
			{
				N n, result;
				bool initializationIsCorrect = true;
				try {
					n = N(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = ADD_1N_N(n);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 3:
			{
				N n1, n2, result;
				bool initializationIsCorrect = true;
				try {
					n1 = N(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				try {
					n2 = N(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
				}
				catch (IncorrectString) {
					this->textBox2->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = ADD_NN_N(n1, n2);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 4:
			{
				N n1, n2, result;
				bool initializationIsCorrect = true;
				try {
					n1 = N(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				try {
					n2 = N(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
				}
				catch (IncorrectString) {
					this->textBox2->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = SUB_NN_N(n1, n2);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 5:
			{
				N n1, n2, result;
				bool initializationIsCorrect = true;
				try {
					n1 = N(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				try {
					n2 = N(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
				}
				catch (IncorrectString) {
					this->textBox2->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = MUL_ND_N(n1, n2.ToUInt());
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 6:
			{
				N n1, n2, result;
				bool initializationIsCorrect = true;
				try {
					n1 = N(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				try {
					n2 = N(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
				}
				catch (IncorrectString) {
					this->textBox2->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = MUL_Nk_N(n1, n2.ToUInt());
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 7:
			{
				N n1, n2, result;
				bool initializationIsCorrect = true;
				try {
					n1 = N(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				try {
					n2 = N(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
				}
				catch (IncorrectString) {
					this->textBox2->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = MUL_NN_N(n1, n2);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 8:
			{
				N n1, n2, result;
				bool initializationIsCorrect = true;
				try {
					n1 = N(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				try {
					n2 = N(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
				}
				catch (IncorrectString) {
					this->textBox2->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = SUB_NDN_N(n1, 1, n2);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 9:
			{
				N n1, n2;
				int result, k;
				bool initializationIsCorrect = true;
				try {
					n1 = N(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				try {
					n2 = N(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
				}
				catch (IncorrectString) {
					this->textBox2->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = DIV_NN_Dk(n1, n2, k);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = result.ToString();
			}
			break;
			case 10:
			{
				N n1, n2, result;
				bool initializationIsCorrect = true;
				try {
					n1 = N(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				try {
					n2 = N(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
				}
				catch (IncorrectString) {
					this->textBox2->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = DIV_NN_N(n1, n2);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 11:
			{
				N n1, n2, result;
				bool initializationIsCorrect = true;
				try {
					n1 = N(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				try {
					n2 = N(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
				}
				catch (IncorrectString) {
					this->textBox2->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = MOD_NN_N(n1, n2);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 12:
			{
				N n1, n2, result;
				bool initializationIsCorrect = true;
				try {
					n1 = N(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				try {
					n2 = N(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
				}
				catch (IncorrectString) {
					this->textBox2->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = GCF_NN_N(n1, n2);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 13:
			{
				N n1, n2, result;
				bool initializationIsCorrect = true;
				try {
					n1 = N(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				try {
					n2 = N(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
				}
				catch (IncorrectString) {
					this->textBox2->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = LCM_NN_N(n1, n2);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 14:
			{
				Z z;
				N result;
				bool initializationIsCorrect = true;
				try {
					z = Z(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = ABS_Z_N(z);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 15:
			{
				Z z;
				int result;
				bool initializationIsCorrect = true;
				try {
					z = Z(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = POZ_Z_D(z);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = result.ToString();
			}
			break;
			case 16:
			{
				Z z, result;
				bool initializationIsCorrect = true;
				try {
					z = Z(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = MUL_ZM_Z(z);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 17:
			{
				N n;
				Z result;
				bool initializationIsCorrect = true;
				try {
					n = N(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = TRANS_N_Z(n);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 18:
			{
				Z z;
				N result;
				bool initializationIsCorrect = true;
				try {
					z = Z(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = TRANS_Z_N(z);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 19:
			{
				Z z1, z2, result;
				bool initializationIsCorrect = true;
				try {
					z1 = Z(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				try {
					z2 = Z(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
				}
				catch (IncorrectString) {
					this->textBox2->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = ADD_ZZ_Z(z1, z2);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 20:
			{
				Z z1, z2, result;
				bool initializationIsCorrect = true;
				try {
					z1 = Z(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				try {
					z2 = Z(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
				}
				catch (IncorrectString) {
					this->textBox2->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = SUB_ZZ_Z(z1, z2);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 21:
			{
				Z z1, z2, result;
				bool initializationIsCorrect = true;
				try {
					z1 = Z(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				try {
					z2 = Z(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
				}
				catch (IncorrectString) {
					this->textBox2->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = MUL_ZZ_Z(z1, z2);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 22:
			{
				Z z, result;
				N n;
				bool initializationIsCorrect = true;
				try {
					z = Z(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				try {
					n = N(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
				}
				catch (IncorrectString) {
					this->textBox2->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = DIV_ZN_Z(z, n);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 23:
			{
				Z z, result;
				N n;
				bool initializationIsCorrect = true;
				try {
					z = Z(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				try {
					n = N(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
				}
				catch (IncorrectString) {
					this->textBox2->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = MOD_ZN_Z(z, n);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 24:
			{
				Q q, result;
				bool initializationIsCorrect = true;
				try {
					q = Q(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = RED_Q_Q(q);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 25:
			{
				Q q;
				bool result;
				bool initializationIsCorrect = true;
				try {
					q = Q(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = INT_Q_B(q);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = result.ToString();
			}
			break;
			case 26:
			{
				Z z;
				Q result;
				bool initializationIsCorrect = true;
				try {
					z = Z(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = TRANS_Z_Q(z);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 27:
			{
				Q q;
				Z result;
				bool initializationIsCorrect = true;
				try {
					q = Q(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = TRANS_Q_Z(q);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 28:
			{
				Q q1, q2, result;
				bool initializationIsCorrect = true;
				try {
					q1 = Q(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				try {
					q2 = Q(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
				}
				catch (IncorrectString) {
					this->textBox2->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = ADD_QQ_Q(q1, q2);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 29:
			{
				Q q1, q2, result;
				bool initializationIsCorrect = true;
				try {
					q1 = Q(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				try {
					q2 = Q(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
				}
				catch (IncorrectString) {
					this->textBox2->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = SUB_QQ_Q(q1, q2);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 30:
			{
				Q q1, q2, result;
				bool initializationIsCorrect = true;
				try {
					q1 = Q(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				try {
					q2 = Q(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
				}
				catch (IncorrectString) {
					this->textBox2->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = MUL_QQ_Q(q1, q2);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 31:
			{
				Q q1, q2, result;
				bool initializationIsCorrect = true;
				try {
					q1 = Q(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				try {
					q2 = Q(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
				}
				catch (IncorrectString) {
					this->textBox2->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = DIV_QQ_Q(q1, q2);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 32:
			{
				P p1, p2, result;
				bool initializationIsCorrect = true;
				try {
					p1 = P(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				try {
					p2 = P(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
				}
				catch (IncorrectString) {
					this->textBox2->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = ADD_PP_P(p1, p2);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 33:
			{
				P p1, p2, result;
				bool initializationIsCorrect = true;
				try {
					p1 = P(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				try {
					p2 = P(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
				}
				catch (IncorrectString) {
					this->textBox2->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = SUB_PP_P(p1, p2);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 34:
			{
				P p, result;
				Q q;
				bool initializationIsCorrect = true;
				try {
					p = P(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				try {
					q = Q(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
				}
				catch (IncorrectString) {
					this->textBox2->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = MUL_PQ_P(p, q);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 35:
			{
				P p, result;
				N n;
				bool initializationIsCorrect = true;
				try {
					p = P(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				try {
					n = N(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
				}
				catch (IncorrectString) {
					this->textBox2->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = MUL_Pxk_P(p, n.ToUInt());
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 36:
			{
				P p;
				Q result;
				bool initializationIsCorrect = true;
				try {
					p = P(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = LED_P_Q(p);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 37:
			{
				P p;
				N result;
				bool initializationIsCorrect = true;
				try {
					p = P(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = DEG_P_N(p);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 38:
			{
				P p;
				Q result;
				bool initializationIsCorrect = true;
				try {
					p = P(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = FAC_P_Q(p);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 39:
			{
				P p1, p2, result;
				bool initializationIsCorrect = true;
				try {
					p1 = P(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				try {
					p2 = P(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
				}
				catch (IncorrectString) {
					this->textBox2->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = MUL_PP_P(p1, p2);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 40:
			{
				P p1, p2, result;
				bool initializationIsCorrect = true;
				try {
					p1 = P(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				try {
					p2 = P(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
				}
				catch (IncorrectString) {
					this->textBox2->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = DIV_PP_P(p1, p2);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 41:
			{
				P p1, p2, result;
				bool initializationIsCorrect = true;
				try {
					p1 = P(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				try {
					p2 = P(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
				}
				catch (IncorrectString) {
					this->textBox2->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = MOD_PP_P(p1, p2);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 42:
			{
				P p1, p2, result;
				bool initializationIsCorrect = true;
				try {
					p1 = P(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				try {
					p2 = P(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
				}
				catch (IncorrectString) {
					this->textBox2->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = GCF_PP_P(p1, p2);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 43:
			{
				P p, result;
				bool initializationIsCorrect = true;
				try {
					p = P(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = DER_P_P(p);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			case 44:
			{
				P p, result;
				bool initializationIsCorrect = true;
				try {
					p = P(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
				}
				catch (IncorrectString) {
					this->textBox1->ForeColor = System::Drawing::Color::Red;
					initializationIsCorrect = false;
				}
				if (!initializationIsCorrect)
					throw Error("ќшибка: ¬ведены некорректные данные");
				try {
					result = NMR_P_P(p);
				}
				catch (ArithmeticalError ex) {
					throw Error(ex.what());
				}
				this->textBox3->Text = msclr::interop::marshal_as<String^>(result.ToString());
			}
			break;
			default:
				this->textBox3->Text = "¬ыберите модуль\r\n\r\nѕодробные описани€ модулей наход€тс€ в справке (дл€ вызова справки нажмите F1)";
				throw Error("ќшибка: ћодуль не выбран");
			break;
		}
		this->toolStripStatusLabel1->Text = "√отово";
		this->toolStripStatusLabel1->BackColor = System::Drawing::Color::SkyBlue;
	}
	catch (Error ex) {
		this->toolStripStatusLabel1->Text = msclr::interop::marshal_as<String^>(ex.what());
		this->toolStripStatusLabel1->BackColor = System::Drawing::Color::LightCoral;
	}
	catch (std::bad_alloc) {
		this->toolStripStatusLabel1->Text = "ќшибка: недостаточно пам€ти";
		this->toolStripStatusLabel1->BackColor = System::Drawing::Color::LightCoral;
	}
	catch (...) {
		this->toolStripStatusLabel1->Text = "ќшибка: неизвестна€ ошибка";
		this->toolStripStatusLabel1->BackColor = System::Drawing::Color::LightCoral;
	}
}

private: System::Void TextBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ str0 = "¬ведите число";
	String^ str1 = "¬ведите натуральное число";
	String^ str2 = "¬ведите целое число";
	String^ str3 = "¬ведите рациональное число";
	String^ str4 = "¬ведите многочлен";
	if (this->textBox1->Text == str0 || this->textBox1->Text == str1 || this->textBox1->Text == str2 || this->textBox1->Text == str3 || this->textBox1->Text == str4)
		this->textBox1->Text = "";
}

private: System::Void TextBox2_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ str0 = "¬ведите число";
	String^ str1 = "¬ведите натуральное число";
	String^ str2 = "¬ведите целое число";
	String^ str3 = "¬ведите рациональное число";
	String^ str4 = "¬ведите многочлен";
	if (this->textBox2->Text == str0 || this->textBox2->Text == str1 || this->textBox2->Text == str2 || this->textBox2->Text == str3 || this->textBox2->Text == str4)
		this->textBox2->Text = "";
}

private: System::Void TextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	this->textBox1->ForeColor = System::Drawing::SystemColors::WindowText;
}

private: System::Void TextBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	this->textBox2->ForeColor = System::Drawing::SystemColors::WindowText;
}

private: System::Void MyForm_HelpButtonClicked(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	ModuleDescriptionForm^ moduleDescriptionForm = gcnew ModuleDescriptionForm();
	moduleDescriptionForm->Show();
}
private: System::Void MainForm_HelpRequested(System::Object^ sender, System::Windows::Forms::HelpEventArgs^ hlpevent) {
	ModuleDescriptionForm^ moduleDescriptionForm = gcnew ModuleDescriptionForm();
	moduleDescriptionForm->Show();
}
private: System::Void ќписаниећодулейToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	ModuleDescriptionForm^ moduleDescriptionForm = gcnew ModuleDescriptionForm();
	moduleDescriptionForm->Show();
}
};
}
