#include <iostream>
#include <vector>

#include "../include/fifo.h"
#include "../include/lru.h"
#include "../include/optimal.h"

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

    return 0;
}