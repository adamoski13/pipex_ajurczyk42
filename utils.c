#include "pipex.h"

char *get_ep_path(char **ep, char *cmd)
{
    char **envPaths;
    char *path;

    while (*ep)
	{
		if (ft_strncmp(*ep, "PATH", 4) == 0)
			break ;
		ep++;
	}
    envPaths = ft_split(*ep + 5, ':');
    while (*envPaths)
    {
        path = ft_strjoin(*envPaths, "/");
        path = ft_strjoin(path, cmd);
        if (access(path, X_OK) == 0)
            return (path);
        envPaths++;
    }
    wrong_command(cmd);
    return (NULL);
}

int	open_file(char *file, int in_or_out)
{
	int	ret;

	if (in_or_out == 0)
		ret = open(file, O_RDONLY, 0777);
	if (in_or_out == 1)
		ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (ret == -1)
		exit(0);
	return (ret);
}

void    do_read(int *pipe1, char **av, char **envp)
{
    char *arg0;
    char **args;
    int fd;

    fd = open_file(av[4], 1);
    args = ft_split(av[3], ' ');
    arg0 = get_ep_path(envp, args[0]);
    close(pipe1[1]);
    dup2(fd, 1);
    dup2(pipe1[0], STDIN_FILENO);
    execve(arg0, args, envp);
    close(pipe1[0]);
}

void    do_write(int *pipe1, char **av, char **envp)
{
    char *arg0;
    char **args;
    int fd;

    fd = open_file(av[1], 0);
    args = ft_split(av[2], ' ');
    arg0 = get_ep_path(envp, args[0]);
    close(pipe1[0]);
    dup2(fd, 0);
    dup2(pipe1[1], STDOUT_FILENO);
    execve(arg0, args, envp);
    close(pipe1[1]);
}