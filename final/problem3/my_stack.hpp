#ifndef _MY_STACK_HPP
#define _MY_STACK_HPP

#include <stack>
#include <mutex>
#include <condition_variable>

class MyStack {
public:
	void push(int value) {
		// TODO: modify this method such that 
		// 1. it is thread-safe
		// 2. if a valued is pushed, wake up a waiting thread
		
		std::unique_lock<std::mutex> lock(the_mutex);

		m_s.push(value);

		lock.unlock();
		
		the_condition_variable.notify_one();
	}

	void pop() {
		// TODO: modify this method to thread-safe
		// If m_s is empty, wait until a value is pushed
		
		std::unique_lock<std::mutex> lock(the_mutex);

		while (m_s.empty()) 
		{
			the_condition_variable.wait(lock);
		}
		
		m_s.pop();
	}

	size_t size() {
		// TODO: modify this method to thread-safe
		std::lock_guard<std::mutex> lock(the_mutex);

		return m_s.size();
	}

private:
	std::stack<int> m_s;
	mutable std::mutex the_mutex;
	std::condition_variable the_condition_variable;
};

#endif // _MY_STACK_HPP
