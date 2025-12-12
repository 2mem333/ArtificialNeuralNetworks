#pragma once
#include <iostream>
#include "MultiLayerNetwork.h"
#include "MultiLayerNetwork2.h"
#include "AutoEncoder.h"

#include <fstream>
#include <msclr/marshal_cppstd.h>

namespace TrainMNIST {

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
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;




	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Label^ label29;
	private: System::Windows::Forms::Label^ label28;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox11;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ textBox12;
	private: System::Windows::Forms::TextBox^ textBox13;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TextBox^ textBox14;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;

	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::TextBox^ textBox21;
	private: System::Windows::Forms::TextBox^ textBox15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::TextBox^ textBox16;
	private: System::Windows::Forms::TextBox^ textBox17;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::TextBox^ textBox18;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::TextBox^ textBox19;
	private: System::Windows::Forms::TextBox^ textBox20;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button5;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->textBox21 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->textBox18 = (gcnew System::Windows::Forms::TextBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->textBox19 = (gcnew System::Windows::Forms::TextBox());
			this->textBox20 = (gcnew System::Windows::Forms::TextBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(84, 288);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(114, 35);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Train";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Main::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 34);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(152, 22);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"C:\\\\Users\\\\negan\\\\Desktop\\\\mnist_dataset\\\\t10k-images.idx3-ubyte";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label1->Location = System::Drawing::Point(12, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(124, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"MNIST inputs path:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label2->Location = System::Drawing::Point(12, 71);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(123, 17);
			this->label2->TabIndex = 4;
			this->label2->Text = L"MNIST labels path:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 90);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(152, 22);
			this->textBox2->TabIndex = 3;
			this->textBox2->Text = L"C:\\\\Users\\\\negan\\\\Desktop\\\\mnist_dataset\\\\t10k-labels.idx1-ubyte";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(141, 247);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(102, 22);
			this->textBox7->TabIndex = 23;
			this->textBox7->Text = L"5,5";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label29->Location = System::Drawing::Point(5, 249);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(122, 20);
			this->label29->TabIndex = 22;
			this->label29->Text = L"Neuron Counts:";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label28->Location = System::Drawing::Point(5, 220);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(108, 20);
			this->label28->TabIndex = 21;
			this->label28->Text = L"Layer Counts:";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(141, 216);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(102, 22);
			this->textBox6->TabIndex = 20;
			this->textBox6->Text = L"2";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(135, 58);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(110, 22);
			this->textBox3->TabIndex = 24;
			this->textBox3->Text = L"0,01";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label3->Location = System::Drawing::Point(30, 58);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(73, 20);
			this->label3->TabIndex = 25;
			this->label3->Text = L"Min Error";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(135, 88);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(110, 22);
			this->textBox5->TabIndex = 26;
			this->textBox5->Text = L"1000";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label6->Location = System::Drawing::Point(30, 117);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(28, 20);
			this->label6->TabIndex = 29;
			this->label6->Text = L"LC";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label5->Location = System::Drawing::Point(30, 88);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(92, 20);
			this->label5->TabIndex = 27;
			this->label5->Text = L"Max Epoch";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(135, 117);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(110, 22);
			this->textBox8->TabIndex = 28;
			this->textBox8->Text = L"0,01";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label4->Location = System::Drawing::Point(30, 150);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(96, 20);
			this->label4->TabIndex = 31;
			this->label4->Text = L"Input Count";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(135, 150);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(110, 22);
			this->textBox4->TabIndex = 30;
			this->textBox4->Text = L"100";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label7->Location = System::Drawing::Point(40, 139);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(96, 20);
			this->label7->TabIndex = 44;
			this->label7->Text = L"Input Count";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(145, 139);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(110, 22);
			this->textBox9->TabIndex = 43;
			this->textBox9->Text = L"100";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(145, 47);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(110, 22);
			this->textBox10->TabIndex = 37;
			this->textBox10->Text = L"0,01";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label8->Location = System::Drawing::Point(40, 47);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(73, 20);
			this->label8->TabIndex = 38;
			this->label8->Text = L"Min Error";
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(145, 77);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(110, 22);
			this->textBox11->TabIndex = 39;
			this->textBox11->Text = L"1000";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label9->Location = System::Drawing::Point(40, 106);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(28, 20);
			this->label9->TabIndex = 42;
			this->label9->Text = L"LC";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label10->Location = System::Drawing::Point(40, 77);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(92, 20);
			this->label10->TabIndex = 40;
			this->label10->Text = L"Max Epoch";
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(145, 106);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(110, 22);
			this->textBox12->TabIndex = 41;
			this->textBox12->Text = L"0,01";
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(160, 232);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(95, 22);
			this->textBox13->TabIndex = 36;
			this->textBox13->Text = L"32,784";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label11->Location = System::Drawing::Point(24, 234);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(122, 20);
			this->label11->TabIndex = 35;
			this->label11->Text = L"Neuron Counts:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label12->Location = System::Drawing::Point(24, 205);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(108, 20);
			this->label12->TabIndex = 34;
			this->label12->Text = L"Layer Counts:";
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(160, 201);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(95, 22);
			this->textBox14->TabIndex = 33;
			this->textBox14->Text = L"2";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(93, 288);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(114, 35);
			this->button2->TabIndex = 32;
			this->button2->Text = L"Encode";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Main::button2_Click);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label13->Location = System::Drawing::Point(73, 11);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(111, 18);
			this->label13->TabIndex = 45;
			this->label13->Text = L"Encode Inputs";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label14->Location = System::Drawing::Point(30, 17);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(194, 18);
			this->label14->TabIndex = 46;
			this->label14->Text = L"Train with only multi-layer";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->panel1->Controls->Add(this->label14);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->textBox6);
			this->panel1->Controls->Add(this->label28);
			this->panel1->Controls->Add(this->label29);
			this->panel1->Controls->Add(this->textBox7);
			this->panel1->Controls->Add(this->textBox8);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->textBox5);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->textBox3);
			this->panel1->Controls->Add(this->textBox4);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Location = System::Drawing::Point(227, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(290, 438);
			this->panel1->TabIndex = 47;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->panel2->Controls->Add(this->button6);
			this->panel2->Controls->Add(this->button3);
			this->panel2->Controls->Add(this->label22);
			this->panel2->Controls->Add(this->textBox21);
			this->panel2->Controls->Add(this->textBox15);
			this->panel2->Controls->Add(this->label16);
			this->panel2->Controls->Add(this->label17);
			this->panel2->Controls->Add(this->textBox16);
			this->panel2->Controls->Add(this->textBox17);
			this->panel2->Controls->Add(this->label18);
			this->panel2->Controls->Add(this->label19);
			this->panel2->Controls->Add(this->textBox18);
			this->panel2->Controls->Add(this->label20);
			this->panel2->Controls->Add(this->textBox19);
			this->panel2->Controls->Add(this->textBox20);
			this->panel2->Controls->Add(this->label21);
			this->panel2->Controls->Add(this->label15);
			this->panel2->Controls->Add(this->label13);
			this->panel2->Controls->Add(this->button2);
			this->panel2->Controls->Add(this->textBox14);
			this->panel2->Controls->Add(this->label7);
			this->panel2->Controls->Add(this->label12);
			this->panel2->Controls->Add(this->textBox9);
			this->panel2->Controls->Add(this->label11);
			this->panel2->Controls->Add(this->textBox10);
			this->panel2->Controls->Add(this->textBox13);
			this->panel2->Controls->Add(this->label8);
			this->panel2->Controls->Add(this->textBox12);
			this->panel2->Controls->Add(this->textBox11);
			this->panel2->Controls->Add(this->label10);
			this->panel2->Controls->Add(this->label9);
			this->panel2->Location = System::Drawing::Point(523, 12);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(628, 438);
			this->panel2->TabIndex = 48;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(470, 352);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(114, 35);
			this->button3->TabIndex = 61;
			this->button3->Text = L"Train";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Main::button3_Click);
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label22->Location = System::Drawing::Point(309, 49);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(119, 17);
			this->label22->TabIndex = 60;
			this->label22->Text = L"Encoder weights:";
			// 
			// textBox21
			// 
			this->textBox21->Location = System::Drawing::Point(312, 69);
			this->textBox21->Name = L"textBox21";
			this->textBox21->Size = System::Drawing::Size(176, 22);
			this->textBox21->TabIndex = 59;
			this->textBox21->Text = L"weight_values(autoencoder),500.txt";
			// 
			// textBox15
			// 
			this->textBox15->Location = System::Drawing::Point(482, 277);
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(102, 22);
			this->textBox15->TabIndex = 47;
			this->textBox15->Text = L"2";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label16->Location = System::Drawing::Point(346, 281);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(108, 20);
			this->label16->TabIndex = 48;
			this->label16->Text = L"Layer Counts:";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label17->Location = System::Drawing::Point(346, 310);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(122, 20);
			this->label17->TabIndex = 49;
			this->label17->Text = L"Neuron Counts:";
			// 
			// textBox16
			// 
			this->textBox16->Location = System::Drawing::Point(482, 308);
			this->textBox16->Name = L"textBox16";
			this->textBox16->Size = System::Drawing::Size(102, 22);
			this->textBox16->TabIndex = 50;
			this->textBox16->Text = L"64,10";
			// 
			// textBox17
			// 
			this->textBox17->Location = System::Drawing::Point(476, 178);
			this->textBox17->Name = L"textBox17";
			this->textBox17->Size = System::Drawing::Size(110, 22);
			this->textBox17->TabIndex = 55;
			this->textBox17->Text = L"0,01";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label18->Location = System::Drawing::Point(371, 149);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(92, 20);
			this->label18->TabIndex = 54;
			this->label18->Text = L"Max Epoch";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label19->Location = System::Drawing::Point(371, 178);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(28, 20);
			this->label19->TabIndex = 56;
			this->label19->Text = L"LC";
			// 
			// textBox18
			// 
			this->textBox18->Location = System::Drawing::Point(476, 149);
			this->textBox18->Name = L"textBox18";
			this->textBox18->Size = System::Drawing::Size(110, 22);
			this->textBox18->TabIndex = 53;
			this->textBox18->Text = L"1000";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label20->Location = System::Drawing::Point(371, 119);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(73, 20);
			this->label20->TabIndex = 52;
			this->label20->Text = L"Min Error";
			// 
			// textBox19
			// 
			this->textBox19->Location = System::Drawing::Point(476, 119);
			this->textBox19->Name = L"textBox19";
			this->textBox19->Size = System::Drawing::Size(110, 22);
			this->textBox19->TabIndex = 51;
			this->textBox19->Text = L"0,01";
			// 
			// textBox20
			// 
			this->textBox20->Location = System::Drawing::Point(476, 211);
			this->textBox20->Name = L"textBox20";
			this->textBox20->Size = System::Drawing::Size(110, 22);
			this->textBox20->TabIndex = 57;
			this->textBox20->Text = L"100";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label21->Location = System::Drawing::Point(371, 211);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(96, 20);
			this->label21->TabIndex = 58;
			this->label21->Text = L"Input Count";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label15->Location = System::Drawing::Point(372, 11);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(159, 18);
			this->label15->TabIndex = 46;
			this->label15->Text = L"Train Encoded Inputs";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(170, 34);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(41, 23);
			this->button4->TabIndex = 49;
			this->button4->Text = L"...";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Main::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(170, 90);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(41, 23);
			this->button5->TabIndex = 50;
			this->button5->Text = L"...";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(494, 69);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(41, 23);
			this->button6->TabIndex = 51;
			this->button6->Text = L"...";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1170, 510);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Name = L"Main";
			this->Text = L"Main";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		
		int layerCount = System::Convert::ToInt32(textBox6->Text);
		int* layersNeurons = new int[layerCount];
		array<String^>^ parts = textBox7->Text->Split(',');

		std::cout << "Layer Count: " << layerCount << "\n";

		if (parts->Length == layerCount) {
			std::cout << "Layer neurons: ";
			for (int i = 0; i < layerCount; i++)
			{
				layersNeurons[i] = Int32::Parse(parts[i]);
				std::cout << layersNeurons[i] << "  ";
			}
		}
		else
			return;

		float minError = System::Convert::ToSingle(textBox3->Text);
		float maxEpoch = System::Convert::ToSingle(textBox5->Text);
		float lc = System::Convert::ToSingle(textBox8->Text);
		int inputCount = System::Convert::ToInt32(textBox4->Text);

		std::ifstream mnistInputsPath(msclr::interop::marshal_as<std::string>(textBox1->Text), std::ios::binary);
		std::ifstream mnistLabelsPath(msclr::interop::marshal_as<std::string>(textBox2->Text), std::ios::binary);

		std::cout << "\nLearninc C: " << lc << "\n";
		std::cout << "maxEpoch: " << maxEpoch << "\n";
		std::cout << "minError: " << minError << "\n";
		std::cout << "Input Count: " << inputCount << "\n";

		MultiLayerNetwork network(layerCount, layersNeurons, 784, inputCount);
		network.initializeBias();
		network.initializeWeights();
		network.readMnistFiles(mnistInputsPath, mnistLabelsPath);
	
		network.StartLearning(minError, maxEpoch, lc);
		network.saveWeights();
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	int layerCount = System::Convert::ToInt32(textBox14->Text);
	int* layersNeurons = new int[layerCount];
	array<String^>^ parts = textBox13->Text->Split(',');

	std::cout << "Layer Count: " << layerCount << "\n";

	if (parts->Length == layerCount) {
		std::cout << "Layer neurons: ";
		for (int i = 0; i < layerCount; i++)
		{
			layersNeurons[i] = Int32::Parse(parts[i]);
			std::cout << layersNeurons[i] << "  ";
		}
	}
	else
		return;

	float minError = System::Convert::ToSingle(textBox10->Text);
	float maxEpoch = System::Convert::ToSingle(textBox11->Text);
	float lc = System::Convert::ToSingle(textBox12->Text);
	int inputCount = System::Convert::ToInt32(textBox9->Text);

	std::ifstream mnistInputsPath(msclr::interop::marshal_as<std::string>(textBox1->Text), std::ios::binary);
	std::ifstream mnistLabelsPath(msclr::interop::marshal_as<std::string>(textBox2->Text), std::ios::binary);

	std::cout << "\nLearninc C: " << lc << "\n";
	std::cout << "maxEpoch: " << maxEpoch << "\n";
	std::cout << "minError: " << minError << "\n";
	std::cout << "Input Count: " << inputCount << "\n";

	AutoEncoder autoencoder(layerCount, layersNeurons, 784, inputCount);

	autoencoder.initializeBias();
	autoencoder.initializeWeights();
	autoencoder.readMnistFiles(mnistInputsPath, mnistLabelsPath);

	autoencoder.StartEncoding(minError, maxEpoch, lc);
	autoencoder.saveWeights();
}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

	int layerCount = System::Convert::ToInt32(textBox15->Text);
	int* layersNeurons = new int[layerCount];
	array<String^>^ parts = textBox16->Text->Split(',');

	std::cout << "Layer Count: " << layerCount << "\n";

	if (parts->Length == layerCount) {
		std::cout << "Layer neurons: ";
		for (int i = 0; i < layerCount; i++)
		{
			layersNeurons[i] = Int32::Parse(parts[i]);
			std::cout << layersNeurons[i] << "  ";
		}
	}
	else
		return;

	std::ifstream mnistInputsPath(msclr::interop::marshal_as<std::string>(textBox1->Text), std::ios::binary);
	std::ifstream mnistLabelsPath(msclr::interop::marshal_as<std::string>(textBox2->Text), std::ios::binary);


	float minError = System::Convert::ToSingle(textBox19->Text);
	float maxEpoch = System::Convert::ToSingle(textBox18->Text);
	float lc = System::Convert::ToSingle(textBox17->Text);
	int inputCount = System::Convert::ToInt32(textBox20->Text);

	std::ifstream fileEncoder(msclr::interop::marshal_as<std::string>(textBox21->Text));
	System::IO::StreamReader^ sr =
		gcnew System::IO::StreamReader(textBox21->Text);

	String^ line = sr->ReadLine();
	int layerCount_ = System::Convert::ToInt32(line);

	int *LayerNeuronCounts_ = new int[layerCount_];
	for (int i = 0; i < layerCount_; i++) {
		line = sr->ReadLine();
		LayerNeuronCounts_[i] = System::Convert::ToInt32(line);
	}

	AutoEncoder autoencoder(layerCount_, LayerNeuronCounts_, 784, inputCount);

	std::cout << "Encoder weights are loaded.\n";
	autoencoder.loadWeights(fileEncoder);
	autoencoder.readMnistFiles(mnistInputsPath, mnistLabelsPath);

	std::cout << "Encoding inputs.\n";
	autoencoder.normalizedSamples = autoencoder.normalizeInputs();

	int dim = autoencoder.retBottlecklayerNeurons();
	MultiLayerNetwork2 network(layerCount, layersNeurons, dim, inputCount);
	network.giveInputs(autoencoder.normalizedSamples);
	network.initializeBias();
	network.initializeWeights();
	std::cout << "Training started.\n";
	network.StartLearning(0.01f, 10000, 0.01f);
	network.saveWeights();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {

}
};
}
