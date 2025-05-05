/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurczyk <ajurczyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:37:56 by ajurczyk          #+#    #+#             */
/*   Updated: 2025/05/05 16:03:42 by ajurczyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_ac_av(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 5)
		exit(1);
	while (av[2][i])
		i++;
	if (i == 0)
		exit(1);
	i = 0;
	while (av[3][i])
		i++;
	if (i == 0)
		exit(1);
}

int	check_command(char **ep, char *cmd)
{
	char	**env_paths;

	while (*ep)
	{
		if (ft_strncmp(*ep, "PATH", 4) == 0)
			break ;
		ep++;
	}
	env_paths = ft_split(*ep + 5, ':');
	if (return_path(env_paths, cmd) == 0)
	{
		ft_free(env_paths);
		return (1);
	}
	else
		return (0);
}
