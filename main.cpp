# include <iostream>
using namespace std;

// stating function prototypes
bool check_win(int &player1score, int &player2score, int grid[3][3]);
bool check_tie(int grid[3][3]);
// main code
int main() {
  int grid[3][3] = {
    {0,0,0},
    {0,0,0},
    {0,0,0}
  };
  bool player1 = true;
  bool gameover = false;
  int player1score = 0;
  int player2score = 0;
  cout << "0 = empty, 1 = player 1 token, 2 = player 2 token"<< endl;
  // while condition for ending game
  while (gameover == false) {
     bool win = false;
     char playagain;
     // player 1 turn
     if (player1 == true){
        bool valid = false;
        while (valid == false){
	  int row;
	  int column;
	  cout << "Player 1's turn" << endl;
	  cout << "Enter the row(1,2,3) you would like to place your token: ";
	  cin >> row;
	  cout << "Enter the column(1,2,3) you would like to place your token: ";
	  cin >> column;
	  if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
	  }
	  // checking if move is valid 
	  if ((row >= 1 && row <= 3) && (column >= 1 && column <= 3) && (grid[row - 1][column - 1] == 0)){
	      grid[row-1][column-1] = 1;
	      valid = true;
	      player1 = false;
	      cout << "-------------------" << endl;
	      for (int i = 0; i <= 2; i += 1) {
		for (int j = 0; j<= 2; j += 1) {
		  if (j != 2){
		    cout << grid[i][j] << " ";
		  }
		  else {
		    cout << grid[i][j] << endl;
		  }
		}
	      }
	      cout << "--------------------" << endl;
	    }
	  if (check_win(player1score, player2score, grid)){
	      cout << "Player 1 wins!" << endl;
	      win = true;
	    }
	}
     }

     // win check
     if (win == true) {
       cout << "Player 1 score: " << player1score << endl;
       cout << "Player 2 score: " << player2score << endl;
       cout << "Do you want to play again?(y/n) ";
       cin >> playagain;
       if (playagain == 'n'){
	 gameover = true;
	 cout << "Thank you for playing!" << endl;
	 player1 = true;
       }
       else {
         cout << "Lets play again!" << endl;
         for (int i = 0; i <= 2; i += 1) {
	   for (int j = 0; j<= 2; j += 1) {
	     grid[i][j] = 0;
	   }
         }
         player1 = true;
       }
     }
     // tie check
     else {
       if (check_tie(grid)) {
	 cout << "Tie!" << endl;
	 cout << "Player 1 score: " << player1score << endl;
         cout << "Player 2 score: " << player2score << endl;
	 cout << "Do you want to play again?(y/n) ";
	 cin >> playagain;
	 if (playagain == 'n'){
	   gameover = true;
	   cout << "Thank you for playing!" << endl;
	   player1 = true;
	 }
	 else {
	   cout << "Lets play again!" << endl;
	   for (int i = 0; i <= 2; i += 1) {
	     for (int j = 0; j<= 2; j += 1) {
	       grid[i][j] = 0;
	     }
	   }
	   player1 = true;
	 }
       }
     }
     
     win = false;
     // player 2 turn
     if (player1 == false){
        bool valid = false;
        while (valid == false){
	  int row;
	  int column;
	  cout << "Player 2's turn" << endl;
	  cout << "Enter the row(1,2,3) you would like to place your token: ";
	  cin >> row;
	  cout << "Enter the column(1,2,3) you would like to place your token: ";
	  cin >> column;
	  if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
          }
	  // checking if move is valid
	  if ((row >= 1 && row <= 3) && (column >= 1 && column <= 3) && (grid[row-1][column-1] == 0)){
	      grid[row-1][column-1] = 2;
	      valid = true;
	      player1 = true;
	      for (int i = 0; i <= 2; i += 1) {
		for (int j = 0; j<= 2; j += 1) {
		  if (j != 2){
		    cout << grid[i][j] << " ";
		  }
		  else {
		    cout << grid[i][j] << endl;
		  }
		}
	      }
	      cout << "--------------------" << endl;
	    }
	  if (check_win(player1score, player2score, grid)){
	      cout << "Player 2 wins!" << endl;
	      win = true;
	  }
	}
     }
     // win check
     if (win == true) {
       cout << "Player 1 score: " << player1score << endl;
       cout << "Player 2 score: " << player2score << endl;
       cout << "Do you want to play again?(y/n) ";
       cin >> playagain;
       if (playagain == 'n'){
	 gameover = true;
	 cout << "Thank you for playing!" << endl;
       }
       else {
         cout << "Lets play again!" << endl;
         for (int i = 0; i <= 2; i += 1) {
	   for (int j = 0; j<= 2; j += 1) {
	     grid[i][j] = 0;
	   }
         }
	 player1 = true; 
       }
     }
     // tie check
     else {
       if (check_tie(grid) && gameover == false) {
	 cout << "Tie!" << endl;
	 cout << "Player 1 score: " << player1score << endl;
         cout << "Player 2 score: " << player2score << endl;
	 cout << "Do you want to play again?(y/n) ";
	 cin >> playagain;
	 if (playagain == 'n'){
	   gameover = true;
	   cout << "Thank you for playing!" << endl;
	   player1 = true;
	 }
	 else {
	   cout << "Lets play again!" << endl;
	   for (int i = 0; i <= 2; i += 1) {
	     for (int j = 0; j<= 2; j += 1) {
	       grid[i][j] = 0;
	     }
	   }
	   player1 = true;
	 }
       }
     }
     win = false;
  }
}

// function for checking win
bool check_win(int &player1score, int &player2score, int grid[3][3]){
  int wins[8][3] = {
    {0,1,2},
    {3,4,5},
    {6,7,8},
    {0,3,6},
    {1,4,7},
    {2,5,8},
    {0,4,8},
    {2,4,6}
  };
  for (int count = 0; count < 8; count += 1) {
    int i = wins[count][0];
    int j = wins[count][1];    
    int k = wins[count][2];
    int ir;
    int jr;
    int kr;
    int ic;
    int jc;
    int kc;
    if (i > 2){
      if (i > 5) {
	ir = 2;
	ic = i - 6;
      }
      else {
	ir = 1;
	ic = i - 3;
      }
    }
    else {
      ir = 0;
      ic = i;
    }

    if (j > 2){
      if (j > 5) {
	jr = 2;
	jc = j - 6;
      }
      else {
	jr = 1;
	jc = j - 3;
      }
    }
    else {
      jr = 0;
      jc = j;
    }

    if (k > 2){
      if (k > 5) {
	kr = 2;
	kc = k - 6;
      }
      else {
	kr = 1;
	kc = k - 3;
      }
    }
    else {
      kr = 0;
      kc = k;
    }
    // checking if there is a win
    if (grid[ir][ic] != 0 && grid[ir][ic] == grid[jr][jc] && grid[jr][jc] == grid[kr][kc]) {
      int player_win = grid[ir][ic];
      if (player_win == 1){
	player1score += 1;
      }
      else {
	player2score += 1;
		
      }
      return true;
    }
  }
  return false;
}

// function for checking  tie
bool check_tie(int grid[3][3]) {
   int tie_count = 0;
   for (int i = 0; i <= 2; i += 1) {
      for (int j = 0; j<= 2; j += 1) {
	if (grid[i][j] == 0){
	    tie_count += 1;
	  }
      }
   }

   if (tie_count == 0) {
     return true;
   }
   else{
     return false;
   }
}
