#include "cpu.hpp"
#include <fstream>
#include <sstream>

CPUStats readCPUStats() {
    std::ifstream file("/proc/stat");
    std::string line;
    std::getline(file, line); // cpu line

    std::istringstream ss(line);
    std::string cpu;
    CPUStats stats;

    ss >> cpu >> stats.user >> stats.nice >> stats.system >> stats.idle
       >> stats.iowait >> stats.irq >> stats.softirq >> stats.steal;

    return stats;
}

long long CPUStats::total() const {
    return user + nice + system + idle + iowait + irq + softirq + steal;
}

long long CPUStats::active() const {
    return user + nice + system + irq + softirq + steal;
}

float calculateCPUUsage(const CPUStats& prev, const CPUStats& curr) {
    long long totalDelta = curr.total() - prev.total();
    long long activeDelta = curr.active() - prev.active();
    return 100.0f * activeDelta / totalDelta;
}
