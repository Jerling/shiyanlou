#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <chrono>
#include <condition_variable>

void foo() {
  std::cout << "Hello world" << std::endl;
}

int main(void)
{
  std::thread t(foo);
  t.join();

  std::queue<int> producted_nums;
  std::mutex m;
  std::condition_variable cond_var;
  bool done = false;
  bool notified = false;

  std::thread producer([&](){
    for (int i = 0; i < 5; i++) {
      std::this_thread::sleep_for(std::chrono::seconds(1));
      std::unique_lock<std::mutex> lock(m); // 创建互斥锁
      std::cout << "producing " << i << std::endl;
      producted_nums.push(i);
      notified = true;
      cond_var.notify_one();               // 通知一个线程
    }
    done = true;
    cond_var.notify_one();
  });

  std::thread consumer([&](){
      std::unique_lock<std::mutex> lock(m);
      while(!done){
        while (!notified) {               // 循环避免虚假唤醒
          cond_var.wait(lock);
        }
        while (!producted_nums.empty()) {
          std::cout << "consuming " << producted_nums.front() << std::endl;
          producted_nums.pop();
        }
        notified = false;
      }
  });

  producer.join();
  consumer.join();
  return 0;
}
