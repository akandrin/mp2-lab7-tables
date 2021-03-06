#pragma once
#include <random>
#include <msclr\marshal_cppstd.h>
#include <fstream>
#include "..\mp2-lab7-tables\TTable.h"
#include "..\mp2-lab7-tables\TSortTable.h"
#include "..\mp2-lab7-tables\TScanTable.h"
#include "..\mp2-lab7-tables\TArrayHash.h"
#include "..\mp2-lab7-tables\TListHash.h"
#include "..\mp2-lab7-tables\TTreeTable.h"
#include "..\mp2-lab7-tables\TBalTree.h"
#include "..\mp2-lab7-tables\RandomRange.h"
#include "MyTextBox.h"
#include <sstream>
namespace CppWinForm1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		System::Windows::Forms::Label^ label1;

		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::TextBox^ textBoxRecNumber;
		System::Windows::Forms::TextBox^ textBoxKeyRange;

		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::Label^ label4;
		System::Windows::Forms::Label^ label5;
		System::Windows::Forms::TextBox^ textBoxKey;
		System::Windows::Forms::TextBox^ textBoxResult;


		System::Windows::Forms::Button^ buttonCreateTable;
		System::Windows::Forms::Button^ buttonFind;
		System::Windows::Forms::Button^ buttonInsert;
		System::Windows::Forms::Button^ buttonDelete;

		System::Windows::Forms::DataGridView^ dataGridView1;
		System::Windows::Forms::DataGridViewTextBoxColumn^ Key;
		System::Windows::Forms::DataGridViewTextBoxColumn^ Value;

		System::Windows::Forms::ComboBox^ comboBox1;

		TTable* table = nullptr;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBoxEff;

		   /// <summary>
		   /// Required designer variable.
		   /// </summary>
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->textBoxRecNumber = (gcnew System::Windows::Forms::TextBox());
			   this->textBoxKeyRange = (gcnew System::Windows::Forms::TextBox());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->textBoxKey = (gcnew System::Windows::Forms::TextBox());
			   this->textBoxResult = (gcnew System::Windows::Forms::TextBox());
			   this->buttonCreateTable = (gcnew System::Windows::Forms::Button());
			   this->buttonFind = (gcnew System::Windows::Forms::Button());
			   this->buttonInsert = (gcnew System::Windows::Forms::Button());
			   this->buttonDelete = (gcnew System::Windows::Forms::Button());
			   this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			   this->Key = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Value = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->textBoxEff = (gcnew System::Windows::Forms::TextBox());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label1->Location = System::Drawing::Point(509, 44);
			   this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(116, 20);
			   this->label1->TabIndex = 0;
			   this->label1->Text = L"??? ???????";
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label2->Location = System::Drawing::Point(745, 44);
			   this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(134, 20);
			   this->label2->TabIndex = 7;
			   this->label2->Text = L"????? ???????";
			   // 
			   // textBoxRecNumber
			   // 
			   this->textBoxRecNumber->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->textBoxRecNumber->Location = System::Drawing::Point(890, 42);
			   this->textBoxRecNumber->Margin = System::Windows::Forms::Padding(4);
			   this->textBoxRecNumber->Name = L"textBoxRecNumber";
			   this->textBoxRecNumber->Size = System::Drawing::Size(73, 24);
			   this->textBoxRecNumber->TabIndex = 8;
			   // 
			   // textBoxKeyRange
			   // 
			   this->textBoxKeyRange->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->textBoxKeyRange->Location = System::Drawing::Point(890, 80);
			   this->textBoxKeyRange->Margin = System::Windows::Forms::Padding(4);
			   this->textBoxKeyRange->Name = L"textBoxKeyRange";
			   this->textBoxKeyRange->Size = System::Drawing::Size(73, 24);
			   this->textBoxKeyRange->TabIndex = 9;
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label3->Location = System::Drawing::Point(721, 82);
			   this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(158, 20);
			   this->label3->TabIndex = 10;
			   this->label3->Text = L"???????? ??????";
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label4->Location = System::Drawing::Point(826, 143);
			   this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(53, 20);
			   this->label4->TabIndex = 11;
			   this->label4->Text = L"????";
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label5->Location = System::Drawing::Point(782, 183);
			   this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(97, 20);
			   this->label5->TabIndex = 12;
			   this->label5->Text = L"?????????";
			   // 
			   // textBoxKey
			   // 
			   this->textBoxKey->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->textBoxKey->Location = System::Drawing::Point(890, 139);
			   this->textBoxKey->Margin = System::Windows::Forms::Padding(4);
			   this->textBoxKey->Name = L"textBoxKey";
			   this->textBoxKey->Size = System::Drawing::Size(73, 24);
			   this->textBoxKey->TabIndex = 13;
			   // 
			   // textBoxResult
			   // 
			   this->textBoxResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->textBoxResult->Location = System::Drawing::Point(890, 181);
			   this->textBoxResult->Margin = System::Windows::Forms::Padding(4);
			   this->textBoxResult->Name = L"textBoxResult";
			   this->textBoxResult->ReadOnly = true;
			   this->textBoxResult->Size = System::Drawing::Size(73, 24);
			   this->textBoxResult->TabIndex = 14;
			   // 
			   // buttonCreateTable
			   // 
			   this->buttonCreateTable->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->buttonCreateTable->Location = System::Drawing::Point(460, 130);
			   this->buttonCreateTable->Margin = System::Windows::Forms::Padding(4);
			   this->buttonCreateTable->Name = L"buttonCreateTable";
			   this->buttonCreateTable->Size = System::Drawing::Size(220, 33);
			   this->buttonCreateTable->TabIndex = 16;
			   this->buttonCreateTable->Text = L"??????? ???????";
			   this->buttonCreateTable->UseVisualStyleBackColor = true;
			   this->buttonCreateTable->Click += gcnew System::EventHandler(this, &MyForm::buttonCreateTable_Click);
			   // 
			   // buttonFind
			   // 
			   this->buttonFind->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->buttonFind->Location = System::Drawing::Point(460, 183);
			   this->buttonFind->Margin = System::Windows::Forms::Padding(4);
			   this->buttonFind->Name = L"buttonFind";
			   this->buttonFind->Size = System::Drawing::Size(220, 33);
			   this->buttonFind->TabIndex = 17;
			   this->buttonFind->Text = L"????? ?? ?????";
			   this->buttonFind->UseVisualStyleBackColor = true;
			   this->buttonFind->Click += gcnew System::EventHandler(this, &MyForm::buttonFind_Click);
			   // 
			   // buttonInsert
			   // 
			   this->buttonInsert->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->buttonInsert->Location = System::Drawing::Point(460, 236);
			   this->buttonInsert->Margin = System::Windows::Forms::Padding(4);
			   this->buttonInsert->Name = L"buttonInsert";
			   this->buttonInsert->Size = System::Drawing::Size(220, 33);
			   this->buttonInsert->TabIndex = 18;
			   this->buttonInsert->Text = L"???????? ??????";
			   this->buttonInsert->UseVisualStyleBackColor = true;
			   this->buttonInsert->Click += gcnew System::EventHandler(this, &MyForm::buttonInsert_Click);
			   // 
			   // buttonDelete
			   // 
			   this->buttonDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->buttonDelete->Location = System::Drawing::Point(460, 291);
			   this->buttonDelete->Margin = System::Windows::Forms::Padding(4);
			   this->buttonDelete->Name = L"buttonDelete";
			   this->buttonDelete->Size = System::Drawing::Size(220, 33);
			   this->buttonDelete->TabIndex = 19;
			   this->buttonDelete->Text = L"??????? ??????";
			   this->buttonDelete->UseVisualStyleBackColor = true;
			   this->buttonDelete->Click += gcnew System::EventHandler(this, &MyForm::buttonDelete_Click);
			   // 
			   // dataGridView1
			   // 
			   this->dataGridView1->AllowUserToAddRows = false;
			   this->dataGridView1->AllowUserToDeleteRows = false;
			   this->dataGridView1->AllowUserToResizeColumns = false;
			   this->dataGridView1->AllowUserToResizeRows = false;
			   dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			   dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			   dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			   dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			   dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			   dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			   this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			   this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->Key, this->Value });
			   dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			   dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			   dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			   dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			   dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			   dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			   this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			   this->dataGridView1->Location = System::Drawing::Point(15, 15);
			   this->dataGridView1->Margin = System::Windows::Forms::Padding(4);
			   this->dataGridView1->Name = L"dataGridView1";
			   this->dataGridView1->ReadOnly = true;
			   this->dataGridView1->RowHeadersWidth = 51;
			   this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			   this->dataGridView1->Size = System::Drawing::Size(410, 447);
			   this->dataGridView1->TabIndex = 20;
			   // 
			   // Key
			   // 
			   this->Key->HeaderText = L"Key";
			   this->Key->MinimumWidth = 6;
			   this->Key->Name = L"Key";
			   this->Key->ReadOnly = true;
			   this->Key->Width = 125;
			   // 
			   // Value
			   // 
			   this->Value->HeaderText = L"Value";
			   this->Value->MinimumWidth = 6;
			   this->Value->Name = L"Value";
			   this->Value->ReadOnly = true;
			   this->Value->Width = 125;
			   // 
			   // comboBox1
			   // 
			   this->comboBox1->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(6) {
				   L"???????????????", L"?????????????",
					   L"???-??????? (??????)", L"???-??????? (??????)", L"??????", L"???-??????"
			   });
			   this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->comboBox1->FormattingEnabled = true;
			   this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				   L"???????????????", L"?????????????", L"???-??????? (??????)",
					   L"???-??????? (??????)", L"??????", L"???-??????"
			   });
			   this->comboBox1->Location = System::Drawing::Point(460, 68);
			   this->comboBox1->Margin = System::Windows::Forms::Padding(4);
			   this->comboBox1->Name = L"comboBox1";
			   this->comboBox1->Size = System::Drawing::Size(220, 26);
			   this->comboBox1->TabIndex = 22;
			   // 
			   // label6
			   // 
			   this->label6->AutoSize = true;
			   this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label6->Location = System::Drawing::Point(727, 223);
			   this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(152, 20);
			   this->label6->TabIndex = 23;
			   this->label6->Text = L"?????????????";
			   // 
			   // textBoxEff
			   // 
			   this->textBoxEff->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->textBoxEff->Location = System::Drawing::Point(890, 223);
			   this->textBoxEff->Margin = System::Windows::Forms::Padding(4);
			   this->textBoxEff->Name = L"textBoxEff";
			   this->textBoxEff->ReadOnly = true;
			   this->textBoxEff->Size = System::Drawing::Size(73, 24);
			   this->textBoxEff->TabIndex = 24;
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(982, 516);
			   this->Controls->Add(this->textBoxEff);
			   this->Controls->Add(this->label6);
			   this->Controls->Add(this->comboBox1);
			   this->Controls->Add(this->dataGridView1);
			   this->Controls->Add(this->buttonDelete);
			   this->Controls->Add(this->buttonInsert);
			   this->Controls->Add(this->buttonFind);
			   this->Controls->Add(this->buttonCreateTable);
			   this->Controls->Add(this->textBoxResult);
			   this->Controls->Add(this->textBoxKey);
			   this->Controls->Add(this->label5);
			   this->Controls->Add(this->label4);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->textBoxKeyRange);
			   this->Controls->Add(this->textBoxRecNumber);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->label1);
			   this->Margin = System::Windows::Forms::Padding(4);
			   this->MaximumSize = System::Drawing::Size(1000, 563);
			   this->MinimumSize = System::Drawing::Size(1000, 563);
			   this->Name = L"MyForm";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"mp2-lab7 Tables";
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private:
		int table_index = 0;
		void FillDataGridView()
		{
			TRecord record;

			dataGridView1->Rows->Clear();
			for (table->Reset(); !table->IsEnd(); table->GoNext())
			{
				record = table->GetCurrentRecord();
				String^ key = record.key.ToString();
				String^ value = msclr::interop::marshal_as<System::String^>(record.value);
				dataGridView1->Rows->Add(key, value);
			}
			dataGridView1->Refresh();
			textBoxEff->Text = table->GetEffectiveness().ToString();
			if (table_index == 4 || table_index == 5)
			{
				MyTextBox^ textBox = gcnew MyTextBox(*dynamic_cast<TTreeTable*>(table));
				textBox->Show();
			}
		}
		void SelectRowContainingKey(TKey key)
		{
			for (int i = 0; i < dataGridView1->Rows->Count; i++)
			{
				String^ key_value = dataGridView1->Rows[i]->Cells["Key"]->Value->ToString()->Trim();
				if (key_value == key.ToString())
				{
					dataGridView1->CurrentCell = dataGridView1->Rows[i]->Cells[0];
				}
			}
		}
		System::Void buttonCreateTable_Click(System::Object^ sender, System::EventArgs^ e)
		{
			int recNum;
			try
			{
				recNum = int::Parse(textBoxRecNumber->Text);
			}
			catch (...)
			{
				MessageBox::Show("?????? ????? ?????????? ???????");
				return;
			}
			try
			{
				int recNum = int::Parse(textBoxRecNumber->Text);
			}
			catch (...)
			{
				MessageBox::Show("?????? ????? ?????????? ???????");
				return;
			}

			table_index = comboBox1->SelectedIndex;
			switch (table_index)
			{
			case 0:
				table = new TScanTable(recNum);
				break;
			case 1:
				table = new TSortTable(recNum);
				break;
			case 2:
				table = new TArrayHash(recNum);
				break;
			case 3:
				table = new TListHash(recNum);
				break;
			case 4:
				table = new TTreeTable();
				break;
			case 5:
				table = new TBalTree();
				break;
			default:
				MessageBox::Show("???????? ??? ???????");
				return;
			}

			int keyRange;
			try
			{
				keyRange = int::Parse(textBoxKeyRange->Text);
			}
			catch (...)
			{
				MessageBox::Show("?????? ????? ????????? ??????");
				return;
			}

			if (keyRange < recNum)
			{
				MessageBox::Show("??????? ????????? ???????? ?????? ??? ?????? ?????????? ???????");
				return;
			}

			TRecord record;
			size_t record_index = 0;
			for (RandomRange<int> randomRange(1, keyRange, NextValue<int>()); randomRange.HasNext() && record_index < recNum;)
			{
				record.key = randomRange.GetNext();
				record.value = std::string("record#") + std::to_string(record_index++ + 1);
				table->Insert(record);
			}

			FillDataGridView();
		}
		System::Void buttonFind_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (table == nullptr)
			{
				MessageBox::Show("?? ?? ??????? ???????. ??????? \"???????\"");
				return;
			}
			TKey key;
			try
			{
				key = int::Parse(textBoxKey->Text);
			}
			catch (...)
			{
				MessageBox::Show("?????? ????? ?????");
				return;
			}
			table->ClearEffectiveness();
			bool result = table->Find(key);
			if (result)
			{
				SelectRowContainingKey(key);
			}
			textBoxResult->Text = result.ToString();
			textBoxEff->Text = table->GetEffectiveness().ToString();
		}
		System::Void buttonInsert_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (table == nullptr)
			{
				MessageBox::Show("?? ?? ??????? ???????. ??????? \"???????\"");
				return;
			}
			if (table->IsFull())
			{
				MessageBox::Show("??????? ?????. ??????? \"??????? ??????\"");
				return;
			}
			TKey key;
			try
			{
				key = int::Parse(textBoxKey->Text);
			}
			catch (...)
			{
				MessageBox::Show("?????? ????? ?????");
				return;
			}
			TRecord rec = { key, std::string("record#") + std::to_string(key) };
			table->ClearEffectiveness();
			bool result = table->Insert(rec);

			FillDataGridView();
			SelectRowContainingKey(key);

			textBoxResult->Text = result.ToString();
			textBoxEff->Text = table->GetEffectiveness().ToString();
		}
		System::Void buttonDelete_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (table == nullptr)
			{
				MessageBox::Show("?? ?? ??????? ???????. ??????? \"???????\"");
				return;
			}
			if (table->IsEmpty())
			{
				MessageBox::Show("??????? ?????. ??????? \"???????? ??????\"");
				return;
			}
			TKey key;
			try
			{
				key = int::Parse(textBoxKey->Text);
			}
			catch (...)
			{
				MessageBox::Show("?????? ????? ?????");
				return;
			}
			table->ClearEffectiveness();
			bool result = table->Delete(key);

			FillDataGridView();

			textBoxResult->Text = result.ToString();
			textBoxEff->Text = table->GetEffectiveness().ToString();
		}
	};
}
