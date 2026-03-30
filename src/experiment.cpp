#include <iostream>
#include <vector>
#include "../include/fifo.h"
#include "../include/lru.h"
#include "../include/optimal.h"
#include "../include/experiment.h"

void runBeladyExperiment(const std::vector<int>& pages, int maxFrames)
{
    std::cout << "\nFrame Size vs Page Faults\n";
    std::cout << "---------------------------------\n";
    std::cout << "Frames\tFIFO\tLRU\tOptimal\n";

    for(int frames = 1; frames <= maxFrames; frames++)
    {
        int fifoFaults = fifoPageReplacement(pages, frames);
        int lruFaults = lruPageReplacement(pages, frames);
        int optimalFaults = optimalPageReplacement(pages, frames);

        std::cout << frames << "\t"
                  << fifoFaults << "\t"
                  << lruFaults << "\t"
                  << optimalFaults << "\n";
    }
}