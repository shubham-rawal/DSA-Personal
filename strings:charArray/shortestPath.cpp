//Given a long route containing directions (NSEW), find the shortest path to reach the location.

#include<iostream>

using namespace std;

int main(){
    int route[1000];
    cin.getline(route, 1000);

    //to store displacement in x and y direction, starting from origin.
    int x = 0;
    int y = 0;

    for(int i = 0 ; route[i]!='\0'; i++){
        switch (route[i])
        {
        case 'N':
            y++;
            break;
        case 'S':
            y--;
            break;
        case 'E':
            x++;
            break;
        case 'W':
            x--;
            break;
        default:
            break;
        }
    } 

    if(x>=0 && y>=0){
        while(y--){
            cout<<'N';
        }
        while(x--){
            cout<<'E';
        }
    }

    if(x<=0 && y>=0)
    {
        while(y--){
            cout<<'N';
        }
        while(x++)
            cout<<'W';
    }

    if(x<=0 && y<=0){
        while(y++)
            cout<<'S';
        while(x++)  cout<<'W';
    }

    if(x>=0 && y<=0){
        while(y++)
            cout<<'S';
        while(x--)  cout<<'E'; 
    }
}