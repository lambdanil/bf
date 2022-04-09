# bf
A simple brainfuck interpreter in C++

### Build
```
g++ main.cpp -O2 -o bf
```

### Usage
```
./bf '>+.' # Your code here
```

```
./bf "$(cat file.bf)" # To read from file
```

### The compiler allows building brainfuck into c++ code, much faster than using the interpreter
```
g++ compiler.cpp
./a.out "$(cat pg)" > code.cpp
g++ -O2 code.cpp
./a.out
```

* Lines after '%' are considered a comment
* Space between 2 '#' is considered a comment
