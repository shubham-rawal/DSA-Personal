
#include <iostream>
using namespace std;


//Given a sentence, find the number of alphabets, digits & spaces in the sentences.
int main() {
	// your code goes here

    //store and then count
    //read one by one while counting <---------------- more efficient here as we do not need to store


    int ch = cin.get();

    int alpha = 0;
    int digits = 0;
    int spaces = 0;

    while(ch!= '\n'){
        if(isalpha(ch))
            alpha++;
        else if(isdigit(ch))
            digits++;
        else if(ch ==' ')
            spaces++; 

        ch = cin.get();
    }

    cout<<"Alphabets : " <<alpha<<endl;
    cout<<"Digits : "<<digits<<endl;
    cout<<"Spaces : "<<spaces<<endl;

}
