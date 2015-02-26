#pragma once


namespace poly {

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
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  canvas;
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
			this->canvas = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->canvas))->BeginInit();
			this->SuspendLayout();
			// 
			// canvas
			// 
			this->canvas->BackColor = System::Drawing::Color::White;
			this->canvas->Dock = System::Windows::Forms::DockStyle::Fill;
			this->canvas->Location = System::Drawing::Point(0, 0);
			this->canvas->Name = L"canvas";
			this->canvas->Size = System::Drawing::Size(362, 325);
			this->canvas->TabIndex = 0;
			this->canvas->TabStop = false;
			this->canvas->Click += gcnew System::EventHandler(this, &Form1::canvas_Click);
			this->canvas->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::canvas_MouseDown);
			this->canvas->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::canvas_MouseMove);
			this->canvas->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::canvas_Paint);
			this->canvas->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::canvas_MouseClick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(362, 325);
			this->Controls->Add(this->canvas);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Form1";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->canvas))->EndInit();
			this->ResumeLayout(false);

		}

		static nGon* shape = new nGon( Vector(130,130), 64, 0, 8, 360);
		static Vector* mXY = new Vector();
		static System::Drawing::Icon^ newIcon = gcnew System::Drawing::Icon( System::Drawing::Icon::ExtractAssociatedIcon("C:\\Program Files\\Windows Calendar\\WinCal.exe"), System::Drawing::Size(32,32) );

#pragma endregion
	private: System::Void canvas_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 
				 e->Graphics->DrawIcon(newIcon, shape->pos().X-16, shape->pos().Y-16);

				 for (int n = 0; n < shape->sides(); n++) {
					 if ( shape->points()[n].isOverlapped( mXY->X, mXY->Y ) ) { 
						shape->points()[n].Size(48);
						e->Graphics->DrawIcon(newIcon, System::Drawing::Rectangle(shape->points()[n].Center().X-shape->points()[n].Size()/2, shape->points()[n].Center().Y-shape->points()[n].Size()/2, shape->points()[n].Size(), shape->points()[n].Size() ));
					 }
					 else {
						shape->points()[n].Size(32);
						e->Graphics->DrawIcon(newIcon, System::Drawing::Rectangle(shape->points()[n].Center().X-shape->points()[n].Size()/2, shape->points()[n].Center().Y-shape->points()[n].Size()/2, shape->points()[n].Size(), shape->points()[n].Size() ));
						}
				}

				 e->Graphics->DrawLine(System::Drawing::Pens::Black, shape->pos().X, shape->pos().Y, mXY->X, mXY->Y);
			 }
	private: System::Void Form1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
				 delete shape;
				 delete mXY;
				 delete newIcon;
			 }
	private: System::Void canvas_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 
			 }
	private: System::Void canvas_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				
			 }
	private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 if (e->KeyCode == Keys::OemPeriod) {
					shape->arcAngle( shape->arcAngle() + 1 );
					canvas->Refresh();
				 }
				 if (e->KeyCode == Keys::Oemcomma) {
					shape->arcAngle( shape->arcAngle() - 1 );
					canvas->Refresh();
				 }
				 if (e->KeyCode == Keys::Up) {
					shape->radius( shape->radius() + 1 );
					canvas->Refresh();
				 }
				 if (e->KeyCode == Keys::Down) {
					shape->radius(shape->radius() - 1);
					canvas->Refresh();
				 }
				 if (e->KeyCode == Keys::Left) {
					shape->angle( shape->angle() - 1 );
					canvas->Refresh();
				 }
				 if (e->KeyCode == Keys::Right) {
					shape->angle( shape->angle() + 1 );
					canvas->Refresh();
				 }
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 
			 }
	private: System::Void canvas_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 mXY->X = e->X;
				 mXY->Y = e->Y;
				 // if it doesn't go outside the specified circle, then refresh canvas
				 if ( Vector(mXY->X - shape->pos().X, mXY->Y - shape->pos().Y).length() < shape->radius() + 48 ) {
					canvas->Refresh();
					}
				 }
private: System::Void canvas_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

