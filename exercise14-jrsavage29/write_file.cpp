// write_file.cpp
#include <QFile>
#include <QDataStream>
#include <QDebug>

#include "file_header.h"
  
int main(int argc, char *argv[])
{
  QFile file("temp.dat");
  file.open(QIODevice::WriteOnly);

  // treat the file as consuming a data stream
  QDataStream out(&file);

  // Write a header with a magic number and a version
  out << MAGIC;
  out << VERSION;

  // use a specific streaming format
  out.setVersion(QDataStream::Qt_5_0);
  
  // write some data
  QList<QString> msg;
  msg << "This is a test. This is only a test.";
  msg << "Test 2";
  msg << "Test 3";
  msg << "Test 4";
  
  out << msg;
  
  // notify the user that we're finished
  qDebug() << "A data stream has been written to a file.";  
  
  return 0;
}
