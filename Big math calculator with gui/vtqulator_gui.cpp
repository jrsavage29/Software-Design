////////////////////////////////////////////////////////////////////////////////////
// ECE 3574, Project 3, Jamahl Savage
//
// File name:	vtqulator_gui.cpp
// Description:	The .cpp file for the vtqulator. This manages the general gui display for the buttons and the precision label. It also handles
// 	the signals recieved from press the buttons or their shortcut and sends the input file needed to be computed to the Interpreter.
//
// Date:	11/02/2019
///////////////////////////////////////////////////////////////////////////////////

#include <QtWidgets>
#include <iomanip>
#include "vtqulator_gui.h"

VtqulatorGui::VtqulatorGui(QWidget* parent)
	: QWidget(parent)
{
	computeStr = "";
	eStr = "";
	piStr = "";
	inputCount = 0;
	VTmath_Toggle = false;
	
	QGridLayout* grid = new QGridLayout;
	
	
	grid->addWidget(Output_window.createReadOnlyGroup(),0,0);//Uses the OutputWindow class to initialize the gui's display box
	grid->addWidget(createTrigRadioGroup(), 1, 0); //initializes the radio buttons
	grid->addWidget(createNormalModeGroup(), 2, 0); //initializes the checkboxes
	grid->addWidget(createPrecisionGroup(), 3, 0); //initializes the precision label
	grid->addWidget(createPushButtonGroup(), 4, 0); //initializes the buttons for usage as well as their shortcuts if any.
	
	radianMode();// by default we will set the radiobutton to radians and have all trig calculations be done in radians
	Output_window.set_prec(0); //by default we will also start out with a precision of 0.
	
	QLabel* label = new QLabel("Copyright@VT ECE3574");
	grid->addWidget(label, 5, 0);
	
	setLayout(grid);

	setWindowTitle(tr("vtqulator"));
}

QGroupBox* VtqulatorGui::createTrigRadioGroup()
{
	QGroupBox* groupBox = new QGroupBox(tr("Unit for trigonometric functions"));

	QRadioButton* Radiobutton_degree = new QRadioButton(tr("degree"));
	Radiobutton_degree->setObjectName("Radiobutton_degree");
	
	QRadioButton* Radiobutton_radian = new QRadioButton(tr("radian"));
	Radiobutton_radian->setObjectName("Radiobutton_radian");
	
	Radiobutton_radian->setChecked(true); //Set the radio button for radians to already be checked
	

	QGridLayout* grid = new QGridLayout;
	grid->addWidget(Radiobutton_degree,0,0);
	grid->addWidget(Radiobutton_radian,0,1);
	
	
	
	groupBox->setLayout(grid);
	
	QObject::connect(Radiobutton_degree, SIGNAL(clicked()), this, SLOT(degreeMode()));//connect the signals for the radio buttons to their slots
	QObject::connect(Radiobutton_radian, SIGNAL(clicked()), this, SLOT(radianMode()));

	return groupBox;
}

QGroupBox* VtqulatorGui::createNormalModeGroup()
{
	QGroupBox* groupBox = new QGroupBox(tr(""));
	
	QCheckBox* Mode_Normal_VTmath = new QCheckBox(tr("VTmath Mode"));
	Mode_Normal_VTmath->setObjectName("Mode_Normal_VTmath");
	Mode_Normal_VTmath->setChecked(false);

	QGridLayout* grid = new QGridLayout;
	grid->addWidget(Mode_Normal_VTmath,0,1);
	groupBox->setLayout(grid);
	
	QObject::connect(Mode_Normal_VTmath, SIGNAL(clicked()), this, SLOT(Norm_VTmath_Mode()));//connect the signal for the checkbox button to its slot
	
	return groupBox;
}

QGroupBox* VtqulatorGui::createPushButtonGroup()//set up the buttions and their keyboard shortcuts
{
	QGroupBox* groupBox = new QGroupBox(tr(""));
	
	//The section consists of setting the object names for each button as well setting up their ouput and keyboard shortcuts.
	Pushbutton_plus = new QPushButton(tr("+"));
	Pushbutton_plus->setObjectName("Pushbutton_plus");
	Pushbutton_plus->setShortcut(QKeySequence(Qt::Key_Plus));
	
	Pushbutton_minus = new QPushButton(tr("-"));
	Pushbutton_minus->setObjectName("Pushbutton_minus");
	Pushbutton_minus->setShortcut(QKeySequence(Qt::Key_Minus));
	
	Pushbutton_multiply = new QPushButton(tr("*"));
	Pushbutton_multiply->setObjectName("Pushbutton_multiply");
	Pushbutton_multiply->setShortcut(QKeySequence(Qt::Key_Asterisk));
	
	Pushbutton_divide = new QPushButton(tr("/"));
	Pushbutton_divide->setObjectName("Pushbutton_divide");
	Pushbutton_divide->setShortcut(QKeySequence(Qt::Key_Slash));
	
	Pushbutton_power = new QPushButton(tr("^"));
	Pushbutton_power->setObjectName("Pushbutton_power");
	Pushbutton_power->setShortcut(QKeySequence(Qt::SHIFT + Qt::Key_6));
	
	Pushbutton_squareroot = new QPushButton(tr("v"));
	Pushbutton_squareroot->setObjectName("Pushbutton_squareroot");
	Pushbutton_squareroot->setShortcut(QKeySequence(Qt::Key_V));
		
	
	Pushbutton_log = new QPushButton(tr("lo&g"));
	Pushbutton_log->setObjectName("Pushbutton_log");
	Pushbutton_log->setShortcut(QKeySequence(Qt::Key_G));
	
	Pushbutton_ln = new QPushButton(tr("&ln"));
	Pushbutton_ln->setObjectName("Pushbutton_ln");
	Pushbutton_ln->setShortcut(QKeySequence(Qt::Key_L));
	
	Pushbutton_sin = new QPushButton(tr("&sin"));
	Pushbutton_sin->setObjectName("Pushbutton_sin");
	Pushbutton_sin->setShortcut(QKeySequence(Qt::Key_S));
	
	Pushbutton_cos = new QPushButton(tr("c&os"));
	Pushbutton_cos->setObjectName("Pushbutton_cos");
	Pushbutton_cos->setShortcut(QKeySequence(Qt::Key_O));
	
	Pushbutton_tan = new QPushButton(tr("t&an"));
	Pushbutton_tan->setObjectName("Pushbutton_tan");
	Pushbutton_tan->setShortcut(QKeySequence(Qt::Key_A));
	
	Pushbutton_e = new QPushButton(tr("e"));
	Pushbutton_e->setObjectName("Pushbutton_e");
	Pushbutton_e->setShortcut(QKeySequence(Qt::Key_E));
	
	Pushbutton_pi = new QPushButton(tr("p&i"));
	Pushbutton_pi->setObjectName("Pushbutton_pi");
	Pushbutton_pi->setShortcut(QKeySequence(Qt::Key_I));
	
	Pushbutton_p = new QPushButton(tr("p"));
	Pushbutton_p->setObjectName("Pushbutton_p");
	Pushbutton_p->setShortcut(QKeySequence(Qt::Key_P));
	
	Pushbutton_n = new QPushButton(tr("n"));
	Pushbutton_n->setObjectName("Pushbutton_n");
	Pushbutton_n->setShortcut(QKeySequence(Qt::Key_N));
	
	Pushbutton_f = new QPushButton(tr("f"));
	Pushbutton_f->setObjectName("Pushbutton_f");
	Pushbutton_f->setShortcut(QKeySequence(Qt::Key_F));
	
	Pushbutton_P = new QPushButton(tr("P"));
	Pushbutton_P->setObjectName("Pushbutton_P");
	Pushbutton_P->setShortcut(QKeySequence(Qt::SHIFT + Qt::Key_P));
	
	Pushbutton_c = new QPushButton(tr("c"));
	Pushbutton_c->setObjectName("Pushbutton_c");
	Pushbutton_c->setShortcut(QKeySequence(Qt::Key_C));
	
	Pushbutton_d = new QPushButton(tr("d"));
	Pushbutton_d->setObjectName("Pushbutton_d");
	Pushbutton_d->setShortcut(QKeySequence(Qt::Key_D));
	
	Pushbutton_r = new QPushButton(tr("r"));
	Pushbutton_r->setObjectName("Pushbutton_r");
	Pushbutton_r->setShortcut(QKeySequence(Qt::Key_R));
	
	Pushbutton_z = new QPushButton(tr("z"));
	Pushbutton_z->setObjectName("Pushbutton_z");
	Pushbutton_z->setShortcut(QKeySequence(Qt::Key_Z));
	
	Pushbutton_k = new QPushButton(tr("k"));
	Pushbutton_k->setObjectName("Pushbutton_k");
	Pushbutton_k->setShortcut(QKeySequence(Qt::Key_K));
	
	Pushbutton_K = new QPushButton(tr("K"));
	Pushbutton_K->setObjectName("Pushbutton_K");
	Pushbutton_K->setShortcut(QKeySequence(Qt::SHIFT + Qt::Key_K));
	
	Pushbutton_Z = new QPushButton(tr("Z"));
	Pushbutton_Z->setObjectName("Pushbutton_Z");
	Pushbutton_Z->setShortcut(QKeySequence(Qt::SHIFT + Qt::Key_Z));
	
	Pushbutton_X = new QPushButton(tr("X"));
	Pushbutton_X->setObjectName("Pushbutton_X");
	Pushbutton_X->setShortcut(QKeySequence(Qt::SHIFT + Qt::Key_X));
	
	
	Pushbutton_9 = new QPushButton(tr("9"));
	Pushbutton_9->setObjectName("Pushbutton_9");
	Pushbutton_9->setShortcut(QKeySequence(Qt::Key_9));
	
	Pushbutton_8 = new QPushButton(tr("8"));
	Pushbutton_8->setObjectName("Pushbutton_8");
	Pushbutton_8->setShortcut(QKeySequence(Qt::Key_8));
	
	Pushbutton_7 = new QPushButton(tr("7"));
	Pushbutton_7->setObjectName("Pushbutton_7");
	Pushbutton_7->setShortcut(QKeySequence(Qt::Key_7));
	
	Pushbutton_6 = new QPushButton(tr("6"));
	Pushbutton_6->setObjectName("Pushbutton_6");
	Pushbutton_6->setShortcut(QKeySequence(Qt::Key_6));
	
	Pushbutton_5 = new QPushButton(tr("5"));
	Pushbutton_5->setObjectName("Pushbutton_5");
	Pushbutton_5->setShortcut(QKeySequence(Qt::Key_5));
	
	Pushbutton_4 = new QPushButton(tr("4"));
	Pushbutton_4->setObjectName("Pushbutton_4");
	Pushbutton_4->setShortcut(QKeySequence(Qt::Key_4));
	
	Pushbutton_3 = new QPushButton(tr("3"));
	Pushbutton_3->setObjectName("Pushbutton_3");
	Pushbutton_3->setShortcut(QKeySequence(Qt::Key_3));
	
	Pushbutton_2 = new QPushButton(tr("2"));
	Pushbutton_2->setObjectName("Pushbutton_2");
	Pushbutton_2->setShortcut(QKeySequence(Qt::Key_2));
	
	Pushbutton_1 = new QPushButton(tr("1"));
	Pushbutton_1->setObjectName("Pushbutton_1");
	Pushbutton_1->setShortcut(QKeySequence(Qt::Key_1));
	
	Pushbutton_0 = new QPushButton(tr("0"));
	Pushbutton_0->setObjectName("Pushbutton_0");
	Pushbutton_0->setShortcut(QKeySequence(Qt::Key_0));
	

	Pushbutton_sign = new QPushButton(tr("+/-"));
	Pushbutton_sign->setObjectName("Pushbutton_sign");
	Pushbutton_sign->setShortcut(QKeySequence(Qt::SHIFT + Qt::Key_Minus));
	
	Pushbutton_dot = new QPushButton(tr("."));
	Pushbutton_dot->setObjectName("Pushbutton_dot");
	Pushbutton_dot->setShortcut(QKeySequence(Qt::Key_Period));
	
	Pushbutton_space = new QPushButton(tr("space"));
	Pushbutton_space->setObjectName("Pushbutton_space");
	Pushbutton_space->setShortcut(QKeySequence(Qt::Key_Space));
	
	Pushbutton_backspace = new QPushButton(tr("backspace"));
	Pushbutton_backspace->setObjectName("Pushbutton_backspace");
	Pushbutton_backspace->setShortcut(QKeySequence(Qt::Key_Backspace));
	
	Pushbutton_return = new QPushButton(tr("return"));
	Pushbutton_return->setObjectName("Pushbutton_return");
	Pushbutton_return->setShortcut(QKeySequence(Qt::Key_Return));
	
	
	QGridLayout* vbox = new QGridLayout;
	
	//We also need to set up the layout of the buttons in the gui for display
	vbox->addWidget(Pushbutton_plus,0 ,0);
	vbox->addWidget(Pushbutton_minus,1 ,0);
	vbox->addWidget(Pushbutton_multiply,2 ,0);
	vbox->addWidget(Pushbutton_divide,3 ,0);
	vbox->addWidget(Pushbutton_power,4 ,0);
	vbox->addWidget(Pushbutton_squareroot,0 ,1);
	vbox->addWidget(Pushbutton_log,1 ,1);
	vbox->addWidget(Pushbutton_ln,2 ,1);
	vbox->addWidget(Pushbutton_sin,3 ,1);
	vbox->addWidget(Pushbutton_cos,4 ,1);
	vbox->addWidget(Pushbutton_tan,0 ,2);
	vbox->addWidget(Pushbutton_e,1 ,2);
	vbox->addWidget(Pushbutton_pi,2 ,2);
	vbox->addWidget(Pushbutton_p,3 ,2);
	vbox->addWidget(Pushbutton_n,4 ,2);
	vbox->addWidget(Pushbutton_f,0 ,3);
	vbox->addWidget(Pushbutton_P,1 ,3);
	vbox->addWidget(Pushbutton_c,2 ,3);
	vbox->addWidget(Pushbutton_d,3 ,3);
	vbox->addWidget(Pushbutton_r,4 ,3);
	vbox->addWidget(Pushbutton_z,0 ,4);
	vbox->addWidget(Pushbutton_k,1 ,4);
	vbox->addWidget(Pushbutton_K,2 ,4);
	vbox->addWidget(Pushbutton_Z,3 ,4);
	vbox->addWidget(Pushbutton_X,4 ,4);
	vbox->addWidget(Pushbutton_7,0 ,5);
	vbox->addWidget(Pushbutton_4,1 ,5);
	vbox->addWidget(Pushbutton_1,2 ,5);
	vbox->addWidget(Pushbutton_0,3 ,5);
	vbox->addWidget(Pushbutton_space,4 ,5);
	vbox->addWidget(Pushbutton_8,0 ,6);
	vbox->addWidget(Pushbutton_5,1 ,6);
	vbox->addWidget(Pushbutton_2,2 ,6);
	vbox->addWidget(Pushbutton_sign,3 ,6);
	vbox->addWidget(Pushbutton_backspace,4 ,6);
	vbox->addWidget(Pushbutton_9,0 ,7);
	vbox->addWidget(Pushbutton_6,1 ,7);
	vbox->addWidget(Pushbutton_3,2 ,7);
	vbox->addWidget(Pushbutton_dot,3 ,7);
	vbox->addWidget(Pushbutton_return,4 ,7);
	
	groupBox->setLayout(vbox);
	
	//Make the connections to the slots for each button.
	//As can be seen some of the buttons share the same slot. This simplifies the design process for one slot can now do the work of what could 9 different slots
	QObject::connect(Pushbutton_0, SIGNAL(clicked()), this, SLOT(digitClicked()));
	QObject::connect(Pushbutton_1, SIGNAL(clicked()), this, SLOT(digitClicked()));
	QObject::connect(Pushbutton_2, SIGNAL(clicked()), this, SLOT(digitClicked()));
	QObject::connect(Pushbutton_3, SIGNAL(clicked()), this, SLOT(digitClicked()));
	QObject::connect(Pushbutton_4, SIGNAL(clicked()), this, SLOT(digitClicked()));
	QObject::connect(Pushbutton_5, SIGNAL(clicked()), this, SLOT(digitClicked()));
	QObject::connect(Pushbutton_6, SIGNAL(clicked()), this, SLOT(digitClicked()));
	QObject::connect(Pushbutton_7, SIGNAL(clicked()), this, SLOT(digitClicked()));
	QObject::connect(Pushbutton_8, SIGNAL(clicked()), this, SLOT(digitClicked()));
	QObject::connect(Pushbutton_9, SIGNAL(clicked()), this, SLOT(digitClicked()));
	
	QObject::connect(Pushbutton_plus, SIGNAL(clicked()), this, SLOT(additiveOperatorClicked()));
	QObject::connect(Pushbutton_minus, SIGNAL(clicked()), this, SLOT(additiveOperatorClicked()));
	QObject::connect(Pushbutton_multiply, SIGNAL(clicked()), this, SLOT(multiplicativeOperatorClicked()));
	QObject::connect(Pushbutton_divide, SIGNAL(clicked()), this, SLOT(multiplicativeOperatorClicked()));
	QObject::connect(Pushbutton_power, SIGNAL(clicked()), this, SLOT(unaryOperatorClicked()));
	QObject::connect(Pushbutton_squareroot, SIGNAL(clicked()), this, SLOT(unaryOperatorClicked()));
	QObject::connect(Pushbutton_log, SIGNAL(clicked()), this, SLOT(specialUnaryOperatorClicked()));
	QObject::connect(Pushbutton_ln, SIGNAL(clicked()), this, SLOT(specialUnaryOperatorClicked()));
	QObject::connect(Pushbutton_sin, SIGNAL(clicked()), this, SLOT(specialUnaryOperatorClicked()));
	QObject::connect(Pushbutton_cos, SIGNAL(clicked()), this, SLOT(specialUnaryOperatorClicked()));
	QObject::connect(Pushbutton_tan, SIGNAL(clicked()), this, SLOT(specialUnaryOperatorClicked()));
	
	QObject::connect(Pushbutton_sign, SIGNAL(clicked()), this, SLOT(changeSignClicked()));
	QObject::connect(Pushbutton_e, SIGNAL(clicked()), this, SLOT(e_or_pi_Clicked()));
	QObject::connect(Pushbutton_pi, SIGNAL(clicked()), this, SLOT(e_or_pi_Clicked()));
	QObject::connect(Pushbutton_p, SIGNAL(clicked()), this, SLOT(commandClicked()));
	QObject::connect(Pushbutton_n, SIGNAL(clicked()), this, SLOT(commandClicked()));
	QObject::connect(Pushbutton_f, SIGNAL(clicked()), this, SLOT(commandClicked()));
	QObject::connect(Pushbutton_P, SIGNAL(clicked()), this, SLOT(commandClicked()));
	QObject::connect(Pushbutton_c, SIGNAL(clicked()), this, SLOT(commandClicked()));
	QObject::connect(Pushbutton_d, SIGNAL(clicked()), this, SLOT(commandClicked()));
	QObject::connect(Pushbutton_r, SIGNAL(clicked()), this, SLOT(commandClicked()));
	QObject::connect(Pushbutton_z, SIGNAL(clicked()), this, SLOT(commandClicked()));
	QObject::connect(Pushbutton_k, SIGNAL(clicked()), this, SLOT(commandClicked()));
	QObject::connect(Pushbutton_K, SIGNAL(clicked()), this, SLOT(commandClicked()));
	QObject::connect(Pushbutton_Z, SIGNAL(clicked()), this, SLOT(commandClicked()));
	QObject::connect(Pushbutton_X, SIGNAL(clicked()), this, SLOT(commandClicked()));
	
	QObject::connect(Pushbutton_dot, SIGNAL(clicked()), this, SLOT(pointClicked()));
	QObject::connect(Pushbutton_space, SIGNAL(clicked()), this, SLOT(space()));
	QObject::connect(Pushbutton_backspace, SIGNAL(clicked()), this, SLOT(backspaceClicked()));
	QObject::connect(Pushbutton_return, SIGNAL(clicked()), this, SLOT(returnClicked()));
	
	
	
	return groupBox;
}

QGroupBox* VtqulatorGui::createPrecisionGroup() //Creating the precision label
{
	QGroupBox* groupBox = new QGroupBox(tr("Precision")); //Give the precision label a visible title
	
	QGridLayout *layout = new QGridLayout;
	
	Label_precision = new QLabel(QString::number(Output_window.get_prec()));//Set the the label to display the precision
	Label_precision->setObjectName("Label_precision"); //Set the object name of the label
	
	layout->addWidget(Label_precision,0,0); //Set the position of the label in gui.
	groupBox->setLayout(layout);
	
	return groupBox;
}


void VtqulatorGui::digitClicked()//slot for when a digit is clicked by mouse or on the keyboard
{
	QPushButton *clickedButton = qobject_cast<QPushButton *>(sender()); //This grabs the output for the button pressed
	QString digitValue = clickedButton->text(); //We then store that otuput as a qstring into a variable
	Output_window.editDisplayString(digitValue);
	
	//out << digitValue.toStdString();
	computeStr = computeStr + digitValue; // we add that qstring to the qstring variable we will send to the interpreter when the return key is pressed
	inputCount++; //increment this number every time input is recieved into the qstring computeStr so we can keep track of the location of special input.
}

void VtqulatorGui::e_or_pi_Clicked() //This slot is used of the special input pi and e.
{
	//When and e and pi are pressed they will not display the letters "e" and "pi" but instead the value of e or pi while considering the current precision
	//That's why it's important to keep track of its location in case the user manually types in the value rather than presses the e or pi button
	//If I were to backspace on the manually typed out value of e or pi it should only delete one char at a time
	//On the other hand, if the user uses the e or pi button and then backspaces, it should delete the whole number.
	
	QPushButton *clickedButton = qobject_cast<QPushButton *>(sender()); //same process as in all the other slots for this line
	
	if(clickedButton->text() == "e")//The user wants to insert euler's number which is just e=2.71828
	{	
		std::ostringstream out;	//create ostringstream so we can still be able to manipulate the precision of the number
		double tempn = M_E * pow(10, Output_window.get_prec());
		tempn = trunc(tempn) / pow(10, Output_window.get_prec());
		
		out <<std::fixed << std::setprecision(Output_window.get_prec()) << tempn;
		eStr = QString::fromStdString(out.str());
		
		Output_window.editDisplayString(eStr); //we display the number on the gui display
		computeStr = computeStr + eStr; //we add the number as a string to the computerStr
	}
		
	if(clickedButton->text() == "p&i")//The user wants to insert pi which is just pi = 3.1415926...
	{
		//The same process as what was done for e is done here as well.
		std::ostringstream out;	
		double tempn = M_PI * pow(10, Output_window.get_prec());
		tempn = trunc(tempn) / pow(10, Output_window.get_prec());
		
		out <<std::fixed << std::setprecision(Output_window.get_prec()) << tempn;
		piStr = QString::fromStdString(out.str());
		
		Output_window.editDisplayString(piStr);
		computeStr = computeStr + piStr;
	}
	
	if(Output_window.get_prec() == 0) //If the precision is currently set to 0 we will only add 1 to the input count
	{
		inputCount = inputCount + (Output_window.get_prec() + 1);
		epiloc.push(inputCount);
	}
	
	else if(Output_window.get_prec() > 0)//If the precision is currently above 0 then we need to account for the number in front of the decimal as well as the decimal itself. Therefore we add 2 to input count
	{
		inputCount = inputCount + (Output_window.get_prec() + 2);
		epiloc.push(inputCount); //we store the location in a stack for keeping track where the user used the e or pi on the display.
	}
	
	//std::cout <<" inputCount after pressing e or pi is: " << inputCount << std::endl;
	
}

void VtqulatorGui::unaryOperatorClicked() //Slot for square root, exponential, etc. Performance is identical to that of the digit's slot
{
	QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
	QString op = clickedButton->text();
	Output_window.editDisplayString(op);
	
	computeStr = computeStr + op;
	inputCount++;
}

void VtqulatorGui::specialUnaryOperatorClicked()//slot for ln,log, and the trigs
{
	QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
	QString op = clickedButton->text();
	
	//We check if the user has pressed the button for sin, cos, tan, log, or ln and display the fully worded 
	//command on the display but only store the appropriate command in the computeStr for computation by the interpreter class.
	//We also increment the inputCount depending on the length of the actual command word.
	if(clickedButton->text() == "lo&g")
	{
		Output_window.editDisplayString("log");
		computeStr = computeStr + QString("g");
		inputCount += 3;
	}
	
	else if(clickedButton->text() == "&ln")
	{
		Output_window.editDisplayString("ln");
		computeStr = computeStr + QString("l");
		inputCount+= 2;
	}
	
	else if(clickedButton->text() == "&sin")
	{
		Output_window.editDisplayString("sin");
		computeStr = computeStr + QString("s");
		inputCount+= 3;
	}
	
	else if(clickedButton->text() == "c&os")
	{
		Output_window.editDisplayString("cos");
		computeStr = computeStr + QString("o");
		inputCount+= 3;
	}
	
	else if(clickedButton->text() == "t&an")
	{
		Output_window.editDisplayString("tan");
		computeStr = computeStr + QString("a");
		inputCount+= 3;
	}
	//std::cout << computeStr.toStdString() << std::endl;
	
}

void VtqulatorGui::additiveOperatorClicked()//For addition and subtraction. Performance is identical to that of the digit's slot as well as the unaryOperatorClicked slot
{
	QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
	QString operation = clickedButton->text();
	Output_window.editDisplayString(operation);
	
	computeStr = computeStr + operation;
	inputCount++;
}

void VtqulatorGui::multiplicativeOperatorClicked()//For multiplication and division. Performance is identical to that of the digit's slot as well as the unaryOperatorClicked slot
{
	//This could have been combined with the additive slot but I was orignally planning on doing something different in the multiplication and division slot.
	QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
	QString operation = clickedButton->text();
	Output_window.editDisplayString(operation);
	
	computeStr = computeStr + operation;
	inputCount++;
}

void VtqulatorGui::returnClicked() //calculate the result of the operands and operation
{	
	Output_window.editDisplayString("\n");
	
	//take the string holding the line of user input to be computed
	string compute = computeStr.toStdString();
	
	calc.open("calculate.txt");
	//Store the string into a file so that it can be read by the interpreter's compute method
	calc << compute;
	calc.close();
	
	output.open("output.txt", std::ios_base::app); //allow the output file to appended text 
	input.open("calculate.txt");//read from the file we stored the user input needing computing
	
	//compute it here
	Output_window.computeDisplay(input, output); //reads from the input and stores the end result in the output file
	
	input.close();
	output.close();
	
	result.open("output.txt"); //We open the file containing the results of the computing for reading
	
	
	string str;
	string fill;
	
	while(getline(result, fill))//read every line in the file containing the results
	{
		str ="";
		str +=fill;
		
	}
	
	QString qstr = QString::fromStdString(str);
	
	Output_window.editDisplayString(qstr);
	
	result.close();
	
	//reset the input count back to zero as well as the computeStr to blank so they are ready for new  user computations
	inputCount = 0;
	computeStr.clear();
	
	/*if(computeStr == "")
	{
		std::cout <<"It's cleared out!"<< std::endl;
	*/
	
	remove("calculate.txt");
	remove("output.txt");
	
	
	Label_precision->setText(QString::number(Output_window.get_prec()));//We will also update the precision display in case the user also adjusted that for computations
	//std::cout << "*" << Output_window.get_text().toStdString() << "*" << std::endl;
	
	
}

void VtqulatorGui::pointClicked()//for decimals
{
	Output_window.editDisplayString(".");
	computeStr += ".";
	inputCount++;
}

void VtqulatorGui::changeSignClicked() //Displays a negative sign in front of the number
{
	Output_window.editDisplayString("_");
	computeStr = computeStr + "_";
	inputCount++;
	
}

void VtqulatorGui::backspaceClicked()//Used for deleting strings and chars
{
	//Will not allow backspacing if there is nothing in the computeStr.
	if(computeStr != "")
	{
		QString text = Output_window.get_text();
		
		int pos; //Used for holding the length of what pi or e should be if the user pressed the pi or e button
			
		if(Output_window.get_prec() > 0)
		{
			pos = 2 + Output_window.get_prec(); 
		}
		
		else if (Output_window.get_prec() == 0)
		{
			pos = 1;
		}
		
		
		//DELETE A STRING ESSENTIALLY 
		if(text.size() >= 3 && (text.right(3)  == "tan" || text.right(3)  == "cos" || 
			text.right(3)  == "sin" || text.right(3)  == "log")) //Since these are all three letter words we can group them together in case either one of them need to be deleted
		{
			//std::cout <<"Backspacing on one of the 3 letter trig functions" <<std::endl;
			inputCount = inputCount - 3; //We will get rid of 3 chars in the input count and in the display.
			Output_window.backspace();
			Output_window.backspace();
			Output_window.backspace();
			
			//however the computeStr does not store the words like "sin" and "cos" but instead "s" and "o" so we only need to chop one char from it.
			computeStr.chop(1);
		}
		
		else if(text.size() >= 2 && text.right(2)  == "ln") //Same thinf is done here but only for the only two letter word "ln"
		{
			//std::cout <<"Backspacing on the 2 letter ln function" <<std::endl;
			inputCount = inputCount - 2;
			Output_window.backspace();
			Output_window.backspace();
			computeStr.chop(1);
		}
		
		else if(epiloc.empty() == false && ( text.right(pos) == piStr || text.right(pos) == eStr )) //This backspace is done for if the user used the e or pi button
		{
			//Checking for either backspace of e or pi
			
			//we check if the the user used the e or pi button at the current 
			//position in the display and also check if the the precision of the pi or e match what the precision of pi and e should currently be.
			if(inputCount == epiloc.top() && text.right(pos) == piStr) 
			{
				//std::cout<<"The location of the first pi input is: "<< epiloc.top()<<std::endl;
				epiloc.pop();// Get rid of the location because we already confimed that we got it at that location
				inputCount = inputCount - pos; //remove the length of e or pi from the input count
				
				for(int i = 0; i < pos; i++)//keep backspacing until its all gone.
				{
					Output_window.backspace();
				}
				
				computeStr.chop(pos);//we will also need to delete the length of the pi or e from the computeStr since the number is also directly written into the QString
			}
			
			else if( inputCount == epiloc.top() && text.right(pos) == eStr) //The same process is done for this if statement
			{
				//std::cout<<"The location of the first e input is: "<< epiloc.top()<<std::endl;
				epiloc.pop();
				inputCount = inputCount - pos;
				
				for(int i = 0; i < pos; i++)
				{
					Output_window.backspace();
				}
				computeStr.chop(pos);
			}
			
		}
		
		//DELETE A SINGLE CHAR AT A TIME
		else
		{
			//std::cout <<"Must just be a char I need to backspace" <<std::endl;
			Output_window.backspace();
			computeStr.chop(1);
			inputCount--;
		}
		
	}
	
	
	
}

void VtqulatorGui::space()//for adding in a space in the display
{
	Output_window.editDisplayString(" ");
	computeStr = computeStr + " ";
	inputCount++;
}

void VtqulatorGui::commandClicked()//if the user clicks on one of the command buttons like "p", "r", "f", etc, it is displayed
{
	QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
	QString command = clickedButton->text();
	Output_window.editDisplayString(command);
	
	computeStr = computeStr + command;
	inputCount++;
}

void VtqulatorGui::degreeMode()//For toggling the calculation of trig depending the on the trig radio buttons
{
	Output_window.toggle_trig_unit(false);
}

void VtqulatorGui::radianMode()//For toggling the calculation of trig depending the on the trig radio buttons
{
	Output_window.toggle_trig_unit(true);
}

void VtqulatorGui::Norm_VTmath_Mode()//For toggling between VTmath mode and normal mode calculations
{
	//Fade out all other commands that cannot be used in VTmath mode
	VTmath_Toggle = !VTmath_Toggle;
	
	Pushbutton_squareroot->setEnabled(!VTmath_Toggle);
	Pushbutton_log->setEnabled(!VTmath_Toggle);
	Pushbutton_ln->setEnabled(!VTmath_Toggle);
	Pushbutton_sin->setEnabled(!VTmath_Toggle);
	Pushbutton_cos->setEnabled(!VTmath_Toggle);
	Pushbutton_tan->setEnabled(!VTmath_Toggle);
	Pushbutton_e->setEnabled(!VTmath_Toggle);
	Pushbutton_pi->setEnabled(!VTmath_Toggle);
	Pushbutton_dot->setEnabled(!VTmath_Toggle);
	Pushbutton_c->setEnabled(!VTmath_Toggle);
	Pushbutton_k->setEnabled(!VTmath_Toggle);
	Pushbutton_K->setEnabled(!VTmath_Toggle);
	Pushbutton_X->setEnabled(!VTmath_Toggle);
	
	//clear the stack since the mode changed
	Output_window.reset_stack();
	
	//Set VTmath status for VTmath calculations in the interpreter class
	Output_window.set_VTmath_mode(VTmath_Toggle);
	
	//All calculations in VTmath mode will use precision setting of 0
	Output_window.set_prec(0);
	
	//Start thread here by using the VTmath_Toggle boolean
	std::thread th(&VtqulatorGui::run_loop, this);
	
	th.detach();
	
	
}

void VtqulatorGui::run_loop()
{
	while(VTmath_Toggle == true)//Keeps the thread active in VTmath mode
	{
		
	}
}