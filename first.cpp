#include "second.h"
#include <chrono>
#include <thread>

using namespace std;

void f(char set, int index) {
    this_thread::sleep_for(chrono::milliseconds(50));
    osyncstream(cout)
        << "З набору " << set << " виконано дію " << index << ".\n";
}

void w(int id, barrier<>& sync_point) {
    for (const auto& batch : batches) {
        if (id < static_cast<int>(batch.size())) {
            f(batch[id].set, batch[id].index);
        }
        sync_point.arrive_and_wait();
    }
}
