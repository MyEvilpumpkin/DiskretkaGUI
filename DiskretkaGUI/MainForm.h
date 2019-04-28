#pragma once
#include <msclr/marshal_cppstd.h>
#include "StringToNConverter.h"
#include "StringToZConverter.h"
#include "StringToQConverter.h"
#include "StringToPConverter.h"
#include "HelpForm.h"

namespace DiskretkaGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
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



	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
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
			this->tableLayoutPanel1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
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
			this->textBox3->Size = System::Drawing::Size(271, 250);
			this->textBox3->TabIndex = 4;
			this->textBox3->Text = L"�������� ������\r\n\r\n��������� �������� ������� ��������� � ������� (��� ������ ������� ������� F1)";
			// 
			// textBox2
			// 
			this->textBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(3, 163);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox2->Size = System::Drawing::Size(271, 90);
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
			this->textBox1->Size = System::Drawing::Size(271, 90);
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
			this->button1->Location = System::Drawing::Point(3, 259);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(271, 26);
			this->button1->TabIndex = 3;
			this->button1->Text = L"���������";
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
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 6;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 32)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 32)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 32)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 32)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(554, 321);
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
			this->label2->Text = L"�����";
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
			this->label1->Text = L"����";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// statusStrip1
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->statusStrip1, 2);
			this->statusStrip1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripStatusLabel1 });
			this->statusStrip1->Location = System::Drawing::Point(0, 288);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(554, 33);
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
			this->toolStripStatusLabel1->Size = System::Drawing::Size(539, 28);
			this->toolStripStatusLabel1->Spring = true;
			this->toolStripStatusLabel1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(554, 321);
			this->Controls->Add(this->tableLayoutPanel1);
			this->HelpButton = true;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(570, 360);
			this->Name = L"MainForm";
			this->Text = L"������� ������������ �������";
			this->HelpButtonClicked += gcnew System::ComponentModel::CancelEventHandler(this, &MainForm::MyForm_HelpButtonClicked);
			this->HelpRequested += gcnew System::Windows::Forms::HelpEventHandler(this, &MainForm::MainForm_HelpRequested);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);

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
	String^ str0 = "������� �����";
	String^ str1 = "������� ����������� �����";
	String^ str2 = "������� ����� �����";
	String^ str3 = "������� ������������ �����";
	String^ str4 = "������� ���������";
	this->textBox1->ForeColor = System::Drawing::SystemColors::WindowText;
	this->textBox2->ForeColor = System::Drawing::SystemColors::WindowText;
	this->textBox3->Text = "";
	this->toolStripStatusLabel1->Text = "";
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
		SetFields(str4, str);
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
	this->toolStripStatusLabel1->Text = "";
	this->textBox3->Text = "";
	switch (this->comboBox1->SelectedIndex) {
	case 0: {
		StringToNConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		StringToNConverter temp2(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		if (!temp2.GetStatus())
			this->textBox2->ForeColor = System::Drawing::Color::Red;
		if (temp1.GetStatus() && temp2.GetStatus()) {
			N *n1 = assignmentN(temp1.GetN()), *n2 = assignmentN(temp2.GetN());
			int result = COM_NN_D(n1, n2);
			this->textBox3->Text = result.ToString();
			freeN(n1);
			freeN(n2);
		}
	}
		break;
	case 1: {
		StringToNConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		else {
			N* n = assignmentN(temp1.GetN());
			int result = NZER_N_B(n);
			this->textBox3->Text = result.ToString();
			freeN(n);
		}
	}
		break;
	case 2: {
		StringToNConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		else {
			N* n = assignmentN(temp1.GetN());
			N* result = ADD_1N_N(n);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeN(n);
			freeN(result);
		}
	}
		break;
	case 3: {
		StringToNConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		StringToNConverter temp2(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		if (!temp2.GetStatus())
			this->textBox2->ForeColor = System::Drawing::Color::Red;
		if (temp1.GetStatus() && temp2.GetStatus()) {
			N* n1 = assignmentN(temp1.GetN()), * n2 = assignmentN(temp2.GetN());
			N* result = ADD_NN_N(n1, n2);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeN(n1);
			freeN(n2);
			freeN(result);
		}
	}
		break;
	case 4: {
		StringToNConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		StringToNConverter temp2(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		if (!temp2.GetStatus())
			this->textBox2->ForeColor = System::Drawing::Color::Red;
		if (temp1.GetStatus() && temp2.GetStatus()) {
			N *n1 = assignmentN(temp1.GetN()), *n2 = assignmentN(temp2.GetN());
			N* result = SUB_NN_N(n1, n2);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeN(n1);
			freeN(n2);
			freeN(result);
		}
	}
		break;
	case 5: {
		StringToNConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		StringToNConverter temp2(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		if (!temp2.GetStatus())
			this->textBox2->ForeColor = System::Drawing::Color::Red;
		if (temp1.GetStatus() && temp2.GetStatus()) {
			N* n = assignmentN(temp1.GetN());
			int d = NToInt(temp2.GetN());
			N* result = MUL_ND_N(n, d);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeN(n);
			freeN(result);
		}
	}
		break;
	case 6: {
		StringToNConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		StringToNConverter temp2(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		if (!temp2.GetStatus())
			this->textBox2->ForeColor = System::Drawing::Color::Red;
		if (temp1.GetStatus() && temp2.GetStatus()) {
			N* n = assignmentN(temp1.GetN());
			int k = NToInt(temp2.GetN());
			N* result = MUL_Nk_N(n, k);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeN(n);
			freeN(result);
		}
	}
		break;
	case 7: {
		StringToNConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		StringToNConverter temp2(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		if (!temp2.GetStatus())
			this->textBox2->ForeColor = System::Drawing::Color::Red;
		if (temp1.GetStatus() && temp2.GetStatus()) {
			N *n1 = assignmentN(temp1.GetN()), *n2 = assignmentN(temp2.GetN());
			N* result = MUL_NN_N(n1, n2);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeN(n1);
			freeN(n2);
			freeN(result);
		}
	}
		break;
	case 8: {
		StringToNConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		StringToNConverter temp2(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		if (!temp2.GetStatus())
			this->textBox2->ForeColor = System::Drawing::Color::Red;
		if (temp1.GetStatus() && temp2.GetStatus()) {
			N *n1 = assignmentN(temp1.GetN()), *n2 = assignmentN(temp2.GetN());
			int d = 1;
			N* result = SUB_NDN_N(n1, d, n2);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeN(n1);
			freeN(n2);
			freeN(result);
		}
	}
		break;
	case 9: {
		StringToNConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		StringToNConverter temp2(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		if (!temp2.GetStatus())
			this->textBox2->ForeColor = System::Drawing::Color::Red;
		if (temp1.GetStatus() && temp2.GetStatus()) {
			N *n1 = assignmentN(temp1.GetN()), *n2 = assignmentN(temp2.GetN());
			int k = 0;
			int result = DIV_NN_Dk(n1, n2, k);
			this->textBox3->Text = result.ToString();
			freeN(n1);
			freeN(n2);
		}
	}
		break;
	case 10: {
		StringToNConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		StringToNConverter temp2(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		if (!temp2.GetStatus())
			this->textBox2->ForeColor = System::Drawing::Color::Red;
		if (temp1.GetStatus() && temp2.GetStatus()) {
			N* n1 = assignmentN(temp1.GetN()), * n2 = assignmentN(temp2.GetN());
			N* result = DIV_NN_N(n1, n2);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeN(n1);
			freeN(n2);
			freeN(result);
		}
	}
		break;
	case 11: {
		StringToNConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		StringToNConverter temp2(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		if (!temp2.GetStatus())
			this->textBox2->ForeColor = System::Drawing::Color::Red;
		if (temp1.GetStatus() && temp2.GetStatus()) {
			N* n1 = assignmentN(temp1.GetN()), * n2 = assignmentN(temp2.GetN());
			N* result = MOD_NN_N(n1, n2);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeN(n1);
			freeN(n2);
			freeN(result);
		}
	}
		break;
	case 12: {
		StringToNConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		StringToNConverter temp2(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		if (!temp2.GetStatus())
			this->textBox2->ForeColor = System::Drawing::Color::Red;
		if (temp1.GetStatus() && temp2.GetStatus()) {
			N* n1 = assignmentN(temp1.GetN()), * n2 = assignmentN(temp2.GetN());
			N* result = GCF_NN_N(n1, n2);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeN(n1);
			freeN(n2);
			freeN(result);
		}
	}
		break;
	case 13: {
		StringToNConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		StringToNConverter temp2(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		if (!temp2.GetStatus())
			this->textBox2->ForeColor = System::Drawing::Color::Red;
		if (temp1.GetStatus() && temp2.GetStatus()) {
			N* n1 = assignmentN(temp1.GetN()), * n2 = assignmentN(temp2.GetN());
			N* result = LCM_NN_N(n1, n2);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeN(n1);
			freeN(n2);
			freeN(result);
		}
	}
		break;
	case 14: {
		StringToZConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		else {
			Z* z = assignmentZ(temp1.GetZ());
			N* result = ABS_Z_N(z);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeZ(z);
			freeN(result);
		}
	}
		break;
	case 15: {
		StringToZConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		else {
			Z* z = assignmentZ(temp1.GetZ());
			int result = POZ_Z_D(z);
			this->textBox3->Text = result.ToString(); 
			freeZ(z);
		}
	}
		break;
	case 16: {
		StringToZConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		else {
			Z* z = assignmentZ(temp1.GetZ());
			Z* result = MUL_ZM_Z(z);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeZ(z);
			freeZ(result);
		}
	}
		break;
	case 17: {
		StringToNConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		else {
			N* n = assignmentN(temp1.GetN());
			Z* result = TRANS_N_Z(n);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeN(n);
			freeZ(result);
		}
	}
		break;
	case 18: {
		StringToZConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		else {
			Z* z = assignmentZ(temp1.GetZ());
			N* result = TRANS_Z_N(z);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeZ(z);
			freeN(result);
		}
	}
		break;
	case 19: {
		StringToZConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		StringToZConverter temp2(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		if (!temp2.GetStatus())
			this->textBox2->ForeColor = System::Drawing::Color::Red;
		if (temp1.GetStatus() && temp2.GetStatus()) {
			Z *z1 = assignmentZ(temp1.GetZ()), *z2 = assignmentZ(temp2.GetZ());
			Z* result = ADD_ZZ_Z(z1, z2);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeZ(z1);
			freeZ(z2);
			freeZ(result);
		}
	}
		break;
	case 20: {
		StringToZConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		StringToZConverter temp2(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		if (!temp2.GetStatus())
			this->textBox2->ForeColor = System::Drawing::Color::Red;
		if (temp1.GetStatus() && temp2.GetStatus()) {
			Z *z1 = assignmentZ(temp1.GetZ()), *z2 = assignmentZ(temp2.GetZ());
			Z* result = SUB_ZZ_Z(z1, z2);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeZ(z1);
			freeZ(z2);
			freeZ(result);
		}
	}
		break;
	case 21: {
		StringToZConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		StringToZConverter temp2(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		if (!temp2.GetStatus())
			this->textBox2->ForeColor = System::Drawing::Color::Red;
		if (temp1.GetStatus() && temp2.GetStatus()) {
			Z *z1 = assignmentZ(temp1.GetZ()), *z2 = assignmentZ(temp2.GetZ());
			Z* result = MUL_ZZ_Z(z1, z2);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeZ(z1);
			freeZ(z2);
			freeZ(result);
		}
	}
		break;
	case 22: {
		StringToZConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		StringToNConverter temp2(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		if (!temp2.GetStatus())
			this->textBox2->ForeColor = System::Drawing::Color::Red;
		if (temp1.GetStatus() && temp2.GetStatus()) {
			Z* z = assignmentZ(temp1.GetZ());
			N* n = assignmentN(temp2.GetN());
			Z* result = DIV_ZN_Z(z, n);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeZ(z);
			freeN(n);
			freeZ(result);
		}
	}
		break;
	case 23: {
		StringToZConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		StringToNConverter temp2(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		if (!temp2.GetStatus())
			this->textBox2->ForeColor = System::Drawing::Color::Red;
		if (temp1.GetStatus() && temp2.GetStatus()) {
			Z* z = assignmentZ(temp1.GetZ());
			N* n = assignmentN(temp2.GetN());
			Z* result = MOD_ZN_Z(z, n);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeZ(z);
			freeN(n);
			freeZ(result);
		}
	}
		break;
	case 24: {
		StringToQConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		else {
			Q* q = assignmentQ(temp1.GetQ());
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(RED_Q_Q(q)));
			freeQ(q);
		}
	}
		break;
	case 25: {
		StringToQConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		else {
			Q* q = assignmentQ(temp1.GetQ());
			int result = INT_Q_B(q);
			this->textBox3->Text = result.ToString();
			freeQ(q);
		}
	}
		break;
	case 26: {
		StringToZConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		else {
			Z* z = assignmentZ(temp1.GetZ());
			Q* result = TRANS_Z_Q(z);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeZ(z);
			freeQ(result);
		}
	}
		break;
	case 27: {
		StringToQConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		else {
			Q* q = assignmentQ(temp1.GetQ());
			Z* result = TRANS_Q_Z(q);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeQ(q);
			freeZ(result);
		}
	}
		break;
	case 28: {
		StringToQConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		StringToQConverter temp2(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		if (!temp2.GetStatus())
			this->textBox2->ForeColor = System::Drawing::Color::Red;
		if (temp1.GetStatus() && temp2.GetStatus()) {
			Q *q1 = assignmentQ(temp1.GetQ()), *q2 = assignmentQ(temp2.GetQ());
			Q* result = ADD_QQ_Q(q1, q2);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeQ(q1);
			freeQ(q2);
			freeQ(result);
		}
	}
		break;
	case 29: {
		StringToQConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		StringToQConverter temp2(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		if (!temp2.GetStatus())
			this->textBox2->ForeColor = System::Drawing::Color::Red;
		if (temp1.GetStatus() && temp2.GetStatus()) {
			Q *q1 = assignmentQ(temp1.GetQ()), *q2 = assignmentQ(temp2.GetQ());
			Q* result = SUB_QQ_Q(q1, q2);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeQ(q1);
			freeQ(q2);
			freeQ(result);
		}
	}
		break;
	case 30: {
		StringToQConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		StringToQConverter temp2(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		if (!temp2.GetStatus())
			this->textBox2->ForeColor = System::Drawing::Color::Red;
		if (temp1.GetStatus() && temp2.GetStatus()) {
			Q *q1 = assignmentQ(temp1.GetQ()), *q2 = assignmentQ(temp2.GetQ());
			Q* result = MUL_QQ_Q(q1, q2);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeQ(q1);
			freeQ(q2);
			freeQ(result);
		}
	}
		break;
	case 31: {
		StringToQConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		StringToQConverter temp2(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		if (!temp2.GetStatus())
			this->textBox2->ForeColor = System::Drawing::Color::Red;
		if (temp1.GetStatus() && temp2.GetStatus()) {
			Q *q1 = assignmentQ(temp1.GetQ()), *q2 = assignmentQ(temp2.GetQ());
			Q* result = DIV_QQ_Q(q1, q2);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeQ(q1);
			freeQ(q2);
			freeQ(result);
		}
	}
		break;
	case 32: {
		StringToPConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		StringToPConverter temp2(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		if (!temp2.GetStatus())
			this->textBox2->ForeColor = System::Drawing::Color::Red;
		if (temp1.GetStatus() && temp2.GetStatus()) {
			P *p1 = assignmentP(temp1.GetP()), *p2 = assignmentP(temp2.GetP());
			P* result = ADD_PP_P(p1, p2);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeP(p1);
			freeP(p2);
			freeP(result);
		}
	}
		break;
	case 33: {
		StringToPConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		StringToPConverter temp2(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		if (!temp2.GetStatus())
			this->textBox2->ForeColor = System::Drawing::Color::Red;
		if (temp1.GetStatus() && temp2.GetStatus()) {
			P *p1 = assignmentP(temp1.GetP()), *p2 = assignmentP(temp2.GetP());
			P* result = SUB_PP_P(p1, p2);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeP(p1);
			freeP(p2);
			freeP(result);
		}
	}
		break;
	case 34: {
		StringToPConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		StringToQConverter temp2(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		if (!temp2.GetStatus())
			this->textBox2->ForeColor = System::Drawing::Color::Red;
		if (temp1.GetStatus() && temp2.GetStatus()) {
			P* p = assignmentP(temp1.GetP());
			Q* q = assignmentQ(temp2.GetQ());
			P* result = MUL_PQ_P(p, q);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeP(p);
			freeQ(q);
			freeP(result);
		}
	}
		break;
	case 35: {
		StringToPConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		StringToNConverter temp2(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		if (!temp2.GetStatus())
			this->textBox2->ForeColor = System::Drawing::Color::Red;
		if (temp1.GetStatus() && temp2.GetStatus()) {
			P* p = assignmentP(temp1.GetP());
			int k = NToInt(temp2.GetN());
			P* result = MUL_Pxk_P(p, k);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeP(p);
			freeP(result);
		}
	}
		break;
	case 36: {
		StringToPConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		else {
			P* p = assignmentP(temp1.GetP());
			Q* result = LED_P_Q(p);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeP(p);
			freeQ(result);
		}
	}
		break;
	case 37: {
		StringToPConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		else {
			P* p = assignmentP(temp1.GetP());
			N* result = DEG_P_N(p);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeP(p);
			freeN(result);
		}
	}
		break;
	case 38: {
		StringToPConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		else {
			P* p = assignmentP(temp1.GetP());
			Q* result = FAC_P_Q(p);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeP(p);
			freeQ(result);
		}
	}
		break;
	case 39: {
		StringToPConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		StringToPConverter temp2(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		if (!temp2.GetStatus())
			this->textBox2->ForeColor = System::Drawing::Color::Red;
		if (temp1.GetStatus() && temp2.GetStatus()) {
			P *p1 = assignmentP(temp1.GetP()), *p2 = assignmentP(temp2.GetP());
			P* result = MUL_PP_P(p1, p2);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeP(p1);
			freeP(p2);
			freeP(result);
		}
	}
		break;
	case 40: {
		StringToPConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		StringToPConverter temp2(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		if (!temp2.GetStatus())
			this->textBox2->ForeColor = System::Drawing::Color::Red;
		if (temp1.GetStatus() && temp2.GetStatus()) {
			P *p1 = assignmentP(temp1.GetP()), *p2 = assignmentP(temp2.GetP());
			P* result = DIV_PP_P(p1, p2);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeP(p1);
			freeP(p2);
			freeP(result);
		}
	}
		break;
	case 41: {
		StringToPConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		StringToPConverter temp2(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		if (!temp2.GetStatus())
			this->textBox2->ForeColor = System::Drawing::Color::Red;
		if (temp1.GetStatus() && temp2.GetStatus()) {
			P *p1 = assignmentP(temp1.GetP()), *p2 = assignmentP(temp2.GetP());
			P* result = MOD_PP_P(p1, p2);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeP(p1);
			freeP(p2);
			freeP(result);
		}
	}
		break;
	case 42: {
		StringToPConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		StringToPConverter temp2(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		if (!temp2.GetStatus())
			this->textBox2->ForeColor = System::Drawing::Color::Red;
		if (temp1.GetStatus() && temp2.GetStatus()) {
			P *p1 = assignmentP(temp1.GetP()), *p2 = assignmentP(temp2.GetP());
			P* result = GCF_PP_P(p1, p2);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeP(p1);
			freeP(p2);
			freeP(result);
		}
	}
		break;
	case 43: {
		StringToPConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		else {
			P* p = assignmentP(temp1.GetP());
			P* result = DER_P_P(p);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeP(p);
			freeP(result);
		}
	}
		break;
	case 44: {
		StringToPConverter temp1(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		if (!temp1.GetStatus())
			this->textBox1->ForeColor = System::Drawing::Color::Red;
		else {
			P* p = assignmentP(temp1.GetP());
			P* result = NMR_P_P(p);
			this->textBox3->Text = msclr::interop::marshal_as<String^>(getString(result));
			freeP(p);
			freeP(result);
		}
	}
		break;
	default:
		this->toolStripStatusLabel1->Text = "������: ������ �� ������";
		this->textBox3->Text = "�������� ������\r\n\r\n��������� �������� ������� ��������� � ������� (��� ������ ������� ������� F1)";
		break;
	}
}

private: System::Void TextBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ str0 = "������� �����";
	String^ str1 = "������� ����������� �����";
	String^ str2 = "������� ����� �����";
	String^ str3 = "������� ������������ �����";
	String^ str4 = "������� ���������";
	if (this->textBox1->Text == str0 || this->textBox1->Text == str1 || this->textBox1->Text == str2 || this->textBox1->Text == str3 || this->textBox1->Text == str4)
		this->textBox1->Text = "";
}

private: System::Void TextBox2_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ str0 = "������� �����";
	String^ str1 = "������� ����������� �����";
	String^ str2 = "������� ����� �����";
	String^ str3 = "������� ������������ �����";
	String^ str4 = "������� ���������";
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
	HelpForm^ helpForm = gcnew HelpForm();
	helpForm->Show();
}
private: System::Void MainForm_HelpRequested(System::Object^ sender, System::Windows::Forms::HelpEventArgs^ hlpevent) {
	HelpForm^ helpForm = gcnew HelpForm();
	helpForm->Show();
}
};
}
