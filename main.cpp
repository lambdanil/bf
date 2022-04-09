#include<iostream>
#include<string.h>

using std::cout;
using std::cin;

void evaluate(char* cmd) {
    char* ptrMem;
    ptrMem = new char[30000];
    char* ptr;
    ptr = ptrMem;
    char* cins;
    bool inLoop = false;
    cins = cmd;
    ptrdiff_t bytes = cins-cmd;
    int cmdlen = strlen(cmd);
    while (true) { 
        if (inLoop == false) {
            bytes = cins-cmd;
            if (bytes > cmdlen-1) break;
        }
        switch (*cins) {
            case '>':
                ++ptr;
                break;
            case '<':
                --ptr;
                break;
            case '+':
                ++(*ptr);
                break;
            case '-':
                --(*ptr);
                break;
            case '.':
                cout << *ptr;
                break;
            case ',':
                cin >> *ptr;
                break;
            case '[':
                inLoop = true;
                if (*ptr == 0) {
                    inLoop = false;
                    int depth = 1;
                    while (depth != 0) {
                        ++cins;
                        if (*cins == '[') ++depth;
                        else if (*cins == ']') --depth;
                    }
                }
                break;
            case ']':
                int depth = 1;
                while (depth != 0) {
                    --cins;
                    if (*cins == ']') ++depth;
                    else if (*cins == '[') --depth;
                }
                --cins;
                break;
        };
    ++cins;
    }
    delete ptrMem;
}

int main(int argc, char** argv) {
    char* cmd;
    cmd = new char[500000];
    //cmd = argv[1];
    int index = 0;
    bool newline = true;
    bool isComment = false;
    int i = 0;
    for (int i = 0; i < strlen(argv[1]); i++) {
        if (argv[1][i] == '%') newline = false;
        if (argv[1][i] == '\n') newline = true;
        if (argv[1][i] == '#') {
            if (isComment) isComment=false;
            else isComment=true;
        }
        if ((argv[1][i] == '>' || argv[1][i] == '<' || argv[1][i] == '+' || argv[1][i] == '-' || argv[1][i] == '[' || argv[1][i] == ']' || argv[1][i] == ',' || argv[1][i] == '.') && newline && isComment == false) {
            cmd[index] = argv[1][i];
            index++;
        }
    }
    evaluate(cmd);
    delete[] cmd;
}
