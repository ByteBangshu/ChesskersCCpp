#include "numberboard.hpp"

Piece::Piece(){
  color = '?';
  value = 0;
  name = 'U';
}
Piece::Piece(char newColor, int newValue, char newName){
  color = newColor;
  value = newValue;
  name = newName;
}
Pawn::Pawn(char newColor, int newValue, char newName){
  color = newColor;
  value = newValue;
  name = newName;
}
Knight::Knight(char newColor, int newValue, char newName){
  color = newColor;
  value = newValue;
  name = newName;
}
Bishop::Bishop(char newColor, int newValue, char newName){
  color = newColor;
  value = newValue;
  name = newName;
}
Rook::Rook(char newColor, int newValue, char newName){
  color = newColor;
  value = newValue;
  name = newName;
}
Queen::Queen(char newColor, int newValue, char newName){
  color = newColor;
  value = newValue;
  name = newName;
}
King::King(char newColor, int newValue, char newName){
  color = newColor;
  value = newValue;
  name = newName;
}
Empty::Empty(char newColor, int newValue, char newName){
  color = newColor;
  value = newValue;
  name = newName;
}
