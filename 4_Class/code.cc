#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include "frequency.h"
using namespace std;

int Code::FindString(string s, string set[SIZE], int size)
{
    string sub = s.substr(0, 24);
    for (int i = 0; i < size; i++)
        if (sub == set[i].substr(0, 24))
            return i;
    return -1;
}

bool Code::CheckName(string s)
{
    int len{(int)s.length()};
    if (isnumber(s[0]))
        return false;
    for (int i = 0; i < len; i++)
        if (!isalnum(s[i]) && s[i] != '_')
            return false;
    return true;
}

Code::Code(void)
{
    for (int i = 0; i < SIZE; i++)
    {
        name[i] = "";
        frequency[i] = 0;
    }
    size = 0;
}

void Code::Process(void)
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

            int isExisted = FindString(token, name, SIZE);
            if (isExisted != -1)
                frequency[isExisted]++;

            int isReserve = FindString(token, reserve, 12);

            if (add)
            {
                if (isReserve == -1 && isExisted == -1 && CheckName(token))
                {
                    name[size] = token.substr(0, 24);
                    frequency[size]++;
                    size++;
                }
                add = false;
            }

            if (isReserve || (line.length() >= ptr && line[ptr] == ','))
                add = true;
        }
    }
}

void Code::PrintAnswer(void)
{
    for (int i = 0; i < size; i++)
        cout << name[i] << ' ' << frequency[i] << endl;
}