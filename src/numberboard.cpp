#include "numberboard.hpp"
#include <math.h>

NumberBoard::NumberBoard(): 
  nb(8, vector<char>(8, '.')), 
  eval(0.0), 
  isOver(false){
    instantiate();
  }
void NumberBoard::instantiate(){
  for(int i=0; i<nb.size(); i++){
    for(int j=0; j<nb[0].size(); j++){
      if(i == 0){
        char possiblePieces[] = {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'};
        nb[i][j] = possiblePieces[j];
      }
      else if(i == 1){
        nb[i][j] = 'p';
      }
      else if(i == 6){
        nb[i][j] = 'P';
      }
      else if(i == 7){
        char possiblePieces[] = {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'};
        nb[i][j] = possiblePieces[j];
      }
    }
  }
}
char NumberBoard::pieceAt(pair<int, int> square){
  return nb.at(square.first).at(square.second);
}
void NumberBoard::setPieceAt(pair<int, int> square, char piece){
  nb.at(square.first).at(square.second) = piece;
}
bool NumberBoard::isPieceAt(pair<int, int> square, char piece){
  return nb.at(square.first).at(square.second) == piece;
}
bool NumberBoard::isEmpty(pair<int, int> square){
  return isPieceAt(square, '.');
}
bool NumberBoard::isLaterallyAdjacent(pair<int, int> current, pair<int, int> square){
  int h = abs(current.first-square.first);
  int w = abs(current.second-square.second);
  if(current.first == 0){
    if(square.first == 7 && w == 0){
      return true;
    }
    return false;
  }
  else if(current.first == 7){
    if(square.first == 0 && w == 0){
      return true;
    }
    return false;
  }
  else if(current.second == 0){
    if(square.second == 7 && h == 0){
      return true;
    }
    return false;
  }
  else if(current.second == 7){
    if(square.second == 0 && h == 0){
      return true;
    }
    return false;
  }
  else{
    return (h == 1 && w == 0) || (h == 0 && w == 1);
  }
}
bool NumberBoard::isDiagonallyAdjacent(pair<int, int> current, pair<int, int> square){
  int h = abs(current.first-square.first);
  int w = abs(current.second-square.second);
  if(w != h){
    if(w == 1){
      if(current.first == 0 && square.first == 7 || current.first == 7 && square.first == 0){
        return true;
      }
      return false;
    }
    else if(h == 1){
      if(current.second == 0 && square.second== 7 || current.second == 7 && current.first == 0){
        return true;
      }
      return false;
    }
    else{
      return ((current.first == 0 && square.first == 7 && current.second == 0 && square.second == 7)
      || (current.first == 7 && square.first == 0 && current.second == 0 && square.second == 7)
      || (current.first == 0 && square.first == 7 && current.second == 7 && square.second == 0)
      || (current.first == 7 && square.first == 0 && current.second == 7 && square.second == 0));
    }
  }
  else{
    return h == 1 && w == 1;
  }
}
void NumberBoard::print(){
  for(int i=0; i<nb.size(); i++){
    string current = "";
    for(int j=0; j<nb[0].size(); j++){
      current += nb[i][j];
    }
    cout << current << endl;
  }
}

// Implementing the checking of the move being a valid chess move to begin with
bool NumberBoard::isPawnMove(pair<int, int> start, pair<int, int> end){
  // If pawn is not moving vertically, or moving laterally, return false
  if(start.second-end.second != 0 || start.first-end.first == 0){
    return false;
  }
  int diff = start.first-end.first;
  // White Pawn
  if(isPieceAt(start, 'P')){
    // If first move, pawn can move up to 2 squares
    if(start.first == 6){
      return diff == -2 || diff == -1;
    }
    else{
      return diff == -1;
    }
  }
  // Black pawn
  else if(isPieceAt(start, 'p')){
    // If first move, pawn can move up to 2 squares
    if(start.first == 1){
      return diff == 2 || diff == 1;
    }
    else{
      return diff == 1;
    }
  }
  else{
    return false;
  }
}
bool NumberBoard::isKnightMove(pair<int, int> start, pair<int, int> end){
  int w = abs(start.first-end.first);
  int h = abs(start.second-end.second);
  return((w == 2 && h == 1) || (w == 1 && h == 2));
}
bool NumberBoard::isBishopMove(pair<int, int> start, pair<int, int> end){
  return abs(start.first-end.first) == abs(start.second-end.second);
}
bool NumberBoard::isRookMove(pair<int, int> start, pair<int, int> end){
  int w = abs(start.first-end.first);
  int h = abs(start.second-end.second);
  return((w == 0 && h != 0) || (w != 0 && h == 0));
}
bool NumberBoard::isQueenMove(pair<int, int> start, pair<int, int> end){
  return isBishopMove(start, end) || isRookMove(start, end);
}
bool NumberBoard::isKingMove(pair<int, int> start, pair<int, int> end){
  int w = abs(start.first-end.first);
  int h = abs(start.second-end.second);
  return((w != 0 || h != 0) && (w <= 1 && h <= 1));
}

// Implementing the checking of steps (non-capturing moves)
bool NumberBoard::isPawnStep(pair<int, int> start, pair<int, int> end){
  return isPawnMove(start, end) && isEmpty(end);
}
bool NumberBoard::isKnightStep(pair<int, int> start, pair<int, int> end){
  return isKnightMove(start, end) && isEmpty(end);
}
bool NumberBoard::isBishopStep(pair<int, int> start, pair<int, int> end){
  return isBishopMove(start, end) && isEmpty(end);
}
bool NumberBoard::isRookStep(pair<int, int> start, pair<int, int> end){
  return isRookMove(start, end) && isEmpty(end);
}
bool NumberBoard::isQueenStep(pair<int, int> start, pair<int, int> end){
  return isQueenMove(start, end) && isEmpty(end);
}
bool NumberBoard::isKingStep(pair<int, int> start, pair<int, int> end){
  return isKingMove(start, end) && isEmpty(end);
}

// Implementing the checking of jumps (capturing moves)
bool NumberBoard::isPawnJump(pair<int, int> start, pair<int, int> middle, pair<int, int> end){
  return isPawnMove(start, middle) && !isEmpty(middle) && isEmpty(end) && isPawnMove(middle, end);
}
bool NumberBoard::isKnightJump(pair<int, int> start, pair<int, int> middle, pair<int, int> end){
  return isKnightMove(start, middle) && !isEmpty(middle) && isEmpty(end) && isLaterallyAdjacent(middle, end);
}
bool NumberBoard::isBishopJump(pair<int, int> start, pair<int, int> middle, pair<int, int> end){
  return isBishopMove(start, middle) && !isEmpty(middle) && isEmpty(end) && isDiagonallyAdjacent(middle, end);
}
bool NumberBoard::isRookJump(pair<int, int> start, pair<int, int> middle, pair<int, int> end){
  return isRookMove(start, middle) && !isEmpty(middle) && isEmpty(end) && isLaterallyAdjacent(middle, end);
}
bool NumberBoard::isQueenJump(pair<int, int> start, pair<int, int> middle, pair<int, int> end){
  return isRookJump(start, middle, end) || isBishopJump(start, middle, end);
}
bool NumberBoard::isKingJump(pair<int, int> start, pair<int, int> middle, pair<int, int> end){
  return isLaterallyAdjacent(start, middle) && isLaterallyAdjacent(middle, end) || isDiagonallyAdjacent(start, middle) && isDiagonallyAdjacent(middle, end);
}
bool NumberBoard::jumpCrossesEdge(pair<int, int> start, pair<int, int> middle, pair<int, int> end){
  return isKingStep(middle, end);
}
// Actually execute the moves

// Execute steps
void NumberBoard::executeStep(pair<int, int> start, pair<int, int> end){
  char piece = pieceAt(start);
  bool stepIsPossible;
  switch(piece){
    case 'p': stepIsPossible = isPawnStep(start, end); break;
    case 'P': stepIsPossible = isPawnStep(start, end); break;
    case 'n': stepIsPossible = isKnightStep(start, end); break;
    case 'N': stepIsPossible = isKnightStep(start, end); break;
    case 'b': stepIsPossible = isBishopStep(start, end); break;
    case 'B': stepIsPossible = isBishopStep(start, end); break;
    case 'r': stepIsPossible = isRookStep(start, end); break;
    case 'R': stepIsPossible = isRookStep(start, end); break;
    case 'q': stepIsPossible = isQueenStep(start, end); break;
    case 'Q': stepIsPossible = isQueenStep(start, end); break;
    case 'k': stepIsPossible = isKingStep(start, end); break;
    case 'K': stepIsPossible = isKingStep(start, end); break;
    default: stepIsPossible = false;
  }
  if(stepIsPossible){
    setPieceAt(end, piece);
    setPieceAt(start, '.');    
  }
}
// Execute the jumps
void NumberBoard::executeJump(pair<int, int> start, pair<int, int> middle, pair<int, int> end){
  char piece = pieceAt(start);
  bool jumpIsPossible;
  switch(piece){
    case 'p': jumpIsPossible = isPawnJump(start, middle, end); break;
    case 'P': jumpIsPossible = isPawnJump(start, middle, end); break;
    case 'n': jumpIsPossible = isKnightJump(start, middle, end); break;
    case 'N': jumpIsPossible = isKnightJump(start, middle, end); break;
    case 'b': jumpIsPossible = isBishopJump(start, middle, end); break;
    case 'B': jumpIsPossible = isBishopJump(start, middle, end); break;
    case 'r': jumpIsPossible = isRookJump(start, middle, end); break;
    case 'R': jumpIsPossible = isRookJump(start, middle, end); break;
    case 'q': jumpIsPossible = isQueenJump(start, middle, end); break;
    case 'Q': jumpIsPossible = isQueenJump(start, middle, end); break;
    case 'k': jumpIsPossible = isKingJump(start, middle, end); break;
    case 'K': jumpIsPossible = isKingJump(start, middle, end); break;
    default: jumpIsPossible = false;
  }
  if(jumpIsPossible){
    setPieceAt(end, piece);
    setPieceAt(middle, '.');
    setPieceAt(start, '.');
  }
}