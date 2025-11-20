/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:59:39 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/27 15:59:39 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "./libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <signal.h>

typedef struct t_pipe
{
	int		infile;
	int		outfile;
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	char	*path1;
	char	*path2;
	char	**cmd1;
	char	**cmd2;
	char	**env_path;
	int		status_error;
}			t_pipe;

//Utils
void	print_array(char **argv);
void	ultimate_free(t_pipe *pipex);
void	ultimate_close(t_pipe *pipex);
void	free_all(char **array, char *chr);
void	printf_error(char *msg, int num_error);
//Arguments
t_pipe	pipe_init(int argc);
void	find_paths(char **envp, t_pipe *pipex);
//Settings
char	*find_command(char *cmd, char **env_path);
void	set_cmd(char **argv, t_pipe *pipex);
void	set_files(t_pipe *pipex, char **argv);
void	set_pipe(t_pipe *pipex);
//Process
void	check_command_i(char **argv, t_pipe *pipex);
void	check_command_ii(char **argv, t_pipe *pipex);
void	first_child(t_pipe *pipex, char **envp, char **argv);
void	second_child(t_pipe *pipex, char **envp, char **argv);
int		father(t_pipe *pipex, char**envp, char **argv);

#endif