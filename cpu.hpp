#pragma once
#include <vector>
#include <string>

struct CPUStats {
    long long user, nice, system, idle, iowait, irq, softirq, steal;

    long long total() const;
    long long active() const;
};

CPUStats readCPUStats();
float calculateCPUUsage(const CPUStats& prev, const CPUStats& curr);
