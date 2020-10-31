#include "MyForm.h"
#include <string>
#include <msclr\marshal_cppstd.h>
#include "Header.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	CalculatorTest::MyForm form;
	Application::Run(% form);
}
