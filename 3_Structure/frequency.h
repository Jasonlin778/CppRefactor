#include <string>
#define SIZE 50
using namespace std;

struct Code{
    string name[SIZE];
    int frequency[SIZE];
    int size;
};


void Init(Code &code);
int FindString(string s,string set[SIZE],int size);
bool CheckName(string s);
void Process(Code &code);
void PrintAnswer(Code &code);