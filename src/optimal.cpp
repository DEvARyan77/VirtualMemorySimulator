#include <iostream>
#include <vector>
#include <algorithm>
#include "../include/optimal.h"

void printFramesOptimal(const std::vector<int>& memory, int frames)
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

int optimalPageReplacement(const std::vector<int>& pages, int frames)
{
    std::vector<int> memory;
    int faults = 0;

    for(int i = 0; i < pages.size(); i++)
    {
        int page = pages[i];

        if(std::find(memory.begin(), memory.end(), page) != memory.end())
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
                int farthest = -1;
                int replaceIndex = -1;

                for(int j = 0; j < memory.size(); j++)
                {
                    int k;
                    for(k = i + 1; k < pages.size(); k++)
                    {
                        if(memory[j] == pages[k])
                            break;
                    }

                    if(k > farthest)
                    {
                        farthest = k;
                        replaceIndex = j;
                    }
                }

                memory[replaceIndex] = page;
            }
        }

        printFramesOptimal(memory, frames);
    }

    return faults;
}