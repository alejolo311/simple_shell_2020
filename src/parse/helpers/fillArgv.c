#include "newShell.h"

void fillArgv()
{
    int j = 0;
    char *line;

    line = strdup(shellData.readData.line);
    
    for (j = 1; ; j++, line = NULL)
	{	
        line = strtok(line, " \t\n"); 
        shellData.parseData.av[j] = line;
		if (line == NULL)
			break;
	}
    free(line); 
}
