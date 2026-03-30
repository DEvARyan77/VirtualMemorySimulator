#include <iostream>
#include <vector>
#include <fstream>

#include "../include/fifo.h"
#include "../include/lru.h"
#include "../include/optimal.h"

void runBeladyExperiment(const std::vector<int>& pages)
{
    int maxFrames;

    std::cout << "\nEnter maximum frame size for experiment: ";
    std::cin >> maxFrames;

    std::ofstream file("results.txt");

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

        file << frames << " "
             << fifoFaults << " "
             << lruFaults << " "
             << optimalFaults << "\n";
    }

    file.close();

    std::cout << "\nExperiment results saved to results.txt\n";
}

int main()
{
    int frames;
    int n;

    std::cout << "Enter number of frames: ";
    std::cin >> frames;

    std::cout << "Enter number of pages: ";
    std::cin >> n;

    std::vector<int> pages(n);

    std::cout << "Enter page reference sequence:\n";

    for(int i = 0; i < n; i++)
    {
        std::cin >> pages[i];
    }

    std::cout << "\n===== FIFO Simulation =====\n";
    int fifoFaults = fifoPageReplacement(pages, frames);

    std::cout << "\n===== LRU Simulation =====\n";
    int lruFaults = lruPageReplacement(pages, frames);

    std::cout << "\n===== Optimal Simulation =====\n";
    int optimalFaults = optimalPageReplacement(pages, frames);

    std::cout << "\n===== Summary =====\n";

    std::cout << "FIFO Faults: " << fifoFaults << std::endl;
    std::cout << "LRU Faults: " << lruFaults << std::endl;
    std::cout << "Optimal Faults: " << optimalFaults << std::endl;

    char choice;

    std::cout << "\nRun Belady's Anomaly Experiment? (y/n): ";
    std::cin >> choice;

    if(choice == 'y' || choice == 'Y')
    {
        runBeladyExperiment(pages);
    }

    return 0;
}