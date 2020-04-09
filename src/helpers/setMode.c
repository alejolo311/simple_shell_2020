#include <newShell.h>

void setMode()
{
    if (isatty(STDIN_FILENO) == 0)
        shellData.interactive = false;
    else
        shellData.interactive = true;
}