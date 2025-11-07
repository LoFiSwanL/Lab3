#pragma once
#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <syncstream>
#include <barrier>
#include <functional>

inline constexpr int nt = 3;

struct Task {
    char set;
    int index;
};

inline const std::vector<std::vector<Task>> batches = {
    { {'a',1}, {'a',2}, {'d',1} },
    { {'a',3}, {'a',4}, {'d',2} },
    { {'d',3}, {'d',4}, {'d',5} },

    { {'b',1}, {'b',2}, {'e',1} },
    { {'b',3}, {'b',4}, {'e',2} },
    { {'b',5}, {'b',6}, {'e',3} },
    { {'c',1}, {'c',2}, {'e',4} },
    { {'c',3}, {'c',4}, {'e',5} },
    { {'e',6}, {'e',7}, {'e',8} },

    { {'f',1}, {'f',2}, {'i',1} },
    { {'f',3}, {'f',4}, {'i',2} },
    { {'f',5}, {'f',6}, {'i',3} },
    { {'f',7}, {'f',8}, {'i',4} },

    { {'h',1}, {'h',2}, {'g',1} },
    { {'h',3}, {'h',4}, {'g',2} },
    { {'h',5}, {'h',6}, {'g',3} },
    { {'h',7}, {'g',4}, {'g',5} },

    { {'k',1}, {'k',2}, {'k',3} },
    { {'k',4}, {'k',5}, {'k',6} },
    { {'k',7}, {'k',8}, {'j',1} },
    { {'j',2}, {'j',3}, {'j',4} },
    { {'j',5} }
};

void f(char set, int index);

void w(int id, std::barrier<>& sync_point);
