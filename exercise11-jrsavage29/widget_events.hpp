// widget_events.hpp
#ifndef WIDGET_EVENTS_H
#define WIDGET_EVENTS_H

#include <QWidget>
#include <QEvent>
#include <QMetaEnum>
#include <QDebug>
#include <iostream>

using std::cout;
using std::endl;

class WidgetEvent: public QWidget
{
	Q_OBJECT
	
	public:
		
		WidgetEvent(QWidget *parent = 0);
		bool event(QEvent* ev);
		
};


#endif
