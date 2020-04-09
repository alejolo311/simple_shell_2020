#include "read.h"
#include "newShell.h"
void _read(){

    shellData.readData.line = NULL;
    shellData.readData.len = 0;

    fflush(stdin);
    
    shellData.readData.readStatus = getline(&shellData.readData.line, 
                                             &shellData.readData.len, 
                                             stdin);
}