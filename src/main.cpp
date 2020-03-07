#include <iostream>
#include "Board.h"

int main() {
    Catan wow;
    std::cout << "Second Compile!\n";
    std::cout << wow.canBuild(BuildingType::SETTLEMENT, PlayerNum::GAMER1, 1, 8) << '\n';
    return 0;
}