/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:33:56 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/10/02 18:33:56 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

t_pipe	pipe_init(int argc)
{
	t_pipe	pipex;

	if (argc != 5)
		printf_error("Missing arguments\n", 1);
	pipex.infile = -1;
	pipex.outfile = -1;
	pipex.pipefd[0] = -1;
	pipex.pipefd[1] = -1;
	pipex.pid1 = -1;
	pipex.pid2 = -1;
	pipex.cmd1 = NULL;
	pipex.cmd2 = NULL;
	pipex.path1 = NULL;
	pipex.path2 = NULL;
	pipex.env_path = NULL;
	pipex.status_error = 0;
	return (pipex);
}

void	find_paths(char **envp, t_pipe *pipex)
{
	int		i;
	char	*path_found;

	i = 0;
	path_found = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_found = envp[i] + 5;
			break ;
		}
		i++;
	}
	if (!path_found || !envp[0])
		printf_error("Environment path not found\n", 1);
	else
		pipex->env_path = ft_split(path_found, ':');
	return ;
}
