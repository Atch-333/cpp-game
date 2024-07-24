#include <iostream>
#include <cmath>
using namespace std;

//start functions

//view board
void theBoard(string arrayOf16[]){
  for (int i = 0; i < 9; i++){
    cout << "  " << arrayOf16[i] << "  ";
    if ((i + 1) % 4 == 0){
      cout << "\n\n";
    }
  }
  for (int i = 9; i < 16; i++){
    cout << "  " << arrayOf16[i] << " ";
    if ((i + 1) % 4 == 0){
      cout << "\n\n";
    }
  }
}
//check if the entered number is vailed or not
int checkNum(int num1, int num2){
  int result;
  if (num1 + 1 == num2 || num1 + 4 == num2 || num1 - 1 == num2 || num1 - 4 == num2){
    result = 1;
  }
  else result = 0;
  return result;
}
//check if the game end or yet 
float checkGame(string arrayOf16[]){
  int result = 0;
  for (int i = 0; i < 16; i++){
    if (arrayOf16[i] == "X"){
      result += 1;
    }
    else if (arrayOf16[i + 1] == arrayOf16[i + 4] && arrayOf16[i + 1] == arrayOf16[i - 4]){
      result += 1;
    }
    else {
      result += 0;
    }
  }
  return result;
}

//end functions

int main(){
  string boardNums[]{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16"};
  int num1;
  int num2;
  int end = 0;
  cout << "\nTwo squares game\n\n";//game name and rules
  cout << "This game is played on a board of 4 x 4 squares. Two players take turns;each of them takes turn to place a rectangle (that covers two squares) on the board,covering any 2 squares. Only one rectangle can be on a square. A square cannot be coveredtwice. The last player who can place a card on the board is the winner.\n\n"; 
  //start gmae code
  theBoard(boardNums);

  for (int i = 0; i < 16; i++){
    cout << "First Player Turn\n";
    for (int i = 1; i < 4; i++){
      cin >> num1;
      cin >> num2;
      if (checkNum(num1, num2) == 1 && num1 < 17 && num1 > 0 && num2 < 17 && num2 > 0 && boardNums[num1 - 1] != "X" && boardNums[num2 - 1] != "X"){
        boardNums[num1 - 1] = "X";
        boardNums[num2 - 1] = "X";
        break;
      }
      else {
        cout << "The squares Not Avilable\n" << "Try agian\n";
      }
      if (i == 3){
        cout << "==================================\n" << "You are so stupied\n to play this  game\n" << "==================================\n";
        end = 1;
        break;
      }
    }

    theBoard(boardNums);
    if (checkGame(boardNums) == 16){
      cout << "==================================\n" << "First Player Wins\n" << "==================================\n";
      break;
    }
    if (end == 1){;
      break;
    }

    cout << "Second Player Turn\n";
    for (int i = 1; i < 4; i++){
      cin >> num1;
      cin >> num2;
      if (checkNum(num1, num2) == 1 && num1 < 17 && num1 > 0 && num2 < 17 && num2 > 0 && boardNums[num1 - 1] != "X" && boardNums[num2 - 1] != "X"){
        boardNums[num1 - 1] = "X";
        boardNums[num2 - 1] = "X";
        break;
      }
      else {
        cout << "The squares Not Avilable\n" << "Try agiam\n";
      }
      if (i == 3){
        cout << "==================================\n" << "You are so stupied\n to play this  game\n" << "==================================\n";
        end = 1;
        break;
      }
    }

    theBoard(boardNums);
    if (checkGame(boardNums) == 16){
      cout << "==================================\n" << "Second Player Wins\n" << "==================================\n";
      break;
    }
    if (end == 1){
      break;
    }
  }

  cout << "\nThe Game End";
  //end game code
  return 0;
}