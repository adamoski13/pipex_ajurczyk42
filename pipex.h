#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "libft/libft.h"
# include <fcntl.h>

char    *get_ep_path(char **ep, char *cmd);
int	    open_file(char *file, int in_or_out);
void    do_read(int *pipe1, char **av, char **envp);
void    do_write(int *pipe1, char **av, char **envp);
void	wrong_command(char *s);
void	wrong_file(char *s);

#endif