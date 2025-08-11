#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player{
    private:
        string name;
        int id;
    public:
        Player(const string &name, int id);
        string showName();
};

#endif