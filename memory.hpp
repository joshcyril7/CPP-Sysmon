#pragma once

struct MemoryInfo {
    long long total;
    long long available;
};

MemoryInfo readMemoryInfo();
