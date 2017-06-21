//Open Hashing
//V1.0
//template based hashing
//Single word mathcing is implemented
//Author: E.V.Subramanian

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <list>

#define m 13

using namespace std;

list<string>* cell;
string input;
string* words;
int comp_count = 0, len=0;

void global_init(){
    cell = new list<string>[m];
    cout<<"Enter the String -> ";
    getline(cin, input, '\n');
}

string* split_general(string* in, string* out, int* size){
    int w_space = 0;
    //count the spaces
    for(int i = 0; i < (*in).length(); i++)
        if((*in)[i]==' ')
            w_space++;
    //generate words
    *size = w_space+1;
    out = new string[w_space+1];
    int fill = 0; //which word to fill
    string temp = "";
    for(int i = 0; i < (*in).length(); i++)
    {
        if((*in)[i]==' '){
            out[fill++] = temp;
            temp = "";
        }
        else
            temp += (*in)[i];
    }
    out[fill] = temp;
    return out;
}

int hash_val(string x){
    int val = 0;
    for(int i = 0; i < x.length(); i++){
        int temp = (int) x[i];
        if(temp>90)
            temp = temp-32;
        val += (temp-64);
    }
    return val%m;
}

void hash(int length){
    for(int i = 0; i < length; i++)
        cell[hash_val(words[i])].push_front(words[i]);
}

void search(){
    cout<<endl<<"Enter String to search -> ";
    string key, *key_list;
    int key_wc = 0,match_count=0;
    getline(cin,key,'\n');
    key_list = split_general(&key,key_list,&key_wc);
    for(int i=0; i<key_wc; i++){
        string key_t = key_list[i];
        int key_val = hash_val(key_t);
        for (list<string>::const_iterator iter = cell[key_val].begin(); iter != cell[key_val].end(); iter++)
        {
            if(*iter == key_t)
            {
                comp_count++;
                match_count++;
                cout<<"\nMatch Found - "<<key_t<<endl;
                break;
            }
            else
                comp_count++;
        }
    }
    if(match_count==key_wc)
        cout<<"\nComplete Match Found || Comparison Count - "<<comp_count<<endl;
    else
        cout<<"\nComplete Match NOT Found || Comparison Count - "<<comp_count<<endl;
}

int main(){
    global_init();
    words = split_general(&input,words,&len);
    hash(len);
    search();
    return 0;
}
