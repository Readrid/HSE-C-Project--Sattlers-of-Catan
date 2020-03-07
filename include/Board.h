#ifndef _BOARDS_H_
#define _BOARDS_H_

#include <vector>
#include <unordered_map>
#include <memory>

const int BOARDSIZE = 5;
const int TERRITORIESNUM = 6;
const int VERTEXNUM = 54;
const int FIELDHEIGHT = 11;
const int FIELDWIDTH = 21;

enum class PlayerNum {
    NONE,
    GAMER1,
    GAMER2,
    GAMER3
};

enum class Resource {
    NONE,
    WOOL, //овцы
    ORE,
    CLAY, //глина
    TREE,
    WHEAT //пшеница
};

enum class Settlement {
    NONE,
    VILLAGE,
    CITY
};

enum class BuildingType {
    NONE,
    SETTLEMENT,
    ROAD
};

class Cell {
public:
    Cell(BuildingType type);

    PlayerNum getPlayer() const;
    void setPlayer(PlayerNum new_player);

    size_t getVertexNum() const;
    size_t getRoadsNum() const;
    std::pair<int, int> getRoad(int i) const;
    std::pair<int, int> getVertex(int i) const;
    BuildingType getType() const;

protected:

    BuildingType type = BuildingType::NONE;
    PlayerNum player = PlayerNum::NONE;
    std::vector<std::pair<int, int>> vertexes;
    std::vector<std::pair<int, int>> roads;
};

class Vertex : public Cell {
public:
    Vertex(int x, int y, bool direction);

    Settlement getSettlement() const;
    void setSettlement(Settlement new_s);

private:
    Settlement s = Settlement::CITY;
};

class Road : public Cell {
public:
    Road(int x, int y, bool is_horizontal, bool is_even);

};

class Hexagon : public Cell {
public:
    Hexagon(int x, int y);

    void setRobbers();
    Resource getResource() const;
    int getNum() const;

private:
    Resource re;
    int num;
    bool robbers;
};

class Player {
public:
    Player(PlayerNum id);

    void giveResource(Resource re, int num);
    void getResource(Resource re, int num);

private:
    PlayerNum id;
    int victory_points = 0;
    std::unordered_map<Resource, int> cards;
    // TODO: std::vector<DevCard>;
};

class Catan {
public:
    Catan();

    void setRobbers(int hex_num);
    void settle(Settlement s, PlayerNum player, int x, int y);
    void setRoad(PlayerNum player, int x, int y);

    bool canBuild(BuildingType mod, PlayerNum player, int x, int y) const;

    const std::unique_ptr<Cell>& getFieldCell(int x, int y) const;

private:
    std::vector<std::vector<std::unique_ptr<Cell>>> field;
    std::vector<Hexagon*> hexes;
    std::unordered_map<PlayerNum, std::unique_ptr<Player>> players;
    int robbers_hex;
    PlayerNum cur_player;
};

#endif