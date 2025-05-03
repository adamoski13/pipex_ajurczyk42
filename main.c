#include "pipex.h"

int main(int ac, char **av, char **ep)
{
    int pipe1[2];
    int pid;

    if (ac != 5)
        return 0;
    if (open(av[1], O_RDWR) < 0)
        wrong_file(av[1]);
    if (pipe(pipe1) == -1)
        return 0;
    pid = fork();
    if (pid < 0)
        return 0;
    if (pid == 0)
        do_write(pipe1, av, ep);
    else
        do_read(pipe1, av, ep);
    close(pipe1[0]);
    close(pipe1[1]);
    waitpid(pid, NULL, 0);
    return 0;
}