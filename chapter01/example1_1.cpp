#include <iostream>
#include <thread>

//join函数是让调用线程等待直到该子线程执行结束
//需要注意的是线程对象执行了join后就不再joinable了，所以只能调用join一次。

void hello() {
  std::cout << "Hello Concurrent World." << std::endl;
}

int main(int argc, char* argv[]) {
  std::thread t(hello);
  if(t.joinable()) {
   t.join();
  }
  
  std::cout << "main func" << std::endl;
  return 0;
}
