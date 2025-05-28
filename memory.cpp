#include "memory.hpp"
#include <fstream>
#include <string>

MemoryInfo readMemoryInfo() {
    std::ifstream file("/proc/meminfo");
    std::string label;
    long long value;
    std::string unit;

    MemoryInfo mem{};
    while (file >> label >> value >> unit) {
        if (label == "MemTotal:") mem.total = value;
        if (label == "MemAvailable:") mem.available = value;
        if (mem.total && mem.available) break;
    }
    return mem;
}
