// complex_widget.hpp
#ifndef COMPLEX_WIDGET_H
#define COMPLEX_WIDGET_H
#include <QtWidgets>

class ComplexWidget : public QWidget
{
  Q_OBJECT

public:
  ComplexWidget();
  double getRealPart();
  double getImaginaryPart();
  double getMagnitude();
  double getPhase();

public slots:
  void updateClicked();

private:
  QLineEdit *m_realLineEdit;
  QLineEdit *m_imaginaryLineEdit;
  QLabel *m_magnitudeValueLabel;
  QLabel *m_phaseValueLabel;
  bool errorReal;
  bool errorImag;
  bool errorPhase;
  bool errorMag;
};

#endif
