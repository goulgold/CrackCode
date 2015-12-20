#include <iostream>                // std::cout
#include <thread>                // std::thread
#include <mutex>                // std::mutex, std::unique_lock
#include <condition_variable>    // std::condition_variable
using namespace std;

int total = 1000;

void minus_one() {
    total--;
}

int main() {
    thread th[1000];
    cout << "total: " << total << endl;
    for (int i = 0; i < 1000; ++i) {
        th[i] = thread(minus_one);
    }
    cout << "total: " << total << endl;
    for (int i = 0; i < 1000; ++i) {
        th[i].join();
    }
    return 0;
}
