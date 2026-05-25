#ifndef FIGURE_HPP
#define FIGURE_HPP

#include "position.hpp"

#include <string>
#include <vector>


using std::string, std::vector;

class Figure{ //Figuren-Klasse
protected:
    string name;
    string id;
    Position position;
    Position startingPosition;
    int value;
public:
    virtual vector<Position> getPossibleMove();
    int move(Position pos);
};

class Pawn:public Figure{ //Bauer-Klasse
public: 
    vector<Position> getPossibleMove();
    int move(Position pos);
};
class Knight:public Figure{ //Pferd-Klasse
public: 
    vector<Position> getPossibleMove();
    int move(Position pos);
};
class Bishop:public Figure{ //Laeufer-Klasse
public: 
    vector<Position> getPossibleMove(); 
    int move(Position pos);
};
class Rook:public Figure{ //Turm-Klasse
public: 
    vector<Position> getPossibleMove();
    int move(Position pos);
};
class Queen:public Figure{ //Koenigin-Klasse
public: 
    vector<Position> getPossibleMove();
    int move(Position pos);
};
class King:public Figure{ //Koenig-Klasse
public: 
    vector<Position> getPossibleMove();
    int move(Position pos);
};

#endif