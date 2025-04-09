#include "Box.h"

#include "Universe.h"

int main()
{

    int N = 1000;
    auto box = Box();
    box.xWidth = 2.0;
    box.yWidth = 2.0;
    box.zWidth = 2.0;
    auto uni = Universe(box,N);

    uni.dumpInitial();


    return 0;
}