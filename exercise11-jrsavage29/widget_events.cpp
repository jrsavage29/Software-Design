// widget_events.cpp
#include "widget_events.hpp"
#include <string>

WidgetEvent::WidgetEvent(QWidget *parent) :
    QWidget(parent)
{
	setWindowTitle(tr("Exercise for event handling in Qt"));
	
	resize(480, 320);
 
}

bool WidgetEvent::event(QEvent* ev)
{
			
			qDebug() << "Handled an event: " << ev->type();
            //std::string mystring;
            //std::cin >> mystring;
			return true;
}


