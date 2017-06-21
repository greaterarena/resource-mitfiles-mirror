//Horsepool String Matching
//V1.0
//Author: E.V.Subramanian

#include <iostream>
#include <map>
#include <string>

using namespace std;

map <char,int> shiftTable;

string pattern, texty;

int check, comparisonCount = 0;

string getPattern(){
    string temp;
    getline(cin,temp,'\n');
    return temp;
}

void shiftTableForm(string in){
    char x = 65;
    while(x<=90)
        shiftTable[x++] = in.length();
    shiftTable[' '] = in.length();
    for(int j=0; j<=in.length()-2; j++)
        shiftTable[in[j]] = in.length() - 1 - j;
}

void displayShiftTable(){
    map<char,int>::iterator iterate;
    cout<<"\nShift Table"<<endl;
    for(iterate = shiftTable.begin(); iterate != shiftTable.end(); iterate++)
        cout<<iterate->first<<" ";
    cout<<endl;
    for(iterate = shiftTable.begin(); iterate != shiftTable.end(); iterate++)
        cout<<iterate->second<<" ";
    cout<<endl;
}

int horsepoolMatching(string ptrn, string text){
    int i = ptrn.length()-1;
    while(i<text.length()){
        int k = 0;
        while(k<ptrn.length() && ptrn[ptrn.length()-1-k]==text[i-k]){
            k += 1;
            comparisonCount++;
        }
        if(k==ptrn.length())
            return i-ptrn.length()+1;
        else
            i = i + shiftTable[text[i]];
    }
    return -1;
}

int main()
{
    cout<<"Enter Pattern - ";
    pattern = getPattern();
    shiftTableForm(pattern);
    displayShiftTable();
    cout<<"\nEnter Text - ";
    texty = getPattern();
    check = horsepoolMatching(pattern,texty);
    if(check!=-1)
        cout<<"\nMatch Found at - "<<check<<" - Comparison Count - "<<comparisonCount;
    else
        cout<<"\nNo Match Found - Comparison Count - "<<comparisonCount;
    return 0;
}
