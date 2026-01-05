#ifndef _NUMBERBOARD_H_
#define _NUMBERBOARD_H_
#include <vector>
#include <utility>
using namespace std;

struct NumberBoard{
  vector<vector<char>> nb; double eval; bool isOver;
  NumberBoard();
  void instantiate();
  char pieceAt(pair<int, int> square);
  void setPieceAt(pair<int, int> square, char piece);
  bool isPieceAt(pair<int, int> square, char piece);
  bool isEmpty(pair<int, int> square);
  bool isLaterallyAdjacent(pair<int, int> current, pair<int, int> square);
  bool isDiagonallyAdjacent(pair<int, int> current, pair<int, int> square);

  // Check if valid chess move
  bool isPawnMove(pair<int, int> start, pair<int, int> end);
  bool isKnightMove(pair<int, int> start, pair<int, int> end);
  bool isBishopMove(pair<int, int> start, pair<int, int> end);
  bool isRookMove(pair<int, int> start, pair<int, int> end);
  bool isQueenMove(pair<int, int> start, pair<int, int> end);
  bool isKingMove(pair<int, int> start, pair<int, int> end);
  // Check step validity
  bool isPawnStep(pair<int, int> start, pair<int, int> end);
  bool isKnightStep(pair<int, int> start, pair<int, int> end);
  bool isBishopStep(pair<int, int> start, pair<int, int> end);
  bool isRookStep(pair<int, int> start, pair<int, int> end);
  bool isQueenStep(pair<int, int> start, pair<int, int> end);
  bool isKingStep(pair<int, int> start, pair<int, int> end);
  // Check jump validity
  bool isPawnJump(pair<int, int> start, pair<int, int> middle, pair<int, int> end);
  bool isKnightJump(pair<int, int> start, pair<int, int> middle, pair<int, int> end);
  bool isBishopJump(pair<int, int> start, pair<int, int> middle, pair<int, int> end);
  bool isRookJump(pair<int, int> start, pair<int, int> middle, pair<int, int> end);
  bool isQueenJump(pair<int, int> start, pair<int, int> middle, pair<int, int> end);
  bool isKingJump(pair<int, int> start, pair<int, int> middle, pair<int, int> end);

  // Actually execute the moves
  void executeStep(pair<int, int> start, pair<int, int> end);
  void executeJump(pair<int, int> start, pair<int, int> middle, pair<int, int> end);
};

#endif