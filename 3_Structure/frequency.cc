#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#define SIZE 50
using namespace std;

int FindString(string s,string set[SIZE],int size){
    string sub = s.substr(0,24);
    for(int i = 0;i<size;i++)
        if(sub == set[i].substr(0,24))
            return i;
    return -1;
}

bool CheckName(string s){
    int len { (int)s.length() };
    if(isnumber(s[0])) return false;
    for(int i = 0;i<len;i++)
        if(!isalnum(s[i]) && s[i] != '_')
            return false;
    return true;
}

void PrintAnswer(string set[SIZE],int fre[SIZE],int size){
    for(int i = 0;i<size;i++)
        cout<<set[i]<<' '<<fre[i]<<endl;
}
int main(){
    string reserve[12] = {"if","else","while","for",
        "switch","case","break","return","void","int","float","char"};
    string delimiter = "+-*/%>=<(){}[],;!?:\"\' ";
    string name[SIZE];
    int frequency[SIZE] = {0};
    int size = 0;
    string code;

    bool add = false;
    while(cin>>code){
        vector<string> tokens;
        boost::split(tokens,code,boost::is_any_of(delimiter));
        int ptr = 0;

        for(string token: tokens){
            ptr += token.length() + 1;
            if(token.length() == 0) continue;

            int isExisted = FindString(token,name,SIZE);
            if(isExisted != -1) frequency[isExisted]++;
        
            int isReserve = FindString(token,reserve,12);

            if(add){
                if(isReserve == -1 && isExisted == -1 && CheckName(token)){
                    name[size] = token.substr(0,24);
                    frequency[size]++;
                    size++;
                }
                add = false;
            }

            if(isReserve || (code.length() >= ptr && code[ptr] == ',')) add = true;
        }
    }
    PrintAnswer(name,frequency,size);
}