#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include "frequency.h"
using namespace std;

void Init(Code &code)
{
    for (int i = 0; i < SIZE; i++)
    {
        code.name[i] = "";
        code.frequency[i] = 0;
    }
    code.size = 0;
}

int FindString(string s, string set[SIZE], int size)
{
    string sub = s.substr(0, 24);
    for (int i = 0; i < size; i++)
        if (sub == set[i].substr(0, 24))
            return i;
    return -1;
}

bool CheckName(string s)
{
    int len{(int)s.length()};
    if (isnumber(s[0]))
        return false;
    for (int i = 0; i < len; i++)
        if (!isalnum(s[i]) && s[i] != '_')
            return false;
    return true;
}

void Process(Code &code)
{
    string reserve[12] = {"if", "else", "while", "for",
                          "switch", "case", "break", "return", "void", "int", "float", "char"};
    string delimiter = "+-*/%>=<(){}[],;!?:\"\' ";
    string line;

    bool add = false;
    while (cin >> line)
    {
        vector<string> tokens;
        boost::split(tokens, line, boost::is_any_of(delimiter));
        int ptr = 0;

        for (string token : tokens)
        {
            ptr += token.length() + 1;
            if (token.length() == 0)
                continue;

            int isExisted = FindString(token, code.name, SIZE);
            if (isExisted != -1)
                code.frequency[isExisted]++;

            int isReserve = FindString(token, reserve, 12);

            if (add)
            {
                if (isReserve == -1 && isExisted == -1 && CheckName(token))
                {
                    int size = code.size;
                    code.name[size] = token.substr(0, 24);
                    code.frequency[size]++;
                    code.size++;
                }
                add = false;
            }

            if (isReserve || (line.length() >= ptr && line[ptr] == ','))
                add = true;
        }
    }
}

void PrintAnswer(Code &code)
{
    for (int i = 0; i < code.size; i++)
        cout << code.name[i] << ' ' << code.frequency[i] << endl;
}