/************************************************************************
** Program name:  Space Class Declaration
** Author:        Patrick Oh
** Date:          06/11/19
** Description:   This file contains the class declaration for the
**                Space parent class.
************************************************************************/
#ifndef FINAL_SPACE_HPP
#define FINAL_SPACE_HPP

#include <string>
#include "Player.hpp"


class Space
{
public:
    explicit Space(Player*);
    virtual ~Space();
    void setUp(Space*);
    void setDown(Space*);
    void setRight(Space*);
    void setLeft(Space*);
    Space* getUp();
    Space* getDown();
    Space* getRight();
    Space* getLeft();
    void setName(std::string);
    std::string getName();
    void setPlayer(Player*);
    Player* getPlayer();
    virtual void prompt_ActionsMenu();
    virtual void enterRoom();

protected:
    Player* player;
    std::string name;
    Space* up;
    Space* down;
    Space* right;
    Space* left;
    int visits;
};


#endif //FINAL_SPACE_H
