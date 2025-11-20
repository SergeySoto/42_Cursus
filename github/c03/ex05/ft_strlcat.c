/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:02:43 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/02/19 18:06:49 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_strlen(char *str)
{
	unsigned int	i;
	
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	count;
	unsigned int	res;

	count = 0;
	i = 0;
	j = 0;
	res = ft_strlen(dest) + ft_strlen(src);
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0' && count < size)
	{
		dest[i] = src[j];
		i++;
		j++;
		count++;
	}
	dest[i] = '\0';
	return (res);
}
