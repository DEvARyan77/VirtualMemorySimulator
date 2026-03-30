#ifndef PAGER_H
#define PAGER_H

#include <vector>
#include <iostream>

class Pager {
private:
    int framesCount;
    std::vector<int> frames;
    int pageFaults;

public:
    Pager(int framesCount);

    void accessPage(int page);
    void printFrames();
    void printStats();
};

#endif

Pager::Pager(int framesCount)
{
    this->framesCount = framesCount;
    pageFaults = 0;
}

void Pager::accessPage(int page)
{
    for(int f : frames)
    {
        if(f == page)
        {
            std::cout << "Page " << page << " -> HIT\n";
            printFrames();
            return;
        }
    }

    pageFaults++;

    if(frames.size() < framesCount)
        frames.push_back(page);
    else
        frames[0] = page;

    std::cout << "Page " << page << " -> FAULT\n";
    printFrames();
}

void Pager::printFrames()
{
    std::cout << "Frames: ";

    for(int f : frames)
        std::cout << "[" << f << "] ";

    for(int i = frames.size(); i < framesCount; i++)
        std::cout << "[ ] ";

    std::cout << "\n\n";
}

void Pager::printStats()
{
    std::cout << "\nTotal Page Faults: " << pageFaults << "\n";
}