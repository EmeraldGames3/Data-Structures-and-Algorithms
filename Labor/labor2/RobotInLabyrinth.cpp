#include <fstream>
#include <iostream>

char readMatrixFromFile(int &rows, int &columns, const char *fileName) {
    std::fstream fin;
    fin.open(fileName);

    rows = 0;
    columns = 0;
    char temp;

    while (fin >> temp){
        columns++;
        if(fin.peek() == '\n')
            rows++;
    }
    rows++;

    std::cout << rows << ' ' << columns << '\n';

    fin.close();
    return 0;
}