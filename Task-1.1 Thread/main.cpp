//
//  main.cpp
//  Task-1.1 Thread
//
//  Created by Маргарет  on 07.05.2024.
//

#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;
int client_count = 0;

void client(int max_num) {
    for (int i = 0; i < max_num; i++) {
        std::this_thread::sleep_for(1000ms);
        client_count += 1;
        std::cout << "Клиент зашел в очередь: client_count = " << client_count << "\n";
    }
}

void operat(int max_num) {
    for (int i = 0; i < max_num; i++) {
        std::this_thread::sleep_for(2000ms);
        client_count -= 1;
        std::cout << "Запрос клинта обработан: client_count = " << client_count << "\n";
    }
}


int main(int argc, const char * argv[]) {
    std::thread th1(client, 10);
    std::thread th2(operat, 10);
    th1.join();
    th2.join();
    std::cout << "Итоговое состояние счетчика клиентов: " << client_count << "\n";
    
    
    return 0;
}
