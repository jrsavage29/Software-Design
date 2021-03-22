////////////////////////////////////////////////////////////////////////////////////
// ECE 3574, Project 3, Jamahl Savage
//
// File name:	test_vtqulator.cpp
// Description:	A simple test file used to test the various capabiliteis of the vtqulator_gui.cpp and its dependencies
//
// Date:	11/02/2019
///////////////////////////////////////////////////////////////////////////////////

#include <QTest>

#include "vtqulator_gui.h"

class TestVtqulator : public QObject {
  Q_OBJECT

private slots:

	void testFindByName();
	void testSinRadian();
	void testAdd();
	void test_subtraction();
	void test_multiplication();
	void test_division();
	void test_squareroot_exponential();
	void test_printStack();
	void test_PopStack_Reverse();
	void test_cosRadian();
	void test_tanRadian();
	void test_sinDegree();
	void test_cosDegree();
	void test_tanDegree();
	void test_e_and_pi();
	void test_duplicate_Length();
	void test_X_Z();
	void text_ln();
	void test_log();
	void test_returnPrec();
	

private:
	VtqulatorGui gui;
	
public:
	void press_Pushbutton_plus();
	void press_Pushbutton_minus();
	void press_Pushbutton_multiply();
	void press_Pushbutton_divide();
	void press_Pushbutton_power();
	void press_Pushbutton_squareroot();
	void press_Pushbutton_log();
	void press_Pushbutton_ln();
	void press_Pushbutton_sin();
	void press_Pushbutton_cos();
	void press_Pushbutton_tan();
	void press_Pushbutton_e();
	void press_Pushbutton_pi();
	void press_Pushbutton_p();
	void press_Pushbutton_n();
	void press_Pushbutton_f();
	void press_Pushbutton_P();
	void press_Pushbutton_c();
	void press_Pushbutton_d();
	void press_Pushbutton_r();
	void press_Pushbutton_z();
	void press_Pushbutton_k();
	void press_Pushbutton_K();
	void press_Pushbutton_Z();
	void press_Pushbutton_X();
	void press_Pushbutton_7();
	void press_Pushbutton_4();
	void press_Pushbutton_1();
	void press_Pushbutton_0();
	void press_Pushbutton_space();
	void press_Pushbutton_8();
	void press_Pushbutton_5();
	void press_Pushbutton_2();
	void press_Pushbutton_sign();
	void press_Pushbutton_backspace();
	void press_Pushbutton_9();
	void press_Pushbutton_6();
	void press_Pushbutton_3();
	void press_Pushbutton_dot();
	void press_Pushbutton_return();
	
	void press_radianMode();
	void press_degreeMode();

};

void TestVtqulator::testFindByName()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_dot");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_dot'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_plus");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_plus'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_minus");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_minus'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_multiply");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_multiply'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_divide");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_divide'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_power");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_power'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_squareroot");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_squareroot'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_log");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_log'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_ln");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_ln'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_sin");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_sin'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_cos");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_cos'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_tan");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_tan'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_e");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_e'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_pi");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_pi'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_p");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_p'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_n");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_n'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_f");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_f'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_P");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_P'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_c");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_c'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_d");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_d'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_r");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_r'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_z");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_z'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_k");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_k'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_K");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_K'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_Z");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_Z'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_X");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_X'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_7");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_7'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_4");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_4'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_1");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_1'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_0");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_0'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_space");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_space'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_8");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_8'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_5");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_5'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_2");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_2'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_sign");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_sign'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_backspace");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_backspace'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_9");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_9'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_6");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_6'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_3");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_3'");
	
	op = gui.findChild<QPushButton *>("Pushbutton_return");
	QVERIFY2(op, "Could not find widget with name: 'Pushbutton_return'");
	
	auto op2 = gui.findChild<QRadioButton *>("Radiobutton_degree");
	QVERIFY2(op2, "Could not find widget with name: 'Radiobutton_degree'");
	
	op2 = gui.findChild<QRadioButton *>("Radiobutton_radian");
	QVERIFY2(op2, "Could not find widget with name: 'Radiobutton_radian'");
	
}

void TestVtqulator::test_printStack()
{
	auto output = gui.findChild<QPlainTextEdit *>("Output_window");
	QVERIFY2(output, "Could not find widget with name: 'Output_window'");
	
	press_Pushbutton_c();
	press_Pushbutton_return();
	
	press_Pushbutton_2();
	press_Pushbutton_space();
	press_Pushbutton_k();
	press_Pushbutton_return();
	
	press_Pushbutton_1();
	press_Pushbutton_2();
	press_Pushbutton_space();
	
	press_Pushbutton_3();
	press_Pushbutton_5();
	press_Pushbutton_dot();
	press_Pushbutton_5();
	press_Pushbutton_4();
	press_Pushbutton_1();
	press_Pushbutton_space();
	
	press_Pushbutton_4();
	press_Pushbutton_7();
	press_Pushbutton_5();
	press_Pushbutton_dot();
	press_Pushbutton_2();
	press_Pushbutton_space();
	
	press_Pushbutton_9();
	press_Pushbutton_6();
	press_Pushbutton_7();
	press_Pushbutton_space();
	
	press_Pushbutton_8();
	press_Pushbutton_space();
	
	press_Pushbutton_f();
	press_Pushbutton_return();
	
	
	
	
	QString result = output->toPlainText();
	//std::cout << result.toStdString() << std::endl;
	
	QVERIFY2(result == "c\n2 k\n12 35.541 475.2 967 8 f\n8.00\n967.00\n475.20\n35.54\n12.00\n", "Output of test_printStack() does not MATCH!");
	output->clear();
}

void TestVtqulator::testAdd()
{
	auto output = gui.findChild<QPlainTextEdit *>("Output_window");
	QVERIFY2(output, "Could not find widget with name: 'Output_window'");
	
	press_Pushbutton_0();
	press_Pushbutton_space();
	press_Pushbutton_k();
	press_Pushbutton_space();
	
	press_Pushbutton_3();
	press_Pushbutton_space();
	
	press_Pushbutton_3();
	press_Pushbutton_space();
	
	press_Pushbutton_plus();
	press_Pushbutton_space();
	
	press_Pushbutton_p();
	press_Pushbutton_return();
	
	QString result = output->toPlainText();
	//std::cout << result.toStdString() << std::endl;
	
	QVERIFY2(result == "0 k 3 3 + p\n6\n", "Output of testAdd() does not MATCH!");
	output->clear();
}

void TestVtqulator::testSinRadian()
{
	
	
	auto output = gui.findChild<QPlainTextEdit *>("Output_window");
	QVERIFY2(output, "Could not find widget with name: 'Output_window'");
	
	press_Pushbutton_3();
	press_Pushbutton_space();
	press_Pushbutton_k();
	press_Pushbutton_return();
	
	press_Pushbutton_3();
	press_Pushbutton_dot();
	press_Pushbutton_2();
	press_Pushbutton_space();
	press_Pushbutton_sin();
	press_Pushbutton_return();
	
	press_Pushbutton_p();
	press_Pushbutton_return();
	
	QString result = output->toPlainText();
	
	QVERIFY2(result == "3 k\n3.2 sin\np\n-0.058\n", "Output of testSin3() does not MATCH!");
	output->clear();
	
}

void TestVtqulator::test_subtraction()
{
	auto output = gui.findChild<QPlainTextEdit *>("Output_window");
	QVERIFY2(output, "Could not find widget with name: 'Output_window'");
	
	press_Pushbutton_2();
	press_Pushbutton_space();
	press_Pushbutton_k();
	press_Pushbutton_return();
	
	press_Pushbutton_7();
	press_Pushbutton_3();
	press_Pushbutton_dot();
	press_Pushbutton_8();
	press_Pushbutton_9();
	press_Pushbutton_space();
	
	press_Pushbutton_4();
	press_Pushbutton_dot();
	press_Pushbutton_2();
	press_Pushbutton_0();
	press_Pushbutton_space();
	
	press_Pushbutton_minus();
	press_Pushbutton_return();
	
	press_Pushbutton_p();
	press_Pushbutton_return();
	
	QString result = output->toPlainText();
	//std::cout << result.toStdString() << std::endl;
	
	QVERIFY2(result == "2 k\n73.89 4.20 -\np\n69.69\n", "Output of testAdd() does not MATCH!");
	output->clear();
}

void TestVtqulator::test_multiplication()
{
	auto output = gui.findChild<QPlainTextEdit *>("Output_window");
	QVERIFY2(output, "Could not find widget with name: 'Output_window'");
	
	press_Pushbutton_0();
	press_Pushbutton_space();
	press_Pushbutton_k();
	press_Pushbutton_return();
	
	press_Pushbutton_7();
	press_Pushbutton_3();
	press_Pushbutton_space();
	
	press_Pushbutton_8();
	press_Pushbutton_9();
	press_Pushbutton_space();
	
	press_Pushbutton_multiply();
	press_Pushbutton_space();
	
	press_Pushbutton_n();
	press_Pushbutton_return();
	
	
	QString result = output->toPlainText();
	//std::cout << result.toStdString() << std::endl;
	
	QVERIFY2(result == "0 k\n73 89 * n\n6497", "Output of test does_multiplication not MATCH!");
	output->clear();
}

void TestVtqulator::test_division()
{
	auto output = gui.findChild<QPlainTextEdit *>("Output_window");
	QVERIFY2(output, "Could not find widget with name: 'Output_window'");
	
	press_Pushbutton_2();
	press_Pushbutton_space();
	press_Pushbutton_k();
	press_Pushbutton_return();
	
	press_Pushbutton_7();
	press_Pushbutton_3();
	press_Pushbutton_space();
	
	press_Pushbutton_8();
	press_Pushbutton_9();
	press_Pushbutton_space();
	
	press_Pushbutton_divide();
	press_Pushbutton_space();
	
	press_Pushbutton_n();
	press_Pushbutton_return();
	
	
	
	QString result = output->toPlainText();
	//std::cout << result.toStdString() << std::endl;
	
	QVERIFY2(result == "2 k\n73 89 / n\n0.82", "Output of test_division() does not MATCH!");
	output->clear();
	
}

void TestVtqulator::test_squareroot_exponential()
{
	auto output = gui.findChild<QPlainTextEdit *>("Output_window");
	QVERIFY2(output, "Could not find widget with name: 'Output_window'");
	
	
	press_Pushbutton_5();
	press_Pushbutton_space();
	press_Pushbutton_k();
	press_Pushbutton_return();
	
	press_Pushbutton_6();
	press_Pushbutton_9();
	press_Pushbutton_space();
	
	press_Pushbutton_squareroot();
	press_Pushbutton_return();
	
	press_Pushbutton_p();
	press_Pushbutton_return();
	
	
	press_Pushbutton_2();
	press_Pushbutton_dot();
	press_Pushbutton_2();
	press_Pushbutton_5();
	press_Pushbutton_space();
	
	press_Pushbutton_3();
	press_Pushbutton_space();
	
	press_Pushbutton_power();
	press_Pushbutton_space();
	
	press_Pushbutton_n();
	press_Pushbutton_return();
	
	
	QString result = output->toPlainText();
	//std::cout << result.toStdString() << std::endl;
	
	QVERIFY2(result == "5 k\n69 v\np\n8.30662\n2.25 3 ^ n\n11.39062", "Output of test_squareroot_exponential() does not MATCH!");
	output->clear();
}

void TestVtqulator::test_PopStack_Reverse()
{
	auto output = gui.findChild<QPlainTextEdit *>("Output_window");
	QVERIFY2(output, "Could not find widget with name: 'Output_window'");
	
	press_Pushbutton_3();
	press_Pushbutton_space();
	press_Pushbutton_k();
	press_Pushbutton_return();
	
	press_Pushbutton_6();
	press_Pushbutton_9();
	press_Pushbutton_space();
	
	press_Pushbutton_2();
	press_Pushbutton_4();
	press_Pushbutton_return();
	
	press_Pushbutton_p();
	press_Pushbutton_return();
	
	press_Pushbutton_P();
	press_Pushbutton_return();
	
	press_Pushbutton_p();
	press_Pushbutton_return();
	
	press_Pushbutton_7();
	press_Pushbutton_2();
	press_Pushbutton_space();
	
	press_Pushbutton_r();
	press_Pushbutton_return();
	
	press_Pushbutton_p();
	press_Pushbutton_return();
	
	
	QString result = output->toPlainText();
	//std::cout << result.toStdString() << std::endl;
	
	QVERIFY2(result == "3 k\n69 24\np\n24.000\nP\np\n69.000\n72 r\np\n69.000\n", "Output of test_PopStack_Reverse() does not MATCH!");
	output->clear();
}


void TestVtqulator::test_cosRadian()
{
	auto output = gui.findChild<QPlainTextEdit *>("Output_window");
	QVERIFY2(output, "Could not find widget with name: 'Output_window'");
	
	
	press_Pushbutton_2();
	press_Pushbutton_space();
	press_Pushbutton_k();
	press_Pushbutton_return();
	
	press_Pushbutton_0();
	press_Pushbutton_space();
	
	press_Pushbutton_cos();
	press_Pushbutton_space();
	
	press_Pushbutton_p();
	press_Pushbutton_return();
	
	
	QString result = output->toPlainText();
	//std::cout << result.toStdString() << std::endl;
	
	QVERIFY2(result == "2 k\n0 cos p\n1.00\n", "Output of test_cosRadian() does not MATCH!");
	output->clear();
}

void TestVtqulator::test_tanRadian()
{
	auto output = gui.findChild<QPlainTextEdit *>("Output_window");
	QVERIFY2(output, "Could not find widget with name: 'Output_window'");
	
	
	press_Pushbutton_2();
	press_Pushbutton_space();
	press_Pushbutton_k();
	press_Pushbutton_return();
	
	press_Pushbutton_1();
	press_Pushbutton_8();
	press_Pushbutton_0();
	press_Pushbutton_space();
	
	press_Pushbutton_tan();
	press_Pushbutton_space();
	
	press_Pushbutton_p();
	press_Pushbutton_return();
	
	
	QString result = output->toPlainText();
	//std::cout << result.toStdString() << std::endl;
	
	QVERIFY2(result == "2 k\n180 tan p\n1.33\n", "Output of test_tanRadian() does not MATCH!");
	output->clear();
}

void TestVtqulator::test_e_and_pi()
{
	auto output = gui.findChild<QPlainTextEdit *>("Output_window");
	QVERIFY2(output, "Could not find widget with name: 'Output_window'");
	
	press_radianMode();
	
	press_Pushbutton_2();
	press_Pushbutton_space();
	press_Pushbutton_k();
	press_Pushbutton_return();
	
	press_Pushbutton_e();
	press_Pushbutton_space();
	
	press_Pushbutton_3();
	press_Pushbutton_space();
	
	press_Pushbutton_plus();
	press_Pushbutton_space();
	
	press_Pushbutton_p();
	press_Pushbutton_return();
	
	press_Pushbutton_sign();
	press_Pushbutton_pi();
	press_Pushbutton_space();
	
	press_Pushbutton_plus();
	press_Pushbutton_space();
	
	press_Pushbutton_c();
	press_Pushbutton_backspace();
	press_Pushbutton_p();
	press_Pushbutton_return();
	
	
	
	
	
	QString result = output->toPlainText();
	//std::cout << result.toStdString() << std::endl;
	
	QVERIFY2(result == "2 k\n2.71 3 + p\n5.71\n_3.14 + p\n2.57\n", "Output of test_e_and_pi() does not MATCH!");
	output->clear();
}

void TestVtqulator::test_duplicate_Length()
{
	auto output = gui.findChild<QPlainTextEdit *>("Output_window");
	QVERIFY2(output, "Could not find widget with name: 'Output_window'");
	
	
	press_Pushbutton_c();
	press_Pushbutton_return();
	
	press_Pushbutton_2();
	press_Pushbutton_space();
	press_Pushbutton_k();
	press_Pushbutton_return();
	
	press_Pushbutton_1();
	press_Pushbutton_2();
	press_Pushbutton_space();
	
	press_Pushbutton_6();
	press_Pushbutton_5();
	press_Pushbutton_return();
	
	press_Pushbutton_d();
	press_Pushbutton_space();
	
	press_Pushbutton_f();
	press_Pushbutton_return();
	
	press_Pushbutton_z();
	press_Pushbutton_return();
	
	
	QString result = output->toPlainText();
	//std::cout << result.toStdString() << std::endl;
	
	QVERIFY2(result == "c\n2 k\n12 65\nd f\n65.00\n65.00\n12.00\nz\n3.00\n", "Output of test_duplicate_Length() does not MATCH!");
	output->clear();
}

void TestVtqulator::test_X_Z()
{
	auto output = gui.findChild<QPlainTextEdit *>("Output_window");
	QVERIFY2(output, "Could not find widget with name: 'Output_window'");
	
	press_Pushbutton_2();
	press_Pushbutton_space();
	press_Pushbutton_k();
	press_Pushbutton_return();
	
	press_Pushbutton_2();
	press_Pushbutton_3();
	press_Pushbutton_4();
	press_Pushbutton_dot();
	press_Pushbutton_8();
	press_Pushbutton_6();
	press_Pushbutton_3();
	press_Pushbutton_1();
	press_Pushbutton_space();
	
	press_Pushbutton_p();
	press_Pushbutton_return();
	
	press_Pushbutton_X();
	press_Pushbutton_space();
	press_Pushbutton_p();
	press_Pushbutton_return();
	
	press_Pushbutton_2();
	press_Pushbutton_3();
	press_Pushbutton_4();
	press_Pushbutton_dot();
	press_Pushbutton_8();
	press_Pushbutton_6();
	press_Pushbutton_3();
	press_Pushbutton_1();
	press_Pushbutton_space();
	
	press_Pushbutton_p();
	press_Pushbutton_return();
	
	press_Pushbutton_Z();
	press_Pushbutton_space();
	press_Pushbutton_p();
	press_Pushbutton_return();
	
	QString result = output->toPlainText();
	//std::cout << result.toStdString() << std::endl;
	
	QVERIFY2(result == "2 k\n234.8631 p\n234.86\nX p\n2.00\n234.8631 p\n234.86\nZ p\n5.00\n", "Output of test_X_Z() does not MATCH!");
	output->clear();
}

void TestVtqulator::text_ln()
{
	auto output = gui.findChild<QPlainTextEdit *>("Output_window");
	QVERIFY2(output, "Could not find widget with name: 'Output_window'");
	
	press_Pushbutton_2();
	press_Pushbutton_space();
	press_Pushbutton_k();
	press_Pushbutton_return();
	
	press_Pushbutton_1();
	press_Pushbutton_space();
	
	press_Pushbutton_ln();
	press_Pushbutton_space();
	
	press_Pushbutton_p();
	press_Pushbutton_return();
	
	
	
	QString result = output->toPlainText();
	//std::cout << result.toStdString() << std::endl;
	
	QVERIFY2(result == "2 k\n1 ln p\n0.00\n", "Output of test_ln()() does not MATCH!");
	output->clear();
}

void TestVtqulator::test_log()
{
	auto output = gui.findChild<QPlainTextEdit *>("Output_window");
	QVERIFY2(output, "Could not find widget with name: 'Output_window'");
	
	press_Pushbutton_2();
	press_Pushbutton_space();
	press_Pushbutton_k();
	press_Pushbutton_return();
	
	press_Pushbutton_1();
	press_Pushbutton_0();
	press_Pushbutton_0();
	press_Pushbutton_space();
	
	press_Pushbutton_log();
	press_Pushbutton_space();
	
	press_Pushbutton_p();
	press_Pushbutton_return();
	
	QString result = output->toPlainText();
	//std::cout << result.toStdString() << std::endl;
	
	QVERIFY2(result == "2 k\n100 log p\n2.00\n", "Output of test_log() does not MATCH!");
	output->clear();
}


void TestVtqulator::test_returnPrec()
{
	auto output = gui.findChild<QPlainTextEdit *>("Output_window");
	QVERIFY2(output, "Could not find widget with name: 'Output_window'");
	
	press_Pushbutton_3();
	press_Pushbutton_space();
	press_Pushbutton_k();
	press_Pushbutton_return();
	
	press_Pushbutton_K();
	press_Pushbutton_return();
	
	
	QString result = output->toPlainText();
	//std::cout << result.toStdString() << std::endl;
	
	QVERIFY2(result == "3 k\nK\n3\n", "Output of test_returnPrec()() does not MATCH!");
	output->clear();
}

void TestVtqulator::test_sinDegree()
{
	auto output = gui.findChild<QPlainTextEdit *>("Output_window");
	QVERIFY2(output, "Could not find widget with name: 'Output_window'");
	
	press_degreeMode();
	
	press_Pushbutton_2();
	press_Pushbutton_space();
	press_Pushbutton_k();
	press_Pushbutton_return();
	
	press_Pushbutton_9();
	press_Pushbutton_0();
	press_Pushbutton_space();
	
	press_Pushbutton_sin();
	press_Pushbutton_space();
	
	press_Pushbutton_p();
	press_Pushbutton_return();
	
	
	QString result = output->toPlainText();
	//std::cout << result.toStdString() << std::endl;
	
	QVERIFY2(result == "2 k\n90 sin p\n1.00\n", "Output of test_sinDegree() does not MATCH!");
	output->clear();
}

void TestVtqulator::test_cosDegree()
{
	auto output = gui.findChild<QPlainTextEdit *>("Output_window");
	QVERIFY2(output, "Could not find widget with name: 'Output_window'");
	
	press_degreeMode();
	
	press_Pushbutton_2();
	press_Pushbutton_space();
	press_Pushbutton_k();
	press_Pushbutton_return();
	
	press_Pushbutton_3();
	press_Pushbutton_0();
	press_Pushbutton_space();
	
	press_Pushbutton_cos();
	press_Pushbutton_space();
	
	press_Pushbutton_p();
	press_Pushbutton_return();
	
	
	QString result = output->toPlainText();
	//std::cout << result.toStdString() << std::endl;
	
	QVERIFY2(result == "2 k\n30 cos p\n0.86\n", "Output of test_cosDegree() does not MATCH!");
	output->clear();
}

void TestVtqulator::test_tanDegree()
{
	auto output = gui.findChild<QPlainTextEdit *>("Output_window");
	QVERIFY2(output, "Could not find widget with name: 'Output_window'");
	
	
	press_degreeMode();
	
	press_Pushbutton_2();
	press_Pushbutton_space();
	press_Pushbutton_k();
	press_Pushbutton_return();
	
	press_Pushbutton_3();
	press_Pushbutton_0();
	press_Pushbutton_space();
	
	press_Pushbutton_tan();
	press_Pushbutton_space();
	
	press_Pushbutton_p();
	press_Pushbutton_return();
	
	
	QString result = output->toPlainText();
	//std::cout << result.toStdString() << std::endl;
	
	QVERIFY2(result == "2 k\n30 tan p\n0.57\n", "Output of test_tanDegree() does not MATCH!");
	output->clear();
}




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////Functions used to make the test statements easier to write//////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void TestVtqulator::press_Pushbutton_plus()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_plus");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_minus()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_minus");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_multiply()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_multiply");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_divide()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_divide");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_power()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_power");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_squareroot()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_squareroot");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_log()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_log");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_ln()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_ln");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_sin()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_sin");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_cos()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_cos");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_tan()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_tan");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_e()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_e");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_pi()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_pi");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_p()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_p");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_n()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_n");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_f()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_f");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_P()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_P");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_c()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_c");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_d()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_d");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_r()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_r");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_z()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_z");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_k()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_k");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_K()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_K");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_Z()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_Z");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_X()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_X");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_7()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_7");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_4()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_4");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_1()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_1");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_0()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_0");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_space()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_space");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_8()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_8");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_5()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_5");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_2()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_2");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_sign()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_sign");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_backspace()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_backspace");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_9()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_9");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_6()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_6");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_3()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_3");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_dot()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_dot");
	
	op->click();
}

void TestVtqulator::press_Pushbutton_return()
{
	auto op = gui.findChild<QPushButton *>("Pushbutton_return");
	
	op->click();
}
void TestVtqulator::press_radianMode()
{
	auto op = gui.findChild<QRadioButton *>("Radiobutton_radian");
	
	op->click();
}

void TestVtqulator::press_degreeMode()
{
	auto op = gui.findChild<QRadioButton *>("Radiobutton_degree");
	
	op->click();
}

QTEST_MAIN(TestVtqulator)
#include "test_vtqulator.moc"
