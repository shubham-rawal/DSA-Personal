#include<iostream>
using namespace std;


//Pass by Value - a copy of original variable is created.
void applyTax(int income){
    float tax = 0.10;
    income -= tax*income;
}

//Pass By Reference - no copy is created, the address of the original variable is passed.
void applyTaxCorrectly1(int &income){
    float tax = 0.10;
    income -= tax*income;
}

//Pass By reference using pointers
void applyTaxCorrectly2(int *incomePtr){
    float tax = 0.10;
    *incomePtr = *incomePtr - tax*(*incomePtr);
}
int main(){
    int income = 100;
    applyTax(income);

    cout<<income<<endl;

    // applyTaxCorrectly1(income);
    applyTaxCorrectly2(&income);

    cout<<"correct income is "<<income<<endl;
}