// usedma.cpp -- inheritance, friends, and DMA
// compile with dma.cpp
#include <iostream>
#include "dma.h"
int main()
{
    using std::cout;
    using std::endl;

	dmaABC * pABC[3];
    baseDMA shirt("Portabelly", 8);
    lacksDMA balloon("red", "Blimpo", 4);
    hasDMA map("Mercator", "Buffalo Keys", 5);
    pABC[0]=&shirt;
    pABC[1]=&balloon;
    pABC[2]=&map;
    
    
	cout << "Displaying baseDMA object:\n";
    pABC[0]->View();
    cout << "Displaying lacksDMA object:\n";
    pABC[1]->View();
    cout << "Displaying hasDMA object:\n";
    pABC[2]->View();
    lacksDMA balloon2(balloon);
    cout << "Result of lacksDMA copy:\n";
    cout << balloon2 << endl;
    hasDMA map2;
    map2 = map;
    cout << "Result of hasDMA assignment:\n";
    cout << map2 << endl;
    // std::cin.get();
    return 0; 
}
