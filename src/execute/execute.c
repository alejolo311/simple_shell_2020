#include "newShell.h"
void _execute(){
    
    pid_t pid;

    pid = fork();
	if (pid == -1)
        exit(1);
	else if (pid == 0)
	{	shellData.executeData.execveCode = execve(shellData.parseData.av[1], (shellData.parseData.av + 1), shellData.env);
		if (shellData.executeData.execveCode == -1)
			exit(127);
	} else
	{	wait(&shellData.executeData.statusCode);
		if (WIFEXITED(shellData.executeData.statusCode))
			shellData.executeData.returnCode = WEXITSTATUS(shellData.executeData.statusCode);
	}
}