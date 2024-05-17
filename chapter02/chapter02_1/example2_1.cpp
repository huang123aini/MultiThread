#include <iostream>
#include <thread>

int main(int argc, char* argv[]) {
  std::thread t([](){
    for(int i = 0; i < 10; i++) {
       std::cout << "i: " << i << std::endl;
    }
  });
  t.detach(); //不等待线程完成
  std::cout << "main func." << std::endl;
  return 0;
}
