#include "newShell.h"
void prompt(){

    if (shellData.interactive == true && shellData.readData.readStatus != -1)
        write(1, "$ ", 2);

    if (shellData.readData.readStatus == -1 && shellData.interactive == true)
	{	
        write(1, "\n", 1);
		exit(0);
	}
}