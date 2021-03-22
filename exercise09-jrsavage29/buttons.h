#ifndef BUTTONS_H
#define BUTTONS_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QGroupBox;
QT_END_NAMESPACE

class Buttons : public QWidget
{
	Q_OBJECT

public:
	Buttons(QWidget* parent = nullptr);

private:
	QGroupBox* createExclusiveGroup();
	QGroupBox* createNonExclusiveGroup();
	QGroupBox* createPushButtonGroup();
};

#endif