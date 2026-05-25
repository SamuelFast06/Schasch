#ifndef POSITION_HPP
#define POSITION_HPP

#include <string>

using std::string;
class Position{
private: 
    int x; //Buchstaben a - h
    int y; //Zahlen 1 - 8

public:
    //Getter
    void getX();
    void getY();
    //
    //Setter
    void setPosition(int x, int y);
    int setPosition(string pos);
};

#endif