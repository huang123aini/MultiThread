#include <iostream>
#include <thread>

//使用RAII等待线程完成

class thread_guard {
 public:
   explicit thread_guard(std::thread& t_): t(t_) {}
   
   ~thread_guard(){
     if(t.joinable()) {
       std::cout << "RAII destructor. " << std::endl;
       t.join();
     }
   }
   
   thread_guard(const thread_guard&) = delete;
   thread_guard& operator = (const thread_guard & ) = delete;
 private:
   std::thread& t;
};


void PrintFunc() {
  for(int i = 0; i < 10; i++) {
   std::cout << "i: " << i << std::endl;
  }
}


void func() {

   std::thread t(PrintFunc);
   thread_guard g(t); //在当前线程执行到func尾部时，局部对象会按照析构函数的逆序被销毁，因此， thread_guard对象g首先被销毁
}

int main(int argc, char* argv[]) {

  func();
  return 0;
}

