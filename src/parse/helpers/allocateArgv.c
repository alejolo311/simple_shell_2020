#include "newShell.h"

void allocateArgv(void){
    
    char *line;
    int ac;

    line = strdup(shellData.readData.line);

    for (ac = 1;(line = strtok(line, " \t\n")) ; ac++, line = NULL)
			if (line == NULL)
				break;
    shellData.parseData.ac = ac;
    shellData.parseData.av = malloc((++shellData.parseData.ac + 2) * sizeof(char **));
    shellData.parseData.av[0] = shellData.argv[0];
    free(line);
}
