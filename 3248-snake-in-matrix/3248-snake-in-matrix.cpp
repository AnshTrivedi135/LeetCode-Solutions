class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        
// class Solution {
// public:
//     int finalPositionOfSnake(int n, vector<string>& commands) {
//         int row = 0, col = 0;

//         for (string command : commands) {
//             if (command == "UP") {
//                 row--;
//             }
//             else if (command == "DOWN") {
//                 row++;
//             }
//             else if (command == "LEFT") {
//                 col--;
//             }
//             else if (command == "RIGHT") {
//                 col++;
//             }
//         }

//         return row * n + col;
    int row=0,col=0;
    for(string command:commands){
        if(command=="UP"){
            row--;
        }
        else if(command =="DOWN"){
            row++;
        }
        else if(command=="LEFT"){
            col--;
        }
        else if(command=="RIGHT"){
            col++;
        }
    }
    return row*n+col;
        
    }
};