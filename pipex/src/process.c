/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 00:10:12 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/10/04 00:10:12 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	check_command_i(char **argv, t_pipe *pipex)
{
	(void)argv;
	if (!pipex->path1)
	{
		free_all(pipex->env_path, NULL);
		free_all(pipex->cmd1, NULL);
		free_all(pipex->cmd2, NULL);
		free_all(NULL, pipex->path2);
		printf_error(argv[2], 127);
	}
}

void	check_command_ii(char **argv, t_pipe *pipex)
{
	if (!pipex->path2)
	{
		free_all(pipex->env_path, NULL);
		free_all(pipex->cmd1, NULL);
		free_all(pipex->cmd2, NULL);
		free_all(NULL, pipex->path1);
		printf_error(argv[3], 127);
	}
}

void	first_child(t_pipe *pipex, char **envp, char **argv)
{
	pipex->pid1 = fork();
	if (pipex->pid1 == -1)
	{
		ultimate_close(pipex);
		ultimate_free(pipex);
		printf_error("Error: Fork first child failed\n", 1);
	}
	else if (pipex->pid1 == 0)
	{
		dup2(pipex->infile, STDIN_FILENO);
		dup2(pipex->pipefd[1], STDOUT_FILENO);
		close(pipex->infile);
		close(pipex->pipefd[0]);
		close(pipex->pipefd[1]);
		check_command_i(argv, pipex);
		if (execve(pipex->path1, pipex->cmd1, envp) == -1)
		{
			ultimate_free(pipex);
			printf_error(pipex->cmd1[0], 126);
		}
	}
}

void	second_child(t_pipe *pipex, char **envp, char **argv)
{
	pipex->pid2 = fork();
	if (pipex->pid2 == -1)
	{
		ultimate_close(pipex);
		ultimate_free(pipex);
		printf_error("Error: Fork second child failed\n", 1);
	}
	else if (pipex->pid2 == 0)
	{
		dup2(pipex->pipefd[0], STDIN_FILENO);
		dup2(pipex->outfile, STDOUT_FILENO);
		ultimate_close(pipex);
		check_command_ii(argv, pipex);
		if (execve(pipex->path2, pipex->cmd2, envp) == -1)
		{
			ultimate_free(pipex);
			printf_error(pipex->cmd2[0], 126);
		}
	}
}

int	father(t_pipe *pipex, char**envp, char **argv)
{
	first_child(pipex, envp, argv);
	second_child(pipex, envp, argv);
	ultimate_close(pipex);
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, &pipex->status_error, 0);
	ultimate_free(pipex);
	return (WEXITSTATUS(pipex->status_error));
}
