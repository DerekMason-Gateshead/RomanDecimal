#include "FormConverterInputOutput.h"


using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	ConvertRomanDecimal::FormConverterInputOutput form;
	Application::Run(% form);
}