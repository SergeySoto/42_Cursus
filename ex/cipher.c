/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cipher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:02:10 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/11/17 12:49:57 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

char	*encode(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		str[i] = 'Z' - (str[i] - 'A');
		else if (str[i] >= 'a' && str[i] <= 'z')
		str[i] = 'z' - (str[i] - 'a');
		i++;
	}
	return (str);
}

char	*decode(char *str)
{
	int	i;
	
	i = 0;
	while(str[i])
	{
		if (str[i] == ' ')
			str[i] = ' ';
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = 'Z' + (str[i] + 'A');
		else if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = 'z' + (str[i] + 'a');
		i++;
	}
	return (str);
	}
	
int	select_mode(char **argv)
{
	if (argv[2][0] == '\0')
		return (1);
	if (ft_strcmp("encode", argv[1]) == 0)
		ft_putstr_fd(encode(argv[2]), 1);
	else if (ft_strcmp("decode", argv[1]) == 0)
		ft_putstr_fd(decode(argv[2]), 1);
	return (0);
}
