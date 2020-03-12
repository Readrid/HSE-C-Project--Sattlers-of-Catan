#include <iostream>
#include "Board.h"

int main() {
    Catan wow;
    std::cout << "Second Compile!\n";
    std::cout << wow.canBuild(BuildingType::VILLAGE, PlayerNum::GAMER1, 1, 8) << '\n';
    std::cout << wow.trade(Resource::TREE, Resource::WHEAT) << '\n';
    return 0;
}