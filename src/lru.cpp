#include <iostream>
#include <vector>
#include <algorithm>
#include "../include/lru.h"

void printFramesLRU(const std::vector<int>& memory, int frames)
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

int lruPageReplacement(const std::vector<int>& pages, int frames)
{
    std::vector<int> memory;
    std::vector<int> recent;
    int faults = 0;

    for(int page : pages)
    {
        auto it = std::find(memory.begin(), memory.end(), page);

        if(it != memory.end())
        {
            std::cout << "Page " << page << " -> HIT\n";

            recent.erase(std::remove(recent.begin(), recent.end(), page), recent.end());
            recent.push_back(page);
        }
        else
        {
            std::cout << "Page " << page << " -> FAULT\n";
            faults++;

            if(memory.size() < frames)
            {
                memory.push_back(page);
                recent.push_back(page);
            }
            else
            {
                int lruPage = recent.front();
                recent.erase(recent.begin());

                auto replaceIndex = std::find(memory.begin(), memory.end(), lruPage);
                *replaceIndex = page;

                recent.push_back(page);
            }
        }

        printFramesLRU(memory, frames);
    }

    return faults;
}