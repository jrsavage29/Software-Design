#include <QtWidgets>

#include "buttons.h"

Buttons::Buttons(QWidget* parent)
	: QWidget(parent)
{
	QGridLayout* grid = new QGridLayout;
	grid->addWidget(createExclusiveGroup(), 0, 0);
	grid->addWidget(createNonExclusiveGroup(), 1, 0);
	grid->addWidget(createPushButtonGroup(), 0, 1);

	QLabel* label = new QLabel("Example of buttons in Qt \nAll inherited from QButton");

	grid->addWidget(label, 1, 1);
	setLayout(grid);

	setWindowTitle(tr("Examples for buttons in Qt"));
	resize(480, 320);
}

QGroupBox* Buttons::createExclusiveGroup()
{
	QGroupBox* groupBox = new QGroupBox(tr("E&xclusive Radio Buttons"));
	groupBox->setCheckable(true);
	groupBox->setChecked(false);

	QRadioButton* radio1 = new QRadioButton(tr("Rad&io button 1"));
	QRadioButton* radio2 = new QRadioButton(tr("Radi&o button 2"));
	QRadioButton* radio3 = new QRadioButton(tr("Radio &button 3"));
	radio1->setChecked(true);
	QCheckBox* checkBox = new QCheckBox(tr("Ind&ependent checkbox"));
	checkBox->setChecked(true);

	QVBoxLayout* vbox = new QVBoxLayout;
	vbox->addWidget(radio1);
	vbox->addWidget(radio2);
	vbox->addWidget(radio3);
	vbox->addWidget(checkBox);
	vbox->addStretch(1);
	groupBox->setLayout(vbox);

	return groupBox;
}

QGroupBox* Buttons::createNonExclusiveGroup()
{
	QGroupBox* groupBox = new QGroupBox(tr("Non-Exclusive Checkboxes"));
	groupBox->setFlat(true);

	QCheckBox* checkBox1 = new QCheckBox(tr("&Checkbox 1"));
	QCheckBox* checkBox2 = new QCheckBox(tr("C&heckbox 2"));
	checkBox2->setChecked(true);
	QCheckBox* tristateBox = new QCheckBox(tr("Tri-&state button"));
	tristateBox->setTristate(true);
	tristateBox->setCheckState(Qt::PartiallyChecked);

	QVBoxLayout* vbox = new QVBoxLayout;
	vbox->addWidget(checkBox1);
	vbox->addWidget(checkBox2);
	vbox->addWidget(tristateBox);
	vbox->addStretch(1);
	groupBox->setLayout(vbox);

	return groupBox;
}

QGroupBox* Buttons::createPushButtonGroup()
{
	QGroupBox* groupBox = new QGroupBox(tr("&Push Buttons"));
	groupBox->setCheckable(true);
	groupBox->setChecked(true);

	QPushButton* pushButton = new QPushButton(tr("&Normal Button"));
	QPushButton* toggleButton = new QPushButton(tr("&Toggle Button"));
	toggleButton->setCheckable(true);
	toggleButton->setChecked(true);
	QPushButton* flatButton = new QPushButton(tr("&Flat Button"));
	flatButton->setFlat(true);

	QPushButton* popupButton = new QPushButton(tr("Pop&up Button"));
	QMenu* menu = new QMenu(this);
	menu->addAction(tr("&First Item"));
	menu->addAction(tr("&Second Item"));
	menu->addAction(tr("&Third Item"));
	menu->addAction(tr("F&ourth Item"));
	popupButton->setMenu(menu);

	QAction* newAction = menu->addAction(tr("Submenu"));
	QMenu* subMenu = new QMenu(tr("Popup Submenu"));
	subMenu->addAction(tr("Item 1"));
	subMenu->addAction(tr("Item 2"));
	subMenu->addAction(tr("Item 3"));
	newAction->setMenu(subMenu);

	QVBoxLayout* vbox = new QVBoxLayout;
	vbox->addWidget(pushButton);
	vbox->addWidget(toggleButton);
	vbox->addWidget(flatButton);
	vbox->addWidget(popupButton);
	vbox->addStretch(1);
	groupBox->setLayout(vbox);

	return groupBox;
}

