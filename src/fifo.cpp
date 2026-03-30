#include <iostream>
#include <vector>
#include "../include/fifo.h"

void printFramesFIFO(const std::vector<int>& memory, int frames)
{
    std::cout << "Frames: ";
    for(int i = 0; i < frames; i++)
    {
        if(i < memory.size())
            std::cout << "[" << memory[i] << "] ";
        else
            std::cout << "[ ] ";
    }
    std::cout << std::endl;
}

int fifoPageReplacement(const std::vector<int>& pages, int frames)
{
    std::vector<int> memory;
    int pointer = 0;
    int faults = 0;

    for(int page : pages)
    {
        bool hit = false;

        for(int m : memory)
        {
            if(m == page)
            {
                hit = true;
                break;
            }
        }

        if(hit)
        {
            std::cout << "Page " << page << " -> HIT\n";
        }
        else
        {
            std::cout << "Page " << page << " -> FAULT\n";
            faults++;

            if(memory.size() < frames)
            {
                memory.push_back(page);
            }
            else
            {
                memory[pointer] = page;
                pointer = (pointer + 1) % frames;
            }
        }

        printFramesFIFO(memory, frames);
    }

    return faults;
}