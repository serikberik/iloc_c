#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//return token from line[index]
char* iloc(char* line, int index)
{
	char* tok = strtok(line, "<> \t");
	while(tok!=NULL)
	{
		//countdown while not zero
		if(!index--)
		{
				printf("%s\n",tok); //lldbg
				return tok;
		}

		tok=strtok(NULL,"<> \t\n");
	}
	return NULL;
}

int main(int argc, char* argv[])
{
    //speedtest
    clock_t start =  clock();

    //2 arg = path to dataFile
    //3 arg = column index

    FILE* hFile = fopen(argv[1], "r");
    if (hFile == NULL) 
	{
			printf("fopen error\n"); 
			exit(1);
	}

    char curLine[256];
    printf("read column index %s\n", argv[2]);

	//walk trougth all line in file
    while (fgets(curLine, sizeof(curLine), hFile))
	{
        //printf("%s", curLine);
        char* tmp = strdup(curLine);
		iloc(tmp, atoi(argv[2]));
        free(tmp);    
    }
    fclose(hFile);

    clock_t end = clock();
    printf("elapsed time: [%.2f]ms\n", (double)((end-start)*1000/CLOCKS_PER_SEC));

    return 0;
}
