#ifndef _NUMBERBOARD_H_
#define _NUMBERBOARD_H_

struct Piece{
  char color; int value; char name;
  Piece();
  Piece(char newColor, int newValue, char newName);
};
struct Pawn: Piece{
  Pawn(char newColor, int newValue, char newName);
};
struct Knight: Piece{
  Knight(char newColor, int newValue, char newName);
};
struct Bishop: Piece{
  Bishop(char newColor, int newValue, char newName);
};
struct Rook: Piece{
  Rook(char newColor, int newValue, char newName);
};
struct Queen: Piece{
  Queen(char newColor, int newValue, char newName);
};
struct King: Piece{
  King(char newColor, int newValue, char newName);
};
struct Empty: Piece{
  Empty(char newColor, int newValue, char newName);
};

#endif