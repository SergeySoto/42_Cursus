/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:35:52 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/06/06 17:04:36 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char *get__line(int fd, char *line)
{
	int ch_read;
	char *buf;

	if (!line)
		line = ft_strdup("");
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf || !line)
		return (NULL);
	ch_read = 1;
	while (ch_read > 0 && ft_strchr(line, '\n') == NULL)
	{
		ch_read = read(fd, buf, BUFFER_SIZE);
		if (ch_read < 0)
		{
			free(buf);
			free(line);
			line = NULL;
			return (NULL);
		}
		buf[ch_read] = '\0';
		line = ft_strjoin(line, buf);
	}
	free(buf);
	return (line);
}

// char *cut__line(char *line)
// {
// 	int i;
// 	char *aux;
// 	char *rest;

// 	i = 0;
// 	while (line[i] != '\n' && line[i])
// 		i++;
// 	aux = ft_substr(line, 0, i + (line[i] == '\n' ? 1 : 0));
// 	if (!aux)
// 	{
// 		free(line);
// 		return (NULL);
// 	}
// 	rest = ft_substr(line, i + (line[i] == '\n' ? 1 : 0), ft_strlen(line + i + (line[i] == '\n' ? 1 : 0), '\0'));
// 	if (!rest)
// 	{
// 		free(aux);
// 		return (NULL);
// 	}
// 	free(line);
// 	line = rest;
// 	free(rest);
// 	return (aux);
// }

char *cut__line(char **line)
{
	int i;
	char *aux;
	char *rest;

	if (!*line)
	{
		free(*line);
		return (NULL);
	}
	i = 0;
	while ((*line)[i] && (*line)[i] != '\n')
		i++;
	if ((*line)[i] == '\n')
		i++;
	aux = ft_substr(*line, 0, i);
	if (!aux)
	{
		free(*line);
		return (NULL);
	}
	rest = ft_substr(*line, i, ft_strlen(*line + i, '\0'));
	if (!rest)
	{
		free(aux);
		return (NULL);
	}
	free(*line);
	*line = rest;
	// free(rest);
	return (aux);
}

char *get_next_line(int fd)
{
	static char *line;
	char *new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	new_line = NULL;
	line = get__line(fd, line);
	if (!line || line[0] == '\0')
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	new_line = cut__line(&line);
	if (!new_line)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	return (new_line);
}

int main(void)
{
	int fd;
	static char *line;

	line = NULL;
	fd = open("file.txt", O_RDONLY);
	/*if (!line)
		line = get_next_line(fd);
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}*/
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}
