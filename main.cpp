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
    cmd = argv[1];
    evaluate(cmd);
}