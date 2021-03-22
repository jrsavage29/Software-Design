/*
* Starter code for exercise 15
*/
#include <vector>
#include <mutex>
#include <condition_variable>

template<typename T>
class ThreadSafeVector
{
public:
	bool empty() const;
	void push_back(const T& value);
	bool try_pop_back(T& popped_value);
	void wait_pop_back(T& popped_value);
private:
	std::vector<T>the_vector;
	mutable std::mutex the_mutex;
	std::condition_variable the_condition_variable;
};

template<typename T>
bool ThreadSafeVector<T>::empty() const
{
	std::lock_guard<std::mutex> lock(the_mutex);

	return the_vector.empty();

	// unlock is unnecessary
}

template<typename T>
void ThreadSafeVector<T>::push_back(const T& value)
{
	std::unique_lock<std::mutex> lock(the_mutex);

	the_vector.push_back(value);

	lock.unlock();
	the_condition_variable.notify_one();
}

template<typename T>
bool ThreadSafeVector<T>::try_pop_back(T& popped_value)
{
	std::lock_guard<std::mutex> lock(the_mutex);

	if (the_vector.empty()) {
		return false;
	}

	popped_value = the_vector.back();
	the_vector.pop_back();

	return true;
}

template<typename T>
void ThreadSafeVector<T>::wait_pop_back(T& popped_value)
{
	std::unique_lock<std::mutex> lock(the_mutex);

	while (the_vector.empty()) {
		the_condition_variable.wait(lock);
	}

	popped_value = the_vector.back();
	the_vector.pop_back();
}