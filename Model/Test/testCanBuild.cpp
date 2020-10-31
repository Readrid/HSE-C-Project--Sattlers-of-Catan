#include "gtest/gtest.h"
#include "../Board.h"
#include "../Utility/random.h"

using utility::Random;
using namespace Board;


TEST(canBuildTest, simpleVillageCase) {
    Random random;
    Catan board(random, 3);
    board.settle(BuildingType::VILLAGE, 8, 6);
    board.settle(BuildingType::ROAD, 8, 7);
    board.changeCurPlayer(PlayerNum::GAMER2);
    ASSERT_EQ(board.canBuild(BuildingType::VILLAGE, 8, 4), false);
    ASSERT_EQ(board.canBuild(BuildingType::VILLAGE, 8, 2), true);
}

TEST(canBuildTest, nearEnemyVillageCase) {
    Random random;
    Catan board(random, 3);
    board.settle(BuildingType::VILLAGE, 8, 6);
    board.settle(BuildingType::ROAD, 8, 7);
    board.settle(BuildingType::ROAD, 8, 9);
    board.changeCurPlayer(PlayerNum::GAMER2);
    ASSERT_EQ(board.canBuild(BuildingType::VILLAGE, 8, 10), true);
}

TEST(canBuildTest, afterBeginningVillageCase) {
    Random random;
    Catan board(random, 3);
    board.settle(BuildingType::VILLAGE, 8, 6);
    board.settle(BuildingType::ROAD, 8, 7);
    board.settle(BuildingType::ROAD, 8, 9);
    board.gotoNextGamePhase();
    ASSERT_EQ(board.canBuild(BuildingType::VILLAGE, 8, 10), true);
    ASSERT_EQ(board.canBuild(BuildingType::VILLAGE, 8, 18), false);
}

TEST(canBuildTest, simpleCityCase) {
    Random random;
    Catan board(random, 3);
    board.settle(BuildingType::VILLAGE, 8, 6);
    board.changeCurPlayer(PlayerNum::GAMER2);
    board.settle(BuildingType::VILLAGE, 4, 4);
    ASSERT_EQ(board.canBuild(BuildingType::CITY, 8, 6), false);
    ASSERT_EQ(board.canBuild(BuildingType::CITY, 4, 4), true);
}

TEST(canBuildTest, simpleRoadCase) {
    Random random;
    Catan board(random, 3);
    board.settle(BuildingType::VILLAGE, 8, 6);
    board.settle(BuildingType::ROAD, 8, 7);
    board.changeCurPlayer(PlayerNum::GAMER2);
    board.settle(BuildingType::VILLAGE, 8, 10);
    ASSERT_EQ(board.canBuild(BuildingType::ROAD, 8, 9), true);
    ASSERT_EQ(board.canBuild(BuildingType::ROAD, 8, 7), false);
    ASSERT_EQ(board.canBuild(BuildingType::ROAD, 4, 7), false);
}

TEST(canBuildTest, fromRulesRoadCase) {
    Random random;
    Catan board(random, 3);
    board.settle(BuildingType::VILLAGE, 8, 6);
    board.settle(BuildingType::ROAD, 7, 6);
    board.changeCurPlayer(PlayerNum::GAMER2);
    board.settle(BuildingType::VILLAGE, 8, 10);
    board.settle(BuildingType::ROAD, 8, 9);
    ASSERT_EQ(board.canBuild(BuildingType::ROAD, 8, 7), true);
    board.settle(BuildingType::ROAD, 8, 7);
    ASSERT_EQ(board.canBuild(BuildingType::ROAD, 9, 8), true);
    ASSERT_EQ(board.canBuild(BuildingType::ROAD, 7, 10), true);
    ASSERT_EQ(board.canBuild(BuildingType::ROAD, 8, 11), true);
    ASSERT_EQ(board.canBuild(BuildingType::ROAD, 9, 8), true);
    ASSERT_EQ(board.canBuild(BuildingType::ROAD, 8, 5), false);
}
