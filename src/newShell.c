#include "newShell.h"

data_t shellData;

int main(int argc, char **argv, char **env)
{
    shellData.argc = argc;
    shellData.argv = argv; 
    shellData.env = env;

    setMode();
    do {
        prompt();
        _read();
        _parse();
        _execute();
    } while (true);
    

    return (0);
}
