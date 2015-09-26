#include <iostream>

using namespace std;


//build a sudoku
int sudoku[9][9];
//check if a Sudoku is built
bool ok = false;

//function declaration
void input();
void output();
bool judge();
int dfs(int n);

int main(void) {
    input();
    dfs(0);
    output();
    return 0;
}

//input sudoku
void input (){
    cout << "please input a sudoku has size 9*9, use 0 for a space: " << endl;
    char temp[9][9];
    for (int row = 0; row<9; row++){
        for (int column=0; column<9; column++){
            cin >> temp[row][column];
            sudoku[row][column] = temp[row][column] - '0';
        }
    }
    return;
}

//output sudoko
void output() {
    cout << endl;
    for (int row = 0; row<9; row++){
        for (int column=0; column<9; column++){
            cout << sudoku[row][column] << " ";
            if (column % 3 == 2) cout << "  ";
            if (column % 9 == 8) cout << endl;
            if (row % 3 == 2 && column % 9 == 8) cout << endl;

        }
    }
}

//judge if key is suitable for position n
bool judge (int n, int key){
    //check the column
    for (int row=0; row<9; row++){
        int column = n % 9;
        if (sudoku[row][column] == key) return false;
    }
    
    //check the row
    for (int column=0; column<9; column++){
        int row = n/9;
        if (sudoku[row][column] == key) return false;

    }
    
    //check every 3*3 box
    int R = n/9/3*3;
    int C = n%9/3*3;
    
    for (int i=R; i<R+3; i++){
        for (int j=C; j<C+3; j++){
            if (sudoku[i][j] == key) return false;
        }
    }
    
    return true;
}

//Depth first search
int dfs (int n){

	//if n=81, the all the numbers has been judged
    if (n==81){
        ok = true;
        return 0;
    }
    
    //if there is a number, then skip
    if (sudoku[n/9][n%9] != 0){
        dfs(n+1);
    }
    else {
        for (int i=1; i<10; i++){
            if (judge(n, i)){
                sudoku[n/9][n%9] = i;
                dfs(n+1);
                if (ok == true) {return 0;}
                else{sudoku[n/9][n%9] = 0;}
            }
        }
    }
}












