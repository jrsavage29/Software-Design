// qt_shared_deque_2.cpp
#include <iostream>
#include <cassert>

#include "shared_ring_buffer.h"

int main(int argc, char *argv[])
{
  SharedRingBuffer<int> buffer;

  buffer.create(100);

  while(true){
    if(buffer.getCount() == 0){
		int i;
		std::cout << "Enter a value to be enqueued: ";
		std::cin >> i;
      //int value = 3;
      buffer.enqueue(i);
      std::cout << "Enqueued: " << i << std::endl;
      //break;
    }
  }

  return 0;
}
