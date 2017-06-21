#include <iostream>
#include <string>
#include <math.h>

using namespace std;

//find the number of comparisons inside each sub match as well

string text,pattern;
int comp_count=0,tp=0,pp=0,m_count=0;
int* res,resp=0;

void match(){
    while(tp<text.length())
    {
        comp_count++;
        if(text[tp]==pattern[pp])
        {
            m_count++;
            tp++;
            pp++;
            if(m_count==pattern.length()){
                pp=0;
                m_count=0;
                res[resp] = tp-pattern.length()+1;
                resp++;
            }
        }
        else{
            tp++;
        }
    }
    if(resp!=0)
    {
        cout<<"\nMatch Found at - ";
        for(int i=0;i<resp;i++)
            cout<<"["<<res[i]<<"] ";
        cout<<"\nComparison Count - "<<comp_count<<endl;
    }
    else
    {
        cout<<"\nNo Match Found";
        cout<<"\nComparison Count - "<<comp_count<<endl;
    }
    comp_count=0; tp=0; pp=0; m_count=0; resp=0;
}

bool check(){
    if(pattern.length()<=text.length())
        return false;
    else
        return true;
}

int main()
{
    /*cout<<"Pattern Matcher V0.1\n";
    cout<<"\nEnter the data text - ";
    getline(cin, text, '\n');
    cout<<"\nEnter the pattern to search for - ";
    getline(cin, pattern, '\n');*/
    text = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    pattern = "ab";
    while(check()){
        cout<<"\nInvalid Pattern Reenter Pattern - ";
        getline(cin, pattern, '\n');
    }
    res = new int[1000];
    match();
    return 0;
}
