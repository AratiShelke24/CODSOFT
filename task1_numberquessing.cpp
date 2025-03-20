#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main() {
  srand(time(0));
int number = rand() % 100 + 1;
int guess;

cout << " guess a number between 1 and 100"; <<end1;

while(true) {
cin>>guess;
if (guess==number){
cout <<"Correct! you guessed the number"; <<end1;

break;
} 
else if (guess>number) {
  cout <<"Too high, try again:" <<end1;
} 
else { 
cout<<"Too low , try again:"<< end1;
}
}
return 0;
}
