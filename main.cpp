#include "second.h"
#include <vector>
#include <thread>

using namespace std;

int main() {
    osyncstream(cout) << "Обчислення розпочато.\n";

    barrier sync_point(nt);

    vector<jthread> threads;
    threads.reserve(nt);
    for (int i = 0; i < nt; ++i) {
        threads.emplace_back(w, i, ref(sync_point));
    }

    for (auto &t : threads) {
        if (t.joinable()) t.join();
    }

    osyncstream(cout) << "Обчислення завершено.\n";

    return 0;
}
