//String length, copy and concatenate using inbuilt functions

#include<iostream>
#include<cstring>

using namespace std;

int main(){

    char a[1000] = "apple";
    char b[1000];

    //StringLength
    cout<<strlen(a)<<endl;

    //StrCopy
    strcpy(b, a);           //destination followed by source.

    cout<<b<<endl;

    //Compare
    cout<<strcmp("apple", a)<<endl;     //ouputs 0 if strings are equal, random number if not.

    //Concatenate
    char web[] = "www.";
    char domain[] = "facebook.com";

    cout<<strcat(web, domain)<<endl;

}