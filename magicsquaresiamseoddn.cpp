#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int>>generateOddMAgicSquare(int n){
    vector<vector<int>>magic(n,vector<int>(n,0));
    //Creates an n × n matrix filled with 0 //vector of vectors a 2d vector
    //named magic that contains n vectors with n size and element 0

   int i=0,j=n/2; //starting in middle of first row ..mid column
for(int num =1; num<=n*n;num++){
    magic[i][j]=num;
}
int new_i= (i-1+n)%n;
int new_j = (j-1+n)%n;
if(magic[new_i][new_j]!=0){
     (i=i+1)%n;

}
else{
    i=new_i;
    j=new_j;
}
return magic;
}
void printMAgicSqaure(const vector<vector<int>>&magic){
    for(const auto&row:magic){
        for(int num:row){
            cout<<num<<"\t";
        }
        cout<<endl;
    }
}
int main() {
 int n;
 cin>>n;
 if(n%2==0){
    return 1;
 }
 vector<vector<int>>magic= generateOddMAgicSquare(n);
 printMAgicSqaure(magic);
    return 0;
}