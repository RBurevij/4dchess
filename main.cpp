#include <SFML/Graphics.hpp>
#include <cstddef>
#include <vector>
#include <Piece.h>
#include <iostream>>

class Board{
    private:
        sf::Texture chessboard;
        std::vector<sf::Sprite> board_mass;
    public:
        bool turnphase;
        Piece *board[4][4][4][4];
        bool generateBoard();
        void boardDraw(sf::RenderWindow &chess);
        void createPiece(int i, int j, int k, int w, int piece, int color);
        Piece* processMouseClick(float x, float y, int& i, int& j, int& k, int& w);
        void movePiece(int i, int j, int k, int w, int ii, int jj, int kk, int ww, Piece* movable);
};

bool Board::generateBoard(){
    if (!chessboard.loadFromFile("Chessboard.png"))
        return 0;
    board_mass.resize(16);
    for(int i=0; i<16; i++){
        board_mass[i].setTexture(chessboard);
        board_mass[i].setScale(0.4, 0.4);
        board_mass[i].setPosition(150*i+20-(600*(i/4)), 20+150*(i/4));
    }
    for(int i = 0; i< 4; i++)
        for(int j = 0; j<4; j++)
            for(int k = 0; k<4; k++)
                for(int w=0; w<4; w++)
                    board[i][j][k][w] = new Empty();
    for(int k = 0; k<4; k++)
        for(int j=0; j<4; j++)
            this->createPiece(0, j, k, 1, PAWN, WHITE);
    for(int k = 0; k<4; k++)
        for(int j=0; j<4; j++)
            this->createPiece(1, j, k, 0, PAWN, WHITE);
    for(int k = 0; k<4; k++)
        for(int j=0; j<4; j++)
            this->createPiece(3, j, k, 2, PAWN, BLACK);
    for(int k = 0; k<4; k++)
        for(int j=0; j<4; j++)
            this->createPiece(2, j, k, 3, PAWN, BLACK);
    this->createPiece(0,0,0,0, ROOK, WHITE);
    this->createPiece(0,1,0,0, KNIGHT, WHITE);
    this->createPiece(0,3,0,0, ROOK, WHITE);
    this->createPiece(0,2,0,0, KNIGHT, WHITE);
    this->createPiece(0,0,3,0, ROOK, WHITE);
    this->createPiece(0,1,3,0, KNIGHT, WHITE);
    this->createPiece(0,3,3,0, ROOK, WHITE);
    this->createPiece(0,2,3,0, KNIGHT, WHITE);

    this->createPiece(3,0,0,3, ROOK, BLACK);
    this->createPiece(3,1,0,3, KNIGHT, BLACK);
    this->createPiece(3,3,0,3, ROOK, BLACK);
    this->createPiece(3,2,0,3, KNIGHT, BLACK);
    this->createPiece(3,0,3,3, ROOK, BLACK);
    this->createPiece(3,1,3,3, KNIGHT, BLACK);
    this->createPiece(3,3,3,3, ROOK, BLACK);
    this->createPiece(3,2,3,3, KNIGHT, BLACK);

    this->createPiece(0,0,1,0, BISHOP, WHITE);
    this->createPiece(0,1,1,0, QUEEN, WHITE);
    this->createPiece(0,3,1,0, QUEEN, WHITE);
    this->createPiece(0,2,1,0, BISHOP, WHITE);
    this->createPiece(0,0,2,0, BISHOP, WHITE);
    this->createPiece(0,1,2,0, KING, WHITE);
    this->createPiece(0,3,2,0, BISHOP, WHITE);
    this->createPiece(0,2,2,0, PAWN, WHITE);

    this->createPiece(3,0,1,3, BISHOP, BLACK);
    this->createPiece(3,1,1,3, QUEEN, BLACK);
    this->createPiece(3,3,1,3, QUEEN, BLACK);
    this->createPiece(3,2,1,3, BISHOP, BLACK);
    this->createPiece(3,0,2,3, BISHOP, BLACK);
    this->createPiece(3,1,2,3, KING, BLACK);
    this->createPiece(3,3,2,3, BISHOP, BLACK);
    this->createPiece(3,2,2,3, PAWN, BLACK);
    return 1;
};


Piece* Board::processMouseClick(float x, float y, int& i, int& j, int& k, int& w){
    if(x>=20 && x<=146.4)
        k=0;
    else if(x>=170 && x<=296.4)
        k=1;
    else if(x>=320 && x<=446.4)
        k=2;
    else if(x>=470 && x<596.4)
        k=3;
    else
        return NULL;

    if(y>=20 && y<=146.4)
        w=3;
    else if(y>=170 && y<=296.4)
        w=2;
    else if(y>=320 && y<=446.4)
        w=1;
    else if(y>=470 && y<596.4)
        w=0;
    else
        return NULL;

    x=(x-20)-(k*150);
    if(x>=0 && x<31.6)
        j=0;
    else if(x>=31.6 && x<63.2)
        j=1;
    else if(x>=63.2 && x<94.8)
        j=2;
    else if(x>=94.8 && x<126.4)
        j=3;

    y=(y-20)-150*(3-w);
    if(y>=0 && y<31.6)
        i=3;
    else if(y>=31.6 && y<63.2)
        i=2;
    else if(y>=63.2 && y<94.8)
        i=1;
    else if(y>=94.8 && y<126.4)
        i=0;

    return board[i][j][k][w];
}

void Board::movePiece(int i, int j, int k, int w, int ii, int jj, int kk, int ww, Piece* movable){
    delete board[ii][jj][kk][ww];
    board[ii][jj][kk][ww] = movable;
    movable->sprite.setPosition(20+31.6*jj+150*kk, 565-(31.6*ii+150*ww));
    board[i][j][k][w] = new Empty();
    turnphase = !movable->color;
};

void Board::createPiece(int i, int j, int k, int w, int piece, int color){
    delete board[i][j][k][w];
    switch (piece){
        case PAWN:
            board[i][j][k][w] = new Pawn(color);
            break;
         case ROOK:
            board[i][j][k][w] = new Rook(color);
            break;
         case KNIGHT:
            board[i][j][k][w] = new Knight(color);
            break;
         case BISHOP:
            board[i][j][k][w] = new Bishop(color);
            break;
         case QUEEN:
            board[i][j][k][w] = new Queen(color);
            break;
         case KING:
            board[i][j][k][w] = new King(color);
            break;
    }
    board[i][j][k][w]->sprite.move(31.6*j+150*k, -(31.6*i+150*w));
}

void Board::boardDraw(sf::RenderWindow &chess){
    for(int i=0; i<16; i++)
            chess.draw(board_mass[i]);
    for(int i = 0; i< 4; i++)
        for(int j = 0; j<4; j++)
            for(int k = 0; k<4; k++)
                for(int w=0; w<4; w++)
                    chess.draw(board[i][j][k][w]->sprite);
}

int main()
{
    // Create the main window
    sf::RenderWindow chess(sf::VideoMode(615, 615), "4-D chess");
    Board board;
    board.turnphase = WHITE;
    bool is_moving = false;
    Piece* mousehold;
    int i, j, k, w, ii, jj, kk, ww;
    float dx, dy;

    if(!board.generateBoard()){
        return EXIT_FAILURE;
    }

	// Start the game loop
    while (chess.isOpen())
    {
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(chess);
        // Process events
        sf::Event event;
        while (chess.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                chess.close();
            if (event.type == sf::Event::MouseButtonPressed)
                if(event.key.code == sf::Mouse::Left){
                    mousehold = board.processMouseClick(mouse_pos.x, mouse_pos.y, i, j, k, w);
                    if(mousehold && mousehold->color == board.turnphase){
                            is_moving = true;
                            dx = mouse_pos.x - mousehold->sprite.getPosition().x;
                            dy = mouse_pos.y - mousehold->sprite.getPosition().y;
                    }
                }
            if (event.type == sf::Event::MouseButtonReleased)
                if(event.key.code == sf::Mouse::Left){
                    if(mousehold)
                        if(board.processMouseClick(mouse_pos.x, mouse_pos.y, ii, jj, kk, ww) && mousehold->moveLegality(i, j, k, w, ii, jj, kk, ww, board.board) && is_moving){
                            board.movePiece(i, j, k, w, ii, jj, kk, ww, mousehold);
                        }
                        else
                            mousehold->sprite.setPosition(20+31.6*j+150*k, 565-(31.6*i+150*w));
                        is_moving = false;
                }
        }
        if(is_moving)
            mousehold->sprite.setPosition(mouse_pos.x - dx, mouse_pos.y - dy);
        chess.clear();
        board.boardDraw(chess);
        chess.display();
    }

    return EXIT_SUCCESS;
}
