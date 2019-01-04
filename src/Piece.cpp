#include "Piece.h"
#include "SFML/Graphics.hpp"

Pawn::Pawn(bool side){
    texture.loadFromFile("pieces.png", sf::IntRect(1000, side*200, 200, 200));
    sprite.setTexture(texture);
    sprite.scale(0.165, 0.165);
    sprite.setPosition(20, 565);
    color = side;
    flag = 1;
    nihil = 0;
}

bool Pawn::moveLegality(int i, int j, int k, int w, int ii, int jj, int kk, int ww, Piece* board[4][4][4][4]){
    if (i==ii && j==jj && k==kk && w==ww)
        return false;
    if(color){
    if((i+1) == ii && j == jj && k == kk && w == ww && board[ii][jj][kk][ww]->nihil){
        flag = 0;
        return true;
    }
    if(i == ii && j == jj && k == kk && (w+1) == ww && board[ii][jj][kk][ww]->nihil){
        flag = 0;
        return true;
    }
    if(flag){
        if((i+2) == ii && j == jj && k == kk && w == ww && board[i+1][jj][kk][ww]->nihil && board[i+2][jj][kk][ww]->nihil){
            flag = 0;
            return true;
        }
        if(i == ii && j == jj && k == kk && (w+2) == ww && board[i][jj][kk][w+1]->nihil && board[i][j][k][w+2]->nihil){
            flag = 0;
            return true;
        }
    }
    if(i+1 == ii){
        if(j+1 == jj && k == kk && w==ww && !board[i+1][j+1][k][w]->nihil && color != board[i+1][j+1][k][w]->color)
            return true;
        if(j-1 == jj && k == kk && w==ww && !board[i+1][j-1][k][w]->nihil && color != board[i+1][j+1][k][w]->color)
            return true;
        if(j == jj && k+1 == kk && w==ww && !board[i+1][j][k+1][w]->nihil && color != board[i+1][j][k+1][w]->color)
            return true;
        if(j == jj && k-1 == kk && w==ww && !board[i+1][j][k-1][w]->nihil && color != board[i+1][j][k-1][w]->color)
            return true;
    }
    if(w+1 == ww){
        if(j+1 == jj && k == kk && i==ii && !board[i][j+1][k][w+1]->nihil && color != board[i][j+1][k][w+1]->color)
            return true;
        if(j-1 == jj && k == kk && i==ii && !board[i][j-1][k][w+1]->nihil && color != board[i][j+1][k][w+1]->color)
            return true;
        if(j == jj && k+1 == kk && i==ii && !board[i][j][k+1][w+1]->nihil && color != board[i][j][k+1][w+1]->color)
            return true;
        if(j == jj && k-1 == kk && i==ii && !board[i][j][k-1][w+1]->nihil && color != board[i][j][k-1][w+1]->color)
            return true;
    }
    return false;
    }


    if((i-1) == ii && j == jj && k == kk && w == ww && board[ii][jj][kk][ww]->nihil){
        flag = 0;
        return true;
    }
    if(i == ii && j == jj && k == kk && (w-1) == ww && board[ii][jj][kk][ww]->nihil){
        flag = 0;
        return true;
    }
    if(flag){
        if((i-2) == ii && j == jj && k == kk && w == ww && board[i-1][jj][kk][ww]->nihil && board[i-2][jj][kk][ww]->nihil){
            flag = 0;
            return true;
        }
        if(i == ii && j == jj && k == kk && (w-2) == ww && board[i][jj][kk][w+1]->nihil && board[i][j][k][w-2]->nihil){
            flag = 0;
            return true;
        }
    }
    if(i-1 == ii){
        if(j+1 == jj && k == kk && w==ww && !board[i-1][j+1][k][w]->nihil && color != board[i-1][j+1][k][w]->color)
            return true;
        if(j-1 == jj && k == kk && w==ww && !board[i-1][j-1][k][w]->nihil && color != board[i-1][j+1][k][w]->color)
            return true;
        if(j == jj && k+1 == kk && w==ww && !board[i-1][j][k+1][w]->nihil && color != board[i-1][j][k+1][w]->color)
            return true;
        if(j == jj && k-1 == kk && w==ww && !board[i-1][j][k-1][w]->nihil && color != board[i-1][j][k-1][w]->color)
            return true;
    }
    if(w-1 == ww){
        if(j+1 == jj && k == kk && i==ii && !board[i][j+1][k][w-1]->nihil && color != board[i][j+1][k][w-1]->color)
            return true;
        if(j-1 == jj && k == kk && i==ii && !board[i][j-1][k][w-1]->nihil && color != board[i][j+1][k][w-1]->color)
            return true;
        if(j == jj && k+1 == kk && i==ii && !board[i][j][k+1][w-1]->nihil && color != board[i][j][k+1][w-1]->color)
            return true;
        if(j == jj && k-1 == kk && i==ii && !board[i][j][k-1][w-1]->nihil && color != board[i][j][k-1][w-1]->color)
            return true;
    }
    return false;
}

Rook::Rook(bool side){
    texture.loadFromFile("pieces.png", sf::IntRect(0, side*200, 200, 200));
    sprite.setTexture(texture);
    sprite.scale(0.165, 0.165);
    sprite.setPosition(20, 565);
    color = side;
    nihil = 0;
}

bool Rook::moveLegality(int i, int j, int k, int w, int ii, int jj, int kk, int ww, Piece* board[4][4][4][4]){
    if (i==ii && j==jj && k==kk && w==ww)\
        return false;
    if(i==ii && j==jj && k==kk){
        for(int counter = 1; w+counter<4; counter++){
            if(w+counter == ww && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j][k][w+counter]->nihil)
                break;
        }
        for(int counter = 1; w-counter>=0; counter++){
            if(w-counter == ww && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j][k][w-counter]->nihil)
                break;
        }
    }
    if(i==ii && j==jj && w==ww){
        for(int counter = 1; k+counter<4; counter++){
            if(k+counter == kk && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j][k+counter][w]->nihil)
                break;
        }
        for(int counter = 1; k-counter>=0; counter++){
            if(k-counter == kk && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j][k-counter][w]->nihil)
                break;
        }
    }
    if(i==ii && k==kk && w==ww){
        for(int counter = 1; j+counter<4; counter++){
            if(j+counter == jj && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j+counter][k][w]->nihil)
                break;
        }
        for(int counter = 1; j-counter>=0; counter++){
            if(j-counter == jj && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j-counter][k][w]->nihil)
                break;
        }
    }
    if(j==jj && k==kk && w==ww){
        for(int counter = 1; i+counter<4; counter++){
            if(i+counter == ii && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i+counter][j][k][w]->nihil)
                break;
        }
        for(int counter = 1; i-counter>=0; counter++){
            if(i-counter == ii && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i-counter][j][k][w]->nihil)
                break;
        }
    }
    return false;
}

Knight::Knight(bool side){
    texture.loadFromFile("pieces.png", sf::IntRect(200, side*200, 200, 200));
    sprite.setTexture(texture);
    sprite.scale(0.165, 0.165);
    sprite.setPosition(20, 565);
    color = side;
    nihil = 0;
}

bool Knight::moveLegality(int i, int j, int k, int w, int ii, int jj, int kk, int ww, Piece* board[4][4][4][4]){
    if(i==ii && j==jj && k==kk && w==ww)
        return false;
    if(i+2 == ii){
        if(j+1 == jj && k==kk && w==ww && color != board[i+2][j+1][k][w]->color)
            return true;
        if(j == jj && k+1==kk && w==ww && color != board[i+2][j][k+1][w]->color)
            return true;
        if(j == jj && k==kk && w+1==ww && color != board[i+2][j][k][w+1]->color)
            return true;
        if(j-1 == jj && k==kk && w==ww && color != board[i+2][j-1][k][w]->color)
            return true;
        if(j == jj && k-1==kk && w==ww && color != board[i+2][j][k-1][w]->color)
            return true;
        if(j == jj && k==kk && w-1==ww && color != board[i+2][j][k][w-1]->color)
            return true;
    }
    if(i-2 == ii){
        if(j+1 == jj && k==kk && w==ww && color != board[i-2][j+1][k][w]->color)
            return true;
        if(j == jj && k+1==kk && w==ww && color != board[i-2][j][k+1][w]->color)
            return true;
        if(j == jj && k==kk && w+1==ww && color != board[i-2][j][k][w+1]->color)
            return true;
        if(j-1 == jj && k==kk && w==ww && color != board[i-2][j-1][k][w]->color)
            return true;
        if(j == jj && k-1==kk && w==ww && color != board[i-2][j][k-1][w]->color)
            return true;
        if(j == jj && k==kk && w-1==ww && color != board[i-2][j][k][w-1]->color)
            return true;
    }
    if(j+2 == jj){
        if(i+1==ii && k==kk && w==ww && color != board[i+1][j+2][k][w]->color)
            return true;
        if(i==ii && k+1==kk && w==ww && color != board[i][j+2][k+1][w]->color)
            return true;
        if(i==ii && k==kk && w+1==ww && color != board[i][j+2][k][w+1]->color)
            return true;
        if(i-1==ii && k==kk && w==ww && color != board[i-1][j+2][k][w]->color)
            return true;
        if(i==ii && k-1==kk && w==ww && color != board[i][j+2][k-1][w]->color)
            return true;
        if(i==ii && k==kk && w-1==ww && color != board[i][j+2][k][w-1]->color)
            return true;
    }
    if(j-2 == jj){
        if(i+1==ii && k==kk && w==ww && color != board[i+1][j-2][k][w]->color)
            return true;
        if(i==ii && k+1==kk && w==ww && color != board[i][j-2][k+1][w]->color)
            return true;
        if(i==ii && k==kk && w+1==ww && color != board[i][j-2][k][w+1]->color)
            return true;
        if(i-1==ii && k==kk && w==ww && color != board[i-1][j-2][k][w]->color)
            return true;
        if(i==ii && k-1==kk && w==ww && color != board[i][j-2][k-1][w]->color)
            return true;
        if(i==ii && k==kk && w-1==ww && color != board[i][j-2][k][w-1]->color)
            return true;
    }
    if(k+2 == kk){
        if(i+1 == ii && j == jj && w == ww && color != board[i+1][j][k+2][w]->color)
            return true;
        if(i == ii && j+1 == jj && w == ww && color != board[i][j+1][k+2][w]->color)
            return true;
        if(i == ii && j == jj && w+1 == ww && color != board[i][j][k+2][w+1]->color)
            return true;
        if(i-1 == ii && j == jj && w == ww && color != board[i-1][j][k+2][w]->color)
            return true;
        if(i == ii && j-1 == jj && w == ww && color != board[i][j-1][k+2][w]->color)
            return true;
        if(i == ii && j == jj && w-1 == ww && color != board[i][j][k+2][w-1]->color)
            return true;
    }
    if(k-2 == kk){
        if(i+1 == ii && j == jj && w == ww && color != board[i+1][j][k-2][w]->color)
            return true;
        if(i == ii && j+1 == jj && w == ww && color != board[i][j+1][k-2][w]->color)
            return true;
        if(i == ii && j == jj && w+1 == ww && color != board[i][j][k-2][w+1]->color)
            return true;
        if(i-1 == ii && j == jj && w == ww && color != board[i-1][j][k-2][w]->color)
            return true;
        if(i == ii && j-1 == jj && w == ww && color != board[i][j-1][k-2][w]->color)
            return true;
        if(i == ii && j == jj && w-1 == ww && color != board[i][j][k-2][w-1]->color)
            return true;
    }
    if(w+2 == ww){
        if(i+1 == ii && j==jj && k==kk && color != board[i+1][j][k][w+2]->color)
            return true;
        if(i == ii && j+1==jj && k==kk && color != board[i][j+1][k][w+2]->color)
            return true;
        if(i == ii && j==jj && k+1==kk && color != board[i][j][k+1][w+2]->color)
            return true;
        if(i-1 == ii && j==jj && k==kk && color != board[i-1][j][k][w+2]->color)
            return true;
        if(i == ii && j-1==jj && k==kk && color != board[i][j-1][k][w+2]->color)
            return true;
        if(i == ii && j==jj && k-1==kk && color != board[i][j][k-1][w+2]->color)
            return true;
    }
    if(w-2 == ww){
        if(i+1 == ii && j==jj && k==kk && color != board[i+1][j][k][w-2]->color)
            return true;
        if(i == ii && j+1==jj && k==kk && color != board[i][j+1][k][w-2]->color)
            return true;
        if(i == ii && j==jj && k+1==kk && color != board[i][j][k+1][w-2]->color)
            return true;
        if(i-1 == ii && j==jj && k==kk && color != board[i-1][j][k][w-2]->color)
            return true;
        if(i == ii && j-1==jj && k==kk && color != board[i][j-1][k][w-2]->color)
            return true;
        if(i == ii && j==jj && k-1==kk && color != board[i][j][k-1][w-2]->color)
            return true;
    }
    return false;
}

Bishop::Bishop(bool side){
    texture.loadFromFile("pieces.png", sf::IntRect(400, side*200, 200, 200));
    sprite.setTexture(texture);
    sprite.scale(0.165, 0.165);
    sprite.setPosition(20, 565);
    color = side;
    nihil = 0;
}

bool Bishop::moveLegality(int i, int j, int k, int w, int ii, int jj, int kk, int ww, Piece* board[4][4][4][4]){
    if(i==ii && j==jj && k==kk && w==ww)
        return false;
    if(k == kk && w==ww){
        for(int counter = 1; i+counter<4 && j+counter<4; counter++){
            if(i+counter == ii && j+counter == jj && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i+counter][j+counter][k][w]->nihil)
                break;
        }
        for(int counter = 1; i-counter>=0 && j-counter>=0; counter++){
            if(i-counter == ii && j-counter == jj && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i-counter][j-counter][k][w]->nihil)
                break;
        }
        for(int counter = 1; i+counter<4 && j-counter>=0; counter++){
            if(i+counter == ii && j-counter == jj && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i+counter][j-counter][k][w]->nihil)
                break;
        }
        for(int counter = 1; i-counter>=0 && j+counter<4; counter++){
            if(i-counter == ii && j+counter == jj && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i-counter][j+counter][k][w]->nihil)
                break;
        }
    }
    if(j == jj && w==ww){
        for(int counter = 1; i+counter<4 && k+counter<4; counter++){
            if(i+counter == ii && k+counter == kk && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i+counter][j][k+counter][w]->nihil)
                break;
        }
        for(int counter = 1; i-counter>=0 && k-counter>=0; counter++){
            if(i-counter == ii && k-counter == kk && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i-counter][j][k-counter][w]->nihil)
                break;
        }
        for(int counter = 1; i+counter<4 && k-counter>=0; counter++){
            if(i+counter == ii && k-counter == kk && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i+counter][j][k-counter][w]->nihil)
                break;
        }
        for(int counter = 1; i-counter>=0 && k+counter<4; counter++){
            if(i-counter == ii && k+counter == kk && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i-counter][j][k+counter][w]->nihil)
                break;
        }
    }
    if(j == jj && k==kk){
        for(int counter = 1; i+counter<4 && w+counter<4; counter++){
            if(i+counter == ii && w+counter == ww && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i+counter][j][k][w+counter]->nihil)
                break;
        }
        for(int counter = 1; i-counter>=0 && w-counter>=0; counter++){
            if(i-counter == ii && w-counter == ww && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i-counter][j][k][w-counter]->nihil)
                break;
        }
        for(int counter = 1; i-counter>=0 && w+counter<4; counter++){
            if(i-counter == ii && w+counter == ww && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i-counter][j][k][w+counter]->nihil)
                break;
        }
        for(int counter = 1; i+counter<4 && w-counter>=0; counter++){
            if(i+counter == ii && w-counter == ww && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i+counter][j][k][w-counter]->nihil)
                break;
        }
    }
    if(i == ii && w==ww){
        for(int counter = 1; j+counter<4 && k+counter<4; counter++){
            if(j+counter == jj && k+counter == kk && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j+counter][k+counter][w]->nihil)
                break;
        }
        for(int counter = 1; j-counter>=0 && k-counter>=0; counter++){
            if(j-counter == jj && k-counter == kk && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j-counter][k-counter][w]->nihil)
                break;
        }
        for(int counter = 1; j-counter>=0 && k+counter<4; counter++){
            if(j-counter == jj && k+counter == kk && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j-counter][k+counter][w]->nihil)
                break;
        }
        for(int counter = 1; j+counter<4 && k-counter>=0; counter++){
            if(j+counter == jj && k-counter == kk && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j+counter][k-counter][w]->nihil)
                break;
        }
    }
    if(i == ii && k==kk){
        for(int counter = 1; j+counter<4 && w+counter<4; counter++){
            if(j+counter == jj && w+counter == ww && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j+counter][k][w+counter]->nihil)
                break;
        }
        for(int counter = 1; j-counter>=0 && w-counter>=0; counter++){
            if(j-counter == jj && w-counter == ww && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j-counter][k][w-counter]->nihil)
                break;
        }
        for(int counter = 1; j+counter<4 && w-counter>=0; counter++){
            if(j+counter == jj && w-counter == ww && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j+counter][k][w-counter]->nihil)
                break;
        }
        for(int counter = 1; j-counter>=0 && w+counter<4; counter++){
            if(j-counter == jj && w+counter == ww && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j-counter][k][w+counter]->nihil)
                break;
        }
    }
    if(i==ii && j == jj){
        for(int counter = 1; k+counter<4 && w+counter<4; counter++){
            if(k+counter == kk && w+counter == ww && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j][k+counter][w+counter]->nihil)
                break;
        }
        for(int counter = 1; k-counter>=0 && w-counter>=0; counter++){
            if(k-counter == kk && w-counter == ww && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j][k-counter][w-counter]->nihil)
                break;
        }
        for(int counter = 1; k-counter>=0 && w+counter<4; counter++){
            if(k-counter == kk && w+counter == ww && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j][k-counter][w+counter]->nihil)
                break;
        }
        for(int counter = 1; k+counter<4 && w-counter>=0; counter++){
            if(k+counter == kk && w-counter == ww && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j][k+counter][w-counter]->nihil)
                break;
        }
    }
    return false;
}

Queen::Queen(bool side){
    texture.loadFromFile("pieces.png", sf::IntRect(600, side*200, 200, 200));
    sprite.setTexture(texture);
    sprite.scale(0.165, 0.165);
    sprite.setPosition(20, 565);
    color = side;
    nihil = 0;
}

bool Queen::moveLegality(int i, int j, int k, int w, int ii, int jj, int kk, int ww, Piece* board[4][4][4][4]){
    if (i==ii && j==jj && k==kk && w==ww)\
        return false;
    if(i==ii && j==jj && k==kk){
        for(int counter = 1; w+counter<4; counter++){
            if(w+counter == ww && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j][k][w+counter]->nihil)
                break;
        }
        for(int counter = 1; w-counter>=0; counter++){
            if(w-counter == ww && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j][k][w-counter]->nihil)
                break;
        }
    }
    if(i==ii && j==jj && w==ww){
        for(int counter = 1; k+counter<4; counter++){
            if(k+counter == kk && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j][k+counter][w]->nihil)
                break;
        }
        for(int counter = 1; k-counter>=0; counter++){
            if(k-counter == kk && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j][k-counter][w]->nihil)
                break;
        }
    }
    if(i==ii && k==kk && w==ww){
        for(int counter = 1; j+counter<4; counter++){
            if(j+counter == jj && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j+counter][k][w]->nihil)
                break;
        }
        for(int counter = 1; j-counter>=0; counter++){
            if(j-counter == jj && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j-counter][k][w]->nihil)
                break;
        }
    }
    if(j==jj && k==kk && w==ww){
        for(int counter = 1; i+counter<4; counter++){
            if(i+counter == ii && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i+counter][j][k][w]->nihil)
                break;
        }
        for(int counter = 1; i-counter>=0; counter++){
            if(i-counter == ii && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i-counter][j][k][w]->nihil)
                break;
        }
    }
    if(k == kk && w==ww){
        for(int counter = 1; i+counter<4 && j+counter<4; counter++){
            if(i+counter == ii && j+counter == jj && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i+counter][j+counter][k][w]->nihil)
                break;
        }
        for(int counter = 1; i-counter>=0 && j-counter>=0; counter++){
            if(i-counter == ii && j-counter == jj && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i-counter][j-counter][k][w]->nihil)
                break;
        }
        for(int counter = 1; i+counter<4 && j-counter>=0; counter++){
            if(i+counter == ii && j-counter == jj && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i+counter][j-counter][k][w]->nihil)
                break;
        }
        for(int counter = 1; i-counter>=0 && j+counter<4; counter++){
            if(i-counter == ii && j+counter == jj && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i-counter][j+counter][k][w]->nihil)
                break;
        }
    }
    if(j == jj && w==ww){
        for(int counter = 1; i+counter<4 && k+counter<4; counter++){
            if(i+counter == ii && k+counter == kk && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i+counter][j][k+counter][w]->nihil)
                break;
        }
        for(int counter = 1; i-counter>=0 && k-counter>=0; counter++){
            if(i-counter == ii && k-counter == kk && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i-counter][j][k-counter][w]->nihil)
                break;
        }
        for(int counter = 1; i+counter<4 && k-counter>=0; counter++){
            if(i+counter == ii && k-counter == kk && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i+counter][j][k-counter][w]->nihil)
                break;
        }
        for(int counter = 1; i-counter>=0 && k+counter<4; counter++){
            if(i-counter == ii && k+counter == kk && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i-counter][j][k+counter][w]->nihil)
                break;
        }
    }
    if(j == jj && k==kk){
        for(int counter = 1; i+counter<4 && w+counter<4; counter++){
            if(i+counter == ii && w+counter == ww && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i+counter][j][k][w+counter]->nihil)
                break;
        }
        for(int counter = 1; i-counter>=0 && w-counter>=0; counter++){
            if(i-counter == ii && w-counter == ww && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i-counter][j][k][w-counter]->nihil)
                break;
        }
        for(int counter = 1; i-counter>=0 && w+counter<4; counter++){
            if(i-counter == ii && w+counter == ww && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i-counter][j][k][w+counter]->nihil)
                break;
        }
        for(int counter = 1; i+counter<4 && w-counter>=0; counter++){
            if(i+counter == ii && w-counter == ww && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i+counter][j][k][w-counter]->nihil)
                break;
        }
    }
    if(i == ii && w==ww){
        for(int counter = 1; j+counter<4 && k+counter<4; counter++){
            if(j+counter == jj && k+counter == kk && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j+counter][k+counter][w]->nihil)
                break;
        }
        for(int counter = 1; j-counter>=0 && k-counter>=0; counter++){
            if(j-counter == jj && k-counter == kk && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j-counter][k-counter][w]->nihil)
                break;
        }
        for(int counter = 1; j-counter>=0 && k+counter<4; counter++){
            if(j-counter == jj && k+counter == kk && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j-counter][k+counter][w]->nihil)
                break;
        }
        for(int counter = 1; j+counter<4 && k-counter>=0; counter++){
            if(j+counter == jj && k-counter == kk && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j+counter][k-counter][w]->nihil)
                break;
        }
    }
    if(i == ii && k==kk){
        for(int counter = 1; j+counter<4 && w+counter<4; counter++){
            if(j+counter == jj && w+counter == ww && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j+counter][k][w+counter]->nihil)
                break;
        }
        for(int counter = 1; j-counter>=0 && w-counter>=0; counter++){
            if(j-counter == jj && w-counter == ww && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j-counter][k][w-counter]->nihil)
                break;
        }
        for(int counter = 1; j+counter<4 && w-counter>=0; counter++){
            if(j+counter == jj && w-counter == ww && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j+counter][k][w-counter]->nihil)
                break;
        }
        for(int counter = 1; j-counter>=0 && w+counter<4; counter++){
            if(j-counter == jj && w+counter == ww && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j-counter][k][w+counter]->nihil)
                break;
        }
    }
    if(i==ii && j == jj){
        for(int counter = 1; k+counter<4 && w+counter<4; counter++){
            if(k+counter == kk && w+counter == ww && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j][k+counter][w+counter]->nihil)
                break;
        }
        for(int counter = 1; k-counter>=0 && w-counter>=0; counter++){
            if(k-counter == kk && w-counter == ww && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j][k-counter][w-counter]->nihil)
                break;
        }
        for(int counter = 1; k-counter>=0 && w+counter<4; counter++){
            if(k-counter == kk && w+counter == ww && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j][k-counter][w+counter]->nihil)
                break;
        }
        for(int counter = 1; k+counter<4 && w-counter>=0; counter++){
            if(k+counter == kk && w-counter == ww && color != board[ii][jj][kk][ww]->color)
                return true;
            if(!board[i][j][k+counter][w-counter]->nihil)
                break;
        }
    }
    return false;
}

King::King(bool side){
    texture.loadFromFile("pieces.png", sf::IntRect(800, side*200, 200, 200));
    sprite.setTexture(texture);
    sprite.scale(0.165, 0.165);
    sprite.setPosition(20, 565);
    color = side;
    nihil = 0;
}

bool King::moveLegality(int i, int j, int k, int w, int ii, int jj, int kk, int ww, Piece* board[4][4][4][4]){
    if(i==ii && j==jj && k==kk && w==ww)
        return false;
    if((i==ii || i+1 == ii || i-1 == ii) && (j==jj || j+1==jj || j-1 == jj) && (k==kk || k+1 == kk || k-1 == kk) && (w==ww || w+1==ww || w-1 == ww) && color != board[ii][jj][kk][ww]->color)
        return true;
    return false;

}

