#pragma once
#include <msclr/marshal_cppstd.h>
#include "StringToNConverter.h"
#include "StringToZConverter.h"
#include "StringToQConverter.h"
#include "StringToPConverter.h"

namespace DiskretkaGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^ label1;
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
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// comboBox1
			// 
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
			this->comboBox1->Location = System::Drawing::Point(8, 28);
			this->comboBox1->Margin = System::Windows::Forms::Padding(4);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(332, 32);
			this->comboBox1->TabIndex = 0;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::ComboBox1_SelectedIndexChanged);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(8, 68);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(332, 122);
			this->textBox1->TabIndex = 1;
			this->textBox1->Visible = false;
			this->textBox1->Click += gcnew System::EventHandler(this, &MyForm::TextBox1_Click);
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::TextBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(8, 198);
			this->textBox2->Margin = System::Windows::Forms::Padding(4);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox2->Size = System::Drawing::Size(332, 122);
			this->textBox2->TabIndex = 2;
			this->textBox2->Visible = false;
			this->textBox2->Click += gcnew System::EventHandler(this, &MyForm::TextBox2_Click);
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::TextBox2_TextChanged);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(8, 329);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(333, 33);
			this->button1->TabIndex = 3;
			this->button1->Text = L"ѕроизвести расчет";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::Button1_Click);
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(8, 28);
			this->textBox3->Margin = System::Windows::Forms::Padding(4);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox3->Size = System::Drawing::Size(332, 333);
			this->textBox3->TabIndex = 4;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(16, 15);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4);
			this->groupBox1->Size = System::Drawing::Size(349, 369);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"¬вод";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 64);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(186, 24);
			this->label1->TabIndex = 7;
			this->label1->Text = L"¬ыберите модуль";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBox3);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox2->Location = System::Drawing::Point(373, 15);
			this->groupBox2->Margin = System::Windows::Forms::Padding(4);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(4);
			this->groupBox2->Size = System::Drawing::Size(349, 369);
			this->groupBox2->TabIndex = 6;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"¬ывод";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(739, 395);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBox2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->HelpButton = true;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"—истема компьютерной алгебры";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
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
	String^ str0 = "¬ведите число";
	String^ str1 = "¬ведите натуральное число";
	String^ str2 = "¬ведите целое число";
	String^ str3 = "¬ведите рациональное число";
	String^ str4 = "¬ведите многочлен";
	this->textBox1->ForeColor = System::Drawing::SystemColors::WindowText;
	this->textBox2->ForeColor = System::Drawing::SystemColors::WindowText;
	this->textBox3->Text = "";
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
	/*case 32:
		SetFields(str4, str4);
		break;
	/*case 33:
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
		break;*/
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
};
}
