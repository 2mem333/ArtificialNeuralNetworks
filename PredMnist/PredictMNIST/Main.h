#pragma once
#include <iostream>
#include <algorithm>
#include "neuronStruct.h"
#include "predictFunctions.h"

namespace PredictMNIST {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	private:
		/// UDV User Defined Variables

		NeuronStruct* neuron = new NeuronStruct[2];
		bool inputChange = false;
		float* input = new float[28 * 28];


	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;

	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Button^ loadEncoderWeights;
	private: System::Windows::Forms::Label^ label13;










	private: System::Windows::Forms::Button^ Predict;


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Button^ LoadInput;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ value0;
	private: System::Windows::Forms::Label^ value1;
	private: System::Windows::Forms::Label^ value3;




	private: System::Windows::Forms::Label^ value2;
	private: System::Windows::Forms::Label^ value7;


	private: System::Windows::Forms::Label^ value6;

	private: System::Windows::Forms::Label^ value5;

	private: System::Windows::Forms::Label^ value4;
	private: System::Windows::Forms::Label^ value9;


	private: System::Windows::Forms::Label^ value8;
	private: System::Windows::Forms::Button^ loadWeights;
	private: System::ComponentModel::IContainer^ components;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->LoadInput = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->value0 = (gcnew System::Windows::Forms::Label());
			this->value1 = (gcnew System::Windows::Forms::Label());
			this->value3 = (gcnew System::Windows::Forms::Label());
			this->value2 = (gcnew System::Windows::Forms::Label());
			this->value7 = (gcnew System::Windows::Forms::Label());
			this->value6 = (gcnew System::Windows::Forms::Label());
			this->value5 = (gcnew System::Windows::Forms::Label());
			this->value4 = (gcnew System::Windows::Forms::Label());
			this->value9 = (gcnew System::Windows::Forms::Label());
			this->value8 = (gcnew System::Windows::Forms::Label());
			this->loadWeights = (gcnew System::Windows::Forms::Button());
			this->Predict = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->loadEncoderWeights = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel5->SuspendLayout();
			this->SuspendLayout();
			// 
			// LoadInput
			// 
			this->LoadInput->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(58)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
				static_cast<System::Int32>(static_cast<System::Byte>(58)));
			this->LoadInput->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->LoadInput->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->LoadInput->ForeColor = System::Drawing::Color::White;
			this->LoadInput->Location = System::Drawing::Point(308, 279);
			this->LoadInput->Name = L"LoadInput";
			this->LoadInput->Size = System::Drawing::Size(174, 36);
			this->LoadInput->TabIndex = 2;
			this->LoadInput->Text = L"Load Input from file";
			this->LoadInput->UseVisualStyleBackColor = false;
			this->LoadInput->Click += gcnew System::EventHandler(this, &Main::LoadInput_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->label2->Font = (gcnew System::Drawing::Font(L"Cambria", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(9, 11);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 38);
			this->label2->TabIndex = 3;
			this->label2->Text = L"0";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->label3->Font = (gcnew System::Drawing::Font(L"Cambria", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(9, 52);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 38);
			this->label3->TabIndex = 4;
			this->label3->Text = L"1";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->label4->Font = (gcnew System::Drawing::Font(L"Cambria", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(9, 134);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 38);
			this->label4->TabIndex = 6;
			this->label4->Text = L"3";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->label5->Font = (gcnew System::Drawing::Font(L"Cambria", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(9, 93);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 38);
			this->label5->TabIndex = 5;
			this->label5->Text = L"2";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->label6->Font = (gcnew System::Drawing::Font(L"Cambria", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(9, 298);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 38);
			this->label6->TabIndex = 10;
			this->label6->Text = L"7";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->label7->Font = (gcnew System::Drawing::Font(L"Cambria", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(9, 257);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(35, 38);
			this->label7->TabIndex = 9;
			this->label7->Text = L"6";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->label8->Font = (gcnew System::Drawing::Font(L"Cambria", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label8->ForeColor = System::Drawing::Color::White;
			this->label8->Location = System::Drawing::Point(9, 216);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(35, 38);
			this->label8->TabIndex = 8;
			this->label8->Text = L"5";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->label9->Font = (gcnew System::Drawing::Font(L"Cambria", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label9->ForeColor = System::Drawing::Color::White;
			this->label9->Location = System::Drawing::Point(9, 175);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(35, 38);
			this->label9->TabIndex = 7;
			this->label9->Text = L"4";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->label10->Font = (gcnew System::Drawing::Font(L"Cambria", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label10->ForeColor = System::Drawing::Color::White;
			this->label10->Location = System::Drawing::Point(9, 380);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(35, 38);
			this->label10->TabIndex = 12;
			this->label10->Text = L"9";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->label11->Font = (gcnew System::Drawing::Font(L"Cambria", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label11->ForeColor = System::Drawing::Color::White;
			this->label11->Location = System::Drawing::Point(9, 339);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(35, 38);
			this->label11->TabIndex = 11;
			this->label11->Text = L"8";
			// 
			// value0
			// 
			this->value0->AutoSize = true;
			this->value0->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->value0->ForeColor = System::Drawing::Color::Gray;
			this->value0->Location = System::Drawing::Point(50, 22);
			this->value0->Name = L"value0";
			this->value0->Size = System::Drawing::Size(32, 21);
			this->value0->TabIndex = 13;
			this->value0->Text = L"%0";
			// 
			// value1
			// 
			this->value1->AutoSize = true;
			this->value1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->value1->ForeColor = System::Drawing::Color::Gray;
			this->value1->Location = System::Drawing::Point(50, 63);
			this->value1->Name = L"value1";
			this->value1->Size = System::Drawing::Size(32, 21);
			this->value1->TabIndex = 14;
			this->value1->Text = L"%0";
			// 
			// value3
			// 
			this->value3->AutoSize = true;
			this->value3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->value3->ForeColor = System::Drawing::Color::Gray;
			this->value3->Location = System::Drawing::Point(50, 142);
			this->value3->Name = L"value3";
			this->value3->Size = System::Drawing::Size(32, 21);
			this->value3->TabIndex = 16;
			this->value3->Text = L"%0";
			// 
			// value2
			// 
			this->value2->AutoSize = true;
			this->value2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->value2->ForeColor = System::Drawing::Color::Gray;
			this->value2->Location = System::Drawing::Point(50, 103);
			this->value2->Name = L"value2";
			this->value2->Size = System::Drawing::Size(32, 21);
			this->value2->TabIndex = 15;
			this->value2->Text = L"%0";
			// 
			// value7
			// 
			this->value7->AutoSize = true;
			this->value7->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->value7->ForeColor = System::Drawing::Color::Gray;
			this->value7->Location = System::Drawing::Point(50, 307);
			this->value7->Name = L"value7";
			this->value7->Size = System::Drawing::Size(32, 21);
			this->value7->TabIndex = 20;
			this->value7->Text = L"%0";
			// 
			// value6
			// 
			this->value6->AutoSize = true;
			this->value6->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->value6->ForeColor = System::Drawing::Color::Gray;
			this->value6->Location = System::Drawing::Point(50, 264);
			this->value6->Name = L"value6";
			this->value6->Size = System::Drawing::Size(32, 21);
			this->value6->TabIndex = 19;
			this->value6->Text = L"%0";
			// 
			// value5
			// 
			this->value5->AutoSize = true;
			this->value5->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->value5->ForeColor = System::Drawing::Color::Gray;
			this->value5->Location = System::Drawing::Point(50, 222);
			this->value5->Name = L"value5";
			this->value5->Size = System::Drawing::Size(32, 21);
			this->value5->TabIndex = 18;
			this->value5->Text = L"%0";
			// 
			// value4
			// 
			this->value4->AutoSize = true;
			this->value4->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->value4->ForeColor = System::Drawing::Color::Gray;
			this->value4->Location = System::Drawing::Point(50, 182);
			this->value4->Name = L"value4";
			this->value4->Size = System::Drawing::Size(32, 21);
			this->value4->TabIndex = 17;
			this->value4->Text = L"%0";
			// 
			// value9
			// 
			this->value9->AutoSize = true;
			this->value9->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->value9->ForeColor = System::Drawing::Color::Gray;
			this->value9->Location = System::Drawing::Point(50, 390);
			this->value9->Name = L"value9";
			this->value9->Size = System::Drawing::Size(32, 21);
			this->value9->TabIndex = 22;
			this->value9->Text = L"%0";
			// 
			// value8
			// 
			this->value8->AutoSize = true;
			this->value8->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->value8->ForeColor = System::Drawing::Color::Gray;
			this->value8->Location = System::Drawing::Point(50, 346);
			this->value8->Name = L"value8";
			this->value8->Size = System::Drawing::Size(32, 21);
			this->value8->TabIndex = 21;
			this->value8->Text = L"%0";
			// 
			// loadWeights
			// 
			this->loadWeights->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(58)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
				static_cast<System::Int32>(static_cast<System::Byte>(58)));
			this->loadWeights->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->loadWeights->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->loadWeights->ForeColor = System::Drawing::Color::White;
			this->loadWeights->Location = System::Drawing::Point(308, 237);
			this->loadWeights->Name = L"loadWeights";
			this->loadWeights->Size = System::Drawing::Size(174, 36);
			this->loadWeights->TabIndex = 23;
			this->loadWeights->Text = L"Load Weights from file";
			this->loadWeights->UseVisualStyleBackColor = false;
			this->loadWeights->Click += gcnew System::EventHandler(this, &Main::loadWeights_Click);
			// 
			// Predict
			// 
			this->Predict->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(58)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
				static_cast<System::Int32>(static_cast<System::Byte>(58)));
			this->Predict->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Predict->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->Predict->ForeColor = System::Drawing::Color::White;
			this->Predict->Location = System::Drawing::Point(263, 11);
			this->Predict->Name = L"Predict";
			this->Predict->Size = System::Drawing::Size(225, 46);
			this->Predict->TabIndex = 24;
			this->Predict->Text = L"Predict";
			this->Predict->UseVisualStyleBackColor = false;
			this->Predict->Click += gcnew System::EventHandler(this, &Main::Predict_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->richTextBox1->ForeColor = System::Drawing::Color::Silver;
			this->richTextBox1->Location = System::Drawing::Point(2, 2);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::ForcedBoth;
			this->richTextBox1->Size = System::Drawing::Size(462, 41);
			this->richTextBox1->TabIndex = 25;
			this->richTextBox1->Text = L"";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(58)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
				static_cast<System::Int32>(static_cast<System::Byte>(58)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(399, 406);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(81, 36);
			this->button1->TabIndex = 26;
			this->button1->Text = L"Load IFT";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Main::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Black;
			this->pictureBox1->Location = System::Drawing::Point(2, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(280, 280);
			this->pictureBox1->TabIndex = 27;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Main::pictureBox1_Paint);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Main::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Main::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Main::pictureBox1_MouseUp);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(58)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
				static_cast<System::Int32>(static_cast<System::Byte>(58)));
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->Location = System::Drawing::Point(18, 406);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(101, 36);
			this->button3->TabIndex = 29;
			this->button3->Text = L"clear draw";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Main::button3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(12, 320);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(103, 20);
			this->label1->TabIndex = 30;
			this->label1->Text = L"Input values:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label12->ForeColor = System::Drawing::Color::White;
			this->label12->Location = System::Drawing::Point(12, 8);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(107, 20);
			this->label12->TabIndex = 31;
			this->label12->Text = L"Input picture:";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(16, 31);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(284, 284);
			this->panel1->TabIndex = 32;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->panel2->Controls->Add(this->richTextBox1);
			this->panel2->Location = System::Drawing::Point(16, 343);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(464, 45);
			this->panel2->TabIndex = 33;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->panel3->Controls->Add(this->label2);
			this->panel3->Controls->Add(this->label3);
			this->panel3->Controls->Add(this->label5);
			this->panel3->Controls->Add(this->label4);
			this->panel3->Controls->Add(this->label9);
			this->panel3->Controls->Add(this->label8);
			this->panel3->Controls->Add(this->label7);
			this->panel3->Controls->Add(this->label6);
			this->panel3->Controls->Add(this->label11);
			this->panel3->Controls->Add(this->label10);
			this->panel3->Controls->Add(this->Predict);
			this->panel3->Controls->Add(this->value9);
			this->panel3->Controls->Add(this->value0);
			this->panel3->Controls->Add(this->value8);
			this->panel3->Controls->Add(this->value1);
			this->panel3->Controls->Add(this->value7);
			this->panel3->Controls->Add(this->value2);
			this->panel3->Controls->Add(this->value6);
			this->panel3->Controls->Add(this->value3);
			this->panel3->Controls->Add(this->value5);
			this->panel3->Controls->Add(this->value4);
			this->panel3->Location = System::Drawing::Point(620, 12);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(500, 429);
			this->panel3->TabIndex = 34;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label14->ForeColor = System::Drawing::Color::White;
			this->label14->Location = System::Drawing::Point(3, 13);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(126, 19);
			this->label14->TabIndex = 36;
			this->label14->Text = L"Weights Loaded:";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label15->ForeColor = System::Drawing::Color::Red;
			this->label15->Location = System::Drawing::Point(126, 13);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(40, 19);
			this->label15->TabIndex = 37;
			this->label15->Text = L"false";
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->panel4->Location = System::Drawing::Point(306, 31);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(174, 174);
			this->panel4->TabIndex = 38;
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->panel5->Controls->Add(this->label13);
			this->panel5->Controls->Add(this->label19);
			this->panel5->Controls->Add(this->label18);
			this->panel5->Controls->Add(this->label17);
			this->panel5->Controls->Add(this->label14);
			this->panel5->Controls->Add(this->label15);
			this->panel5->Location = System::Drawing::Point(308, 33);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(170, 170);
			this->panel5->TabIndex = 39;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label13->ForeColor = System::Drawing::Color::White;
			this->label13->Location = System::Drawing::Point(3, 56);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(95, 19);
			this->label13->TabIndex = 43;
			this->label13->Text = L"Dimension: 0";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label19->ForeColor = System::Drawing::Color::White;
			this->label19->Location = System::Drawing::Point(3, 114);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(81, 19);
			this->label19->TabIndex = 42;
			this->label19->Text = L"Neurons: {}";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label18->ForeColor = System::Drawing::Color::White;
			this->label18->Location = System::Drawing::Point(3, 84);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(109, 19);
			this->label18->TabIndex = 41;
			this->label18->Text = L"Layer Count: 0";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label17->ForeColor = System::Drawing::Color::White;
			this->label17->Location = System::Drawing::Point(3, 93);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(0, 19);
			this->label17->TabIndex = 40;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->checkBox1->Location = System::Drawing::Point(308, 213);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(111, 20);
			this->checkBox1->TabIndex = 40;
			this->checkBox1->Text = L"Use encoded";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Main::checkBox1_CheckedChanged);
			// 
			// loadEncoderWeights
			// 
			this->loadEncoderWeights->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(58)),
				static_cast<System::Int32>(static_cast<System::Byte>(58)), static_cast<System::Int32>(static_cast<System::Byte>(58)));
			this->loadEncoderWeights->Enabled = false;
			this->loadEncoderWeights->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->loadEncoderWeights->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->loadEncoderWeights->ForeColor = System::Drawing::Color::White;
			this->loadEncoderWeights->Location = System::Drawing::Point(420, 211);
			this->loadEncoderWeights->Name = L"loadEncoderWeights";
			this->loadEncoderWeights->Size = System::Drawing::Size(60, 23);
			this->loadEncoderWeights->TabIndex = 41;
			this->loadEncoderWeights->Text = L"Load Input from file";
			this->loadEncoderWeights->UseVisualStyleBackColor = false;
			this->loadEncoderWeights->Click += gcnew System::EventHandler(this, &Main::loadEncoderWeights_Click);
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->ClientSize = System::Drawing::Size(1146, 487);
			this->Controls->Add(this->loadEncoderWeights);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->loadWeights);
			this->Controls->Add(this->LoadInput);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Main";
			this->ShowIcon = false;
			this->Text = L"Main";
			this->Load += gcnew System::EventHandler(this, &Main::Main_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			loadEncoderWeights->Enabled = checkBox1->Checked;
		}

	private: System::Void loadWeights_Click(System::Object^ sender, System::EventArgs^ e) {

		OpenFileDialog^ o = gcnew OpenFileDialog();
		o->Filter = "Txt dosya (*.txt)|*.txt";

		if (o->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if (neuron[0].weightsLoaded)
			{
				neuron[0].deinit();
			}

			System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(o->FileName);

			String^ line;
			line = sr->ReadLine();
			int dimension = System::Convert::ToInt32(line);

			line = sr->ReadLine();
			neuron[0].layerCount = System::Convert::ToInt32(line);
			neuron[0].LayerNeuronCounts = new int[neuron[0].layerCount];

			for (int i = 0; i < neuron[0].layerCount; i++)
			{
				line = sr->ReadLine();
				neuron[0].LayerNeuronCounts[i] = System::Convert::ToInt32(line);
			}

			neuron[0].initialize(dimension);

			float value;

			//EGER ENCODER ILE KULLANMIYORSAK, MULTI LAYER EGITIM VERILERINI DAHIL ET.
			if (checkBox1->Checked == false) {
				for (int d = 0; d < neuron[0].dimension; d++)
				{
					line = sr->ReadLine();
					value = float::Parse(line, System::Globalization::CultureInfo::InvariantCulture);
					neuron[0].mean[d] = value;
					line = sr->ReadLine();
					value = float::Parse(line, System::Globalization::CultureInfo::InvariantCulture);
					neuron[0].std[d] = value;
				}
				line = sr->ReadLine(); //SKIP END
				if (line == "END") {
					std::cout << "Mean std readed.\n";
				}
			}

			for (int i = 0; i < neuron[0].totalHnSize; i++)
			{
				line = sr->ReadLine();
				value = float::Parse(line, System::Globalization::CultureInfo::InvariantCulture);
				neuron[0].Neurons[i] = value;
			}
			line = sr->ReadLine(); //SKIP END
			if (line == "END") {
				std::cout << "Weights readed.\n";
			}

			for (int i = 0; i < neuron[0].totalBiasSize; i++)
			{
				line = sr->ReadLine();
				value = float::Parse(line, System::Globalization::CultureInfo::InvariantCulture);
				neuron[0].bias[i] = value;
			}

			line = sr->ReadLine(); //SKIP END
			if (line == "END") {
				std::cout << "Bias readed.\n";
			}

			sr->Close();

			label15->Text = "True";
			label15->ForeColor = Color::Green;
			neuron[0].weightsLoaded = true;

			label18->Text = "Layer Count: " + neuron[0].layerCount.ToString();;
			label19->Text = "Neurons: ";

			for (int i = 0; i < neuron[0].layerCount; i++)
			{
				label19->Text += "{" + neuron[0].LayerNeuronCounts[i] + "} ";
			}

			label13->Text = "Dimension: " + dimension.ToString();
			std::cout << "Done reading weights!\n";

		}
	}

	private: System::Void LoadInput_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ o = gcnew OpenFileDialog();
		o->Filter = "Metin Dosyasý (*.txt)|*.txt";

		if (o->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if (input) { delete[] input; input = nullptr; }
			input = new float[784];

			System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(o->FileName);

			String^ line = sr->ReadLine(); // tüm 784 deðer tek satýrda

			array<String^>^ parts = line->Split(' '); // boþluklara göre böl

			for (int i = 0; i < 784; i++)
			{
				input[i] = float::Parse(parts[i],
					System::Globalization::CultureInfo::InvariantCulture);
			}

			sr->Close();

			inputChange = true;

			richTextBox1->Clear();
			for (int y = 0; y < 28; y++)
				for (int x = 0; x < 28; x++) {
					richTextBox1->AppendText(System::Convert::ToString(input[y * 28 + x]) + " ");
				}
			pictureBox1->Invalidate(); // Çizimi yenile
			std::cout << "Done reading input!\n";
		}
	}
	private: System::Void Predict_Click(System::Object^ sender, System::EventArgs^ e) {

		if (!inputChange)
			return;

		if (!neuron[0].weightsLoaded)
			return;

		if (checkBox1->Checked == false) {

				for (int d = 0; d < 784; d++) //normalize input
					input[d] = (input[d] - neuron[0].mean[d]) / neuron[0].std[d];

			PREDICT p;
			p.initialize(input,&neuron[0]);

			float* fnet = p.start_predict();
			int outputLayer = neuron[0].layerCount - 1;

			for (int o = 0; o < neuron[0].LayerNeuronCounts[outputLayer]; o++) {
				int indeks = o + neuron[0].LayerBStartInd[outputLayer];

				float accuarity = (1 + fnet[indeks]) / 2 * 100;
				int shade = 128 + (int)(accuarity / 100.0f * 127);
				System::Drawing::Color col =
					System::Drawing::Color::FromArgb(shade, shade, shade);


				std::cout << "Number: " << o << " : " << accuarity << "\n";
				switch (o)
				{
				case 0:
					value0->Text = "%" + System::Convert::ToString(accuarity);
					value0->ForeColor = col;
					break;
				case 1:
					value1->Text = "%" + System::Convert::ToString(accuarity);
					value1->ForeColor = col;
					break;
				case 2:
					value2->Text = "%" + System::Convert::ToString(accuarity);
					value2->ForeColor = col;
					break;
				case 3:
					value3->Text = "%" + System::Convert::ToString(accuarity);
					value3->ForeColor = col;
					break;
				case 4:
					value4->Text = "%" + System::Convert::ToString(accuarity);
					value4->ForeColor = col;
					break;
				case 5:
					value5->Text = "%" + System::Convert::ToString(accuarity);
					value5->ForeColor = col;
					break;
				case 6:
					value6->Text = "%" + System::Convert::ToString(accuarity);
					value6->ForeColor = col;
					break;
				case 7:
					value7->Text = "%" + System::Convert::ToString(accuarity);
					value7->ForeColor = col;
					break;
				case 8:
					value8->Text = "%" + System::Convert::ToString(accuarity);
					value8->ForeColor = col;
					break;
				case 9:
					value9->Text = "%" + System::Convert::ToString(accuarity);
					value9->ForeColor = col;
					break;
				}
			}
			std::cout << "\n";
		}
		else //ENCODER PREDICTI YAPILIR
		{
			if (!neuron[1].weightsLoaded)
				return;

			for (int d = 0; d < 784; d++) //encoderin degerleri ile normalize edilir.
				input[d] = (input[d] - neuron[1].mean[d]) / neuron[1].std[d];

			float* encodedInput = EncodeInput(input,&neuron[1]);

			PREDICT p;
			p.initialize(encodedInput, &neuron[0]);

			float* fnet = p.start_predict();
			int outputLayer = neuron[0].layerCount - 1;

			for (int o = 0; o < neuron[0].LayerNeuronCounts[outputLayer]; o++) {
				int indeks = o + neuron[0].LayerBStartInd[outputLayer];

				float accuarity = (1 + fnet[indeks]) / 2 * 100;
				int shade = 128 + (int)(accuarity / 100.0f * 127);
				System::Drawing::Color col =
					System::Drawing::Color::FromArgb(shade, shade, shade);

				std::cout << "Number: " << o << " : " << accuarity << "\n";
				switch (o)
				{
				case 0:
					value0->Text = "%" + System::Convert::ToString(accuarity);
					value0->ForeColor = col;
					break;
				case 1:
					value1->Text = "%" + System::Convert::ToString(accuarity);
					value1->ForeColor = col;
					break;
				case 2:
					value2->Text = "%" + System::Convert::ToString(accuarity);
					value2->ForeColor = col;
					break;
				case 3:
					value3->Text = "%" + System::Convert::ToString(accuarity);
					value3->ForeColor = col;
					break;
				case 4:
					value4->Text = "%" + System::Convert::ToString(accuarity);
					value4->ForeColor = col;
					break;
				case 5:
					value5->Text = "%" + System::Convert::ToString(accuarity);
					value5->ForeColor = col;
					break;
				case 6:
					value6->Text = "%" + System::Convert::ToString(accuarity);
					value6->ForeColor = col;
					break;
				case 7:
					value7->Text = "%" + System::Convert::ToString(accuarity);
					value7->ForeColor = col;
					break;
				case 8:
					value8->Text = "%" + System::Convert::ToString(accuarity);
					value8->ForeColor = col;
					break;
				case 9:
					value9->Text = "%" + System::Convert::ToString(accuarity);
					value9->ForeColor = col;
					break;
				}
			}
			std::cout << "\n";
		}

		inputChange = false;

	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (input) { delete[] input; input = nullptr; }
		input = new float[784];

		String^ line = richTextBox1->Text->Trim();
		array<String^>^ parts = line->Split(' ');

		for (int i = 0; i < 784; i++)
		{
			input[i] = float::Parse(parts[i],
				System::Globalization::CultureInfo::InvariantCulture);
		}

		inputChange = true;

		pictureBox1->Invalidate(); // Çizimi yenile

		std::cout << "Done reading input!\n";
	}


		   bool isDrawing = false;
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;
		g->FillRectangle(Brushes::Black, 0, 0, 280, 280);

		for (int y = 0; y < 28; y++)
		{
			for (int x = 0; x < 28; x++)
			{
				int val = input[x + y * 28];
				Color c = Color::FromArgb(val, val, val);
				Brush^ b = gcnew SolidBrush(c);
				g->FillRectangle(b, x * 10, y * 10, 10, 10);
			}
		}

	}
	private: System::Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		isDrawing = true;
	}
	private: System::Void pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (!isDrawing) return;

		int px = e->X / 10;
		int py = e->Y / 10;

		if (px < 0 || px >= 28 || py < 0 || py >= 28)
			return;

		int radius = 1;

		for (int dy = -radius; dy <= radius; dy++)
		{
			for (int dx = -radius; dx <= radius; dx++)
			{
				int xx = px + dx;
				int yy = py + dy;

				if (xx >= 0 && xx < 28 && yy >= 0 && yy < 28)
				{
					int dist = Math::Abs(dx) + Math::Abs(dy);
					int addVal = 40 - dist * 15;

					if (addVal < 0) addVal = 0;

					input[xx + yy * 28] = std::min(input[xx + yy * 28] + addVal, 255.0f);
				}
			}
		}
		//std::cout << "deneme";
		pictureBox1->Invalidate();
	}
	private: System::Void pictureBox1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		isDrawing = false;
		inputChange = true;
	}


	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		richTextBox1->Clear();
		for (int y = 0; y < 28; y++)
			for (int x = 0; x < 28; x++) {
				richTextBox1->AppendText(System::Convert::ToString(input[y * 28 + x]) + " ");
			}

		std::cout << "Loaded input from drawing!\n";
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < 784; i++)
			input[i] = 0;

		pictureBox1->Invalidate(); // ekraný yeniden çiz
	}
	private: System::Void Main_Load(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < 784; i++)
			input[i] = 0;
	}

private: System::Void loadEncoderWeights_Click(System::Object^ sender, System::EventArgs^ e) {

	OpenFileDialog^ o = gcnew OpenFileDialog();
	o->Filter = "Txt dosya (*.txt)|*.txt";

	if (o->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		if (neuron[1].weightsLoaded)
		{
			neuron[1].deinit();
		}

		System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(o->FileName);

		String^ line;
		line = sr->ReadLine();
		int dimension = System::Convert::ToInt32(line);
		line = sr->ReadLine();
		neuron[1].layerCount = System::Convert::ToInt32(line);
		neuron[1].LayerNeuronCounts = new int[neuron[1].layerCount];

		for (int i = 0; i < neuron[1].layerCount; i++)
		{
			line = sr->ReadLine();
			neuron[1].LayerNeuronCounts[i] = System::Convert::ToInt32(line);
		}

		neuron[1].initialize(dimension);


		float value;
		for (int d = 0; d < neuron[1].dimension; d++)
		{
			line = sr->ReadLine();
			value = float::Parse(line, System::Globalization::CultureInfo::InvariantCulture);
			neuron[1].mean[d] = value;
			line = sr->ReadLine();
			value = float::Parse(line, System::Globalization::CultureInfo::InvariantCulture);
			neuron[1].std[d] = value;
		}
		line = sr->ReadLine(); //SKIP END
		if (line == "END") {
			std::cout << "Mean std readed.\n";
		}

		for (int i = 0; i < neuron[1].totalHnSize; i++)
		{
			line = sr->ReadLine();
			value = float::Parse(line, System::Globalization::CultureInfo::InvariantCulture);
			neuron[1].Neurons[i] = value;
		}
		line = sr->ReadLine(); //SKIP END
		if (line == "END") {
			std::cout << "Weights readed.\n";
		}

		for (int i = 0; i < neuron[1].totalBiasSize; i++)
		{
			line = sr->ReadLine();
			value = float::Parse(line, System::Globalization::CultureInfo::InvariantCulture);
			neuron[1].bias[i] = value;
		}

		line = sr->ReadLine(); //SKIP END
		if (line == "END") {
			std::cout << "Bias readed.\n";
		}

		sr->Close();


		neuron[1].weightsLoaded = true;


		std::cout << "Done reading encoder weights!\n";

	}
}

};
}
