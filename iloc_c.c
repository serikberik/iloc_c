#include <stdio.h>

int main(int argc, char* argv[])
{
    //2 arg = path to dataFile
    char const* const dataFile = argv[1];
    FILE* hFile = fopen(dataFile, "r") ;
    
    char curLine[256];
    while (fgets(curLine, sizeof(curLine), hFile)){
        printf("%s", curLine);
    }
    fclose(hFile);
    return 0;
}