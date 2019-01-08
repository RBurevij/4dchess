#ifndef PIECE_H
#define PIECE_H
#define WHITE 1
#define BLACK 0
#define NOCOLOR 3
#define NONE 0
#define PAWN 1
#define ROOK 2
#define KNIGHT 3
#define BISHOP 4
#define QUEEN 5
#define KING 6
#include "SFML/Graphics.hpp"


class Piece
{
    public:
        Piece(){};
        virtual ~Piece(){};
        bool virtual moveLegality(int i, int j, int k ,int w, int ii, int jj, int kk, int ww, Piece* board[4][4][4][4]){return false;};
        int color; 
        bool nihil;
        sf::Texture texture;
        sf::Sprite sprite;
};

class Pawn : public Piece{
    public:
        Pawn(bool side);
        ~Pawn(){};
        bool moveLegality(int i, int j, int k, int w, int ii, int jj, int kk, int ww, Piece* board[4][4][4][4]);
        bool flag;
};

class Rook : public Piece{
    public:
        Rook(bool side);
        ~Rook(){};
        bool moveLegality(int i, int j, int k, int w, int ii, int jj, int kk, int ww, Piece* board[4][4][4][4]);
};


class Knight : public Piece{
    public:
        Knight(bool side);
        ~Knight(){};
        bool moveLegality(int i, int j, int k, int w, int ii, int jj, int kk, int ww, Piece* board[4][4][4][4]);
};

class Bishop : public Piece{
    public:
        Bishop(bool side);
        ~Bishop(){};
        bool moveLegality(int i, int j, int k, int w, int ii, int jj, int kk, int ww, Piece* board[4][4][4][4]);
};

class Queen : public Piece{
    public:
        Queen(bool side);
        ~Queen(){};
        bool moveLegality(int i, int j, int k, int w, int ii, int jj, int kk, int ww, Piece* board[4][4][4][4]);
};

class King : public Piece{
    public:
        King(bool side);
        ~King(){};
        bool moveLegality(int i, int j, int k, int w, int ii, int jj, int kk, int ww, Piece* board[4][4][4][4]);
};

class Empty : public Piece{
public:
    Empty(){nihil = 1; color = NOCOLOR};
    ~Empty(){};
};

#endif // PIECE_H
