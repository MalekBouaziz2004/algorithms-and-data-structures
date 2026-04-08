// ADS Praktikum 1.1 Printer
// Name: Max Mustermann
#pragma once
#include <queue>

class Printer
{
    std::priority_queue<Job> jobs;
    int queueSize;
public:
    Printer(int size);
    bool addNewJob(const Job& job);
    void startPrinting();
};