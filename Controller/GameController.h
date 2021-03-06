#ifndef _GAMECONTROLLER_H_
#define _GAMECONTROLLER_H_

#include <vector>
#include <memory>
#include <random.h>

#include "game.grpc.pb.h"
#include "Board.h"
#include "Client.h"
#include "Client.h"
#include "sdl.h"
#include "EventQueue.h"

namespace Controller {
/**
 * @brief Базовый класс для обработчиков событий
 *
 */
class Handler {
public:
    Handler(Board::Catan& model, GUI::GUI& view, GameClient& client)
    : gameModel_(model)
    , gameView_(view)
    , gameClient_(client) { }
    virtual void processEvent(::game::Event& event, bool needSend) = 0; ///< @brief Вызывает нужные команды у модели
    virtual void displayEvent(::game::Event& event) = 0; ///< @brief Вызывает нужные команды у GUI::GUI
    void sendEvent(::game::Event& event); ///< @brief Вызывает нужные команды у клиента
protected:
    Board::Catan& gameModel_;
    GUI::GUI& gameView_;
    GameClient& gameClient_;
};

class CardHandler : public Handler {
public:
    CardHandler(Board::Catan& model, GUI::GUI& view, GameClient& client, int id)
    : Handler(model, view, client)
    , cardType_(0)
    , myTurn_(id) { }
    void processEvent(::game::Event& event, bool needSend) override;
    void displayEvent(::game::Event& event) override;
    using Handler::sendEvent;
private:
    int cardType_;
    int myTurn_;
};

class DiceHandler : public Handler {
public:
    DiceHandler(Board::Catan& model, GUI::GUI& view, GameClient& client, utility::Random& ran, int id)
    : Handler(model, view, client)
    , number1_(0)
    , number2_(0)
    , random_(ran)
    , myTurn_(id) { }
    void processEvent(::game::Event& event, bool needSend) override;
    void displayEvent(::game::Event& event) override;
    using Handler::sendEvent;
private:
    int number1_;
    int number2_;
    utility::Random& random_;
    int myTurn_;
};

class MarketHandler : public Handler {
public:
    MarketHandler(Board::Catan& model, GUI::GUI& view, GameClient& client, int id)
    : Handler(model, view, client)
    , requiredResource_(0)
    , ownedResource_(0)
    , myTurn_(id){ }
    void processEvent(::game::Event& event, bool needSend) override;
    void displayEvent(::game::Event& event) override;
    using Handler::sendEvent;
private:
    int requiredResource_;
    int ownedResource_;
    int myTurn_;
};

class BuildHandler : public Handler {
public:
    BuildHandler(Board::Catan& model, GUI::GUI& view, GameClient& client, int id)
    : Handler(model, view, client)
    , buildingType_(0)
    , x_(0)
    , y_(0)
    , myTurn_(id){ }
    void processEvent(::game::Event& event, bool needSend) override;
    void displayEvent(::game::Event& event) override;
    using Handler::sendEvent;
private:
    int buildingType_;
    int x_;
    int y_;
    int myTurn_;
};

class EndTurnHandler : public Handler {
public:
    EndTurnHandler(Board::Catan& model, GUI::GUI& view, GameClient& client)
    : Handler(model, view, client) { }
    void processEvent(::game::Event& event, bool needSend) override;
    void displayEvent(::game::Event& event) override;
    using Handler::sendEvent;
};

class NextPhaseHandler : public Handler {
public:
    NextPhaseHandler(Board::Catan& model, GUI::GUI& view, GameClient& client)
    : Handler(model, view, client) { }
    void processEvent(::game::Event& event, bool needSend) override;
    void displayEvent(::game::Event& event) override;
    using Handler::sendEvent;
};

class EndGameHandler : public Handler {
public:
    EndGameHandler(Board::Catan& model, GUI::GUI& view, GameClient& client)
    : Handler(model, view, client) { }
    void processEvent(::game::Event& event, bool needSend) override;
    void displayEvent(::game::Event& event) override;
    using Handler::sendEvent;
};

class GameController final {
public:
    GameController(Board::Catan& model, GameClient& client, GUI::GUI& view, utility::Random& ran, const game::OrderInfo& info);

    GameController(const GameController&) = delete;
    GameController operator=(const GameController&) = delete;

    void RunGame();


private:
    bool BeginGame();

    std::vector<std::unique_ptr<Handler>> handlers_;
    Board::Catan& gameModel_;
    GUI::GUI& gameView_;
    GameClient& gameClient_;
    

    int myTurn_ = 0;
    int currentTurn_ = 0;
    int numberOfPlayers_ = 3;
};

} // namespace Controller

#endif