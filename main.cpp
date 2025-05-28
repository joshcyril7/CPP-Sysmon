#include <iostream>
#include <thread>
#include <chrono>
#include <ncurses.h>
#include "cpu.hpp"
#include "memory.hpp"

void drawBar(const std::string& label, float percent, int y) {
    int width = COLS - 20;
    int filled = percent * width / 100;

    mvprintw(y, 0, "%s: %5.1f%% [", label.c_str(), percent);
    for (int i = 0; i < width; ++i)
        addch(i < filled ? '#' : ' ');
    printw("]");
}

int main() {
    initscr();
    noecho();
    curs_set(FALSE);

    CPUStats prev = readCPUStats();

    while (true) {
        CPUStats curr = readCPUStats();
        float cpuUsage = calculateCPUUsage(prev, curr);
        prev = curr;

        MemoryInfo mem = readMemoryInfo();
        float memUsage = 100.0f * (mem.total - mem.available) / mem.total;

        clear();
        drawBar("CPU", cpuUsage, 2);
        drawBar("Mem", memUsage, 4);
        mvprintw(6, 0, "Press Ctrl+C to exit.");
        refresh();

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    endwin();
    return 0;
}
