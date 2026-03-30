#include <iostream>
#include "pager.h"

int main() {

    int frames;
    std::cout << "Enter number of frames: ";
    std::cin >> frames;

    Pager pager(frames);

    int page;

    while(true)
    {
        std::cout << "Enter page number (-1 to stop): ";
        std::cin >> page;

        if(page == -1)
            break;

        pager.accessPage(page);
    }

    pager.printStats();

    return 0;
}