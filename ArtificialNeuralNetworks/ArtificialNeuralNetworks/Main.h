#pragma once
#include <iostream>  //for debugging
#include "PerpectionLearning.h"
#include "DeltaLearning.h"
#include "SingleLayerNetwork.h"
#include "MultiLayerNetwork.h"

#include "Regression.h"
#include <vector>

namespace ArtificialNeuralNetworks {

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
	private:
		/// UDV User Defined Variables
		float* inputs;
		int addedInputCount = 0;
		int dimension = 2; //X VE Y KORDINAT DUZLEMI, 2 BOYUTLU OLUR
		int classCount = 0; //initial value

		int selectedClass = -1;
		float* weights;
		float* bias;

		//regresyon icin fonksiyonlar
		int* yValues = new int[594];

	private: System::Windows::Forms::PictureBox^ coordinate;
	protected:

	protected:




	private: System::Windows::Forms::Button^ testResults;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::Button^ StartLearningDelta;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::Button^ StartLearningPerpection;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage5;





	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ TestSingleLayer;


	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ Clear;
	private: System::Windows::Forms::Button^ saveInputs;
	private: System::Windows::Forms::Button^ StartRegression;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Button^ loadInputs;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox5;

	private: System::Windows::Forms::Button^ StartLearningSingleLayer;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TabPage^ tabPage4;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::Label^ label25;
	private: System::Windows::Forms::Label^ label26;
	private: System::Windows::Forms::Label^ label27;
private: System::Windows::Forms::Label^ totalcycle;
private: System::Windows::Forms::Label^ trainederror;
private: System::Windows::Forms::Label^ trainingtime;
private: System::Windows::Forms::TabPage^ tabPage3;
private: System::Windows::Forms::Label^ label28;
private: System::Windows::Forms::TextBox^ textBox6;
private: System::Windows::Forms::Button^ button2;


private: System::Windows::Forms::TextBox^ textBox7;
private: System::Windows::Forms::Label^ label29;























	protected:

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
			this->coordinate = (gcnew System::Windows::Forms::PictureBox());
			this->testResults = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->StartLearningDelta = (gcnew System::Windows::Forms::Button());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->StartLearningPerpection = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->StartRegression = (gcnew System::Windows::Forms::Button());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->StartLearningSingleLayer = (gcnew System::Windows::Forms::Button());
			this->TestSingleLayer = (gcnew System::Windows::Forms::Button());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->Clear = (gcnew System::Windows::Forms::Button());
			this->saveInputs = (gcnew System::Windows::Forms::Button());
			this->loadInputs = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->totalcycle = (gcnew System::Windows::Forms::Label());
			this->trainederror = (gcnew System::Windows::Forms::Label());
			this->trainingtime = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->coordinate))->BeginInit();
			this->tabPage2->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage5->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// coordinate
			// 
			this->coordinate->BackColor = System::Drawing::SystemColors::HighlightText;
			this->coordinate->Location = System::Drawing::Point(12, 30);
			this->coordinate->Name = L"coordinate";
			this->coordinate->Size = System::Drawing::Size(594, 459);
			this->coordinate->TabIndex = 0;
			this->coordinate->TabStop = false;
			this->coordinate->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Main::coordinate_Paint);
			this->coordinate->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Main::coordinate_MouseClick);
			// 
			// testResults
			// 
			this->testResults->Location = System::Drawing::Point(15, 70);
			this->testResults->Name = L"testResults";
			this->testResults->Size = System::Drawing::Size(170, 39);
			this->testResults->TabIndex = 4;
			this->testResults->Text = L"Test Results";
			this->testResults->UseVisualStyleBackColor = true;
			this->testResults->Click += gcnew System::EventHandler(this, &Main::testResults_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->label12);
			this->tabPage2->Controls->Add(this->label13);
			this->tabPage2->Controls->Add(this->label14);
			this->tabPage2->Controls->Add(this->label15);
			this->tabPage2->Controls->Add(this->StartLearningDelta);
			this->tabPage2->Controls->Add(this->testResults);
			this->tabPage2->Location = System::Drawing::Point(4, 28);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(578, 137);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Delta Learning";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label12->ForeColor = System::Drawing::Color::Red;
			this->label12->Location = System::Drawing::Point(315, 66);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(28, 20);
			this->label12->TabIndex = 20;
			this->label12->Text = L"no";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9));
			this->label13->Location = System::Drawing::Point(255, 66);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(67, 20);
			this->label13->TabIndex = 19;
			this->label13->Text = L"Usable: ";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label14->ForeColor = System::Drawing::Color::Red;
			this->label14->Location = System::Drawing::Point(309, 34);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(93, 20);
			this->label14->TabIndex = 18;
			this->label14->Text = L"not trained!";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9));
			this->label15->Location = System::Drawing::Point(255, 34);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(59, 20);
			this->label15->TabIndex = 17;
			this->label15->Text = L"Status: ";
			// 
			// StartLearningDelta
			// 
			this->StartLearningDelta->Location = System::Drawing::Point(15, 25);
			this->StartLearningDelta->Name = L"StartLearningDelta";
			this->StartLearningDelta->Size = System::Drawing::Size(170, 39);
			this->StartLearningDelta->TabIndex = 6;
			this->StartLearningDelta->Text = L"Start Learning";
			this->StartLearningDelta->UseVisualStyleBackColor = true;
			this->StartLearningDelta->Click += gcnew System::EventHandler(this, &Main::StartLearningDelta_Click);
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label10);
			this->tabPage1->Controls->Add(this->label11);
			this->tabPage1->Controls->Add(this->label9);
			this->tabPage1->Controls->Add(this->label8);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->StartLearningPerpection);
			this->tabPage1->Location = System::Drawing::Point(4, 28);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(578, 137);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Perpection";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label10->ForeColor = System::Drawing::Color::Red;
			this->label10->Location = System::Drawing::Point(315, 66);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(28, 20);
			this->label10->TabIndex = 16;
			this->label10->Text = L"no";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9));
			this->label11->Location = System::Drawing::Point(255, 66);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(67, 20);
			this->label11->TabIndex = 15;
			this->label11->Text = L"Usable: ";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label9->ForeColor = System::Drawing::Color::Red;
			this->label9->Location = System::Drawing::Point(309, 34);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(93, 20);
			this->label9->TabIndex = 14;
			this->label9->Text = L"not trained!";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9));
			this->label8->Location = System::Drawing::Point(255, 34);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(59, 20);
			this->label8->TabIndex = 6;
			this->label8->Text = L"Status: ";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(15, 70);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(170, 39);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Test Results";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Main::button1_Click);
			// 
			// StartLearningPerpection
			// 
			this->StartLearningPerpection->Location = System::Drawing::Point(15, 25);
			this->StartLearningPerpection->Name = L"StartLearningPerpection";
			this->StartLearningPerpection->Size = System::Drawing::Size(170, 39);
			this->StartLearningPerpection->TabIndex = 2;
			this->StartLearningPerpection->Text = L"Start Learning";
			this->StartLearningPerpection->UseVisualStyleBackColor = true;
			this->StartLearningPerpection->Click += gcnew System::EventHandler(this, &Main::StartLearningPerpection_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage5);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F));
			this->tabControl1->Location = System::Drawing::Point(635, 211);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(586, 169);
			this->tabControl1->TabIndex = 5;
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->label16);
			this->tabPage5->Controls->Add(this->label17);
			this->tabPage5->Controls->Add(this->label18);
			this->tabPage5->Controls->Add(this->label19);
			this->tabPage5->Controls->Add(this->label1);
			this->tabPage5->Controls->Add(this->textBox5);
			this->tabPage5->Controls->Add(this->StartRegression);
			this->tabPage5->Location = System::Drawing::Point(4, 28);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(578, 137);
			this->tabPage5->TabIndex = 2;
			this->tabPage5->Text = L"Regression";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label16->ForeColor = System::Drawing::Color::Red;
			this->label16->Location = System::Drawing::Point(330, 66);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(28, 20);
			this->label16->TabIndex = 24;
			this->label16->Text = L"no";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9));
			this->label17->Location = System::Drawing::Point(270, 66);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(67, 20);
			this->label17->TabIndex = 23;
			this->label17->Text = L"Usable: ";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label18->ForeColor = System::Drawing::Color::Red;
			this->label18->Location = System::Drawing::Point(324, 34);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(113, 20);
			this->label18->TabIndex = 22;
			this->label18->Text = L"not regressed!";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9));
			this->label19->Location = System::Drawing::Point(270, 34);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(59, 20);
			this->label19->TabIndex = 21;
			this->label19->Text = L"Status: ";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label1->Location = System::Drawing::Point(6, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(129, 20);
			this->label1->TabIndex = 17;
			this->label1->Text = L"Hidden Neurons:";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(141, 20);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(78, 24);
			this->textBox5->TabIndex = 16;
			this->textBox5->Text = L"10";
			// 
			// StartRegression
			// 
			this->StartRegression->Location = System::Drawing::Point(10, 65);
			this->StartRegression->Name = L"StartRegression";
			this->StartRegression->Size = System::Drawing::Size(209, 33);
			this->StartRegression->TabIndex = 3;
			this->StartRegression->Text = L"Start Regressing";
			this->StartRegression->UseVisualStyleBackColor = true;
			this->StartRegression->Click += gcnew System::EventHandler(this, &Main::StartRegression_Click);
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->label20);
			this->tabPage4->Controls->Add(this->label21);
			this->tabPage4->Controls->Add(this->label22);
			this->tabPage4->Controls->Add(this->label23);
			this->tabPage4->Controls->Add(this->StartLearningSingleLayer);
			this->tabPage4->Controls->Add(this->TestSingleLayer);
			this->tabPage4->Location = System::Drawing::Point(4, 28);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(578, 137);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Single Layer Network";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label20->ForeColor = System::Drawing::Color::Red;
			this->label20->Location = System::Drawing::Point(315, 66);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(28, 20);
			this->label20->TabIndex = 24;
			this->label20->Text = L"no";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9));
			this->label21->Location = System::Drawing::Point(255, 66);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(67, 20);
			this->label21->TabIndex = 23;
			this->label21->Text = L"Usable: ";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label22->ForeColor = System::Drawing::Color::Red;
			this->label22->Location = System::Drawing::Point(309, 34);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(93, 20);
			this->label22->TabIndex = 22;
			this->label22->Text = L"not trained!";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9));
			this->label23->Location = System::Drawing::Point(255, 34);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(59, 20);
			this->label23->TabIndex = 21;
			this->label23->Text = L"Status: ";
			// 
			// StartLearningSingleLayer
			// 
			this->StartLearningSingleLayer->Location = System::Drawing::Point(15, 25);
			this->StartLearningSingleLayer->Name = L"StartLearningSingleLayer";
			this->StartLearningSingleLayer->Size = System::Drawing::Size(170, 39);
			this->StartLearningSingleLayer->TabIndex = 3;
			this->StartLearningSingleLayer->Text = L"Start Learning";
			this->StartLearningSingleLayer->UseVisualStyleBackColor = true;
			this->StartLearningSingleLayer->Click += gcnew System::EventHandler(this, &Main::StartLearningSingleLayer_Click);
			// 
			// TestSingleLayer
			// 
			this->TestSingleLayer->Location = System::Drawing::Point(15, 70);
			this->TestSingleLayer->Name = L"TestSingleLayer";
			this->TestSingleLayer->Size = System::Drawing::Size(170, 39);
			this->TestSingleLayer->TabIndex = 8;
			this->TestSingleLayer->Text = L"Test Results";
			this->TestSingleLayer->UseVisualStyleBackColor = true;
			this->TestSingleLayer->Click += gcnew System::EventHandler(this, &Main::TestSingleLayer_Click);
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->button2);
			this->tabPage3->Controls->Add(this->textBox7);
			this->tabPage3->Controls->Add(this->label29);
			this->tabPage3->Controls->Add(this->label28);
			this->tabPage3->Controls->Add(this->textBox6);
			this->tabPage3->Location = System::Drawing::Point(4, 28);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(578, 137);
			this->tabPage3->TabIndex = 4;
			this->tabPage3->Text = L"Multi Layer Network";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(429, 6);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(143, 39);
			this->button2->TabIndex = 22;
			this->button2->Text = L"Start Learning";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Main::button2_Click);
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(142, 41);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(102, 24);
			this->textBox7->TabIndex = 19;
			this->textBox7->Text = L"5,2";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label29->Location = System::Drawing::Point(6, 43);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(122, 20);
			this->label29->TabIndex = 18;
			this->label29->Text = L"Neuron Counts:";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label28->Location = System::Drawing::Point(6, 14);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(108, 20);
			this->label28->TabIndex = 17;
			this->label28->Text = L"Layer Counts:";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(142, 10);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(102, 24);
			this->textBox6->TabIndex = 16;
			this->textBox6->Text = L"2";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label6->Location = System::Drawing::Point(8, 71);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(28, 20);
			this->label6->TabIndex = 15;
			this->label6->Text = L"LC";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(113, 71);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(110, 22);
			this->textBox4->TabIndex = 14;
			this->textBox4->Text = L"0,1";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label5->Location = System::Drawing::Point(8, 42);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(92, 20);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Max Epoch";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(113, 42);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(110, 22);
			this->textBox3->TabIndex = 12;
			this->textBox3->Text = L"1000";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label4->Location = System::Drawing::Point(8, 12);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(73, 20);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Min Error";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(113, 12);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(110, 22);
			this->textBox2->TabIndex = 10;
			this->textBox2->Text = L"0,01";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(349, 51);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(110, 24);
			this->comboBox1->TabIndex = 10;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Main::comboBox1_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label3->Location = System::Drawing::Point(244, 51);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(99, 20);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Select Class:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label2->Location = System::Drawing::Point(244, 12);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(99, 20);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Class Count:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(349, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(110, 22);
			this->textBox1->TabIndex = 8;
			this->textBox1->Text = L"0";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Main::textBox1_TextChanged);
			// 
			// Clear
			// 
			this->Clear->Location = System::Drawing::Point(508, 495);
			this->Clear->Name = L"Clear";
			this->Clear->Size = System::Drawing::Size(98, 42);
			this->Clear->TabIndex = 9;
			this->Clear->Text = L"Clear";
			this->Clear->UseVisualStyleBackColor = true;
			this->Clear->Click += gcnew System::EventHandler(this, &Main::Clear_Click);
			// 
			// saveInputs
			// 
			this->saveInputs->Location = System::Drawing::Point(12, 495);
			this->saveInputs->Name = L"saveInputs";
			this->saveInputs->Size = System::Drawing::Size(75, 40);
			this->saveInputs->TabIndex = 10;
			this->saveInputs->Text = L"Save Inputs";
			this->saveInputs->UseVisualStyleBackColor = true;
			this->saveInputs->Click += gcnew System::EventHandler(this, &Main::saveInputs_Click);
			// 
			// loadInputs
			// 
			this->loadInputs->Location = System::Drawing::Point(93, 495);
			this->loadInputs->Name = L"loadInputs";
			this->loadInputs->Size = System::Drawing::Size(75, 40);
			this->loadInputs->TabIndex = 16;
			this->loadInputs->Text = L"Load Inputs";
			this->loadInputs->UseVisualStyleBackColor = true;
			this->loadInputs->Click += gcnew System::EventHandler(this, &Main::loadInputs_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->comboBox1);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->textBox3);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->textBox4);
			this->panel1->Location = System::Drawing::Point(635, 55);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(472, 134);
			this->panel1->TabIndex = 17;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label7->Location = System::Drawing::Point(631, 30);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(152, 22);
			this->label7->TabIndex = 18;
			this->label7->Text = L"Set Parameters:";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label24->Location = System::Drawing::Point(631, 398);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(83, 22);
			this->label24->TabIndex = 19;
			this->label24->Text = L"Output:";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label25->Location = System::Drawing::Point(631, 437);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(108, 21);
			this->label25->TabIndex = 20;
			this->label25->Text = L"Total Cycle:";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label26->Location = System::Drawing::Point(631, 470);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(116, 21);
			this->label26->TabIndex = 21;
			this->label26->Text = L"Trained Error:";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label27->Location = System::Drawing::Point(631, 504);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(119, 21);
			this->label27->TabIndex = 22;
			this->label27->Text = L"Training Time:";
			// 
			// totalcycle
			// 
			this->totalcycle->AutoSize = true;
			this->totalcycle->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->totalcycle->Location = System::Drawing::Point(735, 437);
			this->totalcycle->Name = L"totalcycle";
			this->totalcycle->Size = System::Drawing::Size(19, 21);
			this->totalcycle->TabIndex = 23;
			this->totalcycle->Text = L"0";
			// 
			// trainederror
			// 
			this->trainederror->AutoSize = true;
			this->trainederror->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->trainederror->Location = System::Drawing::Point(744, 470);
			this->trainederror->Name = L"trainederror";
			this->trainederror->Size = System::Drawing::Size(19, 21);
			this->trainederror->TabIndex = 24;
			this->trainederror->Text = L"0";
			// 
			// trainingtime
			// 
			this->trainingtime->AutoSize = true;
			this->trainingtime->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->trainingtime->Location = System::Drawing::Point(746, 504);
			this->trainingtime->Name = L"trainingtime";
			this->trainingtime->Size = System::Drawing::Size(19, 21);
			this->trainingtime->TabIndex = 25;
			this->trainingtime->Text = L"0";
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(1250, 547);
			this->Controls->Add(this->trainingtime);
			this->Controls->Add(this->trainederror);
			this->Controls->Add(this->totalcycle);
			this->Controls->Add(this->label27);
			this->Controls->Add(this->label26);
			this->Controls->Add(this->label25);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->loadInputs);
			this->Controls->Add(this->saveInputs);
			this->Controls->Add(this->Clear);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->coordinate);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Main";
			this->ShowIcon = false;
			this->Text = L"Artificial Neural Networks";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->coordinate))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage5->ResumeLayout(false);
			this->tabPage5->PerformLayout();
			this->tabPage4->ResumeLayout(false);
			this->tabPage4->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void draw_sample(int temp_x, int temp_y, int label) {
			Pen^ pen;
			switch (label) { //ilgili label'e gore renk ayarlar.
			case 0: pen = gcnew Pen(Color::Black, 3.0f); break;
			case 1: pen = gcnew Pen(Color::Red, 3.0f); break;
			case 2: pen = gcnew Pen(Color::Blue, 3.0f); break;
			case 3: pen = gcnew Pen(Color::Green, 3.0f); break;
			case 4: pen = gcnew Pen(Color::Yellow, 3.0f); break;
			case 5: pen = gcnew Pen(Color::Orange, 3.0f); break;
			default: pen = gcnew Pen(Color::YellowGreen, 3.0f);
			}
			coordinate->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
			coordinate->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
		}

		float* addInput(float* inputs, int x, int y, int label) {
			float* temp;
			temp = new float[(addedInputCount+1) * (dimension+1)]; 

			//copy all inputs to temp.
			for (int i = 0; i < addedInputCount; i++)
				for(int d = 0; d < dimension+1; d++)
				temp[i + d*(addedInputCount+1)] = inputs[i + d * (addedInputCount)];  
			
				temp[(addedInputCount) + 0 * (addedInputCount + 1)] = x;
				temp[(addedInputCount) + 1 * (addedInputCount + 1)] = y;
				temp[(addedInputCount) + 2 * (addedInputCount + 1)] = label;
				//    sutundaki input indeksi        satirdaki dimension indeks

			delete[] inputs;
			return temp;
		}

		int *createLayer(int layerC)
		{
			int* layers = new int[layerC];
			return layers;
		}
		void addLayer(int* layer, int neuronCount,int ind)
		{
			layer[ind] = neuronCount;
		}


	private: System::Void coordinate_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		
		if (selectedClass == -1)
		{
			return;
		}
		int temp_x = (System::Convert::ToInt32(e->X));
		int temp_y = (System::Convert::ToInt32(e->Y));

		draw_sample(temp_x, temp_y, selectedClass);

		temp_x = temp_x - (coordinate->Width / 2);
		temp_y = coordinate->Height / 2 - temp_y;
		inputs = addInput(inputs, temp_x, temp_y, selectedClass);
		addedInputCount++;

	}
	private: System::Void coordinate_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Pen^ pen = gcnew Pen(Color::Black, 3.0f);
		int center_width, center_height;
		center_width = (int)(coordinate->Width / 2);
		center_height = (int)(coordinate->Height / 2);
		e->Graphics->DrawLine(pen, center_width, 0, center_width, coordinate->Height);
		e->Graphics->DrawLine(pen, 0, center_height, coordinate->Width, center_height);
	}
	
    private: System::Void StartLearningPerpection_Click(System::Object^ sender, System::EventArgs^ e) {

		PERPECTION_Neuron neuron(dimension, addedInputCount, 0.1f);
		neuron.giveInputs(inputs);
		neuron.initializeWeights();
		neuron.printInputs();
		neuron.printWeights();
		float cycle = neuron.startLearning();
		std::cout << "Finished in: " << cycle << " cycle!\n";
		neuron.printWeights();

		weights = neuron.returnWeights();
		bias = neuron.returnBias();

}

private: System::Void testResults_Click(System::Object^ sender, System::EventArgs^ e) {

	Bitmap^ surface = gcnew Bitmap(coordinate->Width, coordinate->Height);
	Graphics^ g = Graphics::FromImage(surface);
	// merkez
	int cx = surface->Width / 2;
	int cy = surface->Height / 2;
	// eksen çiz
	Pen^ axis = gcnew Pen(Color::Black, 2.0f);
	g->DrawLine(axis, cx, 0, cx, surface->Height);
	g->DrawLine(axis, 0, cy, surface->Width, cy);
	//inputlari cizdiririz
	for (int inputInd = 0; inputInd < addedInputCount; inputInd++)
	{
		int label = inputs[inputInd + dimension * addedInputCount];
		Pen^ pen;
		switch (label) { //ilgili label'e gore renk ayarlar.
		case 0: pen = gcnew Pen(Color::Black, 3.0f); break;
		case 1: pen = gcnew Pen(Color::Red, 3.0f); break;
		case 2: pen = gcnew Pen(Color::Blue, 3.0f); break;
		case 3: pen = gcnew Pen(Color::Green, 3.0f); break;
		case 4: pen = gcnew Pen(Color::Yellow, 3.0f); break;
		case 5: pen = gcnew Pen(Color::Orange, 3.0f); break;
		default: pen = gcnew Pen(Color::YellowGreen, 3.0f);
		}

		int temp_x = inputs[inputInd + 0 * addedInputCount] + (coordinate->Width / 2);
		int temp_y = -(inputs[inputInd + 1 * addedInputCount]) + coordinate->Height / 2;

		g->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
		g->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
	}

	//DOGRULARI CIZ
	float x = weights[0];
	float y = weights[1];
	float c = bias[0];
	// w0 * x + w1 * y + b = 0

	x = -x / y;
	c = -c / y;
	//y = x + c
	std::cout << "y = " << x << "x + " << c << "\n";


	float slope = x;
	float intercept = c;

	float X1 = -cx;
	float X2 = cx;

	float Y1 = slope * X1 + intercept;
	float Y2 = slope * X2 + intercept;

	int sx1 = cx + X1;
	int sy1 = cy - Y1;

	int sx2 = cx + X2;
	int sy2 = cy - Y2;

	Pen^ linePen = gcnew Pen(Color::Red, 2.0f);
	g->DrawLine(linePen, sx1, sy1, sx2, sy2);



	coordinate->Image = surface;

}

private: System::Void StartLearningDelta_Click(System::Object^ sender, System::EventArgs^ e) {
	DeltaLearning_Neuron neuron(dimension, addedInputCount, 0.1f);
	neuron.giveInputs(inputs);
	neuron.initializeWeights();
	neuron.printInputs();
	neuron.printWeights();
	float cycle = neuron.startLearning();
	std::cout << "Finished in: " << cycle << " cycle!\n";
	neuron.printWeights();

	weights = neuron.returnWeights();
	bias = neuron.returnBias();


}

private: System::Void StartLearningSingleLayer_Click(System::Object^ sender, System::EventArgs^ e) {

	float minError = System::Convert::ToSingle(textBox2->Text);
	float maxEpoch = System::Convert::ToSingle(textBox3->Text);
	float lc = System::Convert::ToSingle(textBox4->Text);
	std::cout << "Learninc C: " << lc << "\n";
	std::cout << "maxEpoch: " << maxEpoch << "\n";
	std::cout << "minError: " << minError << "\n";

	SingleLayerNetwork network(dimension, addedInputCount, classCount);
	network.giveInputs(inputs);
	network.initializeWeights();
	network.initializeBias();
	network.printInputs();
	network.printWeights();

	info inf = network.StartLearning(minError, maxEpoch);
	trainederror->Text = inf.error.ToString();;
	totalcycle->Text = inf.cycle.ToString();;

	network.printWeights();

	weights = network.returnWeights();
	bias = network.returnBias();

}
private: System::Void TestSingleLayer_Click(System::Object^ sender, System::EventArgs^ e) {

	Bitmap^ surface = gcnew Bitmap(coordinate->Width, coordinate->Height);
	Graphics^ g = Graphics::FromImage(surface);
	// merkez
	int cx = surface->Width / 2;
	int cy = surface->Height / 2;
	// eksen çiz
	Pen^ axis = gcnew Pen(Color::Black, 2.0f);
	g->DrawLine(axis, cx, 0, cx, surface->Height);
	g->DrawLine(axis, 0, cy, surface->Width, cy);
	//inputlari cizdiririz
	for (int inputInd = 0; inputInd < addedInputCount; inputInd++)
	{
		int label = inputs[inputInd + dimension * addedInputCount];
		Pen^ pen;
		switch (label) { //ilgili label'e gore renk ayarlar.
		case 0: pen = gcnew Pen(Color::Black, 3.0f); break;
		case 1: pen = gcnew Pen(Color::Red, 3.0f); break;
		case 2: pen = gcnew Pen(Color::Blue, 3.0f); break;
		case 3: pen = gcnew Pen(Color::Green, 3.0f); break;
		case 4: pen = gcnew Pen(Color::Yellow, 3.0f); break;
		case 5: pen = gcnew Pen(Color::Orange, 3.0f); break;
		default: pen = gcnew Pen(Color::YellowGreen, 3.0f);
		}

		int temp_x = inputs[inputInd + 0 * addedInputCount] + (coordinate->Width / 2);
		int temp_y = -(inputs[inputInd + 1 * addedInputCount]) + coordinate->Height / 2;

		g->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
		g->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
	}

	for (int neuronInd = 0; neuronInd < classCount; neuronInd++)
	{
		//DOGRULARI CIZ  (dimension = 2'ye gore ayarlandi..)
		float x = weights[neuronInd + 0 * classCount];
		float y = weights[neuronInd + 1 * classCount];

		float c = bias[neuronInd];
		// w0 * x + w1 * y + b = 0

		x = -x / y;
		c = -c / y;
		//y = x + c
		std::cout << "Neuron: " << neuronInd << ":  y = " << x << "x + " << c << "\n";
		

		float slope = x;
		float intercept = c;

		float X1 = -cx;
		float X2 = cx;

		float Y1 = slope * X1 + intercept;
		float Y2 = slope * X2 + intercept;

		int sx1 = cx + X1;
		int sy1 = cy - Y1;

		int sx2 = cx + X2;
		int sy2 = cy - Y2;

		Pen^ linePen;
		switch (neuronInd) { 
		case 0: linePen = gcnew Pen(Color::Black, 3.0f); break;
		case 1: linePen = gcnew Pen(Color::Red, 3.0f); break;
		case 2: linePen = gcnew Pen(Color::Blue, 3.0f); break;
		case 3: linePen = gcnew Pen(Color::Green, 3.0f); break;
		case 4: linePen = gcnew Pen(Color::Yellow, 3.0f); break;
		case 5: linePen = gcnew Pen(Color::Orange, 3.0f); break;
		default: linePen = gcnew Pen(Color::YellowGreen, 3.0f);
		}
		g->DrawLine(linePen, sx1, sy1, sx2, sy2);
	}


	coordinate->Image = surface;
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	int classC = System::Convert::ToInt32(textBox1->Text);
	classCount = classC;

	switch (classC)
	{
	case 0:
		label10->Text = "no";
		label12->Text = "no";
		label16->Text = "no";
		label20->Text = "no";
		break;
	case 1:
		label16->Text = "yes";

		label10->Text = "no";
		label12->Text = "no";
		label20->Text = "no";
		break;
	case 2:
		label10->Text = "yes";
		label12->Text = "yes";
		label20->Text = "yes";
		label16->Text = "no";
		break;
	case 3:
		label10->Text = "no";
		label12->Text = "no";
		label16->Text = "no";
		label20->Text = "yes";
		break;
	}



	comboBox1->Items->Clear();

	for (int i = 0; i < classCount; i++)
		comboBox1->Items->Add("Class " + i);

	comboBox1->SelectedIndex = 0;

}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	selectedClass = comboBox1->SelectedIndex;
}
private: System::Void Clear_Click(System::Object^ sender, System::EventArgs^ e) {
	delete[] weights;
	delete[] bias;
	delete[] inputs;

	weights = nullptr;
	bias = nullptr;
	inputs = nullptr;

	addedInputCount = 0;
	coordinate->Image = nullptr;
	coordinate->Refresh();
}
private: System::Void saveInputs_Click(System::Object^ sender, System::EventArgs^ e) {
	SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();

	saveFileDialog->Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
	saveFileDialog->Title = "Save inputs.";

	if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if (addedInputCount != 0) {
			System::IO::StreamWriter^ writer = gcnew System::IO::StreamWriter(saveFileDialog->FileName);

			for (int inputInd = 0; inputInd < addedInputCount; inputInd++)
			{
				writer->WriteLine(inputs[inputInd + 0 * addedInputCount] + " " + inputs[inputInd + 1 * addedInputCount] +
					" " + inputs[inputInd + 2 * addedInputCount]);
			}
			writer->Close();
		}
	}
}
private: System::Void StartRegression_Click(System::Object^ sender, System::EventArgs^ e) {

	float minError = System::Convert::ToSingle(textBox2->Text);
	float maxEpoch = System::Convert::ToSingle(textBox3->Text);
	float lc = System::Convert::ToSingle(textBox4->Text);
	int hiddenNeuronCount = System::Convert::ToInt32(textBox5->Text);

	Regression network(addedInputCount, hiddenNeuronCount, lc, lc);
	network.initializeBias();
	network.initializeWeights();
	network.giveInputs(inputs);
	info inf = network.StartLearning(minError, maxEpoch);
	trainederror->Text = inf.error.ToString();;
	totalcycle->Text = inf.cycle.ToString();;
	network.denormalizeWeights();

	Bitmap^ surface = gcnew Bitmap(coordinate->Width, coordinate->Height);
	Graphics^ g = Graphics::FromImage(surface);

	//inputlari cizdiririz
	for (int inputInd = 0; inputInd < addedInputCount; inputInd++)
	{
		int label = inputs[inputInd + dimension * addedInputCount];

		Pen^ pen;
		switch (label) { //ilgili label'e gore renk ayarlar.
		case 0: pen = gcnew Pen(Color::Black, 3.0f); break;
		case 1: pen = gcnew Pen(Color::Red, 3.0f); break;
		case 2: pen = gcnew Pen(Color::Blue, 3.0f); break;
		case 3: pen = gcnew Pen(Color::Green, 3.0f); break;
		case 4: pen = gcnew Pen(Color::Yellow, 3.0f); break;
		case 5: pen = gcnew Pen(Color::Orange, 3.0f); break;
		default: pen = gcnew Pen(Color::YellowGreen, 3.0f);
		}


		float temp_x = inputs[inputInd + 0 * addedInputCount] + (coordinate->Width / 2);
		float temp_y = -(inputs[inputInd + 1 * addedInputCount]) + coordinate->Height / 2;


		g->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
		g->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
	}


	Pen^ pen = gcnew Pen(Color::Red, 3.0f);
	for (int x = -coordinate->Width / 2 + 5; x < coordinate->Width / 2 - 2; x++)
	{
		int xValue = x + (coordinate->Width / 2);
		int yValue = -network.predict(x) + (coordinate->Height / 2);
		g->DrawLine(pen, xValue - 1, yValue, xValue + 1, yValue);
	}

	coordinate->Image = surface;
}
private: System::Void loadInputs_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenFileDialog^ o = gcnew OpenFileDialog();
	o->Filter = "Metin Dosyası (*.txt)|*.txt";

	if (o->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(o->FileName);

		String^ line;
		while ((line = sr->ReadLine()) != nullptr) {

			// satırı boşluklardan ayır
			array<String^>^ parts = line->Split(' ');

			if (parts->Length == 3) {
				float x = Int32::Parse(parts[0]);
				float y = Int32::Parse(parts[1]);
				int label = Int32::Parse(parts[2]);

				inputs = addInput(inputs, x, y, label);
				addedInputCount++;
			}
		}
		sr->Close();


		Bitmap^ surface = gcnew Bitmap(coordinate->Width, coordinate->Height);
		Graphics^ g = Graphics::FromImage(surface);
		// merkez
		int cx = surface->Width / 2;
		int cy = surface->Height / 2;
		// eksen çiz
		Pen^ axis = gcnew Pen(Color::Black, 2.0f);
		g->DrawLine(axis, cx, 0, cx, surface->Height);
		g->DrawLine(axis, 0, cy, surface->Width, cy);
		//inputlari cizdiririz
		for (int inputInd = 0; inputInd < addedInputCount; inputInd++)
		{
			int label = inputs[inputInd + dimension * addedInputCount];
			Pen^ pen;
			switch (label) { //ilgili label'e gore renk ayarlar.
			case 0: pen = gcnew Pen(Color::Black, 3.0f); break;
			case 1: pen = gcnew Pen(Color::Red, 3.0f); break;
			case 2: pen = gcnew Pen(Color::Blue, 3.0f); break;
			case 3: pen = gcnew Pen(Color::Green, 3.0f); break;
			case 4: pen = gcnew Pen(Color::Yellow, 3.0f); break;
			case 5: pen = gcnew Pen(Color::Orange, 3.0f); break;
			default: pen = gcnew Pen(Color::YellowGreen, 3.0f);
			}

			int temp_x = inputs[inputInd + 0 * addedInputCount] + (coordinate->Width / 2);
			int temp_y = -(inputs[inputInd + 1 * addedInputCount]) + coordinate->Height / 2;

			g->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
			g->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
		}
		coordinate->Image = surface;
	}
}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	testResults_Click(button1, nullptr);
}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {


	int layerCount = System::Convert::ToInt32(textBox6->Text);
	int* layers = createLayer(layerCount);

	array<String^>^ parts = textBox7->Text->Split(',');

	if (parts->Length == layerCount) {
		for (int i = 0; i < layerCount; i++)
		{
			layers[i] = Int32::Parse(parts[i]);
		}
	}
	else
		return;

	float minError = System::Convert::ToSingle(textBox2->Text);
	float maxEpoch = System::Convert::ToSingle(textBox3->Text);
	float lc = System::Convert::ToSingle(textBox4->Text);
	std::cout << "Learninc C: " << lc << "\n";
	std::cout << "maxEpoch: " << maxEpoch << "\n";
	std::cout << "minError: " << minError << "\n";

	MultiLayerNetwork network(layerCount, layers, 2, addedInputCount);
	network.giveInputs(inputs);
	network.printInputs();
	network.showStatus();
	network.initializeBias();
	network.initializeWeights();

	info inf = network.StartLearning(minError, maxEpoch, lc);
	trainederror->Text = inf.error.ToString();;
	totalcycle->Text = inf.cycle.ToString();;


}
};
}
