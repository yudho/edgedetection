/*---------------------------------------*/
/*Copyright © 2012 Yudho Ahmad Diponegoro*/
/*---------------------------------------*/
#include "stdafx.h"
#include <string>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <math.h>
#include <cmath>

#pragma once

namespace My4208 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Drawing::Imaging;
	using namespace System::Runtime::InteropServices;
	using namespace System::Globalization;
	int dataArray_2d[600][600];
	int dataArray_2d_copy[600][600];
	float g_mask[600][600];
	int i_x[600][600];
	int i_y[600][600];
	int sobel_mask_x[600][600];
	int sobel_mask_y[600][600];
	int i_mag[600][600];
	int i_edge[600][600];
	int i_edge_1[600][600];
	int edge_threshold=100;
	int edge_log_threshold=18;
	int edge_direction_threshold=0;
	int edge_index_i[270000];
	int edge_index_j[270000];
	int sd=1;
	int LoG[3][3];
	int log_edge[600][600];
	int log_mag[600][600];
	int columns_1=256;
	int rows_1=256;
	int dataArray[250000];
	int dataArray_1[750000];
	int dataArray_result[250000];
	int dataArray_result_1[750000];
	int log_edge_1[600][600];
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{			
			InitializeComponent();			
		}

	protected:		
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::Button^  button14;
	private: System::Windows::Forms::Button^  button15;
	private: System::Windows::Forms::Button^  button16;
	private: System::Windows::Forms::Button^  button17;
	private: System::Windows::Forms::Button^  button18;
	private: System::Windows::Forms::Button^  button19;
	private: System::Windows::Forms::Button^  button20;
	private: System::Windows::Forms::Button^  button21;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label10;
	private:		
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->label1->Location = System::Drawing::Point(17, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(104, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Standard Deviation :";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(127, 6);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(78, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->Leave += gcnew System::EventHandler(this, &Form1::textBox1_Leave);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(533, 83);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(85, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"choose file";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(535, 137);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(40, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"SD = 1";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 83);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(256, 256);
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(637, 83);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(256, 256);
			this->pictureBox2->TabIndex = 9;
			this->pictureBox2->TabStop = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(229, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(88, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Edge Threshold :";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(323, 6);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(70, 20);
			this->textBox2->TabIndex = 11;
			this->textBox2->Leave += gcnew System::EventHandler(this, &Form1::textBox2_Leave);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(618, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(160, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Orthogonal Direction Threshold :";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(784, 6);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(62, 20);
			this->textBox3->TabIndex = 13;
			this->textBox3->Leave += gcnew System::EventHandler(this, &Form1::textBox3_Leave);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(535, 177);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(74, 13);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Mask Size = 5";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(535, 213);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(84, 13);
			this->label6->TabIndex = 15;
			this->label6->Text = L"Threshold = 100";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(535, 275);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(86, 13);
			this->label7->TabIndex = 16;
			this->label7->Text = L"Direction Thr = 0";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(376, 593);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(335, 13);
			this->label8->TabIndex = 17;
			this->label8->Text = L"Developed by Yudho Ahmad D., Sylvester Albert S.,Yosmar, Elisa";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(157, 35);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(27, 21);
			this->button1->TabIndex = 18;
			this->button1->Text = L"Ix";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(190, 35);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(25, 21);
			this->button3->TabIndex = 19;
			this->button3->Text = L"Iy";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(222, 35);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(46, 21);
			this->button4->TabIndex = 20;
			this->button4->Text = L"mag";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(12, 35);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(48, 21);
			this->button5->TabIndex = 21;
			this->button5->Text = L"source";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(66, 35);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(85, 21);
			this->button6->TabIndex = 22;
			this->button6->Text = L"after gaussian";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(12, 56);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(48, 21);
			this->button7->TabIndex = 23;
			this->button7->Text = L"edge";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(66, 56);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(85, 21);
			this->button9->TabIndex = 25;
			this->button9->Text = L"non-max supp";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(157, 56);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(39, 21);
			this->button10->TabIndex = 26;
			this->button10->Text = L"LoG";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &Form1::button10_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(202, 56);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(66, 21);
			this->button11->TabIndex = 27;
			this->button11->Text = L"LoG supp";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &Form1::button11_Click);
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(637, 35);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(51, 21);
			this->button13->TabIndex = 29;
			this->button13->Text = L"source";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &Form1::button13_Click);
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(694, 35);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(84, 21);
			this->button14->TabIndex = 30;
			this->button14->Text = L"after gaussian";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &Form1::button14_Click);
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(637, 56);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(51, 21);
			this->button15->TabIndex = 31;
			this->button15->Text = L"edge";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &Form1::button15_Click);
			// 
			// button16
			// 
			this->button16->Location = System::Drawing::Point(811, 35);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(28, 21);
			this->button16->TabIndex = 32;
			this->button16->Text = L"Iy";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &Form1::button16_Click);
			// 
			// button17
			// 
			this->button17->Location = System::Drawing::Point(694, 56);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(84, 21);
			this->button17->TabIndex = 33;
			this->button17->Text = L"non-max supp";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &Form1::button17_Click);
			// 
			// button18
			// 
			this->button18->Location = System::Drawing::Point(784, 56);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(39, 21);
			this->button18->TabIndex = 34;
			this->button18->Text = L"LoG";
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Click += gcnew System::EventHandler(this, &Form1::button18_Click);
			// 
			// button19
			// 
			this->button19->Location = System::Drawing::Point(845, 35);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(48, 21);
			this->button19->TabIndex = 35;
			this->button19->Text = L"mag";
			this->button19->UseVisualStyleBackColor = true;
			this->button19->Click += gcnew System::EventHandler(this, &Form1::button19_Click);
			// 
			// button20
			// 
			this->button20->Location = System::Drawing::Point(784, 35);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(25, 21);
			this->button20->TabIndex = 36;
			this->button20->Text = L"Ix";
			this->button20->UseVisualStyleBackColor = true;
			this->button20->Click += gcnew System::EventHandler(this, &Form1::button20_Click);
			// 
			// button21
			// 
			this->button21->Location = System::Drawing::Point(829, 56);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(64, 21);
			this->button21->TabIndex = 37;
			this->button21->Text = L"LoG supp";
			this->button21->UseVisualStyleBackColor = true;
			this->button21->Click += gcnew System::EventHandler(this, &Form1::button21_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(423, 9);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(83, 13);
			this->label9->TabIndex = 38;
			this->label9->Text = L"LoG Threshold :";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(512, 6);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(77, 20);
			this->textBox4->TabIndex = 39;
			this->textBox4->Leave += gcnew System::EventHandler(this, &Form1::textBox4_Leave);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(535, 246);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(101, 13);
			this->label10->TabIndex = 40;
			this->label10->Text = L"LoG Threshold = 18";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1205, 615);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->button21);
			this->Controls->Add(this->button20);
			this->Controls->Add(this->button19);
			this->Controls->Add(this->button18);
			this->Controls->Add(this->button17);
			this->Controls->Add(this->button16);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form1";
			this->Text = L"iSegment_EE4208";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {	
			 if(openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {				
								/*load the data from file, extract its information*/
								int rows;
								int columns;
								int intensity;															
								 String^ fileName =  openFileDialog1->FileName;
								 System::String^ str="";								  
								   array<Int32>^result = gcnew array<Int32>(3);
								   array<Int32>^binary = gcnew array<Int32>(16);		   
								   FileStream^ fileStream = gcnew FileStream( fileName,FileMode::Open );
								   try
								   {
									  fileStream->Seek( 0, SeekOrigin::Begin );									  
									  for ( int i = 0; i < fileStream->Length; i++ )
									  {										  
										dataArray[i] = fileStream->ReadByte();							
									  }
								   }
								   finally
								   {
									  fileStream->Close();
									  /*convert it to .bmp (bitmap) format for display purpose*/
									  rows=dataArray[0];
									  int j;
									  int multiplier=1;									 
									  for(j=15;j>=8;j--){
										  binary[j]=rows%2;
											rows=rows/2;											
										}										
									rows=dataArray[1];
									for(j=7;j>=0;j--){
											binary[j]=rows%2;
											rows=rows/2;											
										}										
										rows=0;
										multiplier=1;
									for(int u=15;u>=0;u--){
										rows=rows+multiplier*binary[u];
										multiplier=multiplier*2;										
									}									
									columns=dataArray[2];
									for(j=15;j>=8;j--){
											binary[j]=columns%2;
											columns=columns/2;											
										}										
									columns=dataArray[3];
									for(j=7;j>=0;j--){
											binary[j]=columns%2;
											columns=columns/2;											
										}										
										columns=0;
										multiplier=1;
									for(int u=15;u>=0;u--){
										columns=columns+multiplier*binary[u];
										multiplier=multiplier*2;										
									}								
									intensity=dataArray[4];
									for(j=7;j>=0;j--){
											binary[j]=intensity%2;
											intensity=intensity/2;											
										}										
										intensity=0;
										multiplier=1;
									for(int u=7;u>=0;u--){
										intensity=intensity+multiplier*binary[u];
										multiplier=multiplier*2;
									}
									rows_1=rows;
									columns_1=columns;
									result[0]=rows;
									result[1]=columns;
									result[2]=intensity;									
									int file_size=(rows_1*columns_1)*3+54+1;
									int bin[32];
									int a=0;int b=0;int c=0;int d=0;
									 for(j=31;j>=0;j--){
										  bin[j]=file_size%2;
											file_size=file_size/2;											
										}										 
									multiplier=1;
									for(int u=31;u>=24;u--){
										a=a+multiplier*bin[u];
										multiplier=multiplier*2;
									}
									multiplier=1;
									for(int u=23;u>=16;u--){
										b=b+multiplier*bin[u];
										multiplier=multiplier*2;
									}
									multiplier=1;
									for(int u=15;u>=8;u--){
										c=c+multiplier*bin[u];
										multiplier=multiplier*2;
									}
									multiplier=1;
									for(int u=7;u>=0;u--){
										d=d+multiplier*bin[u];
										multiplier=multiplier*2;
									}									
									int raw_size=(rows_1*columns_1)*3+1;
									int bi[32];
									int f=0;int g=0;int h=0;int v=0;
									 for(j=31;j>=0;j--){
										  bi[j]=raw_size%2;
											raw_size=raw_size/2;											
										}										 
									multiplier=1;
									for(int u=31;u>=24;u--){
										f=f+multiplier*bi[u];
										multiplier=multiplier*2;
									}
									multiplier=1;
									for(int u=23;u>=16;u--){
										g=g+multiplier*bi[u];
										multiplier=multiplier*2;
									}
									multiplier=1;
									for(int u=15;u>=8;u--){
										h=h+multiplier*bi[u];
										multiplier=multiplier*2;
									}
									multiplier=1;
									for(int u=7;u>=0;u--){
										v=v+multiplier*bi[u];
										multiplier=multiplier*2;
									}
									dataArray_1[0]=66;
									dataArray_1[1]=77;
									dataArray_1[2]=a;dataArray_1[3]=b;dataArray_1[4]=c;dataArray_1[5]=d;
									dataArray_1[6]=0;dataArray_1[7]=0;dataArray_1[8]=0;dataArray_1[9]=0;
									dataArray_1[10]=54;dataArray_1[11]=0;dataArray_1[12]=0;dataArray_1[13]=0;
									dataArray_1[14]=40;dataArray_1[15]=0;dataArray_1[16]=0;dataArray_1[17]=0;
									dataArray_1[18]=dataArray[0];dataArray_1[19]=dataArray[1];dataArray_1[20]=0;dataArray_1[21]=0;
									dataArray_1[22]=dataArray[2];dataArray_1[23]=dataArray[3];dataArray_1[24]=0;dataArray_1[25]=0;
									dataArray_1[26]=1;dataArray_1[27]=0;dataArray_1[28]=24;dataArray_1[29]=0;
									dataArray_1[30]=0;dataArray_1[31]=0;dataArray_1[32]=0;dataArray_1[33]=0;
									dataArray_1[34]=f;dataArray_1[35]=g;dataArray_1[36]=h;dataArray_1[37]=v;
									dataArray_1[38]=19;dataArray_1[39]=11;dataArray_1[40]=0;dataArray_1[41]=0;
									dataArray_1[42]=19;dataArray_1[43]=11;dataArray_1[44]=0;dataArray_1[45]=0;
									dataArray_1[46]=0;dataArray_1[47]=0;dataArray_1[48]=0;dataArray_1[49]=0;
									dataArray_1[50]=0;dataArray_1[51]=0;dataArray_1[52]=0;dataArray_1[53]=0;
									for(int i=54;i<=250000;i++){
										int w=(i-54)*3;
										dataArray_1[w+54]=dataArray[i-49];
										dataArray_1[w+55]=dataArray[i-49];
										dataArray_1[w+56]=dataArray[i-49];																
									}
									 String^ bmp_name=openFileDialog1->FileName;
									 bmp_name=bmp_name->Replace(".raw","_temp.bmp");
									  FileStream^ fileStream_1 = gcnew FileStream(bmp_name,FileMode::Create );
									 if((rows_1==487)){							
									 int total=rows_1*columns_1*3+55+1461;
									 dataArray_1[18]=dataArray[0]+1;dataArray_1[19]=dataArray[1];dataArray_1[20]=0;dataArray_1[21]=0;
									dataArray_1[22]=dataArray[2];dataArray_1[23]=dataArray[3];dataArray_1[24]=0;dataArray_1[25]=0;
									for ( int i = 0; i <= 53; i++ )
									  {
										 fileStream_1->WriteByte( dataArray_1[i] );
									  }
									int t=1;
									 for ( int i = total; i >=54; i-- )
									  {										  
										  if((t%1461)==0){ fileStream_1->WriteByte(0);fileStream_1->WriteByte(0);fileStream_1->WriteByte(0);t=0;}
										 fileStream_1->WriteByte( dataArray_1[i] );
										 t++;
									 }
									 }else{ if((rows_1==190)){								
									int total=rows_1*columns_1*3+55+1140;
									 dataArray_1[18]=dataArray[0]+2;dataArray_1[19]=dataArray[1];dataArray_1[20]=0;dataArray_1[21]=0;
									dataArray_1[22]=dataArray[2];dataArray_1[23]=dataArray[3];dataArray_1[24]=0;dataArray_1[25]=0;
									for ( int i = 0; i <= 53; i++ )
									  {
										 fileStream_1->WriteByte( dataArray_1[i] );
									  }
									int t=1;
									 for ( int i = total; i >=54; i-- )
									  {
										   if((t%570)==0){ fileStream_1->WriteByte(255);fileStream_1->WriteByte(255);fileStream_1->WriteByte(255);
										   fileStream_1->WriteByte(255);fileStream_1->WriteByte(255);fileStream_1->WriteByte(255);t=0;}
										 fileStream_1->WriteByte( dataArray_1[i] );
										 t++;
									  }
									 }else{										
									 int total=rows_1*columns_1*3+54;
									 for ( int i = 0; i <= 53; i++ )
									  {
										 fileStream_1->WriteByte( dataArray_1[i] );
									  }
									 for ( int i = total; i >=54; i-- )
									  {
										 fileStream_1->WriteByte( dataArray_1[i] );
									  }
									 }}
									 fileStream_1->Close();
									 pictureBox1->Size = System::Drawing::Size(rows_1,columns_1);
									 Bitmap^ bitmap1;
									 bitmap1=dynamic_cast<Bitmap^>(Bitmap::FromFile(bmp_name));
									 bitmap1->RotateFlip(RotateFlipType::RotateNoneFlipX);
									 pictureBox1->Image = bitmap1;
									 /*gaussian smoothing */									 
									 int index=5;									 
									 for(int i=0;i<columns_1;i++){
										 for(j=0;j<rows_1;j++){
											 dataArray_2d[i][j]=dataArray[index];
											 dataArray_2d_copy[i][j]=dataArray_2d[i][j];
											 index++;
										 }
									 }									 
									 int g_size=5*sd;
									 int i=0;
									 float smallest=1;
									 for(i=0;i<g_size;i++){
										 for(j=0;j<g_size;j++){
											 g_mask[i][j]=(float)Math::Exp(-(((i-g_size/2)*(i-g_size/2)+(j-g_size/2)*(j-g_size/2))/(2*sd*sd)));
											 if(g_mask[i][j]<smallest){smallest=g_mask[i][j];}
										 }
									 }
									 int g_mask_sum=0;
									 for(i=0;i<g_size;i++){
										 for(j=0;j<g_size;j++){
											 g_mask[i][j]=(float)Math::Round(g_mask[i][j]/smallest);
											 g_mask_sum=(int)(g_mask_sum+g_mask[i][j]);
										 }
									 }									 
									 int sum=0;
									 int qx=0;int qy=0;
									 for(i=g_size/2;i<(columns_1-g_size/2);i++){
										 for(j=g_size/2;j<(rows_1-g_size/2);j++){
											 sum=0;
											 for(qx=-(g_size/2);qx<(g_size/2);qx++){
												 for(qy=-(g_size/2);qy<(g_size/2);qy++){
													 sum=sum+(int)(dataArray_2d[i+qx][j+qy]*g_mask[qx+(g_size/2)][qy+(g_size/2)]);
												 }
											 }
											 dataArray_2d[i][j]=sum/g_mask_sum;
										 }
									 }
									/*sobel mask initialization*/
									sobel_mask_x[0][0]=-1;sobel_mask_x[1][0]=-2;sobel_mask_x[2][0]=-1;
									sobel_mask_x[0][1]=-0;sobel_mask_x[1][1]=0;sobel_mask_x[2][1]=0;
									sobel_mask_x[0][2]=1;sobel_mask_x[1][2]=2;sobel_mask_x[2][2]=1;
									sobel_mask_y[0][0]=-1;sobel_mask_y[1][0]=0;sobel_mask_y[2][0]=1;
									sobel_mask_y[0][1]=-2;sobel_mask_y[1][1]=0;sobel_mask_y[2][1]=2;
									sobel_mask_y[0][2]=-1;sobel_mask_y[1][2]=0;sobel_mask_y[2][2]=1;
									/*convolution with sobel mask*/
									int sum_x=0;
									int sum_y=0;
									int m=0;
									 for(i=1;i<(columns_1-1);i++){
										 for(j=1;j<(rows_1-1);j++){
											 sum_x=0;
											 sum_y=0;
											 for(qx=-1;qx<2;qx++){
												 for(qy=-1;qy<2;qy++){
													 sum_x=sum_x+dataArray_2d[i+qx][j+qy]*sobel_mask_x[qx+1][qy+1];
													 sum_y=sum_y+dataArray_2d[i+qx][j+qy]*sobel_mask_y[qx+1][qy+1];
												 }
											 }
											 i_x[i][j]=sum_x;
											 i_y[i][j]=sum_y;
											 i_mag[i][j]=Math::Abs(sum_x)+Math::Abs(sum_y);
											 if(i_mag[i][j]>edge_threshold){
												 i_edge[i][j]=255;
												 i_edge_1[i][j]=255;
												 edge_index_i[m]=i;
												 edge_index_j[m]=j;
												 m++;
											 }else{
												 i_edge[i][j]=0;
												 i_edge_1[i][j]=0;
											 }

										 }
									 }								 
									 /*non-maximum suppression*/
									 int m_max=m;
									 int i_pos;
									 int j_pos;
									 for(m=0;m<m_max;m++)
									 {										 
										 i_pos=edge_index_i[m];
										 j_pos=edge_index_j[m];
										 if((Math::Abs(i_x[i_pos][j_pos])-Math::Abs(i_y[i_pos][j_pos]))>edge_direction_threshold){											
											 i_pos=edge_index_i[m];
										     j_pos=edge_index_j[m];
											 if((j_pos-1)>=1){
												 if(i_mag[i_pos][j_pos-1]>=i_mag[i_pos][j_pos]){
													while(((j_pos-1)>=1)&&(i_mag[i_pos][j_pos-1]>=i_mag[i_pos][j_pos])){
														i_edge_1[i_pos][j_pos]=0;												
														 j_pos=j_pos-1;
														 }
													 }
											 }
											i_pos=edge_index_i[m];
										    j_pos=edge_index_j[m];
											if((j_pos+1)<(rows_1-1)){ 
												if(i_mag[i_pos][j_pos+1]>=i_mag[i_pos][j_pos]){
													while(((j_pos+1)<(rows_1-1))&&(i_mag[i_pos][j_pos+1]>=i_mag[i_pos][j_pos])){
														i_edge_1[i_pos][j_pos]=0;
														j_pos=j_pos+1;
														}
													}
											}
									    }
										  i_pos=edge_index_i[m];
										     j_pos=edge_index_j[m];
										if((Math::Abs(i_y[i_pos][j_pos])-Math::Abs(i_x[i_pos][j_pos]))>edge_direction_threshold){											
											i_pos=edge_index_i[m];
										     j_pos=edge_index_j[m];
											 if((i_pos-1)>=1){
												 if(i_mag[i_pos-1][j_pos]>=i_mag[i_pos][j_pos]){
													while(((i_pos-1)>=1)&&(i_mag[i_pos-1][j_pos]>=i_mag[i_pos][j_pos])){
														i_edge_1[i_pos][j_pos]=0;
														i_pos=i_pos-1;
														 }
													 }
											 }
											i_pos=edge_index_i[m];
										    j_pos=edge_index_j[m];
											if((i_pos+1)<(columns_1-1)){ 
												if(i_mag[i_pos+1][j_pos]>=i_mag[i_pos][j_pos]){
													while(((i_pos+1)<(columns_1-1))&&(i_mag[i_pos+1][j_pos]>=i_mag[i_pos][j_pos])){
														i_edge_1[i_pos][j_pos]=0;
														i_pos=i_pos+1;
														}
													}
											}

									     }
										 i_pos=edge_index_i[m];
										 j_pos=edge_index_j[m];
										if((Math::Abs(Math::Abs(i_x[i_pos][j_pos])-Math::Abs(i_x[i_pos][j_pos]))<=edge_direction_threshold)&&((i_x[i_pos][j_pos]*i_y[i_pos][j_pos])>0)){
										  	 i_pos=edge_index_i[m];
										     j_pos=edge_index_j[m];
											 if(((j_pos-1)>=1)&&((i_pos+1)<(columns_1-1))){
												 if(i_mag[i_pos+1][j_pos-1]>=i_mag[i_pos][j_pos]){
													while(i_mag[i_pos+1][j_pos-1]>=i_mag[i_pos][j_pos]){
														i_edge_1[i_pos][j_pos]=0;
														if(((j_pos-1)<1)&&((i_pos+1)>=(columns_1-1)))break;
														 j_pos=j_pos-1;
														i_pos=i_pos+1;
														 }
													 }
											 }
											i_pos=edge_index_i[m];
										    j_pos=edge_index_j[m];
											 if(((j_pos+1)<(rows_1-1))&&((i_pos-1)>=1)){
												if(i_mag[i_pos-1][j_pos+1]>=i_mag[i_pos][j_pos]){
													while(i_mag[i_pos-1][j_pos+1]>=i_mag[i_pos][j_pos]){
														i_edge_1[i_pos][j_pos]=0;													
														 if(((j_pos+1)>=(rows_1-1))&&((i_pos-1)<1))break;
														j_pos=j_pos+1;
														i_pos=i_pos-1;
														}
													}
											}
										} 
										i_pos=edge_index_i[m];
										j_pos=edge_index_j[m];
										if((Math::Abs(Math::Abs(i_x[i_pos][j_pos])-Math::Abs(i_x[i_pos][j_pos]))<=edge_direction_threshold)&&((i_x[i_pos][j_pos]*i_y[i_pos][j_pos])<0)){
											 i_pos=edge_index_i[m];
										     j_pos=edge_index_j[m];
											 if(((j_pos-1)>=1)&&((i_pos-1)>=1)){
												 if(i_mag[i_pos-1][j_pos-1]>=i_mag[i_pos][j_pos]){
													while(i_mag[i_pos-1][j_pos-1]>=i_mag[i_pos][j_pos]){
														i_edge_1[i_pos][j_pos]=0;	
														if(((j_pos-1)>=1)&&((i_pos-1)>=1))break;
														 j_pos=j_pos-1;
														 i_pos=i_pos-1;
													 	 }
													 }
											 }
											i_pos=edge_index_i[m];
										    j_pos=edge_index_j[m];
											 if(((j_pos+1)<(rows_1-1))&&((i_pos+1)<(columns_1-1))){
												if(i_mag[i_pos+1][j_pos+1]>=i_mag[i_pos][j_pos]){
													while(i_mag[i_pos+1][j_pos+1]>=i_mag[i_pos][j_pos]){
														i_edge_1[i_pos][j_pos]=0;
														if(((j_pos+1)<(rows_1-1))&&((i_pos+1)<(columns_1-1)))break;
														j_pos=j_pos+1;
														i_pos=i_pos+1;
														}
													}
											}
										}
									 }
									 /*minimum suppression ends*/ /*it works!!! yes yes yes!!! ahaaaa hahahahahahaha #include crazy_mode.h */
									 /*displaying result*/									 
									 display_res("i_edge_1","_afternonmaxsupp",2);									  
									 /*LoG*/
									 LoG[0][0]=2; LoG[1][0]=-1; LoG[2][0]=2;
									 LoG[0][1]=-1; LoG[1][1]=-4; LoG[2][1]=-1;
									 LoG[0][2]=2; LoG[1][2]=-1; LoG[2][2]=2;
									 sum=0;
									 m=0;
									for(i=1;i<(columns_1-1);i++){
										 for(j=1;j<(rows_1-1);j++){
											 sum=0;
												 for(qx=-1;qx<2;qx++){
												 for(qy=-1;qy<2;qy++){
													 sum=sum+dataArray_2d[i+qx][j+qy]*LoG[qx+1][qy+1];													 
												 }
											 }
											 log_mag[i][j]=sum;		 
											 if(log_mag[i][j]>edge_log_threshold){
												 log_edge[i][j]=255;
												 log_edge_1[i][j]=255;
												 edge_index_i[m]=i;
												 edge_index_j[m]=j;
												 m++;
											 }else{
												 log_edge[i][j]=0;
												 log_edge_1[i][j]=0;
											 }

										 }
									 }
									/*non-maximum suppression for LoG*/
									 m_max=m;
									 i_pos;
									 j_pos;
									 for(m=0;m<m_max;m++)
									 {										 
										 i_pos=edge_index_i[m];
										 j_pos=edge_index_j[m];
										 if((Math::Abs(i_x[i_pos][j_pos])-Math::Abs(i_y[i_pos][j_pos]))>edge_direction_threshold){											
											 i_pos=edge_index_i[m];
										     j_pos=edge_index_j[m];
											 if((j_pos-1)>=1){
												 if(log_mag[i_pos][j_pos-1]>=log_mag[i_pos][j_pos]){
													while(((j_pos-1)>=1)&&(log_mag[i_pos][j_pos-1]>=log_mag[i_pos][j_pos])){
														log_edge_1[i_pos][j_pos]=0;												
														 j_pos=j_pos-1;
														 }
													 }
											 }
											i_pos=edge_index_i[m];
										    j_pos=edge_index_j[m];
											if((j_pos+1)<(rows_1-1)){ 
												if(log_mag[i_pos][j_pos+1]>=log_mag[i_pos][j_pos]){
													while(((j_pos+1)<(rows_1-1))&&(log_mag[i_pos][j_pos+1]>=log_mag[i_pos][j_pos])){
														log_edge_1[i_pos][j_pos]=0;
														j_pos=j_pos+1;
														}
													}
											}
									    }
										  i_pos=edge_index_i[m];
										     j_pos=edge_index_j[m];
										if((Math::Abs(i_y[i_pos][j_pos])-Math::Abs(i_x[i_pos][j_pos]))>edge_direction_threshold){											
											i_pos=edge_index_i[m];
										     j_pos=edge_index_j[m];
											 if((i_pos-1)>=1){
												 if(log_mag[i_pos-1][j_pos]>=log_mag[i_pos][j_pos]){
													while(((i_pos-1)>=1)&&(log_mag[i_pos-1][j_pos]>=log_mag[i_pos][j_pos])){
														log_edge_1[i_pos][j_pos]=0;
														i_pos=i_pos-1;
														 }
													 }
											 }
											i_pos=edge_index_i[m];
										    j_pos=edge_index_j[m];
											if((i_pos+1)<(columns_1-1)){ 
												if(log_mag[i_pos+1][j_pos]>=log_mag[i_pos][j_pos]){
													while(((i_pos+1)<(columns_1-1))&&(log_mag[i_pos+1][j_pos]>=log_mag[i_pos][j_pos])){
														log_edge_1[i_pos][j_pos]=0;
														i_pos=i_pos+1;
														}
													}
											}

									     }
										 i_pos=edge_index_i[m];
										 j_pos=edge_index_j[m];
										if((Math::Abs(Math::Abs(i_x[i_pos][j_pos])-Math::Abs(i_x[i_pos][j_pos]))<=edge_direction_threshold)&&((i_x[i_pos][j_pos]*i_y[i_pos][j_pos])>0)){
										  	 i_pos=edge_index_i[m];
										     j_pos=edge_index_j[m];
											 if(((j_pos-1)>=1)&&((i_pos+1)<(columns_1-1))){
												 if(log_mag[i_pos+1][j_pos-1]>=log_mag[i_pos][j_pos]){
													while(log_mag[i_pos+1][j_pos-1]>=log_mag[i_pos][j_pos]){
														log_edge_1[i_pos][j_pos]=0;
														if(((j_pos-1)<1)&&((i_pos+1)>=(columns_1-1)))break;
														 j_pos=j_pos-1;
														i_pos=i_pos+1;
														 }
													 }
											 }
											i_pos=edge_index_i[m];
										    j_pos=edge_index_j[m];
											 if(((j_pos+1)<(rows_1-1))&&((i_pos-1)>=1)){
												if(log_mag[i_pos-1][j_pos+1]>=log_mag[i_pos][j_pos]){
													while(log_mag[i_pos-1][j_pos+1]>=log_mag[i_pos][j_pos]){
														log_edge_1[i_pos][j_pos]=0;													
														 if(((j_pos+1)>=(rows_1-1))&&((i_pos-1)<1))break;
														j_pos=j_pos+1;
														i_pos=i_pos-1;
														}
													}
											}
										} 
										i_pos=edge_index_i[m];
										j_pos=edge_index_j[m];
										if((Math::Abs(Math::Abs(i_x[i_pos][j_pos])-Math::Abs(i_x[i_pos][j_pos]))<=edge_direction_threshold)&&((i_x[i_pos][j_pos]*i_y[i_pos][j_pos])<0)){
											 i_pos=edge_index_i[m];
										     j_pos=edge_index_j[m];
											 if(((j_pos-1)>=1)&&((i_pos-1)>=1)){
												 if(log_mag[i_pos-1][j_pos-1]>=log_mag[i_pos][j_pos]){
													while(log_mag[i_pos-1][j_pos-1]>=log_mag[i_pos][j_pos]){
														log_edge_1[i_pos][j_pos]=0;	
														if(((j_pos-1)>=1)&&((i_pos-1)>=1))break;
														 j_pos=j_pos-1;
														 i_pos=i_pos-1;
													 	 }
													 }
											 }
											i_pos=edge_index_i[m];
										    j_pos=edge_index_j[m];
											 if(((j_pos+1)<(rows_1-1))&&((i_pos+1)<(columns_1-1))){
												if(log_mag[i_pos+1][j_pos+1]>=log_mag[i_pos][j_pos]){
													while(log_mag[i_pos+1][j_pos+1]>=log_mag[i_pos][j_pos]){
														log_edge_1[i_pos][j_pos]=0;
														if(((j_pos+1)<(rows_1-1))&&((i_pos+1)<(columns_1-1)))break;
														j_pos=j_pos+1;
														i_pos=i_pos+1;
														}
													}
											}
										}
									 }									
								  } 								  
				}					
		 }
private: System::Void textBox3_Leave(System::Object^  sender, System::EventArgs^  e) {
			String^ temp_str_2=label7->Text;
			temp_str_2=temp_str_2->Substring(0,15);
			 temp_str_2=String::Concat(temp_str_2," ");
			 if(textBox3->Text==""){temp_str_2=String::Concat(temp_str_2,"0");
			 edge_direction_threshold=0;}else{
			 temp_str_2=String::Concat(temp_str_2,textBox3->Text);
			 edge_direction_threshold=Int32::Parse(textBox3->Text);}
			 label7->Text=temp_str_2;			 
		 }
private: System::Void textBox2_Leave(System::Object^  sender, System::EventArgs^  e) {
			 String^ temp_str_1=label6->Text;
			 temp_str_1=temp_str_1->Substring(0,11);
			 temp_str_1=String::Concat(temp_str_1," ");
			 if(textBox2->Text==""){temp_str_1=String::Concat(temp_str_1,"100");
			 edge_threshold=100;}else{
			 temp_str_1=String::Concat(temp_str_1,textBox2->Text);
			 edge_threshold=Int32::Parse(textBox2->Text);}
			 label6->Text=temp_str_1;			
		 }
private: System::Void textBox1_Leave(System::Object^  sender, System::EventArgs^  e) {		  
			  String^ temp_str=label2->Text;
			 Int32^ size_of_mask=(gcnew Int32());
			 temp_str=temp_str->Substring(0,4);
			 temp_str=String::Concat(temp_str," ");
			 temp_str=String::Concat(temp_str,textBox1->Text);
			 if(textBox1->Text==""){temp_str=String::Concat(temp_str,"1");}
			 label2->Text=temp_str;
			 temp_str=label5->Text;
			 temp_str=temp_str->Substring(0,10);
			 try{sd=Int32::Parse(textBox1->Text);}catch(Exception^ exp){String^ temp_temp=exp->Message;}
			 if(textBox1->Text==""){sd=1;}
			 size_of_mask=sd*5;
			 temp_str=String::Concat(temp_str," ");
			 temp_str=String::Concat(temp_str,size_of_mask->ToString());
			 label5->Text=temp_str;
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 display_res("dataArray_2d_copy","_source",1);
		 }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 display_res("dataArray_2d","_aftergaussian",1);
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 display_res("i_x","_i_x",1);
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 display_res("i_y","_i_y",1);
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 display_res("i_mag","_derivativemagnitude",1);
		 }
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
			 display_res("i_edge","_edge",1);
		 }
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
			 display_res("i_edge_1","_afternonmaxsupp",1);
		 }
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
			 display_res("log_edge","_afterlog",1);
		 }
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
			 display_res("log_edge_1","_afterlogsuppressed",1);
		 }
private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {
			 display_res("dataArray_2d_copy","_source",2);
		 }
private: System::Void button14_Click(System::Object^  sender, System::EventArgs^  e) {
			 display_res("dataArray_2d","_aftergaussian",2);
		 }
private: System::Void button20_Click(System::Object^  sender, System::EventArgs^  e) {
			 display_res("i_x","_i_x",2);
		 }
private: System::Void button16_Click(System::Object^  sender, System::EventArgs^  e) {
			 display_res("i_y","_i_y",2);
		 }
private: System::Void button19_Click(System::Object^  sender, System::EventArgs^  e) {
			 display_res("i_mag","_derivativemagnitude",2);
		 }
private: System::Void button15_Click(System::Object^  sender, System::EventArgs^  e) {
			 display_res("i_edge","_edge",2);
		 }
private: System::Void button17_Click(System::Object^  sender, System::EventArgs^  e) {
			 display_res("i_edge_1","_afternonmaxsupp",2);
		 }
private: System::Void button18_Click(System::Object^  sender, System::EventArgs^  e) {
			 display_res("log_edge","_afterlog",2);
		 }
private: System::Void button21_Click(System::Object^  sender, System::EventArgs^  e) {
			 display_res("log_edge_1","_afterlogsuppressed",2);
		 }
private: void display_res(String^ array_name,String^ mode,int bitmap_index){		
									 try{
									 int j=0;
									 int multiplier=1;
									 int index_1=5;
									 for(int i=0;i<columns_1;i++){
										 for(int j=0;j<rows_1;j++){										
												if(array_name=="dataArray_2d_copy")
													{dataArray_result[index_1]=dataArray_2d_copy[i][j];}
												if(array_name=="dataArray_2d")
													{dataArray_result[index_1]=dataArray_2d[i][j];}
												if(array_name=="i_x")
													{dataArray_result[index_1]=i_x[i][j];}
												if(array_name=="i_y")
													{dataArray_result[index_1]=i_y[i][j];}
												if(array_name=="i_mag")
													{dataArray_result[index_1]=i_mag[i][j];}
												if(array_name=="i_edge")
													{dataArray_result[index_1]=i_edge[i][j];}
												if(array_name=="i_edge_1")
													{dataArray_result[index_1]=i_edge_1[i][j];}
												if(array_name=="log_edge")
													{dataArray_result[index_1]=log_edge[i][j];}
												if(array_name=="log_edge_1")
													{dataArray_result[index_1]=log_edge_1[i][j];}											
											 /*change output?? change above!!*/
											 index_1++;
										 }
									 }
									 dataArray_result[0]=dataArray[0];dataArray_result[1]=dataArray[1];
									 dataArray_result[2]=dataArray[2];dataArray_result[3]=dataArray[3];
									 dataArray_result[4]=dataArray[4];									 
									 /*String^ raw_address="";
									 raw_address=openFileDialog1->FileName;
									 raw_address=raw_address->Replace(".raw","");
									 raw_address=String::Concat(raw_address,mode);									 
									 raw_address=String::Concat(raw_address,".raw");									 
									  FileStream^ fileStream_3 = gcnew FileStream(raw_address,FileMode::Create );									 
									 for ( int i = 0; i < (columns_1*rows_1+5); i++ )
									  {
										 fileStream_3->WriteByte( dataArray_result[i] );										 
									  }
									 fileStream_3->Close();*/
									 int file_size_1=(rows_1*columns_1)*3+54+1;
									int bin_1[32];
									int a_1=0;int b_1=0;int c_1=0;int d_1=0;
									 for(j=31;j>=0;j--){
										  bin_1[j]=file_size_1%2;
											file_size_1=file_size_1/2;											
										}										 
									multiplier=1;
									for(int u=31;u>=24;u--){
										a_1=a_1+multiplier*bin_1[u];
										multiplier=multiplier*2;
									}
									multiplier=1;
									for(int u=23;u>=16;u--){
										b_1=b_1+multiplier*bin_1[u];
										multiplier=multiplier*2;
									}
									multiplier=1;
									for(int u=15;u>=8;u--){
										c_1=c_1+multiplier*bin_1[u];
										multiplier=multiplier*2;
									}
									multiplier=1;
									for(int u=7;u>=0;u--){
										d_1=d_1+multiplier*bin_1[u];
										multiplier=multiplier*2;
									}									
									int raw_size_1=(rows_1*columns_1)*3+1;
									int bi_1[32];
									int f_1=0;int g_1=0;int h_1=0;int v_1=0;
									 for(j=31;j>=0;j--){
										  bi_1[j]=raw_size_1%2;
											raw_size_1=raw_size_1/2;											
										}										 
									multiplier=1;
									for(int u=31;u>=24;u--){
										f_1=f_1+multiplier*bi_1[u];
										multiplier=multiplier*2;
									}
									multiplier=1;
									for(int u=23;u>=16;u--){
										g_1=g_1+multiplier*bi_1[u];
										multiplier=multiplier*2;
									}
									multiplier=1;
									for(int u=15;u>=8;u--){
										h_1=h_1+multiplier*bi_1[u];
										multiplier=multiplier*2;
									}
									multiplier=1;
									for(int u=7;u>=0;u--){
										v_1=v_1+multiplier*bi_1[u];
										multiplier=multiplier*2;
									}
									dataArray_result_1[0]=66;
									dataArray_result_1[1]=77;
									dataArray_result_1[2]=a_1;dataArray_result_1[3]=b_1;dataArray_result_1[4]=c_1;dataArray_result_1[5]=d_1;
									dataArray_result_1[6]=0;dataArray_result_1[7]=0;dataArray_result_1[8]=0;dataArray_result_1[9]=0;
									dataArray_result_1[10]=54;dataArray_result_1[11]=0;dataArray_result_1[12]=0;dataArray_result_1[13]=0;
									dataArray_result_1[14]=40;dataArray_result_1[15]=0;dataArray_result_1[16]=0;dataArray_result_1[17]=0;
									dataArray_result_1[18]=dataArray_result[0];dataArray_result_1[19]=dataArray_result[1];dataArray_result_1[20]=0;dataArray_result_1[21]=0;
									dataArray_result_1[22]=dataArray_result[2];dataArray_result_1[23]=dataArray_result[3];dataArray_result_1[24]=0;dataArray_result_1[25]=0;
									dataArray_result_1[26]=1;dataArray_result_1[27]=0;dataArray_result_1[28]=24;dataArray_result_1[29]=0;
									dataArray_result_1[30]=0;dataArray_result_1[31]=0;dataArray_result_1[32]=0;dataArray_result_1[33]=0;
									dataArray_result_1[34]=f_1;dataArray_result_1[35]=g_1;dataArray_result_1[36]=h_1;dataArray_result_1[37]=v_1;
									dataArray_result_1[38]=19;dataArray_result_1[39]=11;dataArray_result_1[40]=0;dataArray_result_1[41]=0;
									dataArray_result_1[42]=19;dataArray_result_1[43]=11;dataArray_result_1[44]=0;dataArray_result_1[45]=0;
									dataArray_result_1[46]=0;dataArray_result_1[47]=0;dataArray_result_1[48]=0;dataArray_result_1[49]=0;
									dataArray_result_1[50]=0;dataArray_result_1[51]=0;dataArray_result_1[52]=0;dataArray_result_1[53]=0;
									for(int i=54;i<=250000;i++){
										int w=(i-54)*3;
										dataArray_result_1[w+54]=dataArray_result[i-49];
										dataArray_result_1[w+55]=dataArray_result[i-49];
										dataArray_result_1[w+56]=dataArray_result[i-49];																
									}
									 String^ bmp_name_1=openFileDialog1->FileName;
									 bmp_name_1=bmp_name_1->Replace(".raw","");
									 bmp_name_1=String::Concat(bmp_name_1,mode);
									 bmp_name_1=String::Concat(bmp_name_1,".bmp");									 
									  FileStream^ fileStream_2 = gcnew FileStream(bmp_name_1,FileMode::Create );
									 if((rows_1==487)){														
									 int total=rows_1*columns_1*3+55+1461;
									 dataArray_result_1[18]=dataArray_result[0]+1;dataArray_result_1[19]=dataArray_result[1];dataArray_result_1[20]=0;dataArray_result_1[21]=0;
									dataArray_result_1[22]=dataArray_result[2];dataArray_result_1[23]=dataArray_result[3];dataArray_result_1[24]=0;dataArray_result_1[25]=0;
									for ( int i = 0; i <= 53; i++ )
									  {
										 fileStream_2->WriteByte( dataArray_result_1[i] );
									  }
									int t_1=1;
									 for ( int i = total; i >=54; i-- )
									  {										  
										  if((t_1%1461)==0){ fileStream_2->WriteByte(0);fileStream_2->WriteByte(0);fileStream_2->WriteByte(0);t_1=0;}
										 fileStream_2->WriteByte( dataArray_result_1[i] );
										 t_1++;
									 }
									 }else{ if((rows_1==190)){					
									 int total=rows_1*columns_1*3+55+1140;
									 dataArray_result_1[18]=dataArray_result[0]+2;dataArray_result_1[19]=dataArray_result[1];dataArray_result_1[20]=0;dataArray_result_1[21]=0;
									dataArray_result_1[22]=dataArray_result[2];dataArray_result_1[23]=dataArray_result[3];dataArray_result_1[24]=0;dataArray_result_1[25]=0;
									for ( int i = 0; i <= 53; i++ )
									  {
										 fileStream_2->WriteByte( dataArray_result_1[i] );
									  }
									int t_1=1;
									 for ( int i = total; i >=54; i-- )
									  {
										   if((t_1%570)==0){ fileStream_2->WriteByte(255);fileStream_2->WriteByte(255);fileStream_2->WriteByte(255);
										   fileStream_2->WriteByte(255);fileStream_2->WriteByte(255);fileStream_2->WriteByte(255);t_1=0;}
										 fileStream_2->WriteByte( dataArray_result_1[i] );
										 t_1++;
									  }
									 }else{														
									 int total=rows_1*columns_1*3+54;
									 for ( int i = 0; i <= 53; i++ )
									  {
										 fileStream_2->WriteByte( dataArray_result_1[i] );
									  }
									 for ( int i = total; i >=54; i-- )
									  {
										 fileStream_2->WriteByte( dataArray_result_1[i] );
									  }
									 }}
									 fileStream_2->Close();
									 if(bitmap_index==2){
									 pictureBox2->Size = System::Drawing::Size(rows_1,columns_1);
									 Bitmap^ bitmap2;
									 bitmap2=dynamic_cast<Bitmap^>(Bitmap::FromFile(bmp_name_1));
									 bitmap2->RotateFlip(RotateFlipType::RotateNoneFlipX);
									 pictureBox2->Image = bitmap2;	
									 }else{
									 pictureBox1->Size = System::Drawing::Size(rows_1,columns_1);
									 Bitmap^ bitmap1;
									 bitmap1=dynamic_cast<Bitmap^>(Bitmap::FromFile(bmp_name_1));
									 bitmap1->RotateFlip(RotateFlipType::RotateNoneFlipX);
									 pictureBox1->Image = bitmap1;										 
									 }}catch(Exception^ ex){String^ temp_st="Please choose the file first by pressing 'choose file' button \n Error :";
									 temp_st=String::Concat(temp_st,ex->Message);
									 MessageBox::Show(temp_st);}


		 }
private: System::Void textBox4_Leave(System::Object^  sender, System::EventArgs^  e) {
			 String^ temp_string=label10->Text;
			 temp_string=temp_string->Substring(0,15);
			 if(textBox4->Text==""){temp_string=String::Concat(temp_string,"18");edge_log_threshold=18;}
			 else{temp_string=String::Concat(temp_string,textBox4->Text);edge_log_threshold=Int32::Parse(textBox4->Text);}
			 label10->Text=temp_string;
		 }
};
		
		 }
		 