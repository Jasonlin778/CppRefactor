#include <string>
#define SIZE 50
using namespace std;

class Code{
    private:
        string name[SIZE];
        int frequency[SIZE];
        int size;
        int FindString(string s,string set[SIZE],int size);
        bool CheckName(string s);
    public:
        Code(void);
        void Process(void);
        void PrintAnswer(void);
};