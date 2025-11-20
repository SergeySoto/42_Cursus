/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 00:09:03 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/10/04 00:09:03 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	set_cmd(char **argv, t_pipe *pipex)
{
	pipex->cmd1 = ft_split(argv[2], ' ');
	pipex->cmd2 = ft_split(argv[3], ' ');
	if (!pipex->cmd1 || !pipex->cmd1[0])
	{
		free_all(pipex->cmd1, NULL);
		free_all(pipex->cmd2, NULL);
		free_all(pipex->env_path, NULL);
		printf_error(argv[2], 127);
	}
	if (!pipex->cmd2 || !pipex->cmd2[0])
	{
		free_all(pipex->cmd1, NULL);
		free_all(pipex->cmd2, NULL);
		free_all(pipex->env_path, NULL);
		printf_error(argv[3], 127);
	}
	pipex->path1 = find_command(pipex->cmd1[0], pipex->env_path);
	pipex->path2 = find_command(pipex->cmd2[0], pipex->env_path);
}

char	*find_command(char *cmd, char **env_path)
{
	int		i;
	char	*aux;
	char	*full_path;

	i = 0;
	full_path = NULL;
	while (env_path[i])
	{
		aux = ft_strjoin(env_path[i], "/");
		full_path = ft_strjoin(aux, cmd);
		free(aux);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free_all(NULL, full_path);
		i++;
	}
	return (NULL);
}

void	set_files(t_pipe *pipex, char **argv)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile == -1)
	{
		ultimate_free(pipex);
		printf_error("Error: Fail opening infile\n", 1);
	}
	pipex->outfile = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (pipex->outfile == -1)
	{
		close(pipex->infile);
		ultimate_free(pipex);
		printf_error("Error: Fail opening outfile\n", 1);
	}
}

void	set_pipe(t_pipe *pipex)
{
	if (pipe(pipex->pipefd) == -1)
	{
		close(pipex->infile);
		close(pipex->outfile);
		ultimate_free(pipex);
		printf_error("Error: Construction pipe failed\n", 1);
	}
}
