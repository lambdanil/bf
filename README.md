# bf
A simple brainfuck interpreter in C++

### Build
```g++ main.cpp -O2 -o bf```

### Usage
```./bf '>+.' # Your code here```

```./bf "$(cat file.bf) # To read from file"```

* Lines after '%' are considered a comment
* Space between 2 '#' is considered a comment
