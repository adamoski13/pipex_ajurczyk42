#include "pipex.h"

void	wrong_file(char *s)
{
    if (access(s, X_OK) != 0)
    {
        ft_putstr_fd("pipex: permission denied: ", STDERR_FILENO);
        ft_putstr_fd(s, STDERR_FILENO);
        ft_putstr_fd("\n", STDERR_FILENO);
    } else
    {
	    ft_putstr_fd("pipex: no such file or directory :", STDERR_FILENO);
        ft_putstr_fd(s, STDERR_FILENO);
        ft_putstr_fd("\n", STDERR_FILENO);
    }
}

void	wrong_command(char *s)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd("command not found :", STDERR_FILENO);
    ft_putstr_fd(s, STDERR_FILENO);
    ft_putstr_fd("\n", STDERR_FILENO);
	exit(1);
}