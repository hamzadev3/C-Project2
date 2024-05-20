#include <iostream>
using namespace std;
//func test
bool adjtest (int q[], int c){
int array[8][4]={
{-1,-1,-1,-1},  // index 0 is has no tests, -1 is a placeholder 
{0,-1,-1,-1},  // square 1 checks square 0
{1,-1,-1,-1},  // square 2 checks square 1 
{0,1,2,-1},  // square 3 checks squares 0 1 and 2
{1,2,3,-1},  // square 4 checks squares 1 2 and 3
{0,3,4,-1},  // square 5 checks squares 0 3 and 5
{3,4,5,-1},  // square 6 checks squares 3 4 and 5
{2,4,6,-1}  // square 7 checks squares 2, 4, and 6
};
//row test
for(int i=0; i<c; i++){
if(q[i]==q[c]) return false;
}
//for loop parses except for placeholders 
//checks for any threats in suited positions 
for(int i=0; array[c][i]!=-1; i++){
if(abs(q[c]-q[array[c][i]])==1) return false; 
}
return true;
};
//print func
void print(int q[]){
int answer=1;
cout<<"Answer "<<answer++<<":"<<endl; 
//format answer like 8 cross board
cout<<"  "<<q[1]<<"  "<<q[2]<<endl;
cout<<q[0]<<"  "<<q[3]<<"  "<<q[4]<<"  "<<q[7]<<endl;
cout<<"  "<<q[5]<<"  "<<q[6]<<endl;
}
//backtrack function
void backtrack(int &c){
c--; //just like 8 queens, move back previous column 
if(c==-1) exit(1); //exits after no solutions left
};
int main(){
int q[8]={1}, c=0; // c tracks the current spot 
bool backtrackyet=false; //backtrack tracker 
while(true){ // neccessary to keep going until all solutions found 
while(c<8){
if(!backtrackyet) q[c]=0; // if no backtrack occured, reset column to 0
while(q[c]<9){
q[c]++;
if(q[c]==9){ //if placement exceeds 8, backtrack 
backtrack(c);
continue;
}
if(adjtest(q,c)) break; // when valid position found, break out of loop
}
c++; // move to next column 
backtrackyet=false; // reset backtrack tracker 
}
print(q); // code only comes here when criteria met 
backtrack(c);
backtrackyet=true;
}
return 0;
}

