#pragma once
#include <msclr\marshal_cppstd.h>
#include <fstream>
#include <cliext/utility>
#include <cliext/queue>
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
	public ref class MyTextBox : public System::Windows::Forms::Form
	{
	public:

		MyTextBox(const TTreeTable& tree)
		{
			InitializeComponent();
			TNode* root = tree.GetRoot();
			if (root == nullptr)
				return;
			cliext::queue<cliext::pair<TNode*, TreeNode^>^> q;
			TreeNode^ rootNode = gcnew TreeNode(msclr::interop::marshal_as<String^>(std::to_string(root->rec.key)));
			q.push(gcnew cliext::pair<TNode*, TreeNode^>(root, rootNode));
			while (!q.empty())
			{
				cliext::pair<TNode*, TreeNode^>^ currentPair = q.front();
				const TNode* currentNode = currentPair->first;
				TreeNode^ currentTreeNode = currentPair->second;
				q.pop();
				if (currentNode == nullptr)
					break;
				if (currentNode->pLeft != nullptr)
				{
					auto s = std::to_string(currentNode->pLeft->rec.key);
					TreeNode^ leftNode = gcnew TreeNode(msclr::interop::marshal_as<String^>(s));
					q.push(gcnew cliext::pair<TNode*, TreeNode^>(currentNode->pLeft, leftNode));
					currentTreeNode->Nodes->Add(leftNode);
				}
				if (currentNode->pLeft != nullptr || currentNode->pRight != nullptr)
				{
					if (currentNode->pLeft == nullptr)
						currentTreeNode->Nodes->Add(gcnew TreeNode("empty"));
				}
				if (currentNode->pRight != nullptr)
				{
					TreeNode^ rightNode = gcnew TreeNode(msclr::interop::marshal_as<String^>(std::to_string(currentNode->pRight->rec.key)));
					q.push(gcnew cliext::pair<TNode*, TreeNode^>(currentNode->pRight, rightNode));
					currentTreeNode->Nodes->Add(rightNode);
				}
				if (currentNode->pLeft != nullptr || currentNode->pRight != nullptr)
				{
					if (currentNode->pRight == nullptr)
						currentTreeNode->Nodes->Add(gcnew TreeNode("empty"));
				}
			}
			treeView1->Nodes->Add(rootNode);
			treeView1->ExpandAll();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyTextBox()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TreeView^ treeView1;
	protected:

	protected:
	private:
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
			this->treeView1 = (gcnew System::Windows::Forms::TreeView());
			this->SuspendLayout();
			// 
			// treeView1
			// 
			this->treeView1->Location = System::Drawing::Point(31, 35);
			this->treeView1->Name = L"treeView1";
			this->treeView1->Size = System::Drawing::Size(890, 660);
			this->treeView1->TabIndex = 0;
			// 
			// MyTextBox
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(942, 713);
			this->Controls->Add(this->treeView1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximumSize = System::Drawing::Size(960, 760);
			this->MinimumSize = System::Drawing::Size(960, 760);
			this->Name = L"MyTextBox";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Дерево";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
