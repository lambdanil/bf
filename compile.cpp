#include<iostream>
#include<string.h>

using std::cout;
using std::cin;
using std::string;

void evaluate(char* cmd, string* output) {
    *output += "#include<iostream>\n";
    *output += "int main() {\n";
    *output += "char* ptrMem;\n";
    *output += "ptrMem = new char[30000];\n";
    *output += "char* ptr;\n";
    *output += "ptr = ptrMem;\n";
    char* cins;
    cins = cmd;
    ptrdiff_t bytes = cins-cmd;
    int cmdlen = strlen(cmd);
    while (true) { 
        bytes = cins-cmd; // Calculate memory between current instruction and last instruction
        if (bytes > cmdlen-1) break; // Probably faster than comparing memory between last instruction and current instruction
        switch (*cins) {
            case '>':
                *output += "++ptr;\n";
                break;
            case '<':
                *output += "--ptr;\n";
                break;
            case '+':
                *output += "++(*ptr);\n";
                break;
            case '-':
                *output += "--(*ptr);\n";
                break;
            case '.':
                *output += "std::cout << *ptr;\n";
                break;
            case ',':
                *output += "std::cin >> *ptr;\n";
                break;
            case '[':
                *output += "while (*ptr) {\n";
                break;
            case ']':
                *output += "}\n";
                break;
        };
    ++cins;
    }
    *output += "};\n";
}

int main(int argc, char** argv) {
    char* cmd;
    cmd = new char[100000];
    //cmd = argv[1];
    int index = 0;
    bool newline = true;
    bool isComment = false;
    string* output;
    output = new string;
    int i = 0;
    for (int i = 0; i < strlen(argv[1]); i++) {
        if (argv[1][i] == '%') newline = false; // Handle comments
        if (argv[1][i] == '\n') newline = true;
        if (argv[1][i] == '#') {
            if (isComment) isComment=false;
            else isComment=true;
        }
        // This parses the instructions into cmd array
        if ((argv[1][i] == '>' || argv[1][i] == '<' || argv[1][i] == '+' || argv[1][i] == '-' || argv[1][i] == '[' || argv[1][i] == ']' || argv[1][i] == ',' || argv[1][i] == '.') && newline && isComment == false) {
            cmd[index] = argv[1][i];
            index++;
        }
    }
    evaluate(cmd, output); // Call evaluation
    cout << *output;
    delete[] cmd;
    delete output;
}
