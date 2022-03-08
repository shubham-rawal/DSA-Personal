/*
    Given a vector that contains the daily stock price, find the span of the stock's price for the current day. The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backwards), for which the price of the stock was less than or equal to today's price.
*/
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//Stock Span problem

void stockSpan(int prices[], int n, int span[]){
    stack<int> s;       //indices of the days
    s.push(0);          

    span[0] = 1;

    //loop for the rest of the days
    for(int i = 1; i<n; i++){
        
        int currentPrice = prices[i];
        //topmost element that is higher than the currentPrice
        while(!s.empty() and prices[s.top()]<=currentPrice){
            s.pop();
        }

        if(!s.empty()){
            int prev_highest_index = s.top();
            span[i] = i - prev_highest_index;
        }
        else    span[i] = i+1;

        //push this element into the stack
        s.push(i);
    }
}


int main(){
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(prices)/sizeof(int);

    int span[100000] = {0};

    stockSpan(prices, n, span);

    for(int i = 0; i<n; i++){
        cout<<span[i]<<" ";
    }
    cout<<endl;

    return 0;
}