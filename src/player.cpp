#include "include/player.hpp"

void Player::surrender() {
    cout << this->name << " surrendered!\nThe game is finished!" << endl;

    exit(0);
}

void Player::offerDraw() {
    cout << this->name << "offers a draw." << endl

    do {
        cout << "Accept? [y/n]" << endl;
        char buffer;
        cin >> buffer;
    } while (buffer != 'y' && buffer != 'Y' && buffer != 'n' && buffer != 'N');

    if (buffer == 'y' || buffer == 'Y') {
        cout << "The draw got accepted ant the game is finished!" << endl;
        exit(0);
    } else {
        cout << "The draw got denied and the game continues!" << endl;
    }
}

Figure& Player::chooseFigure() {
    cout << "Choose the figure you want to move with providing the current position of the figure e.g. 'A1': " << endl;

    string buffer;
    cin >> buffer;

    bool chooseValid = false
    Position chosenPosition;
    
    do {
        if (buffer.length() != 2 || !Position::positionValid(buffer)) {
            cout << "Invalid position. Please provide a string of the form [A-H][1-8]" << endl;
            cin >> buffer;
            continue;
        }

        chosenPosition = Position(buffer);

        if (!this->figureOnPosition(position)) {
            cout << "You don't have a figure on position " << position << "." << endl;
            continue;
        }

        choseValid = true;
    } while(chooseValid == false)

    for (Figure* figure: this->figures) {
        if (figure->position == chosenPosition) {
            return *figure;
        }
    }
}

bool Player::figureOnPosition(const Position& pos) {
    for (Figure* figure: this->figures) {
        if (figure->position == position) {
            return true;
        }
    }

    return false;
}

void Player::moveFigure(Figure& figure, Player& otherPlayer) {
    cout << "You are moving " << figure->name << "." << endl;

    vector<Position> possibleMoves = this->getPossibleMoves(figure, otherPayer);
    bool validInput = false;
    do {
        cout << "Please enter a valid position to move the figure." << endl;
        string buffer;
        cin >> buffer;

        if (buffer.length() != 2 || !Position::positionValid(buffer)) {
            continue;
        }

        Position movePosition(buffer);

        figure.position = movePosition;

        otherPlayer->kickFigure(movePosition);
    } while (validInput == false);
}

vector<Position> getPossibleMoves(const Figure& figure, const Player& otherPlayer) {
    vector<Position> moves = figure.getPossibleMoves();

    for (unsigned i = 0; i < moves.length(), i++) {
        if (this.figureOnPosition(moves[i])) {
            moves.erase(moves.begin() + i);
        }
    }

    return moves;
}

void Player::kickFigure(const Position& position) {
    for (Figure* figure: this->figures) {
        if (figure->position == position) {
            figure->alive = false
        }
    }
}

bool checkCheck(Player& other) {
    Position kingPos;

    for (Figure* figure: this->figures) {
        if (type == KING) {
            kingPos = figure->position;
            break;
        }
    }

    for (Figure* figure: *(other->getFigures())) {
        vector<Position> posssibleMoves = figure->getPossibleMoves();

        for(Position position: possibleMoves) {
            if (position == kingPos) {
                return true;
            }
        }
    }

    return false;
}

vector<Figure*>* Player::getFigures() {
    return &this->figures;
}