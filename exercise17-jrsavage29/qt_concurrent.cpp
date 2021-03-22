#include <QtConcurrentRun> 
#include <QTextStream>
#include <QDebug>
#include <vector>
#include <numeric>

// exception handling omitted for clarity.
int summation(std::vector<int> numbers)
{
	int ret = 0;
	qDebug() << "Calculating summation in thread with id = " << QThread::currentThreadId();

	// TODO: add your code to calculate the summation
	ret = std::accumulate(numbers.begin(), numbers.end(), 0);
	return ret;
}

int main()
{
	qDebug() << "Hello from main thread with id = " << QThread::currentThreadId();

	qDebug() << "Starting another thread.";

	std::vector<int> numbers = { 7, 5, 16, 8 };

	int result = 0;
	
	QFuture<int> future = QtConcurrent::run(summation, numbers);
	
	// TODO: add your code to generate another thread, 
	// ask it to call the function summation, and get the result back.
	// You may refer to qt_concurrent_ex3.cpp as an example
	
	result = future.result();

	qDebug() << "Calculated sum is " << result;
  
	return 0;
}
